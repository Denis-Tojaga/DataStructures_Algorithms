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

	cout << "\n\n*** BFS PreOrder Traversal (recursion,linked list) *** \n";
	BSTraverse<int>::PreOrder_Recursion(tree)->Print();
	cout << "\n\n*** BFS PreOrder Traversal (iterative,stack) *** \n";
	BSTraverse<int>::PreOrder_Recursion(tree)->Print();



	cout << "\n\n*** BFS PostOrder Traversal (recursion,linked list) *** \n";
	BSTraverse<int>::PostOrder_Recursion(tree)->Print();
	cout << "\n\n*** BFS PostOrder Traversal (iterative,stack) *** \n";
	BSTraverse<int>::PostOrder_Iterative(tree)->Print();



	cout << "\n\n*** BFS InOrder Traversal (recursion,linked list) *** \n";
	BSTraverse<int>::InOrder_Recursion(tree)->Print();
	cout << "\n\n*** BFS InOrder Traversal (iterative,stack) *** \n";
	BSTraverse<int>::InOrder_Iterative(tree)->Print();



	cout << "\n\n*** DFS Level By Level Traversal (iterative,queue) *** \n";
	BSTraverse<int>::LevelByLevel_iterative(tree)->Print();

	cout << "\n\nSearch for node : \n";
	int value;
	cin >> value;
	BSNode<int>* node = tree.Search(value);
	if (node != nullptr)
		cout << "\n*** The value is found! ***\n";
	else
		cout << "\nThe value does not exist! :(\n";
}