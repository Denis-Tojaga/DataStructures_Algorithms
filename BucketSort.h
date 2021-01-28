#pragma once
#include<iostream>
#include "PrirorityQueueLinked.h";
using namespace std;




int MaxValue(int arr[], int size)
{
	int maxValue = INT_MIN;
	for (int i = 0; i < size; i++)
		if (arr[i] > maxValue)
			maxValue = arr[i];
	return maxValue;
}



void BucketSort()
{
	//---------Creation of the array -----------------
	int _array[10], size = 10;
	//Generates 10 random numbers and adds them to array;
	for (int i = 0; i < 10; i++)
		_array[i] = rand() % 100 + 1;

	cout << "\n *** Unsorted array *** \n\n";
	for (int i = 0; i < 10; i++)
		cout << _array[i] << " | ";
	//-------------------------------------------


	PrirorityQueueLinked<int>* Queues = new PrirorityQueueLinked<int>[size];

	int maxValue = MaxValue(_array, size);
	for (int i = 0; i < size; i++)
	{
		int location = (_array[i] * size) / (maxValue + 1);
		Queues[location].Add_To_Queue(_array[i]);
	}



	int _counter = 


}