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

	}

public:
	bool IsEmpty() { return _counter == 0; }
	bool IsFull() { return _counter == max_size; }

	void Add_To_Heap(T value)
	{
		if (IsFull())
			ExpandHeap();
		_counter++;
		_heap[_counter] = value;
		BubbleUp(_counter);
	}
	T Remove_From_Heap()
	{
		if (IsEmpty())
			ShowException();
		T deletedValue = _heap[1];
		_heap[1] = _heap[_counter - 1];

		_counter--;


	}


};