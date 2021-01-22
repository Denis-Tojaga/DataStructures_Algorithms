#pragma once
#include "QueueBase.h";


template<class T>
class PriorityQueue : public Queue<T>
{
	int max_size = 10;
	int _counter = 0;
	T* _priorityQueue = new T[max_size];
public:

};
