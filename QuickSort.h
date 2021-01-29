#pragma once
#include<iostream>
using namespace std;



int Partition(int array[],const int low,const int high)
{
	int pivotElement = array[low];
	int i = low, j = high;
	while (i < j)
	{
		do
		{
			i++;
		} while (array[i]<=pivotElement);

		do
		{
			j--;
		} while (array[j]>pivotElement);

		if (i < j)
		{
			int tempValue = array[i];
			array[i]= 
		}
	}

}


void Quick(int array[],const int low,const int high)
{
	int locationOfPartition;
	//makes sure that there are minimum 2 elements in the array
	if (low < high)
	{
		locationOfPartition = Partition(array, low, high);
		Quick(array, low, locationOfPartition);//recursive call for left side
		Quick(array, locationOfPartition + 1, high);//recursive call for right side
	}
}


void QuickSort()
{
	//---------Creation of the array -----------------
	int _array[10], size = 10;
	//Generates 10 random numbers and adds them to array;
	for (int i = 0; i < 10; i++)
		_array[i] = rand() % 100 + 1;

	cout << "\n *** Unsorted array *** \n\n";
	for (int i = 0; i < 10; i++)
		cout << _array[i] << " | ";
	cout << "\n\n";
	//-------------------------------------------


	






}