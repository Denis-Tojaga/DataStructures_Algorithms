#pragma once
#include<iostream>
using namespace std;




void Merge(int Temp[], int Element[], const int list1, const int size1, const int list2, const int size2)
{
	int i = list1, j = list2, k = list1;

	while (i < list1 + size1 && j < list2 + size2)
	{
		if (Temp[i] < Temp[j])
			Element[k++] = Temp[i++];
		else
			Element[k++] = Temp[j++];
	}

	while (i < list1 + size1)
		Element[k++] = Temp[i++];

	while (j < list2 + size2)
		Element[k++] = Temp[j++];

	for (k = list1; k < list1 + size1 + size2; k++)
		Temp[k] = Element[k];
}


void MergeSort(int TempArray[], int Array[], const int left, const int size)
{
	//initialize three integers for size of the temporary arrays
	int right, sizeLeft, sizeRight;

	if (size > 1)
	{
		right = left + size / 2;
		sizeLeft = right - left;
		sizeRight = size - sizeLeft;
		MergeSort(TempArray, Array, left, sizeLeft);
		MergeSort(TempArray, Array, right, sizeRight);
		Merge(TempArray, Array, left, sizeLeft, right, sizeRight);
	}
} 


void MergeAlgorithm()
{
	//---------Creation of the array -----------------
	int _array1[20],_array2[20] ,size = 20;

	//Generates 20 random numbers and adds them to array;
	for (int i = 0; i < 20; i++)
		_array1[i] = rand() % 100 + 1;

	for (int i = 0; i < 20; i++)
		_array2[i] = _array1[i];

	cout << "\n *** Unsorted array *** \n\n";
	for (int i = 0; i < 20; i++)
		cout << _array1[i] << " | ";
	cout << "\n\n";
	//-------------------------------------------



	MergeSort(_array2,_array1, 0, size);



	cout << "\n\n\n *** MERGE SORT ALGORITHM *** \n\n";
	for (int i = 0; i < size; i++)
		cout << _array2[i] << " | ";

	cout << "\n\n";
}