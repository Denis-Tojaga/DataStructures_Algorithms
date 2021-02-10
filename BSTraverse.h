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

#pragma region Iterative Traversing

	static List<Key>* PreOrder_Iterative(BinarySearchTree<Key>& tree)
	{
		List<Key>* list = new List<Key>;
		StackLinked<BSNode<Key>*> stack;

		stack.Add_To_Stack(tree._root);

		while (!stack.IsEmpty())
		{
			//remove the node from the stack 
			BSNode<Key>* removedNode = stack.Remove_From_Stack();

			//add it to the list of visited nodes
			list->Add_On_End(removedNode);

			//if node had left or right child we add that to stack and repeat procedure
			if (removedNode->rightChild != nullptr)
				stack.Add_To_Stack(removedNode->rightChild);
			
			if (removedNode->leftChild != nullptr)
				stack.Add_To_Stack(removedNode->leftChild);
		}

		return list;
	}
	static List<Key>* PostOrder_Iterative(BinarySearchTree& tree)
	{
		List<Key>* list = new List<Key>; //list of visited nodes
		Stack<Key>* result = new StackLinked<Key>;//result stack for all visited nodes

		StackLinked<BSNode<Key>*> stack;

		stack.Add_To_Stack(tree._root);

		while (!stack.IsEmpty())
		{
			BSNode<Key>* removedNode = stack.Remove_From_Stack();
			if (removedNode != nullptr)
			{
				result->Add_To_Stack(removedNode->value);
				stack.Add_To_Stack(removedNode->leftChild);
				stack.Add_To_Stack(removedNode->rightChild);
			}
		}


		//we empty the result stack and add those elements to the list 
		while (!result->IsEmpty())
			list->Add_On_End(result->Remove_From_Stack());

		return list;
	}
	static List<Key>* InOrder_Iterative(BinarySearchTree& tree)
	{

	}



#pragma endregion


	//Three itertive methods


	//level by level iterative


};