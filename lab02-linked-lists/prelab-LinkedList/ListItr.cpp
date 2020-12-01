/*
Reese Allen (rga2uz)
ListItr.cpp
09-14-20
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#include "List.h"
#include "ListItr.h"


ListItr::ListItr(){}

ListItr::ListItr(ListNode* theNode){
	current = theNode;
}

bool ListItr::isPastEnd() const{
	if(current->next == NULL)
		return true;
	else
		return false;
	
}

bool ListItr::isPastBeginning() const{
	if(current->previous == NULL)
		return true;
	else
		return false;
}

void ListItr::moveForward(){
	if(isPastEnd() == false)
		current = current->next;
}

void ListItr::moveBackward(){
	if(isPastBeginning() == false)
		current= current->previous;
}

int ListItr::retrieve() const{
	return current->value;
}
