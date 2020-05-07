#include <iostream>
#include <stack>
#include "formula_node.h"
#include <map>
#include <functional>
#include <sstream>

std::map<char, std::function<double(double, double) >> operator_map =
{
	{'+', std::plus<double>()},
	{'-', std::minus<double>()},
	{'*', std::multiplies<double>()},
	{'/', std::divides<double>()}
};

double calc_postfix(const std::string& formula_str){
	std::stack<double> container;
	for (char curr : formula_str){
		if (isdigit(curr)) {
			container.push(curr - '0');
			continue;
		}
		double right = container.top(); container.pop();
		double left = container.top(); container.pop();
		container.push(operator_map[curr](left,right));
	}
	return container.top();
}

class Formula {
	
	// 1: char -> out_str, in_str++
	// 2: char -> stack, in_str++
	// 3: stack -> out_str + stack.pop
	// 4: finish
	enum Action { char2str, char2stack, stack2str, finish };
	const Action ActionTable[6][7] =
	{
		//     0          +           -          *           /             ^            N
		{    finish, char2stack, char2stack, char2stack, char2stack,  char2stack,   char2str}, // 0
		{ stack2str,  stack2str,  stack2str, char2stack, char2stack,  char2stack,   char2str}, // +
		{ stack2str,  stack2str,  stack2str, char2stack, char2stack,  char2stack,   char2str}, // -
		{ stack2str,  stack2str,  stack2str, stack2str,  stack2str,   char2stack,   char2str}, // *
		{ stack2str,  stack2str,  stack2str, stack2str,  stack2str,   char2stack,   char2str}, // /
		{ stack2str,  stack2str,  stack2str, stack2str,  stack2str,   stack2str,    char2str} // ^
	};

	size_t ActionColumn(char curr) {
		switch (curr) {
			case   0: return 0;
			case '+': return 1;
			case '-': return 2;
			case '*': return 3;
			case '/': return 4;
			case '^': return 5;
		}
		if (isdigit(curr)) return 6;
		return 6;
	}

	size_t ActionRow(const std::stack<char>& container) {
		if (container.empty()) return 0;
		char curr = container.top();
		switch (curr) {
			case   0: return 0;
			case '+': return 1;
			case '-': return 2;
			case '*': return 3;
			case '/': return 4;
			case '^': return 5;
		}
		return 0;
	}

	std::map<char, std::function<FormulaNode* (FormulaNode*, FormulaNode*)>> node_map =
	{
		{'+', [](FormulaNode* left, FormulaNode* right) {return new PlusNode(left,right); } },
		{'-', [](FormulaNode* left, FormulaNode* right) {return new MinusNode(left,right); } },
		{'*', [](FormulaNode* left, FormulaNode* right) {return new MultNode(left,right); } },
		{'/', [](FormulaNode* left, FormulaNode* right) {return new DivNode(left,right); } },
		{'^', [](FormulaNode* left, FormulaNode* right) {return new PowNode(left, right); } }
	};

	FormulaNode* from_postfix(const std::string& postfix_str) {
		std::stack<FormulaNode*> nodes;
		for (char curr : postfix_str) {
			if (isdigit(curr)){
				nodes.push(new NumNode(curr - '0'));
				continue;
			}
			FormulaNode* node;
			auto right = nodes.top(); nodes.pop();
			auto left = nodes.top(); nodes.pop();
			nodes.push(node_map[curr](left, right));
		}
		return nodes.top();
	}
	std::string infix_to_postfix(const std::string& infix_str) {
		std::stringstream str_stream;
		size_t in_idx = 0;
		Action action;
		std::stack<char> container;
		do {
			if (infix_str[in_idx] == ' ')
			{
				++in_idx;
				continue;
			}
			size_t col = ActionColumn(infix_str[in_idx]);
			size_t row = ActionRow(container);
			action = ActionTable[row][col];
			switch (action) {
				case char2str: str_stream << infix_str[in_idx++]; break;
				case char2stack: container.push(infix_str[in_idx++]); break;
				case stack2str: {
					str_stream << container.top();
					container.pop();
					break;
				}
			}
		} while (action != finish);
		return str_stream.str();
	}

	FormulaNode* _root;
public:
	Formula(const std::string& str, bool is_postfix = false) {_root = from_postfix(is_postfix ? str : infix_to_postfix(str)); }
	double calc() const { return _root ? _root->calc() : 0; }
	std::string str() const { return _root ? _root->str() : ""; }
	Formula(FormulaNode* node) : _root(node) {}
	Formula operator+(const Formula& f) const {
		return Formula(new PlusNode(_root->copy(), f._root->copy()));
	}
	Formula operator-(const Formula& f) const {
		return Formula(new MinusNode(_root->copy(), f._root->copy()));
	}
	Formula operator*(const Formula& f) const {
		return Formula(new MultNode(_root->copy(), f._root->copy()));
	}
	Formula operator/(const Formula& f) const {
		return Formula(new DivNode(_root->copy(), f._root->copy()));
	}
	Formula operator^(const Formula& f) const {
		return Formula(new PowNode(_root->copy(), f._root->copy()));
	}
	Formula& operator+=(const Formula& f)
	{
		_root = new PlusNode(_root, f._root->copy());
		return *this;
	}
	Formula& operator-=(const Formula& f)
	{
		_root = new MinusNode(_root, f._root->copy());
		return *this;
	}
	Formula& operator*=(const Formula& f)
	{
		_root = new MultNode(_root, f._root->copy());
		return *this;
	}
	Formula& operator/=(const Formula& f)
	{
		_root = new DivNode(_root, f._root->copy());
		return *this;
	}
	Formula& operator^=(const Formula& f)
	{
		_root = new PowNode(_root, f._root->copy());
		return *this;
	}

	Formula(const Formula& src) : _root(src._root->copy()) {}
	Formula(Formula&& src) : _root(src._root) { src._root = nullptr; }

	Formula& operator=(const Formula& f)
	{
		if(&f != this)
			_root = f._root->copy();
		return *this;
	}

	Formula& operator=(Formula&& f)
	{
		_root = f._root;
		f._root = nullptr;
		return *this;
	}


	~Formula() {
		if (_root) delete _root;
		_root = nullptr;
	}

	Formula(double num) : _root(new NumNode(num)) {}
	Formula(const char* str, bool is_postfix = false) : _root(is_postfix ? from_postfix(str) :
															 from_postfix(infix_to_postfix(str))) {}
};

int main() {
	setlocale(LC_ALL, "Rus");
	//"2+2" <-> "22+"
	//"4*(2+3)-5/2" <-> "23+4*52/-"
	//"2+(3*4)" <-> "234*+" <-> "34*2+"
	//wrong translation: "23+4*"
	//"-2" <-> "02-"

	//std::cout << calc_postfix("23+4*50/-") << std::endl;

	//Formula f("23+4*52/-");
	//Formula f("2+3*4-5/2");
	
	//Formula x("234*+52/-", true);
	//Formula y("2+3*4-5/2");
	//Formula f = x + y;

	Formula x("2*2^3+1");
	Formula f = x^2;
	f *= "8 / 2";
	
	Formula f2 = f;
	f2 = 3;
	try{
		std::cout << f.str() << " = " << f.calc() << std::endl;
	} catch (const Error& e){
		std::cout << "Error: " << e.what() << std::endl;
	}

	system("pause");
	return 0;
}
