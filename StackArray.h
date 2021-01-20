#pragma once
#include "StackBase.h";



template<class T>
class StackArray : public Stack<T>
{
	int max_size = 10;
	T* _stack = new T[max_size];
	int _counter = 0;

	void ExpandStack()
	{
		T* tempStack = new T[max_size * 2];
		for (int i = 0; i < _counter; i++)
			tempStack[i] = _stack[i];
		delete[] _stack;
		_stack = tempStack;
		max_size *= 2;
		cout << "Stack is expanded, its value now is -> " << max_size << " \n";
	}
	void ShowException()
	{
		throw exception("The stack is empty, you cannot remove elements!\n");
	}
public:
	bool IsFull() { return _counter == max_size; }
	bool IsEmpty() { return _counter == 0; }
	void Add_On_Stack(T value)
	{
		if (IsFull())
			ExpandStack();
		_stack[_counter] = value;
		_counter++;
		cout << "Element -> | " << _stack[_counter - 1] << " | added on stack\n";
	}









};