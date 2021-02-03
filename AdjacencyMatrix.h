#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include "AdjacencyList.h";
#include "LinkedList.h";
#include "ListArray.h";



using namespace std;


typedef T;
class AdjacencyMatrix
{
	T** matrix;
	int _nodeCounter;
	void AlocateMatrix()
	{
		matrix = new T[_nodeCounter];
		for (int i = 0; i < _nodeCounter; i++)
		{
			matrix[i] = new T[_nodeCounter];
			for (int j = 0; j < _nodeCounter; j++)
				matrix[i][j] = 0;
		}
	}
	void AlocateMatrix(ifstream& file)
	{
		matrix = new T[_nodeCounter];
		for (int i = 0; i < _nodeCounter; i++)
		{
			matrix[i] = new T[_nodeCounter];
			for (int j = 0; j < _nodeCounter; j++)
				file >> matrix[i][j];
		}
	}
	void copy(const AdjacencyMatrix& obj)
	{
		_nodeCounter = obj._nodeCounter;
		AlocateMatrix();
		for (int i = 0; i < _nodeCounter; i++)
			for (int j = 0; j < _nodeCounter; j++)
				matrix[i][j] = obj.matrix[i][j];
	}

public:
	 int GetCounter() { return _nodeCounter; }

	AdjacencyMatrix(int nodeCount=0) : _nodeCounter(nodeCount)
	{
		if (nodeCount > 0)
			AlocateMatrix();
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
		if (matrix != nullptr)
			Dealocate();

		ifstream inputFile;
		inputFile.open(fileName);
		inputFile >> _nodeCounter;
		AlocateMatrix(inputFile);
		inputFile.close();//after reading close the file
	}
	T& operator()(int a, int b)
	{
		return matrix[a][b];
	}


	void AddNode()
	{
		T** tempMatrix = matrix;
		_nodeCounter++;
		AlocateMatrix();
		for (int i = 0; i < _nodeCounter-1; i++)
			for (int j = 0; j < _nodeCounter-1; j++)
				matrix[i][j] = tempMatrix[i][j];

		for (int i = 0; i < _nodeCounter-1; i++)
			delete[] tempMatrix[i];
		delete[] tempMatrix;
	}


	string printMatrix()const
	{
		cout << "*** Adjacency Matrix *** \n\n";
		cout << " SIZE -> " << _size << endl;
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