#include <iostream>
#include <string>
#include "../ArrayStack/ArrayStack.hpp"


/************************************************************************/
/* evaluate postfix style expression, make sure the expression is valid.*/
/************************************************************************/

double evaluatePostfixExpression(const std::string& expression)
{
	ArrayStack<double> arrayStack;

	for (int i = 0; i < expression.size(); ++i)
	{
		char ch = expression.at(i);
		
		if (isdigit(ch))
		{
			arrayStack.push(ch);
		}
		else if (isspace(ch))
		{
			;
		}
		else if (
			ch == '+' || 
			ch == '-' || 
			ch == '*' || 
			ch == '/')
		{
			try
			{
				char v2 = arrayStack.top();
				arrayStack.pop();
				char v1 = arrayStack.top();
				arrayStack.pop();

				

				switch (ch)
				{
					case '+':
					{
						
					}break;

					case '-':
					{

					}break;

					case '*':
					{

					}break;

					case '/':
					{

					}break;

					default:
						break;
				}


			}
			catch (std::underflow_error& e)
			{
				std::cerr << "postfix expression error" << std::endl;
				return 0.0;
			}
		}

	}


}


int main()
{
    std::cout << "Hello World!\n";
}
