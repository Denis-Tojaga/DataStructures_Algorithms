#pragma once
#include<iostream>
using namespace std;

template<class T>
class Queue
{
public:
	virtual bool IsFull() = 0;
	virtual bool IsEmpty() = 0;
	virtual void Add_To_Queue(T value) = 0;
	virtual T Remove_From_Queue() = 0;
	virtual int GetCounter() = 0;
	virtual T operator[](int index) = 0;
	virtual void Print() = 0;
};