#pragma once
#include"stdafx.h"

template<class T>
class Node
{
	template<class T> friend class BTree;
	template<class T> friend class Iterator;
private:
	T value;
	Node *parent;
	Node *right, *left;

public:
	Node();

	Node(T value);
};

template<class T>
Node<T>::Node()
{ 
	right = left = NULL;
}

template<class T>
Node<T>::Node(T value)
{
	this->value = value;
	right = left = NULL;
}


