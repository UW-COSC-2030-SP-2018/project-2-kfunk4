// BloomFilter.cpp
// definitions of bloomfilter
// recieved help from Professor Borowczak
// read implementation of blog Professor gave us in class didn't really use it though
// used hashes from lab10 which includes this notice
/**************************************************************************
*                                                                        *
*          General Purpose Hash Function Algorithms Library              *
*                                                                        *
* Author: Arash Partow - 2002 *
* URL : http ://www.partow.net                                             *
	*URL : http ://www.partow.net/programming/hashfunctions/index.html        *
	**
	* Copyright notice : *
	* Free use of the General Purpose Hash Function Algorithms Library is    *
	* permitted under the guidelines and in accordance with the MIT License. *
	* http ://www.opensource.org/licenses/MIT                                 *
	**
	**************************************************************************/

#include "BloomFilter.h"
#include<iostream>
using std::cout;
using std::endl;

// constructor for bloomfilter, sets table to all zeros
BloomFilter::BloomFilter() {}

// deconstructor 
BloomFilter::~BloomFilter() {}

// the insert function, passed the string through three hash functions
void BloomFilter::insert(string s)
{
	int hash = 0;
	// function created in proj2.h
	for (int i = s.length() - 1; i >= 0; i--)
	{
		hash = ((hash + s.at(i)) << 5) % TABLE_SIZE;
	}
	table[hash] = 1;

	// JSHash from lab10 found in GeneralHashFunctions.cpp
	unsigned int hash1 = 1315423911 % TABLE_SIZE;
	for (std::size_t i = 0; i < s.length(); i++)
	{
		hash1 ^= ((hash1 << 5) + s[i] + (hash1 >> 2)) % TABLE_SIZE;
	}
	table[hash1] = 1;

	// SDBMHash from lab10 found in GeneralHashFunctions.cpp
	unsigned int hash2 = 0;
	for (std::size_t i = 0; i < s.length(); i++)
	{
		hash2 = (s[i] + (hash2 << 6) + (hash2 << 16) - hash2) % TABLE_SIZE;
	}
	table[hash2] = 1;
}

bool BloomFilter::contains(string s) const
{
	bool found = false;
	int hash = 0;

	// function created in proj2.h
	for (int i = s.length() - 1; i >= 0; i--)
	{
		hash = ((hash + s.at(i)) << 5) % TABLE_SIZE;
	}
	

	// JSHash from lab10 found in GeneralHashFunctions.cpp
	// added the mod so it would fit in the table
	unsigned int hash1 = 1315423911 % TABLE_SIZE;
	for (std::size_t i = 0; i < s.length(); i++)
	{
		hash1 ^= ((hash1 << 5) + s[i] + (hash1 >> 2)) % TABLE_SIZE;
	}

	// SDBMHash from lab10 found in GeneralHashFunctions.cpp
	// added the mod so it would fit in the table
	unsigned int hash2 = 0;
	for (std::size_t i = 0; i < s.length(); i++)
	{
		hash2 = (s[i] + (hash2 << 6) + (hash2 << 16) - hash2) % TABLE_SIZE;
	}
	if (table[hash] && table[hash1] && table[hash2])
		found = true;
	
	return found;
}

// prints out the table if it is not zero
void BloomFilter::printTable()
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (table[i] != 0)
		{
			cout << i << " " << table[i] << endl;
		}

	}
}