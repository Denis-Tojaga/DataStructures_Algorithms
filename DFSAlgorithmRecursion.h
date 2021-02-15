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
	List<int>* _start()
	{
		Recursion(_startValue);
		return _visitedNodes;
	}
	void Recursion(int startValue)
	{
		_visitedNodes->Add_On_End(startValue);
		for (int i = 0; i < _matrix->GetCounter(); i++)
			if (_matrix->isNeigbour(startValue, i) && !_visitedNodes->Search_By_Key(i))
				Recursion(i);
	}

public:
	static List<int>* start(AdjacencyMatrix* matrix, int startValue)
	{
		return DFSAlgorithmRecursion(matrix, startValue)._start();
	}


};