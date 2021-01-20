#pragma once
#include<iostream>
using namespace std;


template<class T>
class Stack
{
	virtual void AddToStack(T value) = 0;
	virtual T RemoveFromStack() = 0;
	virtual void IsEmpty() = 0;
	virtual void IsFull() = 0;
	virtual void Print() = 0;
};