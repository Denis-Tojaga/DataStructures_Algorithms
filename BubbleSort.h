#pragma once
#include<iostream>
using namespace std;


void BubbleSort()
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



	//---------------SORTING-----------------------
	bool pass = true;
	int numberOfPasses = 0, numberOfSwaps = 0, j = 0;
	while (pass)
	{
		j++;
		numberOfPasses++;
		pass = false;
		for (int i = 0; i < size - j; i++)
			if (_array[i] > _array[i + 1])
			{
				int tempValue = _array[i];
				_array[i] = _array[i + 1];
				_array[i + 1] = tempValue;
				pass = true;
				numberOfSwaps++;
			}
	}

	cout << "\n\n\n *** BUBBLE SORT ALGORITHM *** \n\n";
	for (int i = 0; i < size; i++)
		cout << _array[i] << " | ";

	cout << "\n\n";
	cout << "Number of passes for this array -> " << numberOfPasses << endl;
	cout << "Number of swaps for this array -> " << numberOfSwaps << endl;
	//---------------------------------------------
}