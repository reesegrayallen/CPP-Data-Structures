// REESE ALLEN / rga2uz / hashTable.cpp / 10-12-20

#include <iostream>

#include <vector>

#include <string>

#include <list>

#include <algorithm>

#include "hashTable.h"

HashTable::HashTable(int size){
	table.resize(size);
	tableSize = size;
}

bool HashTable::contains(string key){
	const list<string> & compTable = table[hash(key)];
	return find(compTable.begin(), compTable.end(), key) != compTable.end();
}

void HashTable::insert(string key){
	if(key.length() > 2){
		int hashVal = hash(key);
		table[hashVal].push_back(key);
	}
}

int HashTable::hash(string key){
	int val = 0;
	for(int i = 0; i < key.length(); i++){
		val = 37 * val + key[i];
	}

	val %= tableSize;

	if(val < 0){
		val += tableSize;
	}
	return val;
}
