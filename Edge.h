#pragma once
#include<iostream>
using namespace std;

class Edge
{
	int _startNode;
	int _endNode;
	int weight;
public:
	Edge() : weight(0) {}
	Edge(const int& start, const int& end, int weight=0)
	{
		_startNode = start;
		_endNode = end;
		this->weight = weight;
	}
	int& GetStartNode()
	{
		return _startNode;
	}
	int& GetEndNode()
	{
		return _endNode;
	}
	int GetWeight() { return weight; }
	friend bool operator>(Edge& left, Edge& right)
	{
		return left.GetWeight() < right.GetWeight();
	}
	friend bool operator == (Edge& left, Edge& right)
	{
		return left.GetWeight() == right.GetWeight();
	}
	friend ostream& operator<<(ostream& COUT, Edge& edge)
	{
		COUT << "Edge -> ( " << edge.GetStartNode() << "," << edge.GetEndNode() << " )" << endl;
		return COUT;
	}
};