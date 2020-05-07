#pragma once

template <typename T>
class DoubleList
{
	struct Node
	{
		T val;
		Node* next;
		Node* prev;
		Node(const T& data) : val(data), next(nullptr), prev(nullptr) {}
	};

	Node* _first;
	Node* _last;
	size_t _size;

	void copy(const DoubleList& list)
	{
		clear();
		Node* curr_node = list._first;
		while (curr_node)
		{
			push_back(curr_node->val);
			curr_node = curr_node->next;
		}
	}

	void bubble_sort()
	{
		bool is_changed = false;
		do
		{
			is_changed = false;
			for (auto i = begin(); i != begin() + (_size - 1); ++i)
			{
				if (*i > * (i + 1))
				{
					T temp = *i;
					*i = *(i + 1);
					*(i + 1) = temp;
					is_changed = true;
				}
			}
		} while (is_changed);
	}
public:
	DoubleList() : _first(nullptr), _last(nullptr), _size(0) {}
	DoubleList(const DoubleList& list) : DoubleList()
	{
		copy(list);
	}

	void sort() {bubble_sort(); }

	void push_back(const T& val)
	{
		if (_size == 0)
			_first = _last = new Node(val);
		else
		{
			Node* new_node = new Node(val);
			new_node->prev = _last;
			_last->next = new_node;
			_last = new_node;
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
	~DoubleList() { clear(); }

	DoubleList& operator=(const DoubleList& list) { copy(list); }
	size_t size() const { return _size; }
	size_t capacity() const { return -1; }

	const T& operator[](size_t idx) const
	{
		if (idx >= _size) throw "Index out of bounds";
		Node* curr;
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

		iterator& operator--()
		{
			if (!_node) throw "Iterator out of bounds";
			_node = _node->prev;
			return *this;
		}
		iterator operator--(int)
		{
			Node* node = _node;
			if (!_node) throw "Iterator out of bounds";
			_node = _node->prev;
			return iterator(node);
		}
		iterator operator-(int n)
		{
			Node* curr = _node;
			for (int i = 0; i < n; ++i)
				curr = curr->prev;
			return iterator(curr);
		}

		friend iterator DoubleList::insert(iterator, const T&);
		friend iterator DoubleList::erase(iterator);
		//friend iterator DoubleList::erase(iterator, iterator);
	};

	class reverse_iterator
	{
		Node* _node;
	public:
		reverse_iterator(Node* node = nullptr) : _node(node) {}
		T& operator*() const { return _node->val; }
		bool operator==(const reverse_iterator& it) const { return _node == it._node; }
		bool operator!=(const reverse_iterator& it) const { return !(*this == it); }
		reverse_iterator& operator++()
		{
			if (!_node) throw "Iterator out of bounds";
			_node = _node->prev;
			return *this;
		}
		reverse_iterator operator++(int)
		{
			Node* node = _node;
			if (!_node) throw "Iterator out of bounds";
			_node = _node->prev;
			return iterator(node);
		}
		reverse_iterator operator+(int n)
		{
			Node* curr = _node;
			for (int i = 0; i < n; ++i)
				curr = curr->prev;
			return iterator(curr);
		}

		reverse_iterator& operator--()
		{
			if (!_node) throw "Iterator out of bounds";
			_node = _node->next;
			return *this;
		}
		reverse_iterator operator--(int)
		{
			Node* node = _node;
			if (!_node) throw "Iterator out of bounds";
			_node = _node->next;
			return iterator(node);
		}
		reverse_iterator operator-(int n)
		{
			Node* curr = _node;
			for (int i = 0; i < n; ++i)
				curr = curr->next;
			return iterator(curr);
		}

	};

	reverse_iterator rbegin() const { return reverse_iterator(_last); }
	reverse_iterator rend() const { return reverse_iterator(nullptr); }

	iterator begin() const { return iterator(_first); }
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
			_first->prev = new_node;
			_first = new_node;
			return begin();
		}
		if (it == end())
		{
			_last->next = new_node;
			new_node->prev = _last;
			_last = new_node;
			return iterator(_last);
		}
		new_node->next = it_node;
		new_node->prev = it_node->prev;
		(it_node->prev)->next = new_node;
		it_node->prev = new_node;

		return iterator(new_node);
	}

	iterator erase(iterator it)
	{
		Node* it_node = it._node;
		Node* ret_node;
		if (it_node == _first && it_node == _last)
		{
			_first = nullptr;
			_last = nullptr;
			delete[] it_node;
			return end();
		}
		if (it_node == _first)
		{
			_first = _first->next;
			_first->prev = nullptr;
			ret_node = _first;
		}
		else if (it_node == _last)
		{
			_last = _last->prev;
			_last->next = nullptr;
			ret_node = _last;
		}
		else
		{
			(it_node->prev)->next = it_node->next;
			(it_node->next)->prev = it_node->prev;
			ret_node = it_node->next;
		}
		delete[] it_node;
		return iterator(ret_node);
	}

	iterator erase(iterator it_beg, iterator it_end)
	{
		iterator curr = it_beg;
		while (curr != it_end)
			curr = erase(curr);
		return erase(curr);
	}
};