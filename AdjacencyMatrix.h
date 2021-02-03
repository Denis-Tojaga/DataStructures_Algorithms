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

	void LoadExistingMatrix(string fileName)
	{
		ifstream fin(fileName);
		for (int i = 0; i < _nodeCounter; i++)
			for (int j = 0; j < _nodeCounter; j++)
			{
				T value;//Create place for value
				fin >> value;//Read value from the given file 
				matrix[i][j] = value;//Place value from the file on the right position in matrix
			}
		fin.close();//after reading close the file
	}


	T& operator()(int a, int b)
	{
		return matrix[a][b];
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