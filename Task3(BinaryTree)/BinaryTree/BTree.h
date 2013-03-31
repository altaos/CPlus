#pragma once

struct Node
{
	int value;
	Node *right, *left;

	Node()
	{ 
		right = left = NULL;
	}

	Node(int value)
	{
		this->value = value;
		right = left = NULL;
	}

};


class BTree
{
private:
	Node *root;														//Корень дерева
	int count;														//Количество элемнтов в дереве

	void Insert(Node **node, int value);
	bool Remove(Node **node, const int value);
	void DeleteBTree(Node **node);

public:
	BTree(void);
	BTree(int value);
	~BTree(void);

	void Insert(int value);											//Вставка элемента в дерево
	bool Remove(const int value);									//Удаление элемента из дерева по значению
	int Size() const;												//Получить количество элементов в дереве
};

