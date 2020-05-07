#pragma once
#include <string>
#include "errors.h"

class FormulaNode {
public:
	virtual double calc() const = 0;
	virtual std::string str() const = 0;
	virtual ~FormulaNode() {}
	virtual FormulaNode* copy() const = 0;
};

class NumNode : public FormulaNode {
	const double _num;
public:
	NumNode(double num) : _num(num) {}
	double calc() const override { return _num; }
	std::string str() const override { return std::to_string(_num); }
	FormulaNode* copy() const override
	{
		return new NumNode(_num);
	}
};

class BinNode : public FormulaNode{
protected:
	FormulaNode *_left, *_right;
public:
	BinNode(FormulaNode* left, FormulaNode* right) : _left(left), _right(right) {}
	~BinNode() {
		if (_left) delete _left;
		if (_right) delete _right;
		_left = _right = nullptr;
	}
};

class PlusNode : public BinNode{
public:
	PlusNode(FormulaNode* left, FormulaNode* right) : BinNode(left, right) {}	
	double calc() const override { return _left->calc() + _right->calc(); }
	std::string str() const override { return _left->str() + " + " + _right->str(); }
	virtual FormulaNode* copy() const override
	{
		return new PlusNode(_left->copy(), _right->copy());
	}
};

class MinusNode : public BinNode {
public:
	MinusNode(FormulaNode* left, FormulaNode* right) : BinNode(left, right) {}
	double calc() const override { return _left->calc() - _right->calc(); }
	std::string str() const override { return _left->str() + " - " + _right->str(); }
	virtual FormulaNode* copy() const override
	{
		return new MinusNode(_left->copy(), _right->copy());
	}
};

class MultNode : public BinNode {
public:
	MultNode(FormulaNode* left, FormulaNode* right) : BinNode(left, right) {}
	double calc() const override { return _left->calc() * _right->calc(); }
	std::string str() const override { return "(" + _left->str() + ")*(" + _right->str() +")"; }
	virtual FormulaNode* copy() const override
	{
		return new MultNode(_left->copy(), _right->copy());
	}
};

class DivNode : public BinNode {
public:
	DivNode(FormulaNode* left, FormulaNode* right) : BinNode(left, right) {}
	double calc() const override { 
		if (_right->calc() == 0) throw ErrorDivByZero();
		return _left->calc() / _right->calc(); 
	}
	std::string str() const override { return "(" + _left->str() + ")/(" + _right->str() + ")"; }
	virtual FormulaNode* copy() const override
	{
		return new DivNode(_left->copy(), _right->copy());
	}
};

class PowNode : public BinNode
{
public:
	PowNode(FormulaNode* left, FormulaNode* right) : BinNode(left, right) {}
	double calc() const override
	{
		return pow(_left->calc(), _right->calc());
	}
	std::string str() const override { return "(" + _left->str() + ")^(" + _right->str() + ")"; }
	virtual FormulaNode* copy() const override
	{
		return new PowNode(_left->copy(), _right->copy());
	}
};