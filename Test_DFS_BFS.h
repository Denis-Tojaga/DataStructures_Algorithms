#pragma once
#include<iostream>
#include "BFSAlgorithmIterative.h";
#include "DFSAlgorithmIterative.h";
#include "DFSAlgorithmRecursion.h";
using namespace std;



void Test_BFS_DFS()
{
	AdjacencyMatrix* matrix = new AdjacencyMatrix(9);

	matrix->LoadFromFile("Matrica9.txt");
	cout << "\n*** Loaded matrix is *** \n\n";
	matrix->printMatrix();

	cout << "\n DFS (recursion) \n";
	DFSAlgorithmRecursion::start(matrix, 0)->Print();

	cout << "\n DFS (iterative) \n";
	DFSAlgorithmIterative::start(matrix, 0)->Print();


	cout << "\n BFS (iterative) \n";
	BFSAlgorithmIterative::start(matrix, 0)->Print();

	cout << endl;
	system("pause");
}