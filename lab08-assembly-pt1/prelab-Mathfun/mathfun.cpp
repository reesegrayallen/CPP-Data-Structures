//	REESE ALLEN | rga2uz | mathfun.cpp | 10-26-20

#include <iostream>
#include <cstdlib>

using namespace std;

extern "C" {
	int product(int, int);
	int power(int, int);
}

int main(){
	int x;
	int y;

	cout << "Enter integer 1: ";
	cin >> x;

	cout << "Enter integer 2: ";
	cin >> y;


	int pro = product(x, y);
	int pwr = power(x, y);

	cout << "Product: " << pro << endl;
	cout << "Power: " << pwr << endl;

	return 0;
}
