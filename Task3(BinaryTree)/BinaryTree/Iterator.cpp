#pragma once
#include "stdafx.h"

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
T Iterator<T>::operator*()
{
	return it->value;
}

template<class T>
bool Iterator<T>::operator==(const Iterator<T>& it)
{
	return this->it == it;
}

template<class T>
bool Iterator<T>::operator!=(const Iterator<T>& it)
{
	return this->it != it;
}

