

#include <iostream>
#include "Overcoat.h"
#include "Flat.h"

int main()
{
	Overcoat test("nike", 40, 12.5f);
	Overcoat a(nullptr, 50, 12.8f);


	std::cout << test.getProducer() << std::endl;
	std::cout << a.getProducer() << std::endl;
	std::cout << (a < test) << std::endl;
	std::cout << (a == test) << std::endl;

	test = a;
	test = test;

	std::cout << test.getProducer() << std::endl;
	std::cout << a.getProducer() << std::endl;
	std::cout << (a == test) << std::endl;

	test.setProducer("Nike");
	a.setProducer("H&M");

	std::cout << test.getProducer() << std::endl;
	std::cout << a.getProducer() << std::endl;


	std::cout << "--------------------------------------------------------------------\n";

	Flat flatOne(1, 20, 200, "Bosa");
	Flat flatTwo(2, 25, 400, "Volia");
	Flat flatTree(3, 30, 150, "Bondarenko");

	flatTree = flatOne;
	flatTwo = flatTwo;

	std::cout << flatOne.getFamily() << std::endl;
	std::cout << flatTwo.getFamily() << std::endl;
	std::cout << flatTree.getFamily() << std::endl;

	std::cout << (flatOne > flatTwo) << " " << (flatOne > flatTree) << std::endl;
	std::cout << (flatTree == flatOne) << " " << (flatTree == flatTwo) << std::endl;

	return 0;
}