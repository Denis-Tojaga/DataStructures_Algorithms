#pragma once
#include "NodeBase.h";


template<class T>
class LinkedList : public List<T>
{
	Node<T>* _first = nullptr;
	int _counter = 0;
	void ShowException() { throw std::exception("*** The linked list is empty!***\n"); }
public:
	
	bool IsFull() { return false; }
	int GetCounter() { return _counter; }
	bool IsEmpty() { return _first == nullptr; }

	void Add_On_Start(T value)
	{
		Node<T>* newNode = new Node<T>(value, _first);
		_first = newNode;
		_counter++;
		cout << "Added at the start of linked list -> | " << _first->value << " |\n";
	}
	void Add_On_End(T value)
	{
		Node<T>* tempNode = _first;

		if (tempNode == nullptr)
		{
			tempNode = new Node<T>(value, nullptr);
			cout << "Added at the end of linked list -> | " << tempNode->value << " |\n";
		}
		else
		{
			while (tempNode->_nextNode != nullptr)
			{
				tempNode = tempNode->_nextNode;
			}

			tempNode->_nextNode = new Node<T>(value, nullptr);
			cout << "Added at the end of linked list -> | " << tempNode->_nextNode->value << " |\n";
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
		cout << "Deleted NODE from start with value of -> | " << deletedValue << " | \n";
		return deletedValue;
	}
	T Remove_From_End()
	{
		if (IsEmpty())
			ShowException();
		Node<T>* tempNode = _first;
		Node<T>* helperNode = nullptr;
		while (tempNode->_nextNode != nullptr)
		{
			helperNode = tempNode;
			tempNode = tempNode->_nextNode;
		}

		T deletedValue = tempNode->value;
		delete tempNode;
		if (helperNode != nullptr)
			helperNode->_nextNode = nullptr;
		else
			_first = nullptr;
		_counter--;
		cout << "Deleted NODE from end with value of -> | " << deletedValue << " | \n";
		return deletedValue;
	}

	T operator[] (int index)
	{
		if (index > _counter || index < 0 || _first == nullptr)
			throw exception("Index range is not valid!\n");
		Node<T>* tempNode = _first;
		for (int i = 0; i < index; i++)
			tempNode = tempNode->_nextNode;
		return tempNode->value;
	}
	void Print()
	{
		cout << "\n\n *** LINKED LIST elements *** \n\n";
		Node<T>* tempNode = _first;
		while (tempNode != nullptr)
		{
			cout << tempNode->value << " | ";
			tempNode = tempNode->_nextNode;
		}
		cout << "\n\n";
	}
};
