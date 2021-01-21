#pragma once
#include "QueueBase.h";
#include "NodeBase.h";

template<class T>
class LinkedQueue : public Queue<T>
{
	//_end always points to the last node
	//_start always points to the first node
	Node<T>* _start;
	Node<T>* _end;
	int _counter;
	void ShowException() { throw exception("Not able to remove any elements, the queue is empty!\n"); }
public:
	LinkedQueue() :_start(nullptr), _end(nullptr), _counter(0) {}
	bool IsFull() { return false; }
	bool IsEmpty() { return _start == nullptr; }


	void Add_To_Queue(T value)
	{
		//newNode will now point to the adress of a last element (because _end is already pointing to a last element)
		Node<T>* newNode = new Node<T>(value, nullptr);
		//if _end has something that it's pointing then that Node has to point to a newNode 
		//because newNode has to be the last one
		//if _end doesn't point to anything that means the queue is empty and _start has to point to newNode
		if (_end != nullptr)
			_end->_nextNode = newNode;
		else
			_start = newNode;

		//after reorganization of the last node, now _end has to point to the last node (newNode) no matter what
		_end = newNode;
		cout << "\nNew node added to Linked Queue with value -> | " << _end->value << " |\n";
		_counter++;
	}
	T Remove_From_Queue()
	{
		if (IsEmpty())
			ShowException();
		Node<T>* tempNode = _start;
		T deletedNode = tempNode->value;
		_start = _start->_nextNode;
		delete tempNode;
		cout << "\nNode removed from Linked Queue with value -> | " << deletedNode << " |\n";
		_counter--;
		return deletedNode;
	}



	void Print()
	{
		if (IsEmpty())
			cout << "\n\n***The queue is empty!***\n\n";
		else
		{
			cout << "\n\n\n*** Elements of QueueArray ***\n\n";
			Node<T>* tempNode = _start;

			//If the tempNode is in any case nullptr, that means there is no elements left, and while loop stops
			while (tempNode != nullptr)
			{
				cout << tempNode->value << " | ";
				//tempNode will now be the nextNode
				tempNode = tempNode->_nextNode;
			}
			cout << "\n\n";
		}

	}
	int GetCounter() { return _counter; }
	T operator[](int index) { return 0; }
};