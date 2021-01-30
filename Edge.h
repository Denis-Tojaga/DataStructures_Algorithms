#pragma once
#include<iostream>
using namespace std;

template<class T>
class Edge
{
	T _startNode;
	T _endNode;
	int weight;
public:
	Edge() : weight(0) {}
	Edge(const T& start, const T& end, int weight=0)
	{
		_startNode = start;
		_endNode = end;
		this->weight = weight;
	}
	T& GetStartNode()
	{
		return _startNode;
	}
	T& GetEndNode()
	{
		return _endNode;
	}
	int GetWeight() { return weight; }
	friend bool operator>(Edge<T>& left, Edge<T>& right)
	{
		return left.GetWeight() < right.GetWeight();
	}
	friend bool operator == (Edge<T>& left, Edge<T>& right)
	{
		return left.GetWeight() == right.GetWeight();
	}
	friend ostream& operator<<(ostream& COUT, Edge<T>& edge)
	{
		COUT << "Edge -> ( " << edge.GetStartNode() << "," << edge.GetEndNode() << " )" << endl;
		return COUT;
	}
};