#pragma once
#include<iostream>
using namespace std;


void BubbleSort(int _array[], int size)
{
	bool pass = true;
	int numberOfPasses = 0, numberOfSwaps = 0;
	while (pass)
	{
		numberOfPasses++;
		pass = false;
		int j = 0;
		for (int i = 0; i < size - j; i++)
		{
			j = i;
			if (_array[i] > _array[i + 1])
			{
				int tempValue = _array[i];
				_array[i] = _array[i + 1];
				_array[i + 1] = tempValue;
				pass = true;
				numberOfSwaps++;
			}
		}
	}

	cout << "\n\n\n *** BUBBLE SORT ALGORITHM *** \n\n";
	for

}