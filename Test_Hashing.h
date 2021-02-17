#pragma once
#include "HashingChaining.h";
#include "HashingOpenAdressing.h";
using namespace std;

void Testing(Hashing<int>* hashSet)
{
	cout << "\n\n";
	hashSet->Add(23);
	hashSet->Add(22);
	hashSet->Add(27);
	hashSet->Add(25);
	hashSet->Add(2245);
	hashSet->Add(145);
	hashSet->Add(145);
	hashSet->Add(6434);
	hashSet->Add(1453);
	hashSet->Add(1451);
	cout << "*** HASH SET AFTER ADDING 10 ELEMENTS ***\n";
	hashSet->Print();
	cout << "\n===================\n";
	hashSet->Remove(23);
	hashSet->Remove(25);
	hashSet->Remove(145);
	cout << "===================\n";

	cout << "\n*** HASH SET AFTER REMOVING 3 ELEMENTS ***\n";
	hashSet->Print();
}


void Test_H()
{
	Testing(new HashingOpenAdressing<int>());
	Testing(new HashingChaining<int>());
}