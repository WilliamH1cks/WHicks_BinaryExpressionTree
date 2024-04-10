#pragma once
//#pragma warning
#include "binaryExpressionTree.h"

//using namespace std;

void binaryExpressionTree::buildExpressionTree(string input)
{
	//cout << "The output is: " << input << endl;
	char* expression = new char[input.length() + 1];
	strcpy_s(expression, input.length() + 1, input.c_str());

	for (int i = 0; i < sizeof(expression); i++)
	{
		string currentNumber = "";
		char token = expression[i];

	}

}

double binaryExpressionTree::evaluateExpressionTree()
{
	return evaluateExpressionTree(root);
}

//Private version
double binaryExpressionTree::evaluateExpressionTree(nodeType<std::string>* term)
{
	return 1.0;
}

bool binaryExpressionTree::search(const std::string& searchItem) const
{
	return false;
}

void binaryExpressionTree::insert(const std::string& insertItem)
{
}

void binaryExpressionTree::deleteNode(const std::string& deleteItem)
{
}

binaryExpressionTree::binaryExpressionTree(std::string input)
{
	buildExpressionTree(input);
}