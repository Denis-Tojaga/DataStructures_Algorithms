#pragma once
#include<iostream>
using namespace std;


template<class T>
class Node
{
	//_nextNode field is a generic pointer that points to another node in the list
	Node<T>* _nextNode;
	//value field is the value of current node
	T value;
public:
	Cvor(T value, Node<T>* next)
	{
		this->value = value;
		this->_nextNode = next;
	}
};

