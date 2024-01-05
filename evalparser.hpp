#pragma once
#include <string>

// Based on https://www.tutorialspoint.com/data_structures_algorithms/expression_parsing.htm
/**
 * Evaluates an arithmetic expression 
 * See cpp file, isOperator() for list of operators
 *
 * @param expression Equation to be calculated
 * @return Answer of the expression
 */
float evaluate(const std::string& expression);
