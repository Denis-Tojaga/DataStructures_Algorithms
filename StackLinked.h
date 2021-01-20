#pragma once
#include "StackBase.h";
#include "NodeBase.h";

template<class T>
class StackLinked : public Stack<T>
{
	Node<T>* _head = nullptr;
	int _counter = 0;
	void ShowException()
	{
		throw exception("Stack is empty, you cannot remove elements!\n");
	}
public:
	bool IsFull() { return false; }
	bool IsEmpty() { return _head == nullptr; }
	void Add_To_Stack(T value)
	{
		//newNode will always be pointing to a node bellow it
		Node<T>* newNode = new Node<T>(value, _head);

		//head pointer will always point to last node in stack
		_head = newNode;
		_counter++;
		cout << "Node added with value -> | " << _head->value << " | \n";
	}
	T Remove_From_Stack()
	{
		if (IsEmpty())
			ShowException();

		//TempNode to point to same element as _head
		Node<T>* tempNode = _head;

		T deletedValue = tempNode->value;
		//_head's nextNode is node bellow him
		_head = _head->_nextNode;
		//Dealocation of that element
		delete tempNode;

		cout << "Node removed with value -> | " << deletedValue << " | \n";

		_counter--;
		return deletedValue;
	}
	void Print()
	{
		cout << "\n\n\n ***Linked STACK elements*** \n";
		Node<T>* tempNode = _head;
		//searching while tempNode actually exists
		while (tempNode != nullptr)
		{
			cout << tempNode->value << " | ";
			tempNode = tempNode->_nextNode;
		}
		cout << "\n\n\n";
	}
};