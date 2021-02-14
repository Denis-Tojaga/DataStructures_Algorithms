#pragma once
#include "ListBase.h";
#include<stdlib.h>


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
public:
	ListArray(int max = 10)
	{
		this->max_size = max;
	}

	bool IsFull() { return _counter == max_size; }
	bool IsEmpty() { return _counter == 0; }

	//returns the number of elements 
	int GetCounter() { return _counter; }

	//adds a new element at the beginning of a list
	void Add_On_End(T value)
	{
		if (IsFull())
			ExpandArray();
		_arr[_counter] = value;
		_counter++;
		cout << "Element -> | " << _arr[_counter-1] << " | is added to list.\n";
	}

	//add a new element at the end of a list
	void Add_On_Start(T value)
	{
		if (IsFull())
			ExpandArray();
		for (int i = _counter; i >= 1; i--)
			_arr[i] = _arr[i - 1];

		_arr[0] = value;
		_counter++;
		cout << "Element -> | " << _arr[0] << " | is added to list.\n";
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
		cout << "Element -> | " << deletedValue << " | is deleted from list.\n";
		return deletedValue;
	}

	//removes last element from the beginning of a list
	T Remove_From_End()
	{
		if (IsEmpty())
			ShowException();
		T deletedValue = _arr[_counter - 1];
		_counter--;
		cout << "Element -> | " << deletedValue << " | is deleted from list.\n";
		return deletedValue;
	}

	//returns an element at the specific index
	T operator[] (int index)
	{
		if (index > _counter || index < 0)
			ShowException();
		return _arr[index];
	}

	T Remove_By_Index(int index)
	{
		if (index<0 || index>_counter)
		{
			cout << "Cannot remove element, index is not valid!\n";
			return -1;
		}

		T removedValue = _arr[index];

		for (int i = index; i < _counter - 1; i++)
			_arr[i] = _arr[i + 1];

		_counter--;
		return removedValue;
	}

	T Remove_By_Key(T value)
	{
		int valueIndex = -1;
		for (int i = 0; i < _counter; i++)
			if (_arr[i] == value)
				valueIndex = i;

		if (valueIndex != -1)
			return Remove_By_Index(valueIndex);
		else
			return -1;
	}

	bool Search_By_Key(T value)
	{
		for (int i = 0; i < _counter; i++)
			if (_arr[i] == value)
				return true;
		return false;
	}

	//prints out all elements currently in the list
	void Print()
	{
		if (IsEmpty())
		{
			cout << "The list is empty!\n";
			return;
		}

		cout << "\n\n*** Element of a LIST ARRAY *** \n";

		for (int i = 0; i < GetCounter(); i++)
			cout << _arr[i] << " | ";
		cout << "\n\n\n";
	}
};