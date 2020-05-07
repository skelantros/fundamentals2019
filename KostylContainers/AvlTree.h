#pragma once

template <typename Type>
class AvlTree
{
	struct Node
	{
		Node* left;
		Node* right;
		Node* parent;
		Type data;

		Node(const Type& _data, Node* _parent = nullptr) : data(_data), left(nullptr), right(nullptr), parent(_parent) {}
		~Node()
		{
			if (left) delete left;
			if (right) delete right;
			left = right = nullptr;
		}

		Node* minimum()
		{
			Node* curr = this;
			while (curr->left)
				curr = curr->left;
			return curr;
		}

		Node* next() 
		{
			if (right)
				return right->minimum();
			Node* curr = this;
			Node* curr_parent = parent;
			while (curr_parent)
			{
				if (curr_parent->left == curr)
					break;
				curr = curr_parent;
				curr_parent = curr_parent->parent;
			}
			return curr_parent;
		}

		size_t height() const
		{
			size_t l_height = left ? left->height() : 0;
			size_t r_height = right ? right->height() : 0;
			return l_height < r_height ? r_height + 1 : l_height + 1;
		}

		signed char balance() const
		{
			size_t l_height = left ? left->height() : 0;
			size_t r_height = right ? right->height() : 0;
			return r_height - l_height;
		}
	};

	Node* _root;
	size_t _size;
	void rebalance(Node* sub_root);
	Node* right_rotate(Node* sub_root);
	Node* left_rotate(Node* sub_root);
public:
	void clear()
	{
		if (_root) delete _root;
		_root = nullptr;
	}
	void empty() { clear(); }
	AvlTree() : _root(nullptr), _size(0) {}
	~AvlTree() { clear(); }

	void push_back(const Type& elem)
	{
		++_size;
		if (!_root)
			_root = new Node(elem);
		else
		{
			Node* curr = _root;
			Node* curr_parent = nullptr;
			while (curr)
			{
				curr_parent = curr;
				curr = elem >= curr->data ? curr->right : curr->left;
			}
			//(elem >= curr_parent->data ? curr_parent->right : curr_parent->left) = new Node(elem, curr_parent);
			curr = new Node(elem);
			curr->parent = curr_parent;
			(elem >= curr_parent->data) ? (curr_parent->right = curr) : (curr_parent->left = curr);
			rebalance(curr_parent);
		}
	}


	size_t size() const { return _size; }
	size_t capacity() const { return -1; }

	size_t height() const { return _root->height(); }

	class iterator
	{
		Node* _node;
	public:
		iterator(Node* node = nullptr) : _node(node) {}

		iterator& operator++()
		{
			if (_node == nullptr) throw "Iterator out of bounds";
			_node = _node->next();
			return *this;
		}
		iterator operator++(int)
		{
			if (_node == nullptr) throw "Iterator out of bounds";
			Node* prev = _node;
			_node = _node->next();
			return iterator(prev);
		}

		bool operator==(const iterator& it) const
		{
			return _node == it._node;
		}
		bool operator!=(const iterator& it) const
		{
			return _node != it._node;
		}

		Type& operator*() const { return _node->data; }

		friend iterator AvlTree::erase(iterator);
	};

	iterator begin()
	{
		if (_root) return iterator(_root->minimum());
		return end();
	}
	iterator end() { return iterator(); }

	iterator find(const Type& elem)
	{
		Node* curr = _root;
		while (curr)
		{
			if (curr->data == elem)
				break;
			else if (elem >= curr->data)
				curr = curr->right;
			else
				curr = curr->left;
		}
		return iterator(curr);
	}

	iterator erase(iterator it)
	{
		Node* to_erase = it._node;
		if (_size == 0)
			throw "Nothing to erase";
		if (to_erase == nullptr)
			return it;

		Node* replace;
		if (to_erase->right == nullptr)
			replace = to_erase->left;
		else if (to_erase->left == nullptr)
			replace = to_erase->right;
		else
			replace = to_erase->right->minimum();

		if (to_erase->right && to_erase->left)
		{
			if (replace->parent != to_erase)
			{
				replace->parent->left = replace->right;
				if (replace->right) replace->right->parent = replace->parent;
				replace->right = to_erase->right;
				to_erase->right->parent = replace;
			}
			replace->left = to_erase->left;
			to_erase->left->parent = replace;
		}

		if (replace) replace->parent = to_erase->parent;

		if (to_erase == _root)
			_root = replace;
		else
		{
			if (to_erase->parent->left == to_erase)
				to_erase->parent->left = replace;
			else
				to_erase->parent->right = replace;
		}

		to_erase->right = nullptr;
		to_erase->left = nullptr;
		delete to_erase;
		--_size;

		return iterator(replace);
	}
};

template <typename Type>
void AvlTree<Type>::rebalance(Node* sub_root)
{
	while (sub_root != nullptr && sub_root->balance() != 0)
	{
		switch (sub_root->balance())
		{
		case 2:
		{
			if (sub_root->right->balance() == -1)
				right_rotate(sub_root->right);
			sub_root = left_rotate(sub_root);
			break;
		}
		case -2:
		{
			if (sub_root->left->balance() == -1)
				left_rotate(sub_root->left);
			sub_root = right_rotate(sub_root);
			break;
		}
		}
		if (sub_root->parent == nullptr)
			_root = sub_root;
		sub_root = sub_root->parent;
	}
}

template <typename Type>
typename AvlTree<Type>::Node* AvlTree<Type>::right_rotate(Node* sub_root)
{
	Node* replace = sub_root->left;
	sub_root->left = replace->right;
	if (replace->right) replace->right->parent = sub_root;
	replace->parent = sub_root->parent;
	if (sub_root->parent != nullptr)
	{
		if (sub_root->parent->left == sub_root)
			sub_root->parent->left = replace;
		else
			sub_root->parent->right = replace;
	}
	replace->right = sub_root;
	replace->right->parent = replace;

	return replace;
}

template <typename Type>
typename AvlTree<Type>::Node* AvlTree<Type>::left_rotate(Node* sub_root)
{
	Node* replace = sub_root->right;
	sub_root->right = replace->left;
	if(replace->left) replace->left->parent = sub_root;
	replace->parent = sub_root->parent;
	if (sub_root->parent != nullptr)
	{
		if (sub_root->parent->left == sub_root)
			sub_root->parent->left = replace;
		else
			sub_root->parent->right = replace;
	}
	replace->left = sub_root;
	replace->left->parent = replace;

	return replace;
}