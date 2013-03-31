#include "stdafx.h"
#include "BTree.h"


BTree::BTree(void)
{
	root = NULL;
	count = 0;
}

BTree::BTree(int value)
{
	root = new Node(value);
	count = 1;
}

BTree::~BTree(void)
{
	DeleteBTree(&root);
}

//private Добавление в дерево
void BTree::Insert(Node **node, int value)
{
	//Если узел пуст
	if(!(*node))
	{
		*node = new Node(value);
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
}

//Добавление элемента в дерево
void BTree::Insert(int value)
{
	Insert(&root, value);
}

//private Удаление элемента со значением value
bool BTree::Remove(Node **node, const int value)
{
	if(!(*node))
		return false;

	if(value > (*node)->value)
	{
		Remove(&((*node)->right), value);
	}
	else if(value < (*node)->value)
	{
		Remove(&((*node)->left), value);
	}
	//нашли удаляемый элемент
	else
	{
		Node *current;

		//Если есть одна правая ветвь
		if(!((*node)->left) && (*node)->right)
		{
			current = (*node)->right;
			delete *node;
			*node = current;
		}
		//Если есть одна левая ветвь
		else if(!((*node)->right) && (*node)->left)
		{
			current = (*node)->left;
			delete *node;
			*node = current;
		}
		//Если есть обе ветви
		else
		{
			current = (*node)->right;
			Node *parent = NULL;

			//Поиск самого левого узла в правом поддереве
			while(current->left)
			{
				parent = current;
				current = current->left;
			}
			//Меняем значение value на значение самого левого узла в правом поддереве
			(*node)->value = current->value;

			if(parent)
			{
				Remove(&(parent->left), parent->left->value);
			}
			else
			{
				Remove(&((*node)->right), (*node)->right->value);
			}
		}
	}
}

//Удаление элемента из дерева
bool BTree::Remove(const int value)
{
	if(Remove(&root, value))
	{
		count--;
		return true;
	}

	return false;
}

//Получение количества элементов в дереве
int BTree::Size() const
{
	return count;
}

//private Удаление дерева
void BTree::DeleteBTree(Node **node)
{
	if(!(*node))
	{
		DeleteBTree(&((*node)->left));
		DeleteBTree(&((*node)->right));
		delete *node;
	}
}