/*
Reese Allen (rga2uz)
postfixCalculator.h
09-21-2020
*/

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include <cstdlib>
#include "Stack.h"

using namespace std; 

class Stack;

class postfixCalculator{

public:

	postfixCalculator();

	Stack *theStack;

	void addition();
	void subtraction();
	void multiplication();
	void division();
	void negation();

	int getTop();
	int topPop();
	void pushValue(int val);
};


#endif 