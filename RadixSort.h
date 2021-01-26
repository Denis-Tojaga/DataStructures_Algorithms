#pragma once
#include<iostream>
using namespace std;



void RecursiveFunction(int* _array, int size, int exponent)
{
	//Create one array where the all possible digits can show ( from 0 to 9)
	int _counterArray[10] = { 0 };
	//Create one helper array to place element in correct order
	int* helperArray = new int[size];


	///First fase - To count all numbers with last digit in _counterArray
	for (int i = 0; i < size; i++)
	{
		int element = _array[i];
		int lastDigit = (element / exponent) % 10;
		_counterArray[lastDigit]++;
	}


	//Second fase is to add all counters in _counterArray one by one
	for (int i = 1; i < 10; i++)
		_counterArray[i] += _counterArray[i - 1];


	//Third fase is to go from behind and take the element's last digit, go to its location in _counterArray and subtract the number on that location
	//with  -1, after doing that we will get location to place that element in third array (helperArray)
	for (int i = size -  1 ; i >= 0; i--)
	{
		int element = _array[i];
		int lastDigit = (element / exponent) % 10;

		int& helperCounter = _counterArray[lastDigit];
		helperCounter--;
		helperArray[helperCounter] = element;
	}



	//Fourth fase is to move all elements from helperArray to main array(after finishing all this for all digits)
	for (int i = 0; i < size; i++)
		_array[i] = helperArray[i];
}

int GetMaxValue(int* _array, int size)
{
	int maxValue = INT_MIN;
	for (int i = 0; i < size; i++)
		if (_array[i] > maxValue)
			maxValue = _array[i];

	return maxValue;
}

void RadixSort()
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


	int maxValue = GetMaxValue(_array, size);
	int exponent = 1;
	while (maxValue > 0)
	{
		RecursiveFunction(_array, size, exponent);
		int digitNumber = exponent;
		cout << "\n\n\n *** ARRAY SORTED BY "<<digitNumber<<" *** \n\n";
		for (int i = 0; i < size; i++)
			cout << _array[i] << " | ";
		cout << "\n\n";

		exponent = exponent * 10;
		maxValue = maxValue / 10;
	}

	
	cout << "\n\n\n *** RADIX SORT ALGORITHM *** \n\n";
	for (int i = 0; i < size; i++)
		cout << _array[i] << " | ";

	cout << "\n\n";
}