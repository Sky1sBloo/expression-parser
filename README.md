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

## Building
1. Create build directory
```
mkdir build
cd build
```
2. Create CMakeFiles
```
cmake ../
```
3. Build the Project
```
make
```

## Testing
**Method 1 - Use ctest**  
1. Move to your CMakeFiles directory
```
// In this example we used /build
cd build
```
2. Run ctest
```
ctest
```
**Method 2 - Run tests manually**  
1. Move to your CMakeFiles directory
```
// In this example we used /build
cd build
```
2. Move to the tests folder
```
cd tests
```
3. Run the `EvalParserTests`
```
./EvalParserTests
```
