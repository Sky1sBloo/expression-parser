#include "evalparser.hpp"
#include <stack>
#include <vector>
#include <cmath>

/**
 * Returns operator precedence, the higher value, the higher the precedence
 */
int precedenceOfOperator(char op)
{
	switch (op)
	{
		case '^':
			return 4;
		case '*':
		case '/':
			return 3;
		case '+':
		case '-':
			return 2;
		case '(':
		case ')':
			return 1;
		default:
			return 0;
	}
}

/**
 * Evaluates if character is an existing operator
 */
bool isOperator(char value)
{
	switch (value)
	{
		case '*':
		case '/':
		case '+':
		case '-':
		case '(':
		case ')':
		case '^':
			return true;
		default:
			return false;
	}
}

/**
 * Converts the expression to an easily parsable string
 */
std::vector<std::string> convertToPostfix(const std::string& expression)
{
	std::stack<char> operators;
	std::vector<std::string> postFix;
	bool prevIsNumber = false;
	operators.push('#');
	for (char c : expression)
	{
		if (c == ' ') continue;
		if (!isOperator(c))
		{
			if (prevIsNumber)
				postFix.back() += std::string(1, c);
			else
				postFix.push_back(std::string(1, c));

			prevIsNumber = true;
		}
		else
		{
			prevIsNumber = false;

			if (c == '(')
				operators.push(c);
			else if (c == ')')
			{
				while (operators.top() != '(')
				{
					char operatorChar = operators.top();
					std::string operatorStr = std::string(1, operatorChar);
					operators.pop();
					postFix.push_back(operatorStr);
				}
				operators.pop();
			}
			else if (isOperator(c))
			{
				if (precedenceOfOperator(c) > precedenceOfOperator(operators.top()))
					operators.push(c);
				else
				{
					while (precedenceOfOperator(c) <= precedenceOfOperator(operators.top()))
					{
						char operatorChar = operators.top();
						std::string operatorStr = std::string(1, operatorChar);
						operators.pop();
						postFix.push_back(operatorStr);
					}
					operators.push(c);
				}
			}
		}
	}

	while (operators.top() != '#')
	{
		char operatorChar = operators.top();
		std::string operatorStr = std::string(1, operatorChar);
		operators.pop();
		postFix.push_back(operatorStr);
	}
	return postFix;
}

/**
 * Calculate the expression that is in postfix notation
 */
float calculatePostfix(const std::vector<std::string>& postFix)
{
	std::stack<float> numStack;

	for (std::string value : postFix)
	{
		char arOperator = value[0];  // For checking if character is an operator
		if (isOperator(arOperator))
		{
			// Only took 1 number since exponent only requires 1 digit
			float secondNumber = numStack.top();
			numStack.pop();
			float firstNumber = numStack.top();
			numStack.pop();

			switch (arOperator)
			{
				case '+':
					numStack.push(firstNumber + secondNumber);
					break;
				case '-':
					numStack.push(firstNumber - secondNumber);
					break;
				case '*':
					numStack.push(firstNumber * secondNumber);
					break;
				case '/':
					numStack.push(firstNumber / secondNumber);
					break;
				case '^':
					numStack.push(std::pow(firstNumber, secondNumber));
					break;
			}
		}
		else
		{
			numStack.push(std::stof(value));
		}
	}

	return numStack.top();
}

/**
 * Evaluates the expression
 *
 * @param expression String representaiton of the arithmetic operation
 *
 * @return Answer of the expression
 */
float evaluate(const std::string& expression)
{
	std::vector<std::string> postFix = convertToPostfix(expression);
	return calculatePostfix(postFix);
}
