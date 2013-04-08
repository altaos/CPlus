#pragma once

template<class T>
class Node
{
public:
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