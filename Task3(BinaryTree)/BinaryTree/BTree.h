#pragma once
#include "stdafx.h"

template<class T>
class BTree
{
private:
	Node<T> *root;													//Корень дерева
	int count;														//Количество элемнтов в дереве

	void Insert(Node<T> **node, T value);
	bool BTree<T>::Remove(Node<T> *&node, const T value);
	void DeleteBTree(Node<T> **node);
	void Print(Node<T> *node) const;
	void Insert(Node<T> *node);
	Node<T> *SearchNode(T value);

public:
	BTree(void);
	BTree(T value);
	~BTree(void);

	void Insert(T value);											//Вставка элемента в дерево
	bool Remove(const T value);										//Удаление элемента из дерева по значению
	bool Remove(Iterator<T> it);
	void Clear();
	int Size() const;												//Получить количество элементов в дереве
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

//private Добавление в дерево
/*template<class T>
void BTree<T>::Insert(Node<T> **node, T value)
{
	//Если узел пуст
	if(!(*node))
	{
		*node = new Node<T>(value);
		count++;
	}
	else
	{
		//Если значение больше значения текущего узла, то отправляем в правое поддерево
		if(value >= (*node)->value)
		{
			Insert(&((*node)->right), value);
		}
		else
		{
			Insert(&((*node)->left), value);
		}
	}
}*/

template<class T>
void BTree<T>::Insert(Node<T> *node)
{
	if(!node)
		return;

	if(!root)
	{
		root = node;
		root->parent = NULL;
		count++;
	}
	else
	{
		if(node->parent == NULL)
			node->parent = root;
		
		//вставляем  в левую ветвь
		if(node->value < node->parent->value)
		{
			if(node->parent->left == NULL)
			{
				node->parent->left = node;
				count++;
			}
			else
			{
				node->parent = node->parent->left;
				Insert(node);
			}
		}
		//вставляем в правую ветвь
		else
		{
			if(node->parent->right == NULL)
			{
				node->parent->right = node;
				count++;
			}
			else
			{
				node->parent = node->parent->right;
				Insert(node);
			}
		}
	}
}

//Добавление элемента в дерево
template<class T>
void BTree<T>::Insert(T value)
{
	//Insert(&root, value);
	Node<T> *node = new Node<T>(value);
	Insert(node);
}

//private Удаление элемента со значением value
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
	//нашли удаляемый элемент
	else
	{
		Node<T> *current;

		//Если есть одна правая ветвь
		if(!(node->left))
		//if(!(node->left) && node->right)
		{
			current = node->right;
			delete node;
			node = current;
		}
		//Если есть одна левая ветвь
		else if(!(node->right))
			//if(!(node->right) && node->left)
		{
			current = node->left;
			delete node;
			node = current;
		}
		//Если есть обе ветви
		else
		{
			current = node->right;
			Node<T> *parent = NULL;

			//Поиск самого левого узла в правом поддереве
			while (current->left)
			{
				parent = current;
				current = current->left;
			}
			//Меняем значение value на значение самого левого узла в правом поддереве
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

//Удаление элемента из дерева
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

//Получение количества элементов в дереве
template<class T>
int BTree<T>::Size() const
{
	return count;
}

//private Удаление дерева
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
