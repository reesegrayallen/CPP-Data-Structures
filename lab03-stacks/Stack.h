/*
Reese Allen (rga2uz)
Stack.cpp
09-21-2020
*/

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"
#include "postfixCalculator.h"

class Stack{
public:

	Stack();
	~Stack();

	void push(int e);
	void pop();
	int top();
	bool empty();

private:
	int count;

	List *stack;
	ListItr itr;
};

#endif 
