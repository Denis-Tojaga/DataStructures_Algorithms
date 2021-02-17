#pragma once
#include "HashingChaining.h";
#include "HashingOpenAdressing.h";
using namespace std;

void Testing(Hashing<int>* hashSet)
{
	hashSet->Add(23);
	hashSet->Add(25);
	hashSet->Add(2245);
	hashSet->Add(145);
	hashSet->Add(145);
	hashSet->Add(6434);
	hashSet->Add(1453);
	hashSet->Add(1451);
	cout << "*** HASH SET AFTER ADDING 8 ELEMENTS ***";
	hashSet->Print();
	cout << "===================\n";
	hashSet->Remove(23);
	hashSet->Remove(25);
	hashSet->Remove(145);
	cout << "*** HASH SET AFTER REMOVING 3 ELEMENTS ***";
	hashSet->Print();
}


void Test()
{
	Testing(new HashingOpenAdressing<int>());
	Testing(new HashingChaining<int>());
}