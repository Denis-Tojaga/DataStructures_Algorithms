#pragma once
#include<iostream>
#include"DijkstraAlgorithm.h";
using namespace std;


void Test()
{
	AdjacencyMatrix* matrix = new AdjacencyMatrix(10);
	matrix->LoadFromFile("Matrica10_t.txt");

	DijkstraAlgorithm::start(matrix, 4, 0)->Print();
}