#pragma once
#include "ListBase.h";
#include "NodeBase.h";


template<class T>
class LinkedList : public List<T>
{
	Node<T>* _first;
	int _counter = 0;
	void ShowException() { throw exception("*** The linked list is empty!***\n") }
public:
	LinkedList()
	{
		_first = nullptr;
	}

	bool IsEmpty() { return _first == nullptr; }
	void Add_On_Start(T value)
	{
		if (IsEmpty())
			ShowException();
		Node<T>* newNode = new Node<T>(value, _first);
		_first = _first->_nextNode;
		_counter++;
	}
	void Add_On_End(T value)
	{
		Node<T>* tempNode = _first;

		if (tempNode == nullptr)
			tempNode = new Node<T>(value, nullptr);
		else
		{
			while (tempNode != nullptr)
				tempNode = tempNode->_nextNode;

			tempNode = new Node<T>(value, nullptr);
		}
		_counter++;
	}

	T Remove_From_Start()
	{
		if (IsEmpty())
			ShowException();
		T deletedValue = _first->value;
		_first = _first->_nextNode;
		_counter--;
		cout << "Deleted NODE with value of -> | " << deletedValue << " | \n";
	}


	T Remove_From_End()
	{
		if (IsEmpty())
			ShowException();


	}



};
