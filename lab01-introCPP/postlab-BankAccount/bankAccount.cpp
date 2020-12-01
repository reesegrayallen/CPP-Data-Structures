/*
Reese Allen (rga2uz)
bankAccount.cpp
09-10-20
 */

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <iomanip>

#include "bankAccount.h"

using namespace std;


bankAccount::bankAccount(){
    balance = 0.00;
}

bankAccount::bankAccount(double amount){
    balance = amount;
}

bankAccount::~bankAccount(){}

double bankAccount::withdraw(double amount){
    if(amount > balance)
        return balance; 
    else 
        balance -= amount; 
        return balance;
}

double bankAccount::deposit(double amount){
    balance += amount;
    return balance;
}

double bankAccount::getBalance(){
    return balance; 
}



