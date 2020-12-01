/*
Reese Allen (rga2uz)
Stack.h
09-21-2020
*/

#include <iostream>
#include <cstdlib>
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"
#include "postfixCalculator.h"


Stack::Stack(){
	stack = new List();
	count = 0;
}

Stack::~Stack(){
	delete stack;
}

void Stack::push(int e){
	if(empty()){
		itr = stack->first();
	}
	stack->insertBefore(e, itr);
	count++;
}



int Stack::top(){
	itr.moveBackward();
	int n = itr.retrieve();
	itr.moveForward();
	return n;
}

void Stack::pop(){
	int n = top();
	stack->remove(n);
	count--;
}

bool Stack::empty(){
	if(count == 0){
		return true;
	}
	return false;

}