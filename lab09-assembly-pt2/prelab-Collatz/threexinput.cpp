// REESE ALLEN | rga2uz | threexinput.cpp | 11-01-20

#include <iostream>

#include "timer.h"


using namespace std;

extern "C" int threexplusone(int x);

int main() {

	int x, n;

	cout << "Enter a number: ";
	cin >> x;

	cout << "Enter iterations of subroutine: ";
	cin >> n;

	int steps = threexplusone(x);

	timer t;
	t.start();
	while(n > 0){
		threexplusone(x);
		n--; 
	}
	t.stop();


	cout << "Steps: " << steps << endl;

}