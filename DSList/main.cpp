#include "DSList.hpp"
#include <iostream>


int main()
{
	DSList<int> dslist;

	dslist.push_back(5);
	auto iter = dslist.begin();

	std::cout << dslist << std::endl;

}


