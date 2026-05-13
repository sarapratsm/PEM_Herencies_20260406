#define _CRT_SECURE_NO_WARNINGS
#include "Producte_UniPtr.h"
#include <ostream>



#pragma once
class Neteja_UniPtr : public Producte_UniPtr
{

private:
	char grauPerillositat;

	friend ostream& operator<<(ostream& out, const Neteja_UniPtr& n);

public:
	Neteja_UniPtr(int codi, const char* nom, int grauPerillositat);
	Neteja_UniPtr(const Neteja_UniPtr& n);
	~Neteja_UniPtr() = default; //No cal definir un destructor personalitzat ja que no tenim recursos dinàmics

	int getGrauPerillositat() const;

	void setGrauPerillositat(int grauPerillositat);

	void visualitzar() const;
};

