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

//private ���������� � ������
void BTree::Insert(Node **node, int value)
{
	//���� ���� ����
	if(!(*node))
	{
		*node = new Node(value);
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
void BTree::Insert(int value)
{
	Insert(&root, value);
}

//private �������� �������� �� ��������� value
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
	//����� ��������� �������
	else
	{
		Node *current;

		//���� ���� ���� ������ �����
		if(!((*node)->left) && (*node)->right)
		{
			current = (*node)->right;
			delete *node;
			*node = current;
		}
		//���� ���� ���� ����� �����
		else if(!((*node)->right) && (*node)->left)
		{
			current = (*node)->left;
			delete *node;
			*node = current;
		}
		//���� ���� ��� �����
		else
		{
			current = (*node)->right;
			Node *parent = NULL;

			//����� ������ ������ ���� � ������ ���������
			while(current->left)
			{
				parent = current;
				current = current->left;
			}
			//������ �������� value �� �������� ������ ������ ���� � ������ ���������
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

//�������� �������� �� ������
bool BTree::Remove(const int value)
{
	if(Remove(&root, value))
	{
		count--;
		return true;
	}

	return false;
}

//��������� ���������� ��������� � ������
int BTree::Size() const
{
	return count;
}

//private �������� ������
void BTree::DeleteBTree(Node **node)
{
	if(!(*node))
	{
		DeleteBTree(&((*node)->left));
		DeleteBTree(&((*node)->right));
		delete *node;
	}
}