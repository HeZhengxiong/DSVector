#include "ArrayStack.hpp"
#include <iostream>

int main()
{
	ArrayStack<int> intStack;
	intStack.push(12);
	intStack.push(13);

	std::cout << intStack << std::endl;

	intStack.pop();
	
	std::cout << intStack << std::endl;
}
