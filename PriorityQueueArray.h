#pragma once
#include "QueueBase.h";


template<class T>
class PriorityQueueArray : public Queue<T>
{
	int max_size = 10;
	int _counter = 0;
	T* _priorityQueue = new T[max_size];
	void ShowException() { throw exception("Not able to remove elements,priority queue is empty!\n"); }
	void ExpandQueue()
	{
		T* tempQueue = new T[max_size * 2];
		for (int i = 0; i < _counter; i++)
			tempQueue[i] = _priorityQueue[i];
		delete[] _priorityQueue;
		_priorityQueue = tempQueue;
		max_size *= 2;
		cout << "\nPriority queue max size is -> " << max_size << " now.\n";
	}
public:
	int GetCounter() { return _counter; }
	bool IsFull() { return _counter == max_size; }
	bool IsEmpty() { return _counter == 0; }

	void Add_To_Queue(T value)
	{
		if (IsFull())
			ExpandQueue();

		_priorityQueue[_counter] = value;
		_counter++;
		cout << "\nElement -> | " << _priorityQueue[_counter - 1] << " | is added to priority queue.";
	}
	T Remove_From_Queue()
	{
		if (IsEmpty())
			ShowException();

		T maxValue = INT_MIN;
		int maxIndex = 0;

		for (int i = 0; i < _counter; i++)
			if (_priorityQueue[i] > maxValue)
			{
				maxValue = _priorityQueue[i];
				maxIndex = i;
			}

		_counter--;
		_priorityQueue[maxIndex] = _priorityQueue[_counter];
		cout << "\nElement -> | " << maxValue << " | is removed from priority queue.";
		return maxValue;
	}

	T operator[](int index)
	{
		if (index<0 || index>_counter)
			throw exception("Index input is not valid!\n");
		return _priorityQueue[index];
	}
	void Print()
	{
		if (IsEmpty())
			cout << "\n\n***The queue is empty!***\n\n";
		else
		{
			cout << "\n\n\n*** Elements of QueueArray ***\n\n";
			for (int i = 0; i < _counter; i++)
				cout << _priorityQueue[i] << " | ";
			cout << "\n\n";
		}
	}
};
