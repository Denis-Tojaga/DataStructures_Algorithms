#pragma once
#include<iostream>
#include "BSNode.h";
using namespace std;



template<class Key>
class BinarySearchTree
{
	//Dealocates the whole tree
	void Recursion_DealocateTree(BSNode<Key>& node)
	{
		if (node != nullptr)
		{
			Recursion_DealocateTree(node->leftChild);
			Recursion_DealocateTree(node->rightChild);
			delete node;
			node = nullptr;
		}
	}







};
