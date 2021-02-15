#pragma once
#include "ListArray.h";
#include "AdjacencyMatrix.h";
using namespace std;



class DFSAlgorithmRecursion
{
	int _startValue;
	AdjacencyMatrix* _matrix;
	List<int>* _visitedNodes;

	DFSAlgorithmRecursion(AdjacencyMatrix* matrix,int startValue)
	{
		_matrix = matrix;
		_startValue = startValue;
		_visitedNodes = new ListArray<int>;
		//private constructor does not allow instatiating an object of this class 
	}









public:

};