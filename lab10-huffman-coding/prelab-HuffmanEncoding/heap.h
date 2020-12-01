// REESE ALLEN | rga2uz | 11-14-20 | heap.h 

#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <iostream>
#include <string>

#include "huffmanNode.h"


using namespace std;

class binary_heap {

	public:
		binary_heap();
		~binary_heap();

		void insert(huffmanNode* node);

		void percolateUp(int hole);
		void percolateDown(int hole);

		huffmanNode* findMin();
		huffmanNode* deleteMin();

		unsigned int get_size();
		void makeEmpty();
		bool isEmpty();
		void print();

		
		vector <huffmanNode*> getHeap();

		vector <huffmanNode*> heap;
		unsigned int heap_size;

};

#endif