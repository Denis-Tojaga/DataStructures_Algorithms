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

	int _counter = size - 1;

	for (int i = size - 1; i >= 0; i--)
	{
		//we grab the original queue on specific location (from last to first) from "Queues" array 
		PrirorityQueueLinked<int>& remover = Queues[i];

		while (!remover.IsEmpty())
		{
			//we remove the biggest value from that specific priorityQueue
			int removedValue = remover.Remove_From_Queue();

			//after removing it, we put it in main array on the last location as sorted element
			_array[_counter] = removedValue;
			_counter--;
		}
	}


	cout << "\n\n\n *** BUCKET SORT ALGORITHM *** \n\n";
	for (int i = 0; i < size; i++)
		cout << _array[i] << " | ";

	cout << "\n\n";
}