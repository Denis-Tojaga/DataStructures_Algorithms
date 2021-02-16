#pragma once
#include<iostream>
#include"ListArray.h";
#include "Edge.h";
#include "AdjacencyMatrix.h";

using namespace std;


class DijkstraAlgorithm
{
	AdjacencyMatrix* _matrix;
	int* _distance;
	int* _previous;
	bool* _visited;

	int _startValue;
	int _endValue;
	
	DijkstraAlgorithm(AdjacencyMatrix* matrix,int start,int end)
	{
		_matrix = matrix;

		_distance = new int[matrix->GetCounter()];
		_previous = new int[matrix->GetCounter()];
		_visited = new bool[matrix->GetCounter()];

		_startValue = start;
		_endValue = end;
		//private constructor does not allow instatiating an object of this class 
	}



	int minNonVisitedNode()
	{
		int minDistance = INT_MAX;
		int minValue = -1;
		for (int i = 0; i < _matrix->GetCounter(); i++)
			if (!_visited[i] && _distance[i] < minDistance)
			{
				minValue = i;
				minDistance = _distance[i];
			}
		return minValue;
	}


	ListArray<Edge<int>*>* _start()
	{
		cout << "Start value -> " << _startValue << " ----- end value -> " << _endValue << endl;

		ListArray<Edge<int>*>* result = new ListArray<Edge<int>*>;

		//set all distances to infinity and all nodes are not visited
		for (int i = 0; i < _matrix->GetCounter(); i++)
		{
			_distance[i] = INT_MAX;
			_visited[i] = false;
		}


		_distance[_startValue] = 0;
		//--------------------------------------




		for (int i = 0; i < _matrix->GetCounter(); i++)
		{
			//first step is to take smallest non visted node
			int currentValue = minNonVisitedNode();
			_visited[currentValue] = true;
			int distance = _distance[currentValue];

			//we need to check all his neigbours
			for (int neigbour = 0; neigbour < _matrix->GetCounter(); neigbour++)
			{
				//if they are neigbours we go further
				if (_matrix->isNeigbour(currentValue, neigbour))
				{
					int weight = _matrix->GetEdgeWeight(currentValue, neigbour);
					int sumDistance = distance + weight;


					//sum the distance and weight of that edge
					//if that is smaller than default distance to that node we change it
					if (sumDistance < _distance[neigbour])
					{
						_distance[neigbour] = sumDistance;
						_previous[neigbour] = currentValue;
					}

				}
			}
		}
		//-----------------------------------------
		
	}


};
