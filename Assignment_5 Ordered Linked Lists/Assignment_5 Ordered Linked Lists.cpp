// Assignment_5 Ordered Linked Lists.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SortedList.h"

using namespace std;

void CreateList1();
void CreateList2();
void PrintList();
void EmptyList();
void Exit();

SortedType<string> OL1;
SortedType<string> OL2;
SortedType<string> OL3;

bool quitFlag = false;

int main()
{
	int option;
	do
	{
		cout << "\n\n\n\n";
		cout << "\t__________________________________________________________________" << endl;
		cout << "\t|                                                                |" << endl;
		cout << "\t|\t\t\t MENU OPTION                             |" << endl;
		cout << "\t|________________________________________________________________|" << endl;
		cout << "\t|                                                                |" << endl;
		cout << "\t|\t1. Input Values to the List 1                            |\n";
		cout << "\t|\t2. Input Values to the List 2                            |\n";
		cout << "\t|\t3. Print Ordered List 3                               |\n";
		cout << "\t|\t4. Clear List                                            |\n";
		cout << "\t|\t5. Exit                                                  |\n";
		cout << "\t|________________________________________________________________|" << endl;
		cout << endl;
		cout << "\tOption: ";
		cin >> option;
		cout << "\n";

		switch (option)
		{
			//============================= FUNCTIONS CALL =============================
		case 1:
			CreateList1();
			break;
		case 2:
			CreateList2();
			break;
		case 3:
			PrintList();
			break;
		case 4:
			EmptyList();
			break;
		case 5:
			Exit();
			break;
		default:
			cout << " -- Invalid option ! -- " << endl;
			break;
		}
	} while (!quitFlag);
	return 0;
}

void CreateList1()
{
	string str_1;
	cout << " \n\n\t\tCREATE LIST 1 \n\n";
	for (int i = 0; i < 6; i++)
	{
		cout << "\t\tEnter a word: ";
		cin >> str_1;
		OL1.InsertItem(str_1);
	}
}

void CreateList2()
{
	string str_2;
	cout << " \n\n\t\tCREATE LIST 2 \n\n";
	for (int i = 0; i < 4; i++)
	{
		cout << "\t\tEnter a word: ";
		cin >> str_2;
		OL2.InsertItem(str_2);
	}

}


//================================POPULATE THE LIST=======================
void PrintList()
{
	if (OL1.IsEmpty() && OL2.IsEmpty() && OL3.IsEmpty())
	{
		cout << "\n\n\t-- THE LIST IS EMPTY ! --\n";
	}

	else
	{
		// Output the values into List 
		cout << "\n\tLIST 1:";
		OL1.PrintList();
		cout << "\n\tLIST 2:";
		OL2.PrintList();


		// Merge Lists into a third list
		OL2.SetCurrentPos(); OL1.SetCurrentPos();
		while (OL2.GetCurrentPos() != NULL)
		{
			OL3.InsertItem(OL2.GetCurrentPos()->info);
			OL2.MoveToNextItem();

			while (OL1.GetCurrentPos() != NULL)
			{
				OL3.InsertItem(OL1.GetCurrentPos()->info);
				OL1.MoveToNextItem();
			}

		}
		// Print the third list
		cout << "\n\n\t SORTED LIST\n\n ";
		OL3.PrintList();
		cout << endl;
	}
}

//============================DELETE THE VALUES IN THE LIST==========================
void EmptyList() {

	if (!OL3.IsEmpty() || !OL2.IsEmpty() || !OL1.IsEmpty()) 
	{
		OL1.MakeEmpty();
		OL2.MakeEmpty();
		OL3.MakeEmpty();
		cout << "\n\n\t-- LISTS ARE CLEARED! --\n";
	}

	else
	{
		cout << "\n\n\t--!NO VALUES TO CLEAR!--\n";
	}
}

void Exit() 
{
	quitFlag = true;
}

