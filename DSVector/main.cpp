#include "DSVector.hpp"

int main()
{
	DSVector<int> icsv;
	icsv.size();
	std::cout << icsv.size() << "\n" << icsv.capacity() << "\n";
	icsv.push_back(10);
	std::cout << icsv << std::endl;

	//DSVector<int> newDSV = icsv;
	//std::cout << newDSV << std::endl;
}