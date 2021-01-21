#include<iostream>
#include "LinkedList.h";
#include "ListArray.h";
#include "StackArray.h";
#include "StackLinked.h";
#include "QueueArray.h";
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




void main()
{
	system("pause>0");
}