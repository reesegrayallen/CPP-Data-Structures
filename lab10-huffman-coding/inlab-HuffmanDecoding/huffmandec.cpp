// REESE ALLEN | rga2uz | 11-14-20 | huffmadec.cpp



// Some code taken from skeleton (for reading in)

#include "heap.h"
#include "huffmanNode.h"

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


using namespace std;

void buildTree2(huffmanNode* n, char c, string code);
string decode(huffmanNode* root, string code);

huffmanNode* root;

int main (int argc, char** argv) {
	root = new huffmanNode();
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    // read in the first section of the file: the prefix codes
    while (true) {

        string character, prefix;
        // read in the first token on the line
        file >> character;

        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

        // char g = character[0];
        char c = character[0];

        // read in the prefix code
        file >> prefix;

        buildTree2(root, c, prefix);

    }

    // read in the second section of the file: the encoded message
    stringstream sstm;
    while (true) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if (bits[0] == '-') {
            break;
        }
        // add it to the stringstream
        sstm << bits;
    }

    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    // close the file before exiting
    file.close();

    huffmanNode* node = root;

    string ans = decode(node, allbits);

    cout << ans << endl;

    return 0;


}



void buildTree2(huffmanNode* node, char c, string code){
	for(int i = 0; i < code.length()-1; i++){
		if(code[i] == '1'){
			if (node->right){
				node = node->right;
			}else{
				node->right = new huffmanNode();
				node = node->right;
			}
		}if(code[i] == '0'){
			if (node->left){
				node = node->left;
			}else{
				node->left = new huffmanNode();
				node = node->left;
			}
		}
	}
	if(code[code.length() - 1] == '1'){
		node->right = new huffmanNode();
		node->right->character = c;
	}else{
		node->left = new huffmanNode();
		node->left->character = c;
	}

}


string decode(huffmanNode* root, string code){
	string output = "";
	huffmanNode* current = root;
	for(int i = 0; i < code.length(); i++){
		if(code[i] == '0'){
			current = current->left;
		}else{current = current->right;}
		if(current->left == NULL && current->right == NULL){
			output += current->character;
			current = root;
		}
	}
	return output;

}
