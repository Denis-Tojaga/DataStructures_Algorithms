#pragma once
#include<iostream>
#include "Hashing.h";
#include "LinkedList.h";
using namespace std;


template<class T>
class HashingChaining : public Hashing<T>
{
	LinkedList<T>* _array;
	int _numberOfElements;
	int HashFunction(T value)
	{
		return value % _numberOfElements;
	}
public:
	HashingChaining(int numberOfElements = 10)
	{
		_numberOfElements = numberOfElements;
		_array = new LinkedList<T>[_numberOfElements];
	}
	void Add(T value)
	{
		int location = HashFunction(value);
		LinkedList<T>& list = _array[location];
		list.Add_On_Start(value);
	}
	void Remove(T value)
	{
		int location = HashFunction(value);
		LinkedList<T>& list = _array[location];
		T removed = list.Remove_By_Key(value);
		cout << "Element -> " << removed << " removed from HashSet!\n";
	}
	void Print()
	{
		for (int i = 0; i < _numberOfElements; i++)
		{
			cout << "\nList on location -> " << i;
			LinkedList<T>& currentList = _array[i];
			currentList.Print();
		}
	}
};
