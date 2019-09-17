#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include "../ArrayStack/ArrayStack.hpp"


/************************************************************************/
/* Evaluate postfix style expression, make sure the expression is valid.
   also this program is only for study, so simplify the case where operand
   and operators are separated with space.   
   */
/************************************************************************/

double evaluatePostfixExpression(const std::string& expression)
{
	ArrayStack<double> arrayStack;

	std::istringstream ism(expression);

	std::string sval;
	double dval;
	while (ism >>sval)
	{
		if (sval == "+")
		{
			double v1, v2;
			try
			{
				v2 = arrayStack.top();
				arrayStack.pop();
				v1 = arrayStack.top();
				arrayStack.pop();
			}
			catch (std::underflow_error&)
			{
				std::cerr << "expression error" << std::endl;
				exit(-1);
			}

			double v = v1 + v2;
			arrayStack.push(v);
		}
		else if (sval == "-")
		{
			double v1, v2;
			try
			{
				v2 = arrayStack.top();
				arrayStack.pop();
				v1 = arrayStack.top();
				arrayStack.pop();
			}
			catch (std::underflow_error&)
			{
				std::cerr << "expression error" << std::endl;
				exit(-1);
			}

			double v = v1 - v2;
			arrayStack.push(v);
		}
		else if (sval == "*")
		{
			double v1, v2;
			try
			{
				v2 = arrayStack.top();
				arrayStack.pop();
				v1 = arrayStack.top();
				arrayStack.pop();
			}
			catch (std::underflow_error&)
			{
				std::cerr << "expression error" << std::endl;
				exit(-1);
			}

			double v = v1 * v2;
			arrayStack.push(v);
		}
		else if (sval == "/")
		{
			double v1, v2;
			try
			{
				v2 = arrayStack.top();
				arrayStack.pop();
				v1 = arrayStack.top();
				arrayStack.pop();
			}
			catch (std::underflow_error&)
			{
				std::cerr << "expression error" << std::endl;
				exit(-1);
			}
			double v = v1 / v2;
			arrayStack.push(v);
		}
		else
		{
			try
			{
				dval = std::stod(sval);
			}
			catch (std::invalid_argument&)
			{
				std::cerr << "Argument error" << std::endl;
				exit(-1);
			}

			arrayStack.push(dval);
		}
	}
	
	if (arrayStack.isEmpty())
	{
		std::cout << "expression error" << std::endl;
		exit(-1);
	}
	else
	{
		double eval = arrayStack.top();
		arrayStack.pop();
		if (arrayStack.isEmpty())
		{
			return eval;
		}
		else
		{
			std::cout << "expression error" << std::endl;
			exit(-1);
		}
	}
}

double evaluatePrefixExpression(const std::string& prexpression)
{
	return 0.0;
}

/************************************************************************/
/* Function to convert infix to postfix
	Only for study, for simplicity, deal with the following scenario:
	1. the operands and operators of infix use space to separate
	2. infix expression only contains + - * / ()
*/
/************************************************************************/
void pushToString(std::string& postfixExpression, const std::string& sval)
{
	if (postfixExpression.empty())
	{
		postfixExpression += sval;
	}
	else
	{
		postfixExpression += " ";
		postfixExpression += sval;
	}
}

bool convertInfixToPostfix(const std::string& infixExpression, std::string& postfixExpression)
{
	ArrayStack<std::string> operatorStack;
	std::istringstream ism(infixExpression);
	std::string sval;

	while (ism >> sval)
	{
		if (("+" == sval) || ("-" == sval))
		{
			if (operatorStack.isEmpty() || operatorStack.top() == "(")
			{
				operatorStack.push(sval);
			}
			else  // + - lowest precedence so pop up till the stack is empty
			{
				while ((!operatorStack.isEmpty()) && 
					(operatorStack.top() != "("))
				{
					pushToString(postfixExpression, operatorStack.top());
					operatorStack.pop();
				}
				operatorStack.push(sval);
			}
		}
		else if (("*" == sval) || ("/" == sval))
		{
			if (operatorStack.isEmpty() || ("(" == operatorStack.top()))
			{
				operatorStack.push(sval);
			}
			else if ((operatorStack.top() == "+") || (operatorStack.top() == "-"))
			{
				operatorStack.push(sval);
			}
			else  // + - lowest precedence so pop up till the stack is empty
			{
				while ((!operatorStack.isEmpty()) &&
					(operatorStack.top() != "(")
					)
				{
					pushToString(postfixExpression, operatorStack.top());
					operatorStack.pop();
				}
				operatorStack.push(sval);
			}
		}
		else if ("(" == sval)
		{
			operatorStack.push(sval);
		}
		else if (")" == sval)
		{
			if (operatorStack.isEmpty())
			{
				return false;
			}
			else
			{
				while (operatorStack.top() != "(")
				{
					pushToString(postfixExpression, operatorStack.top());
					operatorStack.pop();
				}
				operatorStack.pop();	//pop "("
			}
		}
		else
		{
			pushToString(postfixExpression, sval);
		}
	}

	while (!operatorStack.isEmpty())
	{
		if (postfixExpression.empty())
			return false;

		postfixExpression += " ";
		postfixExpression += operatorStack.top();
		operatorStack.pop();
	}
	
	return true;
}

/************************************************************************/
/* Postfix to infix												  */
/************************************************************************/
bool isOperator(std::string ch)
{
	if (ch == "+" ||
		ch == "-" ||
		ch == "*" ||
		ch == "/" ||
		ch == "(" ||
		ch == ")" )
		return true;
	return false;
}

bool convertPostfixToInfix(const std::string& postfix, std::string& infix)
{
	std::stringstream ss(postfix);
	std::string word;
	ArrayStack<std::string> sstack;
	while (ss >> word)
	{
		if (isOperator(word))
		{
			try
			{
				std::string v2 = sstack.top();
				sstack.pop();
				std::string v1 = sstack.top();
				sstack.pop();
				
				std::string ret = v1 + " " + word + " " + v2;
				std::string v = std::string("( ") + ret + " )";
				sstack.push(v);
			}
			catch (std::underflow_error)
			{
				return false;
			}
		}
		else //it is a operand
		{
			sstack.push(word);
		}
	}
	
	if (sstack.isEmpty())
	{
		return false;
	}
	else
	{
		infix = sstack.top();
		sstack.pop();
		if (sstack.isEmpty())
		{
			return true;
		}
		else
			return false;
	}

}

bool convertPrefixToInfix(const std::string& prefix, std::string& infix)
{
	std::string reverseString = prefix;
	std::reverse(reverseString.begin(), reverseString.end());
	if (convertPostfixToInfix(reverseString, infix))
	{
		std::reverse(infix.begin(), infix.end());
		for (int i = 0; i < infix.size();++i)
		{
			if (infix[i] == '(')
				infix[i] = ')';
			else if (infix[i] == ')')
				infix[i] = '(';
		}
		return true;
	}
	return false;
}

bool convertPrefixToPostfix(const std::string prefix, std::string& postfix);

bool convertPostfixToPrefix(const std::string& postfix, std::string& prefix);


/************************************************************************/
/* Infix to Prefix: for simplicity: assume the operand and operator are separated with space
	also the 
*/
/************************************************************************/
bool convertInfixToPrefix(const std::string& infixExpression, std::string& prefixExpression)
{
	//first replace the ( with ) vice versa
	std::string reverseString = infixExpression;
	for (int i = 0; i < reverseString.size(); ++i)
	{
		if (reverseString[i] == '(')
			reverseString[i] = ')';
		else if (reverseString[i] == ')')
			reverseString[i] = '(';
	}
	std::reverse(reverseString.begin(), reverseString.end());
	std::string postFixString;
	
	if (convertInfixToPostfix(reverseString, postFixString))
	{
		std::reverse(postFixString.begin(), postFixString.end());
		prefixExpression = postFixString;
		return true;
	}
		
	return false;
}



int main()
{
	std::string postFixExpression1 = "4 5 6 * +";
	std::cout << "Evaluate expression of 456*+ is: " << evaluatePostfixExpression(postFixExpression1) << std::endl;

	std::string postFixExpression2 = "1 2 3 4 5 * + * + ";
	std::cout << "Evalute expression of 12345*+*+ is: " << evaluatePostfixExpression(postFixExpression2) << std::endl;

	std::string infix1 = "a + b * c + d";
	std::string postfix1;
	if (convertInfixToPostfix(infix1, postfix1))
	{
		std::cout << "Infix " << infix1 << " to postfix is: " << postfix1 << std::endl;
	}

	std::string infix2 = "2 * 3 / ( 2 - 1 ) + 3 * ( 4 - 1 )";
	std::string postfix2;
	if (convertInfixToPostfix(infix2,postfix2))
	{
		std::cout << "Infix " << infix2 << " to postfix is: " << postfix2 << std::endl;
		std::cout << "Evaluate expression of " << postfix2 << " is: " << evaluatePostfixExpression(postfix2) << std::endl;
	}

	std::string infix3 = "( a - b / c ) * ( a / k - l )";
	std::string prefix1;
	if (convertInfixToPrefix(infix3, prefix1))
	{
		std::cout << "Infix " << infix3 << " to prefix is: " << prefix1 << std::endl;
	}

	std::string postfix11 = "a b * c + ";
	std::string infix11;
	if (convertPostfixToInfix(postfix11, infix11))
	{
		std::cout << "Postfix " << postfix11 << " to infix is: " << infix11 << std::endl;
	}

	std::string prefix22 = "* - A / B C - / A K L";
	std::string infix22;
	if (convertPrefixToInfix(prefix22, infix22))
	{
		std::cout << "Prefix " << prefix22 << " to infix is: " << infix22 << std::endl;
	}
}
