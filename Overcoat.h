#pragma once

#include <iostream>

class Overcoat
{
private:
	char* producer;
	int size;
	float price;

public:
	Overcoat(const char* pProducer, int pSize, float pPrice) : producer(nullptr), size(38), price(0.f) { setProducer(pProducer); setSize(pSize); setPrice(pPrice); }
	Overcoat(const Overcoat& pOther) : Overcoat(pOther.producer, pOther.size, pOther.price) {}
	Overcoat(Overcoat&& pOther);
	~Overcoat();

	const char* getProducer() const { return producer; }
	int getSize() const { return size; }
	float getPrice() const { return price; }

	void setProducer(const char* pString);
	void setSize(int pSize);
	void setPrice(float pPrice);

	bool operator==(const Overcoat& pOther) const;
	Overcoat& operator=(const Overcoat& pOther);

	bool operator>(const Overcoat& pOther) const { return price > pOther.price; }
	bool operator>=(const Overcoat& pOther) const { return price >= pOther.price; }
	bool operator<(const Overcoat& pOther) const { return price < pOther.price; }
	bool operator<=(const Overcoat& pOther) const { return price <= pOther.price; }

	friend std::ostream& operator<<(std::ostream& out, Overcoat& overcoat);
};

