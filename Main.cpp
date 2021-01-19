#include "ListArray.h";
using namespace std;


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


		for (int i = 0; i < 3; ++i)
			_listArr.Remove_From_End();


		while (!_listArr.IsEmpty())
			_listArr.Remove_From_Start();
	}
	catch (const std::exception& ex)
	{
		cout << "Exception -> " << ex.what() << endl;
	}
}

void main()
{
	//Test_ListArray();

	system("pause>0");
}