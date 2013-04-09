#pragma once
#include "stdafx.h"

template<class T>
class BTree
{
private:
	Node<T> *root;													//������ ������
	int count;														//���������� �������� � ������

	void Insert(Node<T> **node, T value);
	bool BTree<T>::Remove(Node<T> *&node, const T value);
	void DeleteBTree(Node<T> **node);
	void Print(Node<T> *node) const;

public:
	BTree(void);
	BTree(T value);
	~BTree(void);

	void Insert(T value);											//������� �������� � ������
	bool Remove(const T value);										//�������� �������� �� ������ �� ��������
	bool Remove(Iterator<T> it);
	void Clear();
	int Size() const;												//�������� ���������� ��������� � ������
	Iterator<T> begin();
	Iterator<T> end();
	void Print() const;

	typedef Iterator<T> iterator;
};

template<class T>
BTree<T>::BTree(void)
{
	root = NULL;
	count = 0;
}

template<class T>
BTree<T>::BTree(T value)
{
	root = new Node<T>(value);
	count = 1;
}

template<class T>
BTree<T>::~BTree(void)
{
	DeleteBTree(&root);
}

//private ���������� � ������
template<class T>
void BTree<T>::Insert(Node<T> **node, T value)
{
	//���� ���� ����
	if(!(*node))
	{
		*node = new Node<T>(value);
		count++;
	}
	else
	{
		//���� �������� ������ �������� �������� ����, �� ���������� � ������ ���������
		if(value >= (*node)->value)
		{
			Insert(&((*node)->right), value);
		}
		else
		{
			Insert(&((*node)->left), value);
		}
	}
}

//���������� �������� � ������
template<class T>
void BTree<T>::Insert(T value)
{
	Insert(&root, value);
}

//private �������� �������� �� ��������� value
template<class T>
bool BTree<T>::Remove(Node<T> *&node, const T value)
{
	if(!node)
		return false;

	if(value > node->value)
	{
		return Remove(node->right, value);
	}
	else if(value < node->value)
	{
		return Remove(node->left, value);
	}
	//����� ��������� �������
	else
	{
		Node<T> *current;

		//���� ���� ���� ������ �����
		if(!(node->left))
		//if(!(node->left) && node->right)
		{
			current = node->right;
			delete node;
			node = current;
		}
		//���� ���� ���� ����� �����
		else if(!(node->right))
			//if(!(node->right) && node->left)
		{
			current = node->left;
			delete node;
			node = current;
		}
		//���� ���� ��� �����
		else
		{
			current = node->right;
			Node<T> *parent = NULL;

			//����� ������ ������ ���� � ������ ���������
			while (current->left)
			{
				parent = current;
				current = current->left;
			}
			//������ �������� value �� �������� ������ ������ ���� � ������ ���������
			node->value = current->value;

			if (parent)
			{
				return Remove(parent->left, parent->left->value);
			}
			else
			{
				return Remove(node->right, node->right->value);
			}
		}
	}
	return false;
}

template<class T>
bool BTree<T>::Remove(Iterator<T> it)
{
	//Node<T>* node = *it;
	count--;
	return Remove(it.it, (*it)->value);
}

//�������� �������� �� ������
template<class T>
bool BTree<T>::Remove(const T value)
{
	if(Remove(root, value))
	{
		count--;
		return true;
	}

	return false;
}

template<class T>
void BTree<T>::Clear()
{
	DeleteBTree(&root);
}

//��������� ���������� ��������� � ������
template<class T>
int BTree<T>::Size() const
{
	return count;
}

//private �������� ������
template<class T>
void BTree<T>::DeleteBTree(Node<T> **node)
{
	if((*node))
	{
		DeleteBTree(&((*node)->left));
		DeleteBTree(&((*node)->right));
		delete *node;
		count = 0;
	}
}

template<class T>
Iterator<T> BTree<T>::begin()
{
	Iterator<T> it(root);
	return it;
}

template<class T>
Iterator<T> BTree<T>::end()
{
	Iterator<T> it(NULL);
	return it;
}

template<class T>
void BTree<T>::Print(Node<T> *node) const
{
	if(node == NULL) return;

	Print(node->left);
	cout<<node->value<<" ";
	Print(node->right);
}

template<class T>
void BTree<T>::Print() const
{
	if(root == NULL) return;

	Print(root);
	cout<<endl;
}
