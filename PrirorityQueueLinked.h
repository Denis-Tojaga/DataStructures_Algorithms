#pragma once
#include "QueueBase.h";
#include "NodeBase.h";

template<class T>
class PrirorityQueueLinked : public Queue<T>
{
	Node<T>* _first;
	int _counter;
	void ShowException() { throw exception("Not able to remove elements, because the priority queue is empty!\n"); }
public:
	bool IsEmpty() { return _first == nullptr; }
	bool IsFull() { return false; }
	int GetCounter() { return _counter; }
	PrirorityQueueLinked(): _first(nullptr),_counter(0){}

	void Add_To_Queue(T value)
	{
		Node<T>* tempNode = _first;
		Node<T>* helpNode = nullptr;
		while (tempNode != nullptr && tempNode->value > value)
		{
			helpNode = tempNode;
			tempNode = tempNode->_nextNode;
		}

		Node<T>* newNode = new Node<T>(value, tempNode);
		_counter++;
		if (helpNode != nullptr)
			helpNode->_nextNode = newNode;
		else
			_first = newNode;
		cout << "\nElement -> | " << newNode->value << " | is added to priority queue.";
	}
	T Remove_From_Queue()
	{
		if (IsEmpty())
			ShowException();
		Node<T>* tempNode = _first;
		T deletedValue = tempNode->value;
		_first = _first->_nextNode;
		delete tempNode;
		_counter--;
		cout << "\nElement -> | " << deletedValue << " | is removed from priority queue.";
	}

	T operator[](int index)
	{
		if (index<0 || index>_counter)
			throw exception("Value of index input is not valid!\n");
		Node<T>* tempNode = _first;
		for (int i = 0; i < index; i++)
			tempNode = tempNode->_nextNode;
		return tempNode->value;
	}
	void Print()
	{

	}
};