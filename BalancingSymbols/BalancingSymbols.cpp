#include "../ArrayStack/ArrayStack.hpp"

#include <fstream>
#include <string>

/************************************************************************/
/* Check whether parentheses brackets braces are paired.
*/
/************************************************************************/

bool balancingSymbols(const std::string& contents)
{
	ArrayStack<int> arrayStack;

	for (int i = 0; i < contents.size(); ++i)
	{
		if (contents[i] == '(' ||
			contents[i] == '[' ||
			contents[i] == '{') 
		{
			arrayStack.push(contents[i]);
		}
		else if (contents[i] == ')')
		{
			if (arrayStack.isEmpty())
				return false;
			char currentTopChar = arrayStack.top();
			if (currentTopChar == '(')
				arrayStack.pop();
			else
				return false;
		}
		else if (contents[i] == ']')
		{
			if (arrayStack.isEmpty())
				return false;
			char currentTopChar = arrayStack.top();
			if (currentTopChar == '[')
				arrayStack.pop();
			else
				return false;
		}
		else if (contents[i] == '}')
		{
			if (arrayStack.isEmpty())
				return false;
			char currentTopChar = arrayStack.top();
			if (currentTopChar == '{')
				arrayStack.pop();
			else
				return false;
		}
	}

	if (arrayStack.isEmpty())
		return true;
	else
		return false;
}


int main(int argc, char** argv)
{
	if (argc != 2)
		std::cerr << "Usage: BalancingSymbols.exe filename" << std::endl;

	std::string  filecontent;
	std::ifstream fis(argv[1]);
	if (fis.is_open())
	{
		char ch;
		while (fis >> ch)
		{
			filecontent.push_back(ch);
		}
		if (balancingSymbols(filecontent))
		{
			std::cout << "braces balancing." << std::endl;
		}
		else
			std::cout << "Some balancing error happed, Please check!" << std::endl;
	}
	else
	{
		std::cerr << "Open File Failed." << std::endl;
	}

	return 0;
}