#pragma once

template <typename T>
class List
{
	struct Node
	{
		T val;
		Node* next;
		Node(const T& data) : val(data), next(nullptr) {}
	};

	Node* _first;
	Node* _last;
	size_t _size;

	void copy(const List& list)
	{
		clear();
		Node* curr_node = list._first;
		while (curr_node)
		{
			push_back(curr_node->val);
			curr_node = curr_node->next;
		}
	}
public:
	List() : _first(nullptr), _last(nullptr), _size(0) {}
	List(const List& list) : List()
	{
		copy(list);
	}

	void push_back(const T& val)
	{
		if (_size == 0)
			_first = _last = new Node(val);
		else
		{
			_last->next = new Node(val);
			_last = _last->next;
		}
		++_size;
	}

	void clear()
	{
		Node* curr_node;
		while (_first)
		{
			curr_node = _first;
			_first = _first->next;
			delete[] curr_node;
		}
		_size = 0;
		_last = nullptr;
	}
	void empty() { clear(); }
	~List() { clear(); }

	List& operator=(const List& list) { copy(list); }
	size_t size() const { return _size; }
	size_t capacity() const { return -1; }

	const T& operator[](size_t idx) const
	{
		if (idx >= _size) throw "Index out of bounds";
		Node* curr = _first;
		for (size_t i = 0; i < idx; ++i)
			curr = curr->next;
		return curr->val;
	}

	class iterator
	{
		Node* _node;
	public:
		iterator(Node* node = nullptr) : _node(node) {}
		T& operator*() const { return _node->val; }
		bool operator==(const iterator& it) const { return _node == it._node; }
		bool operator!=(const iterator& it) const { return !(*this == it); }
		iterator& operator++()
		{
			if (!_node) throw "Iterator out of bounds";
			_node = _node->next;
			return *this;
		}
		iterator operator++(int)
		{
			Node* node = _node;
			if (!_node) throw "Iterator out of bounds";
			_node = _node->next;
			return iterator(node);
		}
		iterator operator+(int n)
		{
			Node* curr = _node;
			for (int i = 0; i < n; ++i)
				curr = curr->next;
			return iterator(curr);
		}

		friend iterator List::insert(iterator, const T&);
		//friend iterator List::erase(iterator, iterator);
		friend iterator List::erase(iterator);
	};

	/*class reverse_iterator
	{
		Node* _node;
		const List* _list;
	public:
		reverse_iterator(const List* list = nullptr, Node* node = nullptr) : _list(list), _node(node) {}
		T& operator*() const { return _node->val; }
		bool operator==(const reverse_iterator& it) const { return _node == it._node; }
		bool operator!=(const reverse_iterator& it) const { return !(*this == it); }
		reverse_iterator& operator++()
		{
			Node* curr = _list->_first;
			Node* prev = nullptr;
			while (curr != nullptr)
			{
				if (curr == _node)
				{
					_node = prev;
					return *this;
				}
				prev = curr;
				curr = curr->next;
			}
			throw "Something went wrong";
		}
		reverse_iterator operator++(int)
		{
			Node* curr = _list->_first;
			Node* prev = nullptr;
			while (curr != nullptr)
			{
				if (curr == _node)
				{
					_node = prev;
					return reverse_iterator(curr);
				}
				prev = curr;
				curr = curr->next;
			}
			throw "Something went wrong";
		}
		
	};

	reverse_iterator rbegin() const { return reverse_iterator(this); }
	reverse_iterator rend() const { return reverse_iterator(this, _last); }

	*/

	iterator begin() const { /*std::cout << (iterator(_first))._node->val << std::endl;*/ return  iterator(_first); }
	iterator end() const { return iterator(); }

	iterator find(const T& val) const
	{
		Node* curr = _first;
		while (curr)
		{
			if (curr->val == val)
				return iterator(curr);
			curr = curr->next;
		}
		return end();
	}

	iterator insert(iterator it, const T& elem)
	{
		++_size;
		Node* it_node = it._node;
		Node* new_node = new Node(elem);
		if (it == begin())
		{
			new_node->next = _first;
			_first = new_node;
			return begin();
		}
		if (it == end())
		{
			_last->next = new_node;
			_last = new_node;
			return iterator(_last);
		}
		new_node->next = it_node;
		for (Node* curr = _first; curr != _last; curr = curr->next)
		{
			if (curr->next == it_node)
			{
				curr->next = new_node;
				break;
			}
		}
		return iterator(new_node);
	}

	/*iterator erase(iterator it_beg, iterator it_end = nullptr)
	{
		if (it_end == nullptr)
			it_end = it_beg + 1;

		Node* curr = _first;
		Node* bef = nullptr;
		while (curr != it_beg._node)
		{
			bef = curr;
			curr = curr->next;
		}

		if (bef != nullptr)
		{
			while (true)
			{
				bef->next = curr->next;
				if (curr == it_end._node)
				{
					delete[] curr;
					break;
				}
				delete[] curr;
				curr = bef->next;
			}
			return iterator(bef->next);
		}
		else
		{
			while (true)
			{
				_first = curr->next;
				if (curr == it_end._node)
				{
					delete[] curr;
					break;
				}
				delete[] curr;
				curr = _first;
			}
			return iterator(_first);
		}
	}*/

	iterator erase(iterator it)
	{
		Node* curr = it._node;
		Node* next = curr->next;
		Node* prev = _first;
		if (size == 0)
			_first = _last = nullptr;
		else if (curr == _first)
			_first = next;
		else if (curr == _last)
			_last = prev;
		for (; prev->next != curr; prev = prev->next);
		prev->next = curr->next;
		if (curr) delete[] curr;
		return iterator(next);
	}

};