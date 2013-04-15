#pragma once
#include "stdafx.h"

template<class T>
class Iterator
{
	template<class T> friend class BTree;
private:
	Node<T> *it;

public:
	Iterator();
	Iterator(Node<T> *node);

	Iterator operator++(int i);
	Iterator operator--(int i);
	T& operator*();
	bool operator==(const Iterator& it);
	bool operator!=(const Iterator& it);
	Node<T>* operator ->();
};

template<class T>
Iterator<T>::Iterator() { }

template<class T>
Iterator<T>::Iterator(Node<T> *node) : it(node) { }

template<class T>
Iterator<T> Iterator<T>::operator++(int i)
{
	it = it->right;
	return *this;
}

template<class T>
Iterator<T> Iterator<T>::operator--(int i)
{
	it = it->left;
	return *this;
}

template<class T>
T& Iterator<T>::operator*()
{
	return it->value;
}

template<class T>
bool Iterator<T>::operator==(const Iterator& it)
{
	return this->it == it;
}

template<class T>
bool Iterator<T>::operator!=(const Iterator& it)
{
	return this->it != it.it;
}

template<class T>
Node<T>* Iterator<T>::operator ->()
{
		return it;
}