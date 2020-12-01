#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
using namespace std;

AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
    insert(root, x);
}

// // private insert
// void AVLTree::insert(AVLNode*& node, const string& x){
// 	if(node == NULL){
// 		AVLNode* newNode = new AVLNode();
// 		newNode->value = x;
// 		node = newNode;
// 	}if (x < node->value){
// 		insert(node->left, x);
// 	}if(x > node->value){
// 		insert(node->right, x);
// 	}
// }

// private insert
void AVLTree::insert(AVLNode*& node, const string& x) const{
	if(node == NULL){
		AVLNode* newNode = new AVLNode();
		newNode->value = x;
		node = newNode;
	}else if (x < node->value){
		insert(node->left, x);
		if(height(node->left) - height(node->right) == 2){
			if(x < node->left->value){
				rotateLeft(node);
			}else{
				rotateRight(node->left);
				rotateLeft(node);
			}
		}
	}else if(x > node->value){
		insert(node->right, x);
		if(height(node->right) - height(node->left) == 2){
			if(x > node->right->value){
				rotateRight(node);
			}else{
				rotateLeft(node->right);
				rotateRight(node);
			}
		}
	}
}

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
    root = remove(root, x);
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
    if(find(x)){
    	return pathTo(root, x);
    }
    return "";
}

// private pathTo
string AVLTree::pathTo(AVLNode* node, const string& x) const{
	if(node == NULL){
		return "";
	}
	if(node->value < x){
		return (node->value) + " " + pathTo(node->right, x);
	}
	if(node->value > x){
		return (node->value) + " " + pathTo(node->left, x);
	}
	return (node->value);
}

// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) const {
    return find(root, x);
}

// private find
bool AVLTree::find(AVLNode* node, const string& x) const{
    if(node==NULL){
        return false;
    }
    if(node->value == x){
        return true;
    }
    bool leftSide = find(node->left, x);
    if(leftSide){return true;}
    bool rightSide = find(node->right, x);
    return rightSide;
}

// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
    return numNodes(root);
}

// private numNodes
int AVLTree::numNodes(AVLNode* node) const{
    if(node == NULL){
        return 0; 
    }else{
        return 1 + numNodes(node->left) + numNodes(node->right);
    }
}

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
    // balance factor = height right subtree - height left subtree
    // balance factor(node) = height(node->left) - height(node-right)
}

// rotateLeft performs a single rotation on node n with its right child.
void AVLTree::rotateLeft(AVLNode*& n) const{
	AVLNode* newNode = new AVLNode();
	newNode = n->left;
	n->left = newNode->right;
	newNode->right = n;
	n->height = max(height(n->left), height(n->right)) + 1;
	newNode->height = max(height(newNode->left), height(newNode->right)) + 1;
	newNode = n;
}

// rotateRight performs a single rotation on node n with its left child.
void AVLTree::rotateRight(AVLNode*& n) const{
    AVLNode* newNode = new AVLNode();
    newNode = n->right;
    n->right = newNode->left;
    newNode->left = n;
    n->height = max(height(n->left), height(n->right)) + 1;
    newNode->height = max(height(newNode->right), height(newNode->right)) + 1;
    newNode = n;
}

// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);

    return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);

    delete trunk;
}

void AVLTree::printTree() {
    printTree(root, NULL, false);
}
