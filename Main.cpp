#include<iostream>
#include "LinkedList.h";
#include "ListArray.h";
#include "StackArray.h";
#include "StackLinked.h";
#include "QueueArray.h";
#include "QueueLinked.h";
#include "Heap.h";
#include "PriorityQueueArray.h";
using namespace std;


/// <summary>
/// Test Methods for List data structure
/// </summary>
void Test_ListArray()
{
	ListArray<int> _listArr;
	try
	{
		for (int i = 0; i < 15; ++i)
			_listArr.Add_On_Start(i);

		for (int i = 0; i < 15; ++i)
			_listArr.Add_On_End(i);

		cout << endl;
		_listArr.Print();
		cout << endl;

		for (int i = 0; i < 5; ++i)
			_listArr.Remove_From_Start();

		for (int i = 0; i < 50; ++i)
			_listArr.Remove_From_End();

		while (!_listArr.IsEmpty())
			_listArr.Remove_From_Start();
	}
	catch (const std::exception& ex)
	{
		cout << "Exception -> " << ex.what() << endl;
	}
}
void Test_LinkedList()
{
	LinkedList<int> _linkedList;
	try
	{
		for (int i = 0; i < 5; ++i)
			_linkedList.Add_On_Start(i);

		for (int i = 0; i < 5; ++i)
			_linkedList.Add_On_End(i);

		cout << endl;
		_linkedList.Print();
		cout << endl;

		for (int i = 0; i < 2; ++i)
			_linkedList.Remove_From_Start();

		for (int i = 0; i < 2; ++i)
			_linkedList.Remove_From_End();

		while (!_linkedList.IsEmpty())
			_linkedList.Remove_From_Start();
	}
	catch (const std::exception& ex)
	{
		cout << "Exception -> " << ex.what() << endl;
	}
}






/// <summary>
/// Test Methods for Stack data struture
/// </summary>
void Test_StackArray()
{
	StackArray<int> stack;
	for (int i = 0; i < 10; i++)
		stack.Add_To_Stack(i);

	for (int i = 0; i < 10; i++)
		stack.Add_To_Stack(i);


	stack.Print();


	for (int i = 0; i < 3; i++)
		stack.Remove_From_Stack();

	for (int i = 0; i < 12; i++)
		stack.Remove_From_Stack();

	while (!stack.IsEmpty())
	{
		stack.Remove_From_Stack();
	}
	cout << "\nStack is now empty!\n";
}
void Test_StackLinked()
{
	StackLinked<int> stack;
	for (int i = 0; i < 10; i++)
		stack.Add_To_Stack(i);

	for (int i = 0; i < 10; i++)
		stack.Add_To_Stack(i);


	stack.Print();

	for (int i = 0; i < 3; i++)
		stack.Remove_From_Stack();

	for (int i = 0; i < 12; i++)
		stack.Remove_From_Stack();


	while (!stack.IsEmpty())
		stack.Remove_From_Stack();

}






/// <summary>
/// Test Methods for Queue data structure
/// </summary>
void Test_QueueArray()
{
	QueueArray<int> _queueArr;

	for (int i = 0; i < 10; ++i)
		_queueArr.Add_To_Queue(i);


	for (int i = 0; i < 10; ++i)
		_queueArr.Add_To_Queue(i);

	_queueArr.Print();

	for (int i = 0; i < 3; ++i)
		_queueArr.Remove_From_Queue();

	for (int i = 0; i < 12; ++i)
		_queueArr.Remove_From_Queue();


	while (!_queueArr.IsEmpty())
		_queueArr.Remove_From_Queue();
}
void Test_QueueLinked()
{
	LinkedQueue<int> _linkedQueue;
	for (int i = 0; i < 10; ++i)
		_linkedQueue.Add_To_Queue(i);
	for (int i = 0; i < 10; ++i)
		_linkedQueue.Add_To_Queue(i);


	_linkedQueue.Print();

	for (int i = 0; i < 3; ++i)
		_linkedQueue.Remove_From_Queue();

	for (int i = 0; i < 12; ++i)
		_linkedQueue.Remove_From_Queue();


	while (!_linkedQueue.IsEmpty())
		_linkedQueue.Remove_From_Queue();
}





/// <summary>
/// Test Methods for Heap data structure
/// </summary>
void Test_Heap()
{
	Heap<int> heap;
	for (int i = 0; i < 10; ++i)
		heap.Add_On_Heap(i);

	for (int i = 0; i < 10; ++i)
		heap.Add_On_Heap(i);

	heap.Print();

	for (int i = 0; i < 3; ++i)
		heap.Remove_From_Heap();

	for (int i = 0; i < 12; ++i)
		heap.Remove_From_Heap();

	while (!heap.IsEmpty())
		heap.Remove_From_Heap();
}








/// <summary>
/// Test methods for Prirority Queue data structure
/// </summary>
void Test_PriorityQueue()
{
	PriorityQueueArray<int> _priorityQueue;
	for (int i = 0; i < 10; ++i)
		_priorityQueue.Add_To_Queue(i);

	for (int i = 0; i < 10; ++i)
		_priorityQueue.Add_To_Queue(i);

	_priorityQueue.Print();

	for (int i = 0; i < 3; ++i)
		_priorityQueue.Remove_From_Queue();

	for (int i = 0; i < 12; ++i)
		_priorityQueue.Remove_From_Queue();

	while (!_priorityQueue.IsEmpty())
		_priorityQueue.Remove_From_Queue();
}


















void main()
{
	Test_PriorityQueue();
	system("pause>0");
}