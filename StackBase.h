#pragma once
#include<iostream>
using namespace std;


template<class T>
class Stack
{
public:
	virtual void Add_To_Stack(T value) = 0;
	virtual T Remove_From_Stack() = 0;
	virtual bool IsEmpty() = 0;
	virtual bool IsFull() = 0;
	virtual void Print() = 0;
};