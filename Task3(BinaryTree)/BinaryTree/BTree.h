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
	Node *root;														//������ ������
	int count;														//���������� �������� � ������

	void Insert(Node **node, int value);
	bool Remove(Node **node, const int value);
	void DeleteBTree(Node **node);

public:
	BTree(void);
	BTree(int value);
	~BTree(void);

	void Insert(int value);											//������� �������� � ������
	bool Remove(const int value);									//�������� �������� �� ������ �� ��������
	int Size() const;												//�������� ���������� ��������� � ������
};

