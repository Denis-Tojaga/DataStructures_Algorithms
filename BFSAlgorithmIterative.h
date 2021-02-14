#pragma once

#include<iostream>
#include "QueueLinked.h";
#include "QueueArray.h";
#include "ListArray.h";
#include "LinkedList.h";
#include "AdjacencyMatrix.h";

using namespace std;


class BFSAlgorithmIterative
{
	int startNode;
	AdjacencyMatrix* _matrix;

	BFSAlgorithmIterative(AdjacencyMatrix* matrix,int start)
	{
		this->_matrix = matrix;
		this->startNode = start;
		//private constructor does not allow instantiating an object of this class
	}

	List<int>* _start()
	{
		List<int>* visitedNodes = new ListArray<int>(_matrix->GetCounter());

		QueueArray<int> queue;

		//adding first node to queue

		queue.Add_To_Queue(startNode);
		while (!queue.IsEmpty())
		{
			//remove the node from the queue
			int removedValue = queue.Remove_From_Queue();

			//if that node is not in list of visited nodes
			if (!visitedNodes->Search_By_Key(removedValue))
			{
				//we add it in that list
				visitedNodes->Add_On_End(removedValue);

				//we go through all values 
				for (int i = 0; i < _matrix->GetCounter(); i++)
				{
					//if that removedValue has any neigbours 
					if (_matrix->isNeigbour(removedValue, i))
					{
						//we check if that neigbour is already in list of visitedNodes, if not we add it to queue
						if (!visitedNodes->Search_By_Key(i))
							queue.Add_To_Queue(i);
					}
				}

			}
		}

		return visitedNodes;
	}

public:

	static List<int>* start(AdjacencyMatrix* matrix, int startValue = 0)
	{
		return BFSAlgorithmIterative(matrix, startValue)._start();
	}

};
