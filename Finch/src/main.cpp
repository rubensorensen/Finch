#include <iostream>
#include "PVec.h"

int main() {
	PVec vec1(5, 32, 2.5);
	PVec vec2(10, 2, 5.3);

	std::cout << "-------------------" << std::endl;
	std::cout << "Vector 1: " << std::endl;
	vec1.PrintVals();
	std::cout << std::endl;
	std::cout << "Vector 2: " << std::endl;
	vec2.PrintVals();
	std::cout << "-------------------" << std::endl;
	std::cout << "Cross product vector:" << std::endl;
	PVec::PrintVals(PVec::Cross(vec1, vec2));
	std::cout << std::endl;
	std::cout << "Dot Product: " << PVec::Dot(vec1, vec2) << std::endl;
	std::cin.get();
}