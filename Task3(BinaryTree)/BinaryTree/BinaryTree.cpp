// BinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include "BTree.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int choice;
	bool created = false;
	BTree<int> *intTree = new BTree<int>();
	BTree<string> *stringTree = new BTree<string>();
	int flag = -1;

	do
	{
		if(!created)
		{
			cout<< "1. Int tree" << endl;
			cout<< "2. String tree" << endl<<endl;

			cin>>choice;
			switch (choice)
			{
			case 1: 
				intTree = new BTree<int>();
				flag = 1;
				created = true;
				break;
			case 2:
				stringTree = new BTree<string>();
				flag = 2;
				created = true;
				break;
			default:
				break;
			}
		}
		else
		{
			if(flag == 1)
				cout<<"Int tree"<<endl<<endl;
			if(flag == 2)
				cout<<"String tree"<<endl<<endl;

			cout<<"1. Insert element"<<endl;
			cout<<"2. Remove element"<<endl;
			cout<<"3. Print tree"<<endl;
			cout<<"4. Clear tree"<<endl;
			cout<<"5. Count"<<endl;
			cout<<"6. Main menu"<<endl<<endl;

			cin>>choice;

			switch (choice)
			{
			case 1 :
				if(flag == 1)
				{
					int element;
					cin>>element;
					intTree->Insert(element);
					cout<<"Int::Element was inserted"<<endl<<endl;
				}
				else
				{
					string element;
					cin>>element;
					stringTree->Insert(element);
					cout<<"String::Element was inserted"<<endl<<endl;
				}
				break;
			case 2: 
				if(flag == 1)
				{
					int element;
					cin>>element;
					intTree->Remove(element);
					cout<<"Int::Element was removed"<<endl<<endl;
				}
				else
				{
					string element;
					cin>>element;
					stringTree->Remove(element);
					cout<<"String::Element was removed"<<endl<<endl;
				}
				break;
			case 3:
				if(flag == 1)
				{
					intTree->Print();
					for(BTree<int>::iterator it = intTree->begin(); it != intTree->end(); it++)
						if((*it)->value == 2) 
						{
							intTree->Remove(it);
						}
				}
				else
				{
					stringTree->Print();
				}
				break;
			case 4:
				if(flag == 1)
				{
					intTree->Clear();
					cout<<"Int::Tree is clear"<<endl<<endl;
				}
				else
				{
					stringTree->Clear();
					cout<<"String::Tree is clear"<<endl<<endl;
				}
				break;
			case 5 :
				cout<<"Count : ";
				if(flag == 1)
				{
					cout<<intTree->Size()<<endl;
				}
				else
				{
					cout<<stringTree->Size()<<endl;
				}
				cout<<endl;
				break;
			case 6:
				created = false;
				if(flag == 1)
				{
					delete intTree;
				}
				else
				{
					delete stringTree;
				}
				flag = -1;
				break;
			default:
				break;
			}
		}
	}
	while (choice != 7);

	return 0;
}

