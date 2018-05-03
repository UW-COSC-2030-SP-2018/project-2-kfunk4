// proj2.cpp
// test file for project 2  
// Kelby Funk
// project 2
// COSC 2030

#include "proj2.h"
#include "BloomFilter.h"

int main()
{
	cout << "Testing quick sort" << endl << endl;
	vector<double> vector1 = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

	cout << "Even sized unsorted vector" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << vector1[i] << " ";
	}

	quickSort(vector1, 0, 9);

	cout << endl << endl << "Even sized sorted vector" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << vector1[i] << " ";
	}

	cout << endl << endl << "Odd sized unsorted vector" << endl;
	vector<double> vector2 = { -5, 789, 34, 800, 2, 54, 34, 102, 90, 80, 1 };
	for (int i = 0; i < 11; i++)
	{
		cout << vector2[i] << " ";
	}

	quickSort(vector2, 0, 10);

	cout << endl << endl << "Odd sized sorted vector" << endl;
	for (int i = 0; i < 11; i++)
	{
		cout << vector2[i] << " ";
	}

	cout << endl << endl;
	
	vector<double> vec = { 1, 2, 3, 4, 7, 10, 24, 25, 30, 31, 50, 56, 78, 90, 99 };

	cout << "Testing binary search" << endl << endl;
	cout << "Using binary search for odd sized vector" << endl;
	cout << "Seeing if it can find all elements in vector" << endl << endl;

	bool found = binarySearch(vec, 0, 14, 1);
	cout << "Searching for 1, is found: " << found << endl;
	bool found1 = binarySearch(vec, 0, 14, 2);
	cout << "Searching for 2, is found: " << found1 << endl;
	bool found2 = binarySearch(vec, 0, 14, 3);
	cout << "Searching for 3, is found: " << found2 << endl;
	bool found3 = binarySearch(vec, 0, 14, 4);
	cout << "Searching for 4, is found: " << found3 << endl;
	bool found4 = binarySearch(vec, 0, 14, 7);
	cout << "Searching for 7, is found: " << found4 << endl;
	bool found5 = binarySearch(vec, 0, 14, 10);
	cout << "Searching for 10, is found: " << found5 << endl;
	bool found6 = binarySearch(vec, 0, 14, 24);
	cout << "Searching for 24, is found: " << found6 << endl;
	bool found7 = binarySearch(vec, 0, 14, 25);
	cout << "Searching for 25, is found: " << found7 << endl;
	bool found8 = binarySearch(vec, 0, 14, 30);
	cout << "Searching for 30, is found: " << found8 << endl;
	bool found9 = binarySearch(vec, 0, 14, 31);
	cout << "Searching for 31, is found: " << found9 << endl;
	bool found10 = binarySearch(vec, 0, 14, 50);
	cout << "Searching for 50, is found: " << found10 << endl;
	bool found11 = binarySearch(vec, 0, 14, 56);
	cout << "Searching for 56, is found: " << found11<< endl;
	bool found12 = binarySearch(vec, 0, 14, 78);
	cout << "Searching for 78, is found: " << found12 << endl;
	bool found13 = binarySearch(vec, 0, 14, 90);
	cout << "Searching for 90, is found: " << found13 << endl;
	bool found14 = binarySearch(vec, 0, 14, 99);
	cout << "Searching for 99, is found: " << found14 << endl << endl;
	cout << "Now seeing if it can find things not in vector" << endl << endl;
	bool found15 = binarySearch(vec, 0, 14, 0);
	cout << "Searching for 0, is found: " << found15 << endl;
	bool found16 = binarySearch(vec, 0, 14, 102);
	cout << "Searching for 102, is found: " << found16 << endl;
	bool found17 = binarySearch(vec, 0, 14, -5);
	cout << "Searching for -5, is found: " << found17 << endl << endl;

	cout << "Using binary search for even sized vector" << endl;
	cout << "Seeing if it can find all elements in vector" << endl << endl;

	vector<double> vect = { 1, 2, 3, 4, 7, 10, 24, 25 };

	bool found18 = binarySearch(vec, 0, 7, 1);
	cout << "Searching for 1, is found: " << found18 << endl;
	bool found19 = binarySearch(vec, 0, 7, 2);
	cout << "Searching for 2, is found: " << found19 << endl;
	bool found20 = binarySearch(vec, 0, 7, 3);
	cout << "Searching for 3, is found: " << found20 << endl;
	bool found21 = binarySearch(vec, 0, 7, 4);
	cout << "Searching for 4, is found: " << found21 << endl;
	bool found22 = binarySearch(vec, 0, 7, 7);
	cout << "Searching for 7, is found: " << found22 << endl;
	bool found23 = binarySearch(vec, 0, 7, 10);
	cout << "Searching for 10, is found: " << found23 << endl;
	bool found24 = binarySearch(vec, 0, 7, 24);
	cout << "Searching for 24, is found: " << found24 << endl;
	bool found25 = binarySearch(vec, 0, 7, 25);
	cout << "Searching for 25, is found: " << found25 << endl << endl;
	cout << "Now seeing if it can find things not in vector" << endl << endl;
	bool found26 = binarySearch(vec, 0, 7, 0);
	cout << "Searching for 0, is found: " << found26 << endl;
	bool found27 = binarySearch(vec, 0, 7, 502);
	cout << "Searching for 502, is found: " << found27 << endl;
	bool found28 = binarySearch(vec, 0, 7, -7);
	cout << "Searching for -7, is found: " << found28 << endl << endl;

	cout << "Testing merge sort" << endl << endl;

	int vector3[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };

	cout << "Odd sized unsorted array" << endl;

	for (int i = 0; i < 9; i++)
	{
		cout << vector3[i] << " ";
	}

	mergeSort(vector3, 0, 8);

	cout << endl << endl << "Odd sized sorted array" << endl;
	for (int i = 0; i < 9; i++)
	{
		cout << vector3[i] << " ";
	}

	int vector4[] = { 5, -2, 89, 34, 105, 21, 600, 456, 2, 50 };

	cout << endl << endl <<"Even sized unsorted array" << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << vector4[i] << " ";
	}

	mergeSort(vector4, 0, 9);

	cout << endl << endl << "Even sized sorted array" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << vector4[i] << " ";
	}

	cout << endl << endl;
	
	cout << "Testing hash function" << endl << endl;

	string table[97];

	for (int i = 0; i < 97; i++)
	{
		table[i] = "null";
	}
	string value1 = "hello world";
	int hash1 = hashString(value1, 97);
	table[hash1] = value1;

	string value2 = "COSC 2030";
	int hash2 = hashString(value2, 97);
	table[hash2] = value2;

	string value3 = "Project 2";
	int hash3 = hashString(value3, 97);
	table[hash3] = value3;
	
	cout << "What hashes indexed to" << endl;
	cout << "hash1: " << hash1 << endl;
	cout << "hash2: " << hash2 << endl;
	cout << "hash3: " << hash3 << endl << endl; 

	cout << "Printing out hash table with index and value" << endl;

	for (int i = 0; i < 97; i++)
	{
		if (table[i] != "null")
		{
			cout << i << " " << table[i] << endl;
		}
			
	}
	
	cout << endl << "Testing BloomFilter" << endl << endl;
	BloomFilter bloom;
	bloom.insert("hello world");
	cout << "Testing to see if hash table contains hello world: ";
	cout << bloom.contains("hello world") << endl;
	cout << "Printing out hash table" << endl;
	bloom.printTable();
	bloom.insert("cosc 2030");
	cout << endl << "Testing to see if hash table contains cosc 2030: ";
	cout << bloom.contains("cosc 2030") << endl;
	cout << "Printing out hash table" << endl;
	bloom.printTable();
	bloom.insert("proj 2");
	cout << endl << "Testing to see if hash table contains proj 2: ";
	cout << bloom.contains("proj 2") << endl;
	cout << "Printing out hash table" << endl;
	bloom.printTable();
	cout << endl << "Testing to see if hash table contains hello: ";
	cout << bloom.contains("hello") << endl;
	cout << "Printing out hash table" << endl;
	bloom.printTable();

	cout << endl << endl;
	
	return 0;
}