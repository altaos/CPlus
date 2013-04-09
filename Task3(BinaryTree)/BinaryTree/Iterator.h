#pragma once
#include "Node.h"

//template<class T> BTree;

template<class T>
class Iterator
{
private:
	Node<T> *it;

public:
	Iterator() {}
	Iterator(Node<T> *node) : it(node) { }

	Iterator operator++(int i)
	{
		it = it->right;
		return *this;
	}

	Iterator operator--(int i)
	{
		it = it->left;
		return *this;
	}

	T& operator*()
	{
		return it->value;
	}

	bool operator==(const Iterator& it)
	{
		return this->it == it;
	}

	bool operator!=(const Iterator& iter)
	{
		return it != iter.it;
	}

};