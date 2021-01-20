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
	void Add_To_Stack(T value)
	{
		if (IsFull())
			ExpandStack();
		_stack[_counter] = value;
		_counter++;
		cout << "Element -> | " << _stack[_counter - 1] << " | is added to stack\n";
	}
	T Remove_From_Stack()
	{
		if (IsEmpty())
			ShowException();
		T deletedValue = _stack[_counter - 1];
		_counter--;
		cout << "Element -> | " << _stack[_counter] << " | is removed from stack\n";
		return deletedValue;
	}
	void Print()
	{
		cout << "\n\n\n";
		for (int i = _counter-1; i > -1; i--)
			cout << _stack[i] << " | ";
		cout << "\n\n\n";
	}
};