#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include "AdjacencyList.h";
#include "LinkedList.h";
#include "ListArray.h";
#include"Edge.h";



using namespace std;


class AdjacencyMatrix
{
	int** matrix;
	int _nodeCounter;
	void copy(const AdjacencyMatrix& obj)
	{
		_nodeCounter = obj._nodeCounter;

		//alocate
		matrix = new int* [_nodeCounter];
		for (int i = 0; i < _nodeCounter; i++)
		{
			matrix[i] = new int[_nodeCounter];
			for (int j = 0; j < _nodeCounter; j++)
				matrix[i][j] = 0;
		}

		//copy values
		for (int i = 0; i < _nodeCounter; i++)
			for (int j = 0; j < _nodeCounter; j++)
				matrix[i][j] = obj.matrix[i][j];
	}

public:
	 int GetCounter() { return _nodeCounter; }

	AdjacencyMatrix(int nodeCount=0) : _nodeCounter(nodeCount)
	{
		if (nodeCount > 0)
		{
			matrix = new int* [nodeCount];
			for (int i = 0; i < nodeCount; i++)
			{
				matrix[i] = new int[nodeCount];
				for (int j = 0; j < nodeCount; j++)
					matrix[i][j] = 0;
			}
		}
		else
			matrix = nullptr;
	}
	AdjacencyMatrix(const AdjacencyMatrix& obj)
	{
		copy(obj);
	}
	AdjacencyMatrix& operator=(const AdjacencyMatrix& obj)
	{
		if (this != &obj)
		{
			Dealocate();
			copy(obj);
		}
		return *this;
	}

	void LoadFromFile(string fileName)
	{
		ifstream inFile(fileName,ios::in);

		for (int i = 0; i < _nodeCounter; i++)
			for (int j = 0; j < _nodeCounter; j++)
			{
				int value;
				inFile >> value;
				matrix[i][j] = value;
			}

		inFile.close();
	}

	int& operator()(int a, int b)
	{
		return matrix[a][b];
	}


	void AddNode()
	{
		int** tempMatrix = matrix;
		_nodeCounter++;
		//alocate matrix with size bigger for one
		matrix = new int* [_nodeCounter];
		for (int i = 0; i < _nodeCounter; i++)
		{
			matrix[i] = new int[_nodeCounter];
			for (int j = 0; j < _nodeCounter; j++)
				matrix[i][j] = 0;
		}


		//copy values
		for (int i = 0; i < _nodeCounter-1; i++)
			for (int j = 0; j < _nodeCounter-1; j++)
				matrix[i][j] = tempMatrix[i][j];

		//dealocate helper matrix
		for (int i = 0; i < _nodeCounter-1; i++)
			delete[] tempMatrix[i];
		delete[] tempMatrix;
	}

	void AddEdge(Edge& edge)
	{
		matrix[edge.GetStartNode()][edge.GetEndNode()] = edge.GetWeight();
	}

	int& GetEdgeWeight(int from,int to)
	{
		return matrix[from][to];
	}

	bool isNeigbour(int from, int to)
	{
		return matrix[from][to] > 0;
	}

	int FromNeigbourCounter(int row)
	{
		if (row<0 || row>_nodeCounter)
			throw exception("You've entered the wrong row index!\n");

		//To count neigbours from the certain node, we count by columns

		int sum = 0;
		for (int j = 0; j < _nodeCounter; j++)
			sum += matrix[row][j];
		return sum;
	}
	int ToNeigboursCounter(int column)
	{
		if (column<0 || column>_nodeCounter)
			throw exception("You've entered the wrong column index!\n");
		//To count neigbours to the certain node, we count by rows

		int sum = 0;
		for (int i = 0; i < _nodeCounter; i++)
			sum += matrix[i][column];
		return sum;
	}

	string printMatrix()const
	{
		cout << "*** Adjacency Matrix *** \n\n";
		cout << " Number of nodes -> " << _nodeCounter << endl;
		stringstream ss;

		for (int i = 0; i < _nodeCounter; i++)
			ss << i << " | ";

		ss << endl << string(_nodeCounter * 4 + 3, '-') << endl;

		for (int i = 0; i <_nodeCounter; i++)
		{
			ss << i << " | ";
			for (int j = 0; j < _nodeCounter; j++)
				ss << matrix[i][j] << " | ";
			ss << endl;
		}

		ss << endl;
		return ss.str();
	}
	void Dealocate()
	{
		//Dealocation of an existing matrix
		for (int i = 0; i < _nodeCounter; i++)
			delete[] matrix[i];
		delete[] matrix;
	}
	friend ostream& operator<<(ostream& COUT, const AdjacencyMatrix& obj)
	{
		COUT << obj.printMatrix();
		return COUT;
	}

};