#include "Overcoat.h"

#include <conio.h>
#include <iostream>

Overcoat::~Overcoat()
{
	if (producer)
		delete[] producer;
}

void Overcoat::setProducer(const char* pString)
{
	if (!pString)
	{
		if (producer) 
			delete[] producer;
		producer = new char[5] {'N', 'o', 'n', 'e', '\0'};
		return;
	}

	size_t stringLength = std::strlen(pString) + 1;

	if (!producer)
		producer = new char[stringLength];
	else if (std::strlen(producer) + 1 != stringLength)
	{
		delete[] producer;
		producer = new char[stringLength];
	}

	strcpy_s(producer, stringLength, pString);
}

void Overcoat::setSize(int pSize)
{
	if (pSize < 30 || pSize > 56)
	{
		std::cout << "[ INFO ] Overcoat: invalide value to setSize!\n";
		return;
	}

	size = pSize;
}

void Overcoat::setPrice(float pPrice)
{
	if (pPrice < 0.f)
	{
		std::cout << "[ INFO ] Overcoat: invalide value to setPrice!\n";
		return;
	}

	price = pPrice;
}

bool Overcoat::operator==(const Overcoat& pOther) const
{
	if (producer && pOther.producer && std::strcmp(producer, pOther.producer) != 0)
		return false;
	if (!producer || !pOther.producer)
		return false;

	return size == pOther.size && price == pOther.price;
}

Overcoat& Overcoat::operator=(const Overcoat& pOther)
{
	if (this == &pOther)
		return *this;

	size = pOther.size;
	price = pOther.price;
	setProducer(pOther.producer);

	return *this;
}