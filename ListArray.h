#pragma once
#include "ListBase.h";


template<class T>
class ListArray : public List<T>
{
	int max_size = 10;
	T* _arr = new T[max_size];
	int _counter = 0;

	void ExpandArray()
	{
		T* tempArr = new T[max_size * 2];
		for (int i = 0; i < _counter; i++)
			tempArr[i] = _arr[i];
		delete[] _arr;
		_arr = tempArr;
		max_size *= 2;
		cout << "The array is expanded, its size is ->  " << max_size << " now.\n";
	}
	void ShowException() { throw std::exception("The list is empty!\n"); }
	bool IsFull() { return _counter == max_size; }
	bool IsEmpty() { return _counter == 0; }
public:
	//returns the number of elements 
	int GetCounter() { return _counter; }
	//adds a new element at the beginning of a list
	void Add_On_End(T value)
	{
		if (IsFull())
			ExpandArray();
		_arr[_counter] = value;
		_counter++;
	}
	//add a new element at the end of a list
	void Add_On_Start(T value)
	{
		if (IsFull())
			ExpandArray();
		for (int i = _counter - 1; i >= 1; i--)
			_arr[i] = _arr[i - 1];

		_arr[0] = value;
		_counter++;
	}
	//removes first element from the beginning of a list
	T Remove_From_Start()
	{
		if (IsEmpty())
			ShowException();
		T deletedValue = _arr[0];
		for (int i = 0; i < _counter - 1; i++)
			_arr[i] = _arr[i + 1];
		_counter--;
		return deletedValue;
	}
	//removes last element from the beginning of a list
	T Remove_From_End()
	{
		if (IsEmpty())
			ShowException();
		T deletedValue = _arr[_counter - 1];
		_counter--;
		return deletedValue;
	}
	//returns an element at the specific index
	T operator[] (int index)
	{
		if (index > _counter || index < 0)
			ShowException();
		return _arr[index];
	}
	//prints out all elements currently in the list
	void Print()
	{
		if (IsEmpty())
		{
			cout << "The list is empty!\n";
			return;
		}

		cout << "*** Element of a LIST ARRAY *** \n";

		for (int i = 0; i < _counter; i++)
			cout << _arr[i] << " | ";
	}
};