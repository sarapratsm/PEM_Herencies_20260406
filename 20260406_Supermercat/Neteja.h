#pragma once
#include "Producte.h"

//Hereda de Producte
class Neteja : public Producte
{
private:
	char grauPerillositat;

	friend ostream& operator<<(ostream& out, const Neteja& n);

public:
	Neteja(int codi, const char* nom, float preuCompra, float preuVenda, Data dataAlta, int grauPerillositat);
	Neteja(const Neteja& n);
	~Neteja() = default; //No cal definir un destructor personalitzat ja que no tenim recursos dinàmics

	int getGrauPerillositat() const;
	void setGrauPerillositat(int grauPerillositat);

	void visualitzar() const;

};

