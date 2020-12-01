// REESE ALLEN | rga2uz | 11-19-20 | puzzle.cpp

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>
#include <algorithm>


using namespace std;

/**
 * @method print 
 * @brief prints the current state of the puzzle as a string
 */
void printNode(string node){
	cout << node;
}

/**
 * @method swapHole 
 * @brief Swaps the position of two characters in a string
 * @details Used in generating neighbors. Swaps the location of one number with another number 
 * in the representation of a 8-puzzle table, subsequently returning a new state of the puzzle
 *
 * @param node The string representation of the puzzle
 * @param x The index of the first number in the string to swap
 * @param y The index of the second number in the string to swap
 */
string swapHole(string node, int x, int y){
	string newNode(node);
	newNode[x] = node[y];
	newNode[y] = node[x];
	return newNode;
}

/**
 * @method generatingNeighbors
 * @brief Generates list containing the neighbors of one state of the puzzle
 * @details Given a string representation of an 8-puzzle, creates a vector of nodes, or 
 * other string representations, for all the possible inversions, based on the position of the hole
 *
 * @param curNode The string representing the 8-puzzle state for which to generate neighbors 
 * @return vector<string> A vector of all possible immediate states from inverting
 */
vector<string> generatingNeighbors(string curNode){

	vector<string> neighbors;
	string neigbhborNode = "";

	// locate where the "hole" is 
	int pos = curNode.find('0'); 	//string index (between 0 and 8)

	// tried 4 conditions from lecture intially 
	switch(pos){

		case 0:
		neigbhborNode = swapHole(curNode, pos, 1);
		neighbors.push_back(neigbhborNode);
		neigbhborNode = swapHole(curNode, pos, 3);
		neighbors.push_back(neigbhborNode);
		break;

		case 1:
		neigbhborNode = swapHole(curNode, pos, 0);
		neighbors.push_back(neigbhborNode);
		neigbhborNode = swapHole(curNode, pos, 2);
		neighbors.push_back(neigbhborNode);
		neigbhborNode = swapHole(curNode, pos, 4);
		neighbors.push_back(neigbhborNode);
		break;

		case 2:
		neigbhborNode = swapHole(curNode, pos, 1);
		neighbors.push_back(neigbhborNode);
		neigbhborNode = swapHole(curNode, pos, 5);
		neighbors.push_back(neigbhborNode);
		break;

		case 3:
		neigbhborNode = swapHole(curNode, pos, 0);
		neighbors.push_back(neigbhborNode);
		neigbhborNode = swapHole(curNode, pos, 4);
		neighbors.push_back(neigbhborNode);
		neigbhborNode = swapHole(curNode, pos, 6);
		neighbors.push_back(neigbhborNode);
		break;

		case 4:
		neigbhborNode = swapHole(curNode, pos, 1);
		neighbors.push_back(neigbhborNode);
		neigbhborNode = swapHole(curNode, pos, 3);
		neighbors.push_back(neigbhborNode);
		neigbhborNode = swapHole(curNode, pos, 5);
		neighbors.push_back(neigbhborNode);
		neigbhborNode = swapHole(curNode, pos, 7);
		neighbors.push_back(neigbhborNode);
		break;

		case 5:
		neigbhborNode = swapHole(curNode, pos, 2);
		neighbors.push_back(neigbhborNode);
		neigbhborNode = swapHole(curNode, pos, 4);
		neighbors.push_back(neigbhborNode);
		neigbhborNode = swapHole(curNode, pos, 8);
		neighbors.push_back(neigbhborNode);
		break;

		case 6:
		neigbhborNode = swapHole(curNode, pos, 3);
		neighbors.push_back(neigbhborNode);
		neigbhborNode = swapHole(curNode, pos, 7);
		neighbors.push_back(neigbhborNode);
		break;

		case 7:
		neigbhborNode = swapHole(curNode, pos, 6);
		neighbors.push_back(neigbhborNode);
		neigbhborNode = swapHole(curNode, pos, 4);
		neighbors.push_back(neigbhborNode);
		neigbhborNode = swapHole(curNode, pos, 8);
		neighbors.push_back(neigbhborNode);
		break;

		case 8:
		neigbhborNode = swapHole(curNode, pos, 5);
		neighbors.push_back(neigbhborNode);
		neigbhborNode = swapHole(curNode, pos, 7);
		neighbors.push_back(neigbhborNode);
		break;

	}

	return neighbors;
}



/**
 * @method bfs
 * @brief Performs a breadth-first search to determine min number of inversions 
 * required to reach the end state of an 8-puzzle
 *
 * @param node A representation of the puzzle
 * @return void
 */ 
void bfs(string node){
	// impossible to solve if gone through all inversions and queue is empty (or if # inversions is odd)
	unordered_map<string, int> dist;
	vector<string> neighbors;
	queue<string> q;
	q.push(node);
	dist[node] = 0;
	bool found = false;

	while(q.size() > 0){
		string curNode = q.front();
		q.pop();
		// cout << curNode << " --- " << dist[curNode] << "\n";
		neighbors = generatingNeighbors(curNode);
		if(curNode.compare("123456780") == 0){
			// cout << "here\n";
			cout << dist[curNode] << endl;
			found = true;
			break;
		}

		for(int i =0; i < neighbors.size(); i++){
			if(dist.count(neighbors[i]) == 0){
				q.push(neighbors[i]);
				dist[neighbors[i]] = dist[curNode] + 1;
			}
		}

	}
	if(!found){cout << "IMPOSSIBLE" << endl;}


}

int main(){

	/* TAKE INPUT */

	int numbers[9]; // 1D array for initial state 

	cout << "Enter a puzzle" << endl;

	for(int i = 0; i < 9; i++){  // std::cin ignores spaces
		cin >> numbers[i];
	}


	cout << "Solving puzzle" << endl;

	string str = "";

	for(int i =0; i < 9; i++){
		str += to_string(numbers[i]);
	}

	bfs(str);

	// impossible to solve if gone through all inversions and queue is empty

	return 0;
}
