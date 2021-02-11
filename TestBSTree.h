#pragma once
#include<iostream>
#include "BinarySearchTree.h";
#include "BSTraverse.h";
using namespace std;



void TestBSTree()
{
	BinarySearchTree<int> tree;


	for (int i = 0; i < 10; i++)
	{
		int randomNumber = rand() % 100 + 1;
		tree.Add(randomNumber);
		cout << "Number -> " << randomNumber << " is added to the tree!\n";
	}


	cout << "\n\n*** BFS PreOrder Traversal (recursion) *** \n";
	BSTraverse<int>::PreOrder_Recursion(tree)->Print();

}