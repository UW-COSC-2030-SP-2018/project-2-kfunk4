// BloomFilter.h
// header file for bloom filter
// revieved help from Professor Borowczak
// read implementation of blog Professor gave us in class didn't really use it though

#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

#define TABLE_SIZE 8191

#include<string>
using std::string;

class BloomFilter
{
public:
	BloomFilter();
	~BloomFilter();

	void insert(string s);
	bool contains(string s) const;
	void printTable();

private:
	int table[TABLE_SIZE] = { 0 };
};

#endif