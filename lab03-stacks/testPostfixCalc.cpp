/*
Reese Allen (rga2uz)
testPostfixCalc.cpp
09-21-2020
*/

#include "postfixCalculator.h"
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>

using namespace std;

int main(){

	postfixCalculator pCalc;

	string token;

	while (cin >> token){
		cout << token << endl;

		if(token == "-"){
			pCalc.subtraction();
		}
		else if(token == "+"){
			pCalc.addition();
		}
		else if(token == "/"){
			pCalc.division();
		}
		else if(token == "*"){
			pCalc.multiplication();
		}
		else if(token == "~"){
			pCalc.negation();
		}
		else{
			pCalc.pushValue(std::stoi(token));
		}
	}

		cout << pCalc.getTop() << endl;

		return 0;

}

 


