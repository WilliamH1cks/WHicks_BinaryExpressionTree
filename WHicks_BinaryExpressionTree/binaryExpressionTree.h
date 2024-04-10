#pragma once

#include "binaryTree.h"
#include <stack>
#include <iostream>
using namespace std;

class binaryExpressionTree : public binaryTreeType<string>
{
public:
	void buildExpressionTree(string);
	double evaluateExpressionTree();
	bool search(const string& searchItem) const;
	void insert(const string& insertItem);
	void deleteNode(const string& deleteItem);

	//Default constructor
	binaryExpressionTree(string);

private:
	double evaluateExpressionTree(nodeType<string>*);
	stack<nodeType<string>*> ptrStack;
};

