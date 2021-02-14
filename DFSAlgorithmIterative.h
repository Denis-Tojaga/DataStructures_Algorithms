#pragma once
#include<iostream>
#include "StackArray.h";
#include "StackLinked.h";
#include "ListArray.h";
#include "LinkedList.h";
#include "AdjacencyMatrix.h";
using namespace std;



class DFSAlgorithmIterative
{
	int startValue;
	AdjacencyMatrix* _matrix;

	DFSAlgorithmIterative(AdjacencyMatrix* matrix, int start)
	{
		this->_matrix = matrix;
		this->startValue = start;
		//private constructor does not allow instatiating the object of this class 
	}


	List<int>* _start()
	{
		List<int>* visitedNodes = new ListArray<int>(_matrix->GetCounter());

		StackLinked<int> stack;

		stack.Add_To_Stack(startValue);

		while (!stack.IsEmpty())
		{
			int removedValue = stack.Remove_From_Stack();
			if (!visitedNodes->Search_By_Key(removedValue))
			{
				visitedNodes->Add_On_End(removedValue);

				for (int i = _matrix->GetCounter() - 1; i >= 0; i--)
				{
					if (_matrix->isNeigbour(removedValue, i))
					{
						if (!visitedNodes->Search_By_Key(i))
							stack.Add_To_Stack(i);
					}
				}
			}
		}


		return visitedNodes;

	}
public:


};