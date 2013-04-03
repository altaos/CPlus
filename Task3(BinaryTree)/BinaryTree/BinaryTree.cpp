// BinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BTree.h"


int _tmain(int argc, _TCHAR* argv[])
{
	/*BTree *tree = new BTree(10);
	tree->Insert(8);
	tree->Insert(16);
	tree->Insert(9);
	tree->Insert(7);
	tree->Insert(18);
	tree->Insert(17);
	tree->Insert(19);*/
	//tree->Insert(13);

	//tree->Remove(10);

	BTree<int> *tree = new BTree<int>(10);
	tree->Insert(8);
	tree->Insert(16);
	tree->Insert(9);
	tree->Insert(7);
	tree->Insert(18);
	tree->Insert(17);
	tree->Insert(19);

	tree->Remove(10);

	return 0;
}

