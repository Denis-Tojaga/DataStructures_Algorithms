#pragma once
#include<iostream>
using namespace std;



void InsertionSort()
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


	int numberOfPasses = 0, numberOfSwaps = 0;

	for (int i = 1; i < size; i++)
	{
		int j = i;
		while (j > 0 && _array[j] < _array[j - 1])
		{
			numberOfPasses++;
			numberOfSwaps++;
			int tempValue = _array[j];
			_array[j] = _array[j - 1];
			_array[j - 1] = tempValue;
			j--;
		}
	}


	cout << "\n\n\n *** INSERTION SORT ALGORITHM *** \n\n";
	for (int i = 0; i < size; i++)
		cout << _array[i] << " | ";

	cout << "\n\n";
	cout << "Number of passes for this array -> " << numberOfPasses << endl;
	cout << "Number of swaps for this array -> " << numberOfSwaps << endl;
}