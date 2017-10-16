// product_database.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	bool end = false;
	while (!end)
	{
		int choice;
		cout << "1. Add product" << endl;
		cout << "2. Delete product" << endl;
		cout << "3. Edit product" << endl;
		cout << "4. Show all products" << endl;
		cout << "5. Search for a product" << endl;
		cout << "6. Save database to a file" << endl;
		cout << "7. Add a record to a file" << endl;
		cout << "8. Load database from a file" << endl;
		cout << "9. Exit" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			end = true;
			break;
		default:
			cout << "Invalid input." << endl;
			break;
		}
	}

    return 0;
}

