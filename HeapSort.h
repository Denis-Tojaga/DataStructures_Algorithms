#pragma once
#include <iostream>
using namespace std;


//Reconstruction of an array from the top to bottom
void BubbleDown(int array[], int size,int index)
{
	int largest = index; //initializing the root as largest;
	int leftChild = index * 2 +1;//formula for leftChild
	int rightChild = index * 2 + 2;//formula for rightChild
	bool isRightChild = false;

	//if this is valid that means that element at that index has right child
	if (index * 2 + 2 < size)
		isRightChild = true;

	//if left child is bigger than it's parent
	if (leftChild < size && array[leftChild] > array[largest])
		largest = leftChild;

	//if right child is existing and it's bigger than it's parent
	if (array[rightChild] > array[largest] && isRightChild)
		largest = rightChild;


	//at the end if those are two different locations we swap those elements
	if (largest != index)
	{
		swap( array[index],array[largest]);
		//recursive call 
		BubbleDown(array,size,largest);
	}
}


void HeapSort()
{
	//---------Creation of the array -----------------
	int size = 10, _array[10];
	//Generates 10 random numbers and adds them to array;
	for (int i = 0; i < 10; i++)
		_array[i] = rand() % 100 + 1;

	cout << "\n *** Unsorted array *** \n\n";
	for (int i = 0; i < 10; i++)
		cout << _array[i] << " | ";
	cout << "\n\n";
	//-------------------------------------------

	//Build Heap (rearrange array)
	for (int i = size/2 - 1; i >= 0; i--)
		BubbleDown(_array, size, i);


	//One by one extract an element from heap
	int helperSize = size;
	for (int i = size - 1; i >=0; i--)
	{
		int tempValue = _array[0];
		_array[0] = _array[i];
		helperSize--;

		//after removing the root, and placing the last element on that position we need to reconstruct tree 
		BubbleDown(_array, helperSize, 0);
	}


	cout << "\n\n\n *** HEAP SORT ALGORITHM *** \n\n";
	for (int i = 0; i < size; i++)
		cout << _array[i] << " | ";

	cout << "\n\n";
}