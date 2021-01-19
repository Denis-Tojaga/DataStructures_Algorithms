#pragma once


template<class T>
class List
{
public:
	virtual void Add_On_Start(T value) = 0;
	virtual void Add_On_End(T value) = 0;
	virtual T Remove_From_Start() = 0;
	virtual T Remove_From_End() = 0;
	virtual bool IsEmpty() = 0;
	virtual bool IsFull() = 0;
	virtual void Print() = 0;
	virtual T operator[](int index) = 0;
};