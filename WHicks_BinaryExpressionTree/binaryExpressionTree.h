#pragma once

#include "binaryTree.h"
#include <stack>
#include <iostream>
#include <cmath>
using namespace std;

class binaryExpressionTree : public binaryTreeType<string>
{
public:

	//Precond: A string of a postfix expression is fed in
	//Postcond: The expression is convetred into a binary tree
	void buildExpressionTree(string);

	//Precond: The binary expression tree is formed
	//Postcond: The entire binary tree is evaluated to a number.
	double evaluateExpressionTree();

	bool search(const string& searchItem) const;
	void insert(const string& insertItem);
	void deleteNode(const string& deleteItem);

	//Default constructor
	binaryExpressionTree(string);

private:
	//Precond: A binary tree's root is inputted (includes segments of a larger tree)
	//Postcond: The tree/segment's expression is evaluated to a number.
	double evaluateExpressionTree(nodeType<string>*);

	stack<nodeType<string>*> ptrStack;
};

