#pragma once


template<class Key>
class BSNode
{
public:
	Key value;
	BSNode* leftChild;
	BSNode* rightChild;
	BSNode(Key keyValue) : value(keyValue)
	{
		leftChild = nullptr;
		rightChild = nullptr;
	}

};