/* 
xToN.cpp
Reese Allen (rga2uz)
CS 2150 Pre-Lab1 09-07-20
 */

#include <iostream>
using namespace std;

int xToN (int x, int n){
  if (n==0)
    return 1;
  else
    return (x * xToN(x, n-1));
}

int main(){
  int a, b;
  cin >> a;
  cin >> b;
  cout << xToN(a, b) << endl;
  return 0; 
}
