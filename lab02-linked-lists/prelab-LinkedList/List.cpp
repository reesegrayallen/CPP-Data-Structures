/*
Reese Allen (rga2uz)
List.cpp
09-14-20
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#include "List.h"
#include "ListItr.h"

List::List(){
	head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;
}

// Copy constructor - called when constructing a new list from an existing one
List::List(const List& source) {
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}


List::~List(){
	makeEmpty();
	delete head;
	delete tail;
}

// Copy assignment operator - called when setting an existing list equal to another one 
List& List::operator=(const List& source) {
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

bool List::isEmpty() const{
	if(count ==0)
		return true;
	else
		return false;
}

void List::makeEmpty(){
}

ListItr List::first(){
	return ListItr(head->next);
}

ListItr List::last(){
	return ListItr(tail->previous);
}

void List::insertAfter(int x, ListItr position){}

void List::insertBefore(int x, ListItr position){}


void List::insertAtTail(int x){
	ListNode * n = new ListNode();
	n-> value = x;
	n->next = tail;
	n->previous = tail->previous;
	tail->previous->next = n;
	tail->previous = n;
	count++;
}

ListItr List::find(int x){
	return NULL;
}

void List::remove(int x){
}

int List::size() const{
	return count;
}



void printList(List& source, bool forward){
	if(forward == true){
		ListItr iter = source.first();
		while(iter.isPastEnd() == false){
			cout << iter.retrieve();
			iter.moveForward();
		}
	}
	else{
		ListItr iter = source.last();
		while(iter.isPastBeginning() == false){
			cout<< iter.retrieve();
			iter.moveBackward();
		}
	}
}
