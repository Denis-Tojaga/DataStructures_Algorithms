#include<iostream>
#include "LinkedList.h";
#include "ListArray.h";
using namespace std;


/// <summary>
/// Test Methods for list data structure
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




void main()
{
	

	system("pause>0");
}