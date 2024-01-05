# Expression Parser
A basic parser based on [tutorialspoint](https://www.tutorialspoint.com/data_structures_algorithms/expression_parsing.htm) that supports multidigit values.

## Usage
```
#include <iostream>
#include <evaluate_parser>

int main()
{
  std::cout << evaluate("1 + (2 - 5^2) * 3") << std::endl;
}
```
**float evaluate(const std::string& expression)**  
Evaluates an arithmetic expression.
> See cpp file isOperator() for list of operators
