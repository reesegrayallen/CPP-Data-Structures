/*
Reese Allen (rga2uz)
postfixCalculator.cpp
09-21-2020
*/

#include "postfixCalculator.h"
#include "Stack.h"
#include <iostream>
#include <cstdlib>


postfixCalculator::postfixCalculator(){
	theStack = new Stack();
}


void postfixCalculator::addition(){
	int first = topPop();
	int second = topPop();
	theStack->push(first + second);
}


void postfixCalculator::subtraction(){
	int first = topPop();
	int second = topPop();
	theStack->push(second - first);
}


void postfixCalculator::multiplication(){
	int first = topPop();
	int second = topPop();
	theStack->push(first * second);
}


void postfixCalculator::division(){
	int first = topPop();
	int second = topPop();
	theStack->push(second / first);
}


void postfixCalculator::negation(){
	int first = topPop();
	theStack->push(first * (-1));
}


// int postfixCalculator::top(){
// 	if(this->theStack.empty()){
// 		cout<< "Error: stack empty" << endl;
// 		exit(-1);
// 	}
// 	else{
// 		return this->theStack.top();
// 	}
// }


// void postfixCalculator::pop(){
// 	if(this->theStack.empty()){
// 		cout<< "Error: stack empty" << endl;
// 		exit(-1);
// 	}
// 	else{
// 		this->theStack.pop();
// 	}
// }


// int postfixCalculator::getTop(){
// 	int top = theStack.top();
// 	this->theStack.pop();
// 	return top;
// }

int postfixCalculator::getTop(){
	if(theStack->empty()){
		cout << "Error: stack empty" << endl;
		exit(-1);
	}
	return this->theStack->top();
}

int postfixCalculator::topPop(){
	if(theStack->empty()){
		cout << "Error: stack empty" << endl;
		exit(-1);
	}
	int t = theStack->top();
	this->theStack->pop();
	return t;
}
void postfixCalculator::pushValue(int val){
	this->theStack->push(val);
}


