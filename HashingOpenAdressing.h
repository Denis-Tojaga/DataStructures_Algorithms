#pragma once
#include <iostream>
#include "Hashing.h";
#include<exception>
using namespace std;


template<class T>
class HashingOpenAdressing : public Hashing<T>
{
	T* _array;
	int numberOfNodes;
	bool* _visited;
	int _counter;

	int HashMethod(T value)
	{
		return value % numberOfNodes;
	}

public:
	HashingOpenAdressing(int numberOfNodes = 10)
	{
		this->numberOfNodes = numberOfNodes;
		_array = new T[numberOfNodes];
		_visited = new bool[numberOfNodes] {false};
		_counter = 0;
	}


	bool IsFull() { return _counter == numberOfNodes; }
	bool IsEmpty() { return _counter == 0; }

	void Add(T value)
	{
		if (IsFull())
			throw exception("Error -> Hashset is full!\n");

		int location = HashMethod(value);

		while (_visited[location])
		{
			location++;
			if (location == numberOfNodes)
				location = 0;
		}

		_array[location] = value;
		_visited[location] = true;
		_counter++;
	}


	void Remove(T value)
	{
		if (IsEmpty())
			throw exception("Error -> Hashset is empty!\n");

		int location = HashMethod(value);
		int helper = 0;
		while (helper != numberOfNodes)
		{
			if (_visited[location])
			{
				if (_array[location] == value)
				{
					_visited[location] = false;
					cout << "Node with value -> " << value << " is removed from hashset!\n";
					_counter--;
					return;
				}
			}
			location++;
			helper++;
			if (location == numberOfNodes)
				location = 0;
		}
	}

	void Print()
	{
		for (int i = 0; i < numberOfNodes; i++)
			if (_visited[i])
				cout << "Location -> " << i << " : " << _array[i] << " \n";
			else
				cout << "Location-> " << i << " : (x)\n";
	}


};