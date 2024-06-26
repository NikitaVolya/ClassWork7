#include "Flat.h"

#include <iostream>
#include <conio.h>

Flat::Flat(int pStage, float pArea, float pPrice, const char* pFamily) : stage(pStage), area(1.f), price(0.f), family(nullptr)
{
	setArea(pArea);
	setPrice(pPrice);
	setFamily(pFamily);
}

Flat::Flat(Flat&& pOther) : stage(pOther.stage), area(pOther.area), price(pOther.price), family(pOther.family)
{
	pOther.family = nullptr;
}

Flat::~Flat()
{
	if (family)
		delete[] family;
}

void Flat::setArea(float pArea)
{
	if (pArea < 0.f)
	{
		std::cout << "[ INFO ] Flat: invalide value to area!\n";
		return;
	}

	area = pArea;
}

void Flat::setPrice(float pPrice)
{
	if (price < 0.f)
	{
		std::cout << "[ INFO ] Flat: invalide value to price!\n";
		return;
	}

	price = pPrice;
}

void Flat::setFamily(const char* pString)
{
	if (!pString)
	{
		if (family)
			delete[] family;
		family = new char[5] {'N', 'o', 'n', 'e', '\0'};
		return;
	}

	size_t stringLength = std::strlen(pString) + 1;

	if (!family)
		family = new char[stringLength];
	else if (std::strlen(family) + 1 != stringLength)
	{
		delete[] family;
		family = new char[stringLength];
	}

	strcpy_s(family, stringLength, pString);
}

Flat& Flat::operator=(const Flat& pOther)
{
	if (this == &pOther)
		return *this;

	stage = pOther.stage;
	area = pOther.area;
	price = pOther.price;
	setFamily(pOther.family);

	return *this;
}

std::ostream& operator<<(std::ostream& out, Flat& overcoat)
{
	out << overcoat.stage << ' ' << overcoat.area << ' ' << overcoat.price << " | ";
	if (overcoat.family)
		out << overcoat.family;
	else
		out << "None";

	return out;
}
