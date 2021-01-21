#pragma once
#include "QueueBase.h";

template<class T>
class QueueArray : public Queue<T>
{
	int max_size = 50;
	int _start = 0;
	int _end = 0;
	int _counter = 0;
	T* _queue = new T[max_size];
	void ShowException() { throw exception("Not able to remove elements from the queue, it's empty!\n"); }
public:
	int GetCounter() { return _counter; }
	bool IsEmpty() { return _counter == 0; }
	bool IsFull() { return false; }
	void Add_To_Queue(T value)
	{
		_queue[_end] = value;
		cout << "Element added to queue -> | " << _queue[_end] << " | \n";
		_end++;
		_counter++;

		if (_end == max_size)
			_end = 0;
	}
	T Remove_From_Queue()
	{
		if (IsEmpty())
			ShowException();

		T deletedValue = _queue[_start];
		cout << "Element removed from queue -> | " << _queue[_start] << " | \n";
		_start++;
		_counter--;
		if (_start == max_size)
			_start = 0;
		return deletedValue;
	}
	T operator[] (int index)
	{
		if (index > _counter || index < 0)
			throw exception("Not able to find element on that location, please enter valid index!\n");
		return _queue[index];
	}
	void Print()
	{
		if (IsEmpty())
			cout << "\n\n***The queue is empty!***\n\n";
		else
		{
			cout << "\n\n\n*** Elements of QueueArray ***\n\n";
			int helpCounter = 0;
			int helpStart = _start;
			while (helpCounter < _counter)
			{
				cout << _queue[helpStart] << " | ";
				helpCounter++;
				helpStart++;
				if (helpStart == max_size)
					helpStart = 0;
			}

			cout << "\n\n";
		}
	}
};