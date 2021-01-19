#pragma once
#include "ListBase.h";

template<class T>
class Node
{
public:
	//_nextNode field is a generic pointer that points to another node in the list
	Node<T>* _nextNode;
	//value field is the value of current node
	T value;

	Node(T value, Node<T>* next)
	{
		this->value = value;
		this->_nextNode = next;
	}
};

