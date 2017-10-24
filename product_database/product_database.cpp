// product_database.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct product
{
	int id;
	string name;
	float price;
};

vector<product> product_collection;

int ID = 1;

void add_product();
void delete_product(int product_id);
void edit_product(int product_id);
void display_products();
void search_product(int product_id);
void search_product(string product_name);
void save_to_file();
void add_to_file();
void load_from_file();

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
			add_product();
			break;
		case 2:
			int remove_id;
			cout << "Enter the ID of the product you wish to remove: ";
			cin >> remove_id;
			delete_product(remove_id);
			break;
		case 3:
			int edit_id;
			cout << "Enter the ID of the product you wish to edit: ";
			cin >> edit_id;
			break;
		case 4:
			display_products();
			break;
		case 5:
			int search_criteria;
			cout << "Select searching criteria: " << endl;
			cout << "1. ID" << endl;
			cout << "2. Name" << endl;
			cout << "3. Price" << endl;
			cin >> search_criteria;

			if (search_criteria == 1)
			{
				int search_id;
				cout << "Enter the ID you want to search for: ";
				cin >> search_id;
				search_product(search_id);
			}
			else if (search_criteria == 2)
			{
				int search_name;
				cout << "Enter the name you want to search for: ";
				cin >> search_name;
				search_product(search_name);
			}
			else if (search_criteria == 3)
			{
				int search_price;
				cout << "Enter the price you want to search for: ";
				cin >> search_price;
				search_product(search_price);
			}
			else
			{
				cout << "Invalid input." << endl;
			}
			break;
		case 6:
			save_to_file();
			break;
		case 7:
			add_to_file();
			break;
		case 8:
			load_from_file();
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

void add_product()
{
	product new_product;

	cout << "Enter a name: ";
	cin >> new_product.name;
	cout << "Enter a price: ";
	cin >> new_product.price;
	new_product.id = ID;

	ID++;
	product_collection.push_back(new_product);
	cout << endl;
}

void delete_product(int product_id)
{
	if (product_collection.empty())
	{
		cout << "The database is empty." << endl;
		return;
	}

	int collection_size = product_collection.size();
	for (int i = 0; i < collection_size; i++)
	{
		if (product_collection[i].id == product_id)
		{
			product_collection.erase(product_collection.begin() + i);
			return;
		}
	}
	cout << "There is no product with such ID." << endl;
}

void edit_product(int product_id)
{
	if (product_collection.empty())
	{
		cout << "The database is empty." << endl;
		return;
	}

	int collection_size = product_collection.size();
	for (int i = 0; i < collection_size; i++)
	{
		if (product_collection[i].id == product_id)
		{
			cout << "Enter a new name: ";
			cin >> product_collection[i].name;
			cout << "Enter a new price: ";
			cin >> product_collection[i].price;
			return;
		}
	}
	cout << "There is no product with such ID." << endl;
}

void display_products()
{
	if (product_collection.empty())
	{
		cout << "The database is empty." << endl;
		return;
	}

	int collection_size = product_collection.size();
	cout << endl << "Products in database: " << endl;
	for (int i = 0; i < collection_size; i++)
	{
		cout << product_collection[i].id << "\t" << product_collection[i].name << "\t" <<
			product_collection[i].price << endl;
	}
	cout << endl;
}

void search_product(int product_id)
{
	if (product_collection.empty())
	{
		cout << "The database is empty." << endl;
		return;
	}

	int collection_size = product_collection.size();

	for (int i = 0; i < collection_size; i++)
	{
		if (product_collection[i].id == product_id)
		{
			cout << "Product: " << endl << product_collection[i].id << "\t" << product_collection[i].name <<
				"\t" << product_collection[i].price << endl;
			return;
		}
		cout << "There is no product with such ID." << endl;
	}
}

void search_product(string product_name)
{
	if (product_collection.empty())
	{
		cout << "The database is empty." << endl;
		return;
	}

	int collection_size = product_collection.size();

	for (int i = 0; i < collection_size; i++)
	{
		if (product_collection[i].name == product_name)
		{
			cout << "Product: " << endl << product_collection[i].id << "\t" << product_collection[i].name <<
				"\t" << product_collection[i].price << endl;
			return;
		}
		cout << "There is no product with such ID." << endl;
	}
}

void search_product(float product_price)
{
	if (product_collection.empty())
	{
		cout << "The database is empty." << endl;
		return;
	}

	int collection_size = product_collection.size();

	for (int i = 0; i < collection_size; i++)
	{
		if (product_collection[i].price == product_price)
		{
			cout << "Product: " << endl << product_collection[i].id << "\t" << product_collection[i].name <<
				"\t" << product_collection[i].price << endl;
			return;
		}
		cout << "There is no product with such ID." << endl;
	}
}

void save_to_file()
{
	if (product_collection.empty())
	{
		cout << "The database is empty." << endl;
		return;
	}

	int collection_size = product_collection.size();
	fstream file;

	file.open("product_database.txt", ios::out);
	for (int i = 0; i < collection_size; i++)
	{
		file << endl << product_collection[i].id << "\t" << product_collection[i].name <<
			"\t" << product_collection[i].price << endl;
	}
	file.close();

	cout << "The database was saved to file.";
}

void add_to_file()
{
	float price;
	string name;
	cout << "Enter a price: ";
	cin >> price;
	cout << "Enter a name: ";
	cin >> name;

	fstream file;
	file.open("product_database.txt", ios::out | ios::app);
	file << endl << ID << "\t" << name << "\t" << price;
	file.close();
	ID++;

	cout << "The product was added to file.";
}

void load_from_file()
{
	fstream file;
	file.open("product_database.txt", ios::in);

	if (file.good())
	{
		product_collection.clear();

		while (!file.eof())
		{
			int id;
			string name;
			float price;

			file >> id >> name >> price;

			product new_product;
			new_product.id = id;
			new_product.name = name;
			new_product.price = price;
			ID = new_product.id;

			product_collection.push_back(new_product);
		}

		file.close();
		ID++;
		cout << "The database was loaded from the file.";
	}
	else
	{
		cout << "The file could not be opened.";
	}
}