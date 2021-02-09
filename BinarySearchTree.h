#pragma once
#include<iostream>
#include "BSNode.h";
using namespace std;



template<class Key>
class BinarySearchTree
{

	bool IsEqual(Key& firstValue, Key& secondValue) { return firstValue == secondValue; }
	bool IsLarger(Key& firstValue, Key& secondValue){return firstValue > secondValue;}

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


	//Search for the given Key value through the tree
	BSNode<Key>* Recursion_SearchFor(BSNode<Key>* node, Key value)
	{
		if (node == nullptr)
			return nullptr;
		if (IsEqual(node->value, value))
			return node;
		if (IsLarger(node->value, value)) 
			return Recursion_SearchFor(node->leftChild, value);
		else
			return Recursion_SearchFor(node->rightChild, value);
	}








public:







};
