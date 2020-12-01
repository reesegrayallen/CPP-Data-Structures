// REESE ALLEN / rga2uz / hashTable.h / 10-12-20

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>

#include <vector>

#include <string>

#include <list>

#include <algorithm>

using namespace std; 

class HashTable{
public:
	HashTable(int size);
	bool contains(string key);
	void insert(string key);

private:
	vector<list<string> > table;
	int tableSize;
	int hash(string word);
};


#endif 
