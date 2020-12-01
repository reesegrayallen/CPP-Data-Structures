#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#include "List.h"
#include "ListItr.h"

ListItr::ListItr(){}

ListItr::ListItr(ListNode *theNode){}

bool ListItr::isPastEnd() const{
    return true;
}

bool ListItr::isPastBeginning() const{
    return true;
}

void ListItr::moveForward(){

}

void ListItr::moveBackward(){

}

int ListItr::retrieve() const{
    return 0;
}
