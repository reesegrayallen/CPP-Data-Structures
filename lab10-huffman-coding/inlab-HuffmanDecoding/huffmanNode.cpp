// REESE ALLEN | rga2uz | 11-14-20 | huffmanNode.cpp

#include "huffmanNode.h"
#include <iostream>
#include <string>

using namespace std;

huffmanNode::huffmanNode(){
	character = '$';
	frequency = 0;
	left = NULL;
	right = NULL;
	prefix = "";
}