#pragma once
#include "HeapBase.h";


template<class T>
class Heap : public PriorityQueue<T>
{
	int max_size = 100;
	int _counter = 0;
	T* _heap = new T[max_size];

	void ShowException() { throw exception("Not able to remove any elements, the HEAP is empty!\n"); }
	void ExpandHeap()
	{
		T* tempHeap = new T[max_size * 2];
		for (int i = 0; i < _counter; i++)
			tempHeap[i] = _heap[i];
		delete[] _heap;
		_heap = tempHeap;
		max_size *= 2;
		cout << "HEAP size is now -> " << max_size << endl;
	}

	void SWAP(int index_1, int index_2)
	{
		T tempValue = _heap[index_1];
		_heap[index_1] = _heap[index_2];
		_heap[index_2] = tempValue;
	}
	void BubbleUp(int location)
	{
		//this means we are already at the top of the heap
		if (location == 1)
			return;

		int root = location / 2;

		if (_heap[location] > _heap[root])
		{
			SWAP(location,root);
			BubbleUp(root);
		}
	}
	void BubbleDown(int location)
	{
		//if the location is greater than number of elements in heap, then we are breaking the method
		if (2 * location > _counter)
			return;

		//location * 2 => calculation of left child
		//location * 2 + 1 => calculation of right child
		int leftChild = location * 2;
		int rightChild = location * 2 + 1;
		bool rightChildExists = false;


		//if right child's location is less or equal to number of elements then it exists
		if (location * 2 + 1 <= _counter)
			rightChildExists = true;

		//In the steps bellow we are trying to find an element which is greater than the current element on the location 1
		//when we find it, we swap those two elements
		int maxIndex = location;


		if (_heap[leftChild] > _heap[maxIndex])
			maxIndex = leftChild;

		if (rightChildExists && _heap[rightChild] > _heap[maxIndex])
			maxIndex = rightChild;

		if (maxIndex != location)
		{
			SWAP(location, maxIndex);
			BubbleDown(maxIndex);
		}
	}

public:
	bool IsEmpty() { return _counter == 0; }
	bool IsFull() { return _counter == max_size; }
	int GetCounter() { return _counter; }
	void Print()
	{
		cout << "\n\n\n*** Elements of QueueArray ***\n\n";
		for (int i = 1; i < _counter; i++)
			cout << _heap[i] << " | ";
		cout << "\n\n";
	}

	void Add_On_Heap(T value)
	{
		if (IsFull())
			ExpandHeap();
		_counter++;
		_heap[_counter] = value;
		cout << "Element -> | " << _heap[_counter] << " | is added on heap\n";
		BubbleUp(_counter);
	}
	T Remove_From_Heap()
	{
		if (IsEmpty())
			ShowException();
		T deletedValue = _heap[1];
		_heap[1] = _heap[_counter];
		_counter--;

		BubbleDown(1);
		cout << "Element -> | " << deletedValue << " | is removed from heap\n";
		return deletedValue;
	}
};