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

	//Adds a new node to a tree with recursion
	bool Recursion_AddNode(BSNode<Key>*& node, Key value)
	{
		if (node == nullptr)
		{
			node = new BSNode<Key>(value);
			return true;
		}

		if (IsEqual(node->value, value))
			return false;

		if (IsLarger(node->value, value))
			return Recursion_AddNode(node->leftChild, value);
		else
			return Recursion_AddNode(node->rightChild, value);
	}

public:
	BSNode<Key>* _root;
	BinarySearchTree() : _root(nullptr) {}

	bool Add(Key value)
	{
		if (_root == nullptr)
			_root = new BSNode<Key>(value);

		return Recursion_AddNode(_root, value);
	}

	void Dealocate()
	{
		Recursion_DealocateTree(_root);
	}

	//Searches for the given Key value in the tree
	BSNode<Key>* Search(Key value)
	{
		return Recursion_SearchFor(_root, value);
	}

	bool Contains(Key value)
	{
		//Checks if tree contains the given value
		return Search(value) != nullptr;
	}
};
