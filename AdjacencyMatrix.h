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
public:
	const int _size;

	AdjacencyMatrix(int size) : _size(size)
	{
		matrix = new T[size];
		for (int i = 0; i < size; i++)
		{
			matrix[i] = new T[size];
			for (int j = 0; j < size; j++)
				matrix[i][j] = 0;
		}
	}

	void LoadExistingMatrix(string fileName)
	{
		ifstream fin(fileName);
		for (int i = 0; i < _size; i++)
			for (int j = 0; j < _size; j++)
			{
				T value;//Create place for value
				fin >> value;//Read value from the given file 
				matrix[i][j] = value;//Place value from the file on the right position in matrix
			}
		fin.close();//after reading close the file
	}

};