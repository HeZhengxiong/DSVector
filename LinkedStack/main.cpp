#include <iostream>
#include "LinkedStack.hpp"

int main()
{
	LinkedStack<int> linkedStack;
	linkedStack.push(12);
	linkedStack.push(13);

	std::cout << linkedStack << std::endl;

	linkedStack.pop();

	std::cout << linkedStack << std::endl;
}
