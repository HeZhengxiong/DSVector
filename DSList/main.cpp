#include "DSList.hpp"
#include <iostream>


int main()
{
	DSList<int> dslist;

	dslist.push_back(5);

	std::cout << dslist << std::endl;

}


