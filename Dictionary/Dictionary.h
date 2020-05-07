#pragma once
#include "..\KostylContainers\AvlTree.h"
#include "DictPairT.h"

template <typename Key, typename Value>
class Dictionary
{
	typedef DictPairT<Key, Value> Pair;
	typedef AvlTree<Pair> Tree;
	typedef typename Tree::iterator t_iterator;
	Tree _tree;

	struct DictProxy
	{
		t_iterator it;
		DictProxy(t_iterator i) : it(i) {}
		DictProxy& operator=(Value val)
		{
			*it = Pair((*it).key(), val);
			return *this;
		}
		operator Value()
		{
			return (*it).value();
		}
	};

public:
	Dictionary() {}
	~Dictionary() { clear();	 }

	void add(Pair pair)
	{
		_tree.push_back(pair);
	}
	void add(Key key, Value val)
	{
		_tree.push_back(Pair(key, val));
	}

	t_iterator find(Key key)
	{
		t_iterator it = _tree.begin();
		while (it != _tree.end())
		{
			if (*it == Pair(key))
				break;
			++it;
		}
		return it;
	}

	t_iterator erase(Key key)
	{
		return _tree.erase(find(key));
	}

	t_iterator erase(t_iterator it)
	{
		return _tree.erase(it);
	}

	void clear()
	{
		_tree.clear();
	}

	DictProxy operator[](Key key)
	{
		t_iterator it = find(key);
		if (it == _tree.end())
			add(key, Value());
		it = find(key);
		return DictProxy(it);
	}
};