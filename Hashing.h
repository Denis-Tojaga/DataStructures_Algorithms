#pragma once

template<class T>
class Hashing
{
public:
	virtual void Add(T value) = 0;
	virtual void Remove(T value) = 0;
	virtual void Print() = 0;
};