/*
Reese Allen (rga2uz)
bankAccount.h
09-10-20
 */

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <iomanip>

using namespace std;


class bankAccount{
    public:
        bankAccount(); 
        bankAccount(double balance);
        ~bankAccount();

        double withdraw(double amount);
        double deposit(double amount);
        double getBalance();

    private:
    double balance; 
};

#endif 
