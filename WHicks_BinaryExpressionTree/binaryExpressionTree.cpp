#pragma once
#include "binaryExpressionTree.h"
#include <string>

using namespace std;

void binaryExpressionTree::buildExpressionTree(string input)
{
	char* expression = new char[input.length() + 1];
	strcpy_s(expression, input.length() + 1, input.c_str());

	string currentTerm = "";

	for (int i = 0; i < input.length() + 1; i++)
	{
		char item = expression[i];

		if (isdigit(item))
		{
			currentTerm += item;
		}
		else if (item == '+' || item == '-' || item == '*' || item == '/')
		{
			nodeType<string>* newNode = new nodeType<string>;
			newNode->lLink = nullptr;
			newNode->rLink = nullptr;
			newNode->info = item;
			if (!ptrStack.empty())
			{
				newNode->rLink = ptrStack.top();
				ptrStack.pop();
				if (!ptrStack.empty())
				{
					newNode->lLink = ptrStack.top();
					ptrStack.pop();
					ptrStack.push(newNode);
				}
				else
				{
					cout << "Error: Empty Stack." << endl;
					return;
				}
			}
			else
			{
				cout << "Error: Empty Stack." << endl;
				return;
			}
		}
		else if (item == ' ')
		{
			if (currentTerm != "")
			{
				nodeType<string>* newNode = new nodeType<string>;
				newNode->info = currentTerm;
				newNode->lLink = nullptr;
				newNode->rLink = nullptr;
				ptrStack.push(newNode);
			}
			currentTerm = "";
		}
		else if (item != NULL)
		{
			cout << "Error: " << item << " not defined." << endl;
			return;
		}
		
	}
	if (!ptrStack.empty())
	{
		root = ptrStack.top();
		ptrStack.pop();
	}
	else
	{
		cout << "The stack is empty. Setting root to null." << endl;
		root = NULL;
	}
}

double binaryExpressionTree::evaluateExpressionTree()
{
	double result = evaluateExpressionTree(root);
	return result;
}

//Private version
double binaryExpressionTree::evaluateExpressionTree(nodeType<std::string>* term)
{
	if (term->lLink == nullptr && term->rLink == nullptr)
		return stod(term->info);
	else
	{
		double x = evaluateExpressionTree(term->lLink);
		double y = evaluateExpressionTree(term->rLink);
		string op = term->info;
		if (op == "+")
			return x + y;
		else if (op == "-")
			return x - y;
		else if (op == "*")
			return x * y;
		else if (op == "/")
			return x / y;
	}
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