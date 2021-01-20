#pragma once
#include "QueueBase.h";

template<class T>
class QueueArray : public Queue<T>
{
	int max_size = 50;
	int _start = 0;
	int _end = 0;
	int _counter = 0;
	T* _queue = new T[max_size];
public:

};