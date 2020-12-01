// REESE ALLEN | rga2uz | 11-14-20 | huffmanNode.h

#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <iostream>
#include <string>

using namespace std;

class huffmanNode {

public:

	huffmanNode();

	huffmanNode* left;
	huffmanNode* right;

	char character;
	int frequency;
	string prefix;
};

#endif 