// REESE ALLEN / rga2uz / 10-05-20 / TreeCalc.cpp

#include "TreeCalc.h"
#include <iostream>

using namespace std;

// Constructor
TreeCalc::TreeCalc() {
    stack<TreeNode*> expressionStack;
}

// Destructor - frees memory
TreeCalc::~TreeCalc() {
    if (expressionStack.size() != 0){ // if(tree)
        cleanTree(expressionStack.top());
    }
}

// Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* tree) {
    if(tree){
        cleanTree(tree->left);
        cleanTree(tree->right);
        delete tree;
    }
}

// Gets data from user
// DO NOT MODIFY
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*'
            || response[0] == '-' || response[0] == '+') {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

// Puts value in tree stack
// if val is an operand, one-node tree (no children) created and its pointer is pushed to the stack
// if val is an operator, the pointers to the 2 trees are popped, new tree w/ root operator created ...
// ... left and right children become the previous 2 trees and its pointer is pushed to the stack 
void TreeCalc::insert(const string& val) {
    TreeNode* newNode = new TreeNode(val); // newNode is a pointer to an empty tree 
    if (val == "/" || val == "*" || val == "-" || val == "+"){
        TreeNode* right = expressionStack.top();
        expressionStack.pop();
        newNode->right = right;
        TreeNode* left = expressionStack.top();
        expressionStack.pop();
        newNode->left = left;
    }
    expressionStack.push(newNode);
}



// Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* tree) const {
    // print the tree in prefix format
    cout << tree->value << " ";
    if(tree->left != NULL){
        printPrefix(tree->left);
    }
    if(tree->right != NULL){
        printPrefix(tree->right);
    }
}


// Prints data in infix form
void TreeCalc::printInfix(TreeNode* tree) const {
    // print tree in infix format with appropriate parenthesis
    if(tree->value != "?"){
        if (tree->value == "/" || tree->value == "*" || tree->value == "-" || tree->value == "+"){
            cout << "(";
        }
        if(tree->left != NULL){
            printInfix(tree->left);
            cout << " ";
        }
        cout << tree->value;
        if (tree->value == "/" || tree->value == "*" || tree->value == "-" || tree->value == "+"){
            cout << " ";
        }
        if(tree->right != NULL){
            printInfix(tree->right);
        }
        if (tree->value == "/" || tree->value == "*" || tree->value == "-" || tree->value == "+"){
            cout << ")";
        }
    }
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* tree) const {
    if(tree->left != NULL){
        printPostfix(tree->left);
    }
    if(tree->right != NULL){
        printPostfix(tree->right);
    }
    cout << tree->value << " ";
}

// Prints tree in all 3 (post, in, pre) forms
// DO NOT MODIFY
void TreeCalc::printOutput() const {
    if (expressionStack.size() != 0 && expressionStack.top() != NULL) {
        TreeNode* tree = expressionStack.top();
        cout << "Expression tree in postfix expression: ";
        printPostfix(tree);
        cout << endl;

        cout << "Expression tree in infix expression: ";
        printInfix(tree);
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        printPrefix(tree);
        cout << endl;
    } else {
        cout << "Size is 0." << endl;
    }
}

// Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* tree) const {
    if(tree->value == "/"){
        return calculate(tree->left) / calculate(tree->right);
    }
    if(tree->value == "*"){
        return calculate(tree->left) * calculate(tree->right);
    }
    if(tree->value == "-"){
        return calculate(tree->left) - calculate(tree->right);
    }
    if(tree->value == "+"){
        return calculate(tree->left) + calculate(tree->right);
    }

    else{
        string n = tree->value;
        return atoi(n.c_str());
    }
}


// Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    int i  = calculate(expressionStack.top());
    return i;
    cleanTree(expressionStack.top());
    expressionStack.pop();
}