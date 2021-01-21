#pragma once
#include<iostream>
using namespace std;


template<class T>
class PriorityQueue
{
public:
	virtual void Add_On_Heap(T value) = 0;
	virtual T Remove_From_Heap() = 0;
	virtual bool IsEmpty() = 0;
	virtual bool IsFull() = 0;
	virtual int GetCounter() = 0;
	virtual void Print() = 0;
};