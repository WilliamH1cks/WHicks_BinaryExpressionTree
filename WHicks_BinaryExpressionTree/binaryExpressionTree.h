#pragma once

#include "binaryTree.h"
#include <stack>
//#include <iostream>
using namespace std;

class binaryExpressionTree : public binaryTreeType<string>
{
public:
	void buildExpressionTree(string);
	double evaluateExpressionTree();
	//bool search(const string&);
	//void insert(const string&);
	//void deleteNode(const string&);

	//Default constructor
	binaryExpressionTree(string);

private:
	double evaluateExpressionTree(nodeType<string>*);
	stack<nodeType<string>*> ptrStack;
};

