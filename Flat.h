#pragma once

#include <iostream>

class Flat
{
private:
	int stage;
	float area;
	float price;
	char* family;

public:
	Flat(int pStage, float pArea, float pPrice, const char* pFamily);
	Flat(const Flat& pOther) : Flat(pOther.stage, pOther.area, pOther.price, pOther.family) {};
	Flat(Flat&& pOther);
	~Flat();

	int getStage() const { return stage; }
	float getArea() const { return area; }
	float getPrice() const { return price; }
	const char* getFamily() const { return family; }

	void setStage(int pStage) { stage = pStage; };
	void setArea(float pArea);
	void setPrice(float pPrice);
	void setFamily(const char* pString);

	Flat& operator=(const Flat& pOther);

	bool operator==(const Flat& pOther) const { return area == pOther.area; };
	bool operator>(const Flat& pOther) const { return price > pOther.price; }
	bool operator>=(const Flat& pOther) const { return price >= pOther.price; }
	bool operator<(const Flat& pOther) const { return price < pOther.price; }
	bool operator<=(const Flat& pOther) const { return price <= pOther.price; }

	friend std::ostream& operator<<(std::ostream& out, Flat& overcoat);
};