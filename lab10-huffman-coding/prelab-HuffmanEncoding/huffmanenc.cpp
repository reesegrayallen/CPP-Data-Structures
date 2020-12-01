// REESE ALLEN | rga2uz | 11-14-20 | huffmanec.cpp

// Implementation of Huffman encoding algorithm 

#include "heap.h"
#include "huffmanNode.h"

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void setFix(huffmanNode* node, string code);
void printCode(huffmanNode* node);

int main(int argc, char **argv){


    if (argc != 2) {
        cout << "Error: Inappropriate number of command-line parameters" << endl;
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if(fp==NULL){
    	cout << "Error: Unable to open '" << argv[1] << "'" << endl;
    	exit(2);
    }


    int arr[128]; // array of frequencies 

    for (int i = 0; i < 128; i++){
    	arr[i] = 0;					// initially all 0
    } 				



    char c;
    int total = 0;

    while ((c = fgetc(fp)) != EOF) { 	// read through characters 
        if( ((int) c < 128)  && ((int) c > 31)){
        	arr[(int) c]++;		// store frequencies of each character in array
        	total ++;
        } 
    }

    rewind(fp); 	// back to beginning of file 


    int symbols = 0;
    binary_heap aheap = binary_heap();

// storing character frequencies in heap
    for(int i = 1; i < 128; i++){
    	if (arr[i] > 0){  		
    		symbols++;
    		huffmanNode* node = new huffmanNode();
    		node->character = (char) i;
    		node->frequency = arr[i];
    		aheap.insert(node);
    	}
    }

    binary_heap bheap = binary_heap();
	bheap = aheap; 		// copy for bit printing

	while(aheap.get_size() > 1) {
		huffmanNode* left = aheap.deleteMin();
		huffmanNode* right = aheap.deleteMin();
		huffmanNode* parent = new huffmanNode();
		parent->left = left;
		parent->right = right;
		parent->character = '$';
		parent->frequency = (left->frequency) + (right->frequency);
		aheap.insert(parent);
	}


    setFix(aheap.findMin(), "");
    printCode(aheap.findMin());
    cout << "----------------------------------------" << endl;

    vector<huffmanNode*> vec = bheap.getHeap();

    int original = total * 8;
    int compressed = 0;

    while((c = fgetc(fp)) != EOF){
        for(int i = 1; i < vec.size(); i++){
            if(vec[i]->character == c){
                huffmanNode* node = new huffmanNode();
                node = vec[i];
                if(node != NULL){
                    cout << node->prefix << " ";
                    compressed += (node->prefix).size();
                }
            }
        }
    }


    cout << endl;

    fclose(fp);
    cout << "----------------------------------------" << endl;

    cout << "There are a total of " << total << " symbols that are encoded." << endl;
    cout << "There are " << symbols <<  " distinct symbols used." << endl;
    cout << "There were " << original << " bits in the original file." << endl;
    cout << "There were " << compressed << " bits in the compressed file." << endl;
    cout << "This gives a compression ratio of " << (float) original / compressed << "." << endl;
    cout << "The cost of the Huffman tree is "<< (float) compressed / total << " bits per character." << endl;



    return 0;
}


void printCode(huffmanNode* node){
	if(node->left == NULL && node->right == NULL){
		if(node->character == ' '){
			cout << "space " << node->prefix << endl;
		}else{ cout << node->character << " " << node->prefix << endl;}
	}
	if(node->left){
		printCode(node->left);
	}
	if(node->right){
		printCode(node->right);
	}
}

void setFix(huffmanNode* node, string code){
	if(node->left == NULL && node->right == NULL){
		node->prefix = code;
	}
	if(node->left){
		setFix(node->left, code + "0");
	}
	if(node->right){
		setFix(node->right, code + "1");
	}

}


