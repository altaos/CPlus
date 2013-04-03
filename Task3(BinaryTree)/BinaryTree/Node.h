#pragma once

template<class T>
struct Node
{
	T value;
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