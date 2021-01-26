#pragma once
#include<iostream>
using namespace std;


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







}