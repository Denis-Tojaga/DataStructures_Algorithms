#include<iostream>
#include<random>
#include "LinkedList.h";
#include "ListArray.h";
#include "StackArray.h";
#include "StackLinked.h";
#include "QueueArray.h";
#include "QueueLinked.h";
#include "Heap.h";
#include "PriorityQueueArray.h";
#include "PrirorityQueueLinked.h";
#include "BubbleSort.h";
#include "InsertionSort.h";
#include "SelectionSort.h";
#include "RadixSort.h";
#include "BucketSort.h";
#include "HeapSort.h";
#include "QuickSort.h";
#include "MergeSort.h";

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
void Test_PriorityQueueArray()
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
void Test_PriorityQueueLinked()
{
	PrirorityQueueLinked<int> _priorityQueue;

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





/// <summary>
/// Test methods for Sorting Algorithms
/// </summary>
void Test_BubbleSort()
{
	BubbleSort();
}
void Test_InsertionSort()
{
	InsertionSort();
}
void Test_SelectionSort()
{
	SelectionSort();
}
void Test_HeapSort()
{
	HeapSort();
}
void Test_RadixSort()
{
	RadixSort();
}
void Test_BucketSort()
{
	BucketSort();
}
void Test_QuickSort()
{
	QuickSort();
}
void Test_MergeSort()
{
	MergeAlgorithm();
}







void main()
{
	int userEntry;
	do
	{
		cout << "***** Hello please select which data structure / algorithm you want to test ? *****\n\n";
		cout << "*** DATA STRUCTURES MENU *** \n\n";

		cout << "1.  Test * LIST SEQUENCE *\n";
		cout << "2.  Test * LIST LINKED *\n\n";
		cout << "3.  Test * STACK SEQUENCE *\n";
		cout << "4.  Test * STACK LINKED *\n\n";
		cout << "5.  Test * QUEUE SEQUENCE *\n";
		cout << "6.  Test * QUEUE LINKED *\n\n";
		cout << "7.  Test * PRIORITY QUEUE SEQUENCE *\n";
		cout << "8.  Test * PRIORITY QUEUE LINKED *\n\n";
		cout << "9.  Test * HEAP *\n";



		cout << "\n*** ALGORITHMS MENU *** \n\n";

		cout << "10.  Test * BUBBLE SORT *\n";
		cout << "11.  Test * INSERTION SORT *\n\n";
		cout << "12.  Test * SELECTION SORT *\n";
		cout << "13.  Test * HEAP SORT *\n\n";
		cout << "14.  Test * RADIX SORT *\n";
		cout << "15.  Test * BUCKET SORT *\n\n";
		cout << "16.  Test * QUICK SORT *\n";
		cout << "17.  Test * MERGE SORT *\n\n\n\n";

		cout << "0. ***** EXIT\n";


		cin >> userEntry;

		do
		{
			cout << "Niste unijeli validan broj!\nPokusajte ponovo!\n";
			cin >> userEntry;

		} while (userEntry>17);

		
		system("cls");


		if(userEntry)
		switch (userEntry)
		{
		case 1: Test_ListArray();
			break;
		case 2: Test_LinkedList();
			break;
		case 3: Test_StackArray();
			break;
		case 4: Test_StackLinked();
			break;
		case 5: Test_QueueArray();
			break;
		case 6: Test_QueueLinked();
			break;
		case 7: Test_Heap();
			break;
		case 8: Test_PriorityQueueArray();
			break;
		case 9: Test_PriorityQueueLinked();
			break;
		//case 10: Test_ListArray();
		//	break;
		//case 11: Test_ListArray();
		//	break;
		//case 12: Test_ListArray();
		//	break;
		//case 13: Test_ListArray();
		//	break;
		//case 14: Test_ListArray();
		//	break;
		//case 15: Test_ListArray();
		//	break;
		//case 16: Test_ListArray();
		//	break;
		//case 17: Test_ListArray();
		//	break;
		default:
			break;
		}



	} while (userEntry!=0);
	system("pause>0");
}