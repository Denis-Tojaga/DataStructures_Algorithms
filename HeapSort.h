#pragma once
#include <iostream>
using namespace std;


//Reconstruction of an array from the top to bottom
void BubbleDown(int array[], int size,int index)
{
	int largest = index; //initializing the root as largest;
	int leftChild = index * 2;
	int rightChild = index * 2 + 1;
	bool isRightChild = false;

	if (index * 2 + 1 <= size)
		isRightChild = true;

	if (array[leftChild] > array[largest])
		largest = leftChild;

	if (array[rightChild] > array[largest])
		largest = rightChild;


}