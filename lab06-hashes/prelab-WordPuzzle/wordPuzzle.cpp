// REESE ALLEN / rga2uz / WordPuzzle.cpp / 10-12-20

#include <iostream>

#include <string>

#include <fstream>

#include "hashTable.h"

#include "timer.h"

using namespace std;

char grid[500][500];

bool checkPrime(unsigned int p);
int getNextPrime (unsigned int n);

bool readInGrid (string filename, int &rows, int &cols);
char* getWordInGrid (int startRow, int startCol, int dir, int len, int numRows, int numCols);
int numLines (string s);


int main(int argc, char** argv){
	if(argc != 3){
		cout << "Error: Inappropriate number of command-line parameters." << endl;
		exit(-1);
	}

	string dictionary = argv[1];
    HashTable wordSearch(getNextPrime(numLines(dictionary)));

    string data;
    string key;

    ifstream file(dictionary);
    while(getline(file, data)){
    	key = data;
    	wordSearch.insert(key);
    }

    int rows;
    int cols;

    bool read = readInGrid(argv[2], rows, cols);

    string cardinal [8]= {"N", "NE", "E", "SE", "S", "SW", "W", "NW"};
    int position = 0;

    for(int i = 0; i < rows; i ++){
    	for(int j = 0; j < cols; j++){
    		for(int k = 0; k < 8; k ++){
    			for(int l = 3; l < 22; l++){
    				string coll = getWordInGrid(i, j, k, l, rows, cols);
    				if(wordSearch.contains(coll)){
    					position += 1;
    					cout << cardinal[k] << " " << "(" << i << ", " << j << "): " << coll << endl;
    				}
    				if(getWordInGrid(i, j, k, l+1, rows, cols) == coll){
    					break;
    				}
    			}
    		}
    	}
    }

    cout << position << " words found" << endl;

    return 0;
}

bool checkPrime(unsigned int p) {
	if(p <= 1){
		return false;
	}
	if(p == 2){
		return true;
	}
	if(p % 2 == 0){
		return false;
	}
	for(int i = 3; i*i <= p; i += 2){
		if(p % i == 0){
			return false;
		}
	}
	return true;
}

int getNextPrime(unsigned int n){
	while(!checkPrime(++n));
	return n;
}

bool readInGrid(string filename, int& rows, int& cols) {
	string data;

    ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    file >> rows;
    getline(file, data);

    file >> cols;
    getline(file, data);

    getline(file, data);

    file.close();

    int position = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[position++];
        }
    }
    return true;
}

char* getWordInGrid (int startRow, int startCol, int dir, int len, int numRows, int numCols) {

	static char output[256];

	int position = 0;
    int r = startRow;
    int c = startCol;

    for (int i = 0; i < len; i++) {
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
            break;
        }
        output[position++] = grid[r][c];
        switch (dir) { 
            case 0:
                r--;
                break; // N
            case 1:
                r--;
                c++;
                break; // NE
            case 2:
                c++;
                break; // E
            case 3:
                r++;
                c++;
                break; // SE
            case 4:
                r++;
                break; // S
            case 5:
                r++;
                c--;
                break; // SW
            case 6:
                c--;
                break; // W
            case 7:
                r--;
                c--;
                break; // NW
        }
    }
    output[position] = 0;
    return output;
}

int numLines (string s){
	int n = 0;
	ifstream file(s);
	string t;
	while(getline(file, t)){
		n++;
	}
	file.close();
	return n;
}
