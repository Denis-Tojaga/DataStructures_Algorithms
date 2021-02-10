#pragma once
#include "BinarySearchTree.h";
#include "LinkedList.h";
#include "StackLinked.h";



template<class Key>
class BSTraverse
{

#pragma region Recursion Traversing

	//PostOrder traversing (left child, right child, value comes last)
	static void Recursion_PostOrder(BSNode<Key>* node, List<Key>* listOfNodes)
	{
		if (node != nullptr)
		{
			Recursion_PostOrder(node->leftChild, listOfNodes);
			Recursion_PostOrder(node->rightChild, listOfNodes);
			listOfNodes->Add_On_End(node->value);
		}
	}

	//InOrder traversing(left child,value,right child comes last)
	static void Recursion_InOrder(BSNode<Key>* node, List<Key>* listOfNodes)
	{
		if (node != nullptr)
		{
			Recursion_InOrder(node->leftChild, listOfNodes);
			listOfNodes->Add_On_End(node->value);
			Recursion_InOrder(node->rightChild, listOfNodes);
		}
	}

	//PreOrder traversing(value comes first,left child, right child)
	static void Recursion_PreOrder(BSNode<Key>* node, List<Key>* listOfNodes)
	{
		if (node != nullptr)
		{
			listOfNodes->Add_On_End(node->value);
			Recursion_PreOrder(node->leftChild, listOfNodes);
			Recursion_PreOrder(node->rightChild, listOfNodes);
		}
	}

#pragma endregion


public:

#pragma region Recursion Traverse

	static List<Key>* PostOrder_Recursion(BinarySearchTree<Key>& tree)
	{
		List<Key>* list = new List<Key>;
		Recursion_PostOrder(tree._root, list);
		return list;
	}
	static List<Key>* PreOrder_Recursion(BinarySearchTree<Key>& tree)
	{
		List<Key>* list = new List<Key>;
		Recursion_PreOrder(tree._root, list);
		return list;
	}
	static List<Key>* InOrder_Recursion(BinarySearchTree<Key>& tree)
	{
		List<Key>* list = new List<Key>;
		Recursion_InOrder(tree._root, list);
		return list;
	}

#pragma endregion



	//Three itertive methods


	//level by level iterative


};