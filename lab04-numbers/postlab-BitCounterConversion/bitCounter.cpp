/*
REESE ALLEN / rga2uz / bitCounter.cpp / 10-01-2020
*/

#include <iostream>

#include <cstdlib>

#include <string>

#include <algorithm> // reverse()

using namespace std;

// number of 1s in the binary representation (two's complement) of n 
int bitCount(int n);

// conversion from given start base to base 10
int toBaseTen(string str, int base);

// conversion from base 10 to given end base
string toBaseEnd(int n, int base);


// assuming n is non-negative base 10
int bitCount(int n){
	if(n == 1){
		return 1;
	}
	if (n > 1){
		return (n%2) + bitCount(n/2);
	}
	return 0; // 0 has 0 bits 
}


// assumes non-negative input
int toBaseTen(string str, int base){
	int converted = 0;
	int pow = 1;
	int i;

	for(i = (str.length()) - 1; i>= 0; i--){
		char c = str[i];
		if(c <= '9'){
			c -= '0';
		}
		else{
			c -= 55;
		}
		converted += c * pow;
		pow = pow * base;
	}
	return converted;
}


string toBaseEnd(int n, int base){
	string converted;

	while(n > 0){
		char c = n % base;
	if(c < 10){
		c += '0';
	}else{
		c += 55;
	}
	converted += c;
	n /= base;
	}

	reverse(converted.begin(), converted.end()); // replaces iterative reversal
	return converted;
}


int main(int argc, char **argv){
	if(argc != 5){
		cout << "Error: inappropriate number of command-line parameters" << endl;
		exit(-1);

	}else{

		int n = atoi(argv[1]);  // bitcout number
		string strnum = argv[2];  // number to convert
		int b1 = stoi(argv[3]);  // start base
		int b2 = stoi(argv[4]);  // end base 

		cout << n << " has " << bitCount(n) << " bit(s)" << endl;

		if(b1 == 10 && b2 != 1){
			cout << strnum << " (base 10) = " << toBaseEnd(stoi(strnum), b2) << " (base " << b2 << ")" << endl;
			return 0;
		}

		if (b2 == 10){
			cout << strnum << " (base " << b1 << ")" << " = " << toBaseTen(strnum, b1) << " (base 10)" << endl;
			return 0;

		}

		if(b2 == 1){
			int start = toBaseTen(strnum, b1);
			cout << strnum << " (base " << b1 << ")" << " = ";
			for(int i = 0; i < start; i++){
				cout << 1;
			}
			cout << " (base 1)" << endl;

		}else{
			int start = toBaseTen(strnum, b1);
			string end = toBaseEnd(start, b2);
			cout << strnum << " (base " << b1 << ")" << " = " << end << " (base " << b2 << ")" << endl;
		}

	}
	return 0;
}
