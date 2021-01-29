#pragma once
#include<iostream>
using namespace std;


void Merge(int array[],int left,int middle,int right)
{

}


void MergeSort(int array[],int left,int right)
{
	if (left >= right)
		return;

	int middle = (left + right - 1) / 2;
	MergeSort(array, left, middle);
	MergeSort(array, middle + 1, right);
	Merge(array, left, middle, right);
}


void MergeAlgorithm()
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