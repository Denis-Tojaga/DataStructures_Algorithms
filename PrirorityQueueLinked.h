#pragma once
#include "QueueBase.h";
#include "NodeBase.h";

template<class T>
class PrirorityQueueLinked : public Queue<T>
{
	Node<T>* _first;
	int _counter;
public:
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
	}


};