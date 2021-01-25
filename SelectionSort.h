#pragma once
#include<iostream>
using namespace std;



void SelectionSort()
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



	int numberOfPasses = 0, numberOfSwaps = 0, minIndex = 0;
	for (int i = 0; i < size-1; i++)
	{
		minIndex = i;
		for (int j = i + 1; j < size; j++)
		{
			if (_array[j] < _array[minIndex])
				minIndex = j;
			numberOfPasses++;
		}


		if (minIndex != i)
		{
			int tempValue = _array[i];
			_array[i] = _array[minIndex];
			_array[minIndex] = tempValue;
			numberOfSwaps++;
		}
	}




	cout << "\n\n\n *** SELECTION SORT ALGORITHM *** \n\n";
	for (int i = 0; i < size; i++)
		cout << _array[i] << " | ";

	cout << "\n\n";
	cout << "Number of passes for this array -> " << numberOfPasses << endl;
	cout << "Number of swaps for this array -> " << numberOfSwaps << endl;
}