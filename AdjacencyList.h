#pragma once
#include<iostream>
#include<sstream>
#include "Edge.h";
#include "ListBase.h";
#include "ListArray.h";
using namespace std;

template<class T>
class AdjacencyList
{
	ListArray<Edge<T>> matrixEdges;
public:
	void AddEdge(const Edge<T>& edge)
	{
		matrixEdges.Add_On_End(edge);
	}
	void AddEdge(const T& start, const T& end, int weight = 0)
	{
		matrixEdges.Add_On_End(Edge<T>(start, end, weight));
	}

	//Removes the specified edge 
	void RemoveByKey(const Edge<T>& edge)
	{

		if (matrixEdges.Search_By_Key(edge))
			matrixEdges.Remove_By_Key(edge);
		else
			cout << "\nEdge not found!\n";
	}

	//Removes the edge on the specific index 
	Edge<T> RemoveByIndex(int index)
	{
		return matrixEdges.Remove_By_Index(index);
	}


	Edge<T>& operator[](int index)
	{
		if (index<0 || index>matrixEdges.GetCounter())
			throw exception("Index input is not valid!\n");
		return matrixEdges[index];
	}

	ListArray<Edge<T>>& GetEdges() { return matrixEdges; }
	string toString()const {
		stringstream ss;
		for (int i = 0; i < matrixEdges._counter; i++)
			ss << matrixEdges[i] << endl;
		return ss.str();
	}
	friend ostream& operator<<(ostream& COUT, const AdjacencyList& obj)
	{
		COUT << obj.toString();
		return COUT;
	}
};