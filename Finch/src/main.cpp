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
	std::cout << std::endl;
	std::cout << "Cross product vector:" << std::endl;
	PVec::PrintVals(PVec::Cross(vec1, vec2));
	std::cout << std::endl;
	std::cout << "Dot Product: " << PVec::Dot(vec1, vec2) << std::endl;
	std::cout << "Distance between the vectors as points: " << PVec::Dist(vec1, vec2) << std::endl;
	std::cout << "Angle between the vectors: " << PVec::AngleBetween(vec1, vec2) << " radians" << std::endl;
	std::cout << std::endl;
	std::cout << "Vector 1 normalized: " << std::endl;
	PVec::PrintVals(PVec::Normalize(vec1));
	std::cout << std::endl;
	std::cout << "Vector 2 normalized: " << std::endl;
	PVec::PrintVals(PVec::Normalize(vec2));
	std::cout << std::endl;
	std::cin.get();
}