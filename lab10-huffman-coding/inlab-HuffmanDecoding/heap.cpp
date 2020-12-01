// REESE ALLEN | rga2uz | 11-14-20 | heap.cpp

// Implementation of binary heap (priority queue)

// CITATION (much of this code is not my original work):
// Original source code written by Aaron Bloomfield and part of https://github.com/aaronbloomfield/pdr repository

#include <iostream>

#include "heap.h"

using namespace std;


binary_heap::binary_heap(){
    huffmanNode* node = new huffmanNode();
    heap_size = 0;
    heap.push_back(node);
}


binary_heap::~binary_heap() {
	makeEmpty();
}

void binary_heap::insert(huffmanNode* node) {
    heap.push_back(node);
    heap_size++;
    percolateUp(heap_size);
}

void binary_heap::percolateUp(int hole) {
    // get the value just inserted
    huffmanNode* x = heap[hole];
    // while we haven't run off the top and while the
    // value is less than the parent...
    for ( ; (hole > 1) && (x->frequency < heap[hole/2]->frequency); hole /= 2) {
        heap[hole] = heap[hole/2]; // move the parent down
    }
    // correct position found!  insert at that spot
    heap[hole] = x;
  }


huffmanNode* binary_heap::deleteMin() {
    // make sure the heap is not empty
    if (heap_size == 0) {
        throw "deleteMin() called on empty heap";
    }

    // save the value to be returned
    huffmanNode* ret = heap[1];
    // move the last inserted position into the root
    heap[1] = heap[heap_size];
    heap_size--;
    // make sure the vector knows that there is one less element
    heap.pop_back();
    // percolate the root down to the proper position
    // if (!isEmpty()) {
    //     percolateDown(1);
    // }
    percolateDown(1);
    // return the old root node
    return ret;
}

void binary_heap::percolateDown(int hole) {
    // get the value to percolate down
    huffmanNode* x = heap[hole];
    // while there is a left child...
    while (hole*2 <= heap_size) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ((child+1 <= heap_size) && (heap[child+1]->frequency < heap[child]->frequency)) {
            child++;
        }
        // if the child is greater than the node...
        if (x->frequency > heap[child]->frequency) {
            heap[hole] = heap[child]; // move child up
            hole = child;             // move hole down
        } else {
            break;
        }
    }
    // correct position found!  insert at that spot
    heap[hole] = x;
}

huffmanNode* binary_heap::findMin() {
    if (heap_size == 0) {
        throw "findMin() called on empty heap";
    }
    return heap[1];
}

unsigned int binary_heap::get_size() {
    return heap_size;
}

void binary_heap::makeEmpty() {
    heap_size = 0;
}


bool binary_heap::isEmpty() {
    return heap_size == 0;
}

void binary_heap::print() {
    cout << "(" << heap[0]->character << ") ";
    for (int i = 1; i <= heap_size; i++) {
        cout << heap[i]->character << " ";
        // next line from http://tinyurl.com/mf9tbgm
        bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        if (isPow2) {
            cout << endl << "\t";
        }
    }
    cout << endl;
}

vector<huffmanNode*> binary_heap::getHeap(){
	return heap;
}