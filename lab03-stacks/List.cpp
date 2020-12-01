/*
Reese Allen (rga2uz)
List.cpp
09-23-20
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
	if(count == 0){
		return true;
	}
	else{
		return false;
	}
}


void List::makeEmpty(){
	ListItr position = first();
	ListNode * newNode = position.current;
	while(position.isPastEnd() == false){
		newNode = position.current->next;
		delete(position.current);
		position.current = newNode;
	}
	head->next = tail;
	tail->previous = head;
	count = 0;
}


ListItr List::first(){
	return ListItr(head->next);
}


ListItr List::last(){
	return ListItr(tail->previous);
}


void List::insertAfter(int x, ListItr position){
	ListNode * newNode = new ListNode();
	newNode->value = x;
	position.current->next->previous = newNode;
	newNode->next = position.current -> next;
	newNode->previous = position.current;
	position.current->next = newNode;
	count++;
}


void List::insertBefore(int x, ListItr position){
	ListNode * newNode = new ListNode();
	newNode->value = x;
	position.current->previous->next = newNode;
	newNode->previous = position.current->previous;
	newNode->next = position.current;
	position.current->previous = newNode;
	count++;
}


void List::insertAtTail(int x){
	ListNode * newNode = new ListNode();
	newNode->value = x;
	newNode->next = tail;
	newNode->previous = tail->previous;
	tail->previous->next = newNode;
	tail->previous = newNode;
	count++;
}


ListItr List::find(int x){
	ListItr iter = first();
	while(iter.isPastEnd() == false){
		if(iter.current->value == x){
			return iter;
		}
		else{
			iter.moveForward();
		}
	}
	return iter;
}


void List::remove(int x){
	ListItr iter = find(x);
	if(iter.current == tail){
		return;
	}
	else{
		iter.current->previous->next = iter.current->next;
		iter.current->next->previous = iter.current->previous;
		delete iter.current;
		count --;
	}
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