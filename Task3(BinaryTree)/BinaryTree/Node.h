#pragma once
#include"stdafx.h"

template<class T>
class Node
{
public:
	T value;
	Node *parent;
	Node *right, *left;

	Node()
	{ 
		right = left = NULL;
	}

	Node(T value)
	{
		this->value = value;
		right = left = NULL;
	}
};
