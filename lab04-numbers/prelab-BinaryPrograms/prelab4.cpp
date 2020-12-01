/*
Reese Allen (rga2uz)
prelab4.cpp
09-26-20
*/

#include <iostream>
#include <string>
#include <climits>
#include <cstdlib>

using namespace std;


void sizeOfTest();
void overflow();
void outputBinary(unsigned int x);


void sizeOfTest(){

	cout << "Size of int: " << sizeof(int) << endl;
	cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
	cout << "Size of float: " << sizeof(float) << endl;
	cout << "Size of double: " << sizeof(double) << endl;
	cout << "Size of char: " << sizeof(char) << endl;
	cout << "Size of bool: " << sizeof(bool) << endl;
	cout << "Size of int*: " << sizeof(int*) << endl;
	cout << "Size of char*: " << sizeof(char*) << endl;
	cout << "Size of double*: " << sizeof(double*) << endl;

}


void overflow(){

	unsigned int x = UINT_MAX + 1;
	cout << INT_MAX << " + 1 = " << x << endl;

}


void outputBinary(unsigned int x){

	string binary = "";

	for(int i = 31; i >= 0; i--){
		if(x & (1 << i)){
			binary += "1";
		}
		else{
			binary += "0";
		}
		if(i%4 == 0){
			binary += " ";
		}
	}
	cout << binary << endl;

}


int main(){
	int n;
	cin >> n;
	sizeOfTest();
	overflow();
	outputBinary(n);
	return 0;
}
