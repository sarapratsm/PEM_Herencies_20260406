#pragma once
#include "Producte.h"


class Aliment : public Producte
{
private:
	char* lot;
	short diesCaducitat;

	friend ostream& operator<<(ostream& out, const Aliment& a);

public:
	Aliment(int codi, const char* nom, float preuCompra, float preuVenda, Data dataAlta, const char* lot, short diesCaducitat);
	Aliment(const Aliment& a);
	~Aliment();
	Aliment& operator=(const Aliment& a); 
	const char* getLot() const;
	short getDiesCaducitat() const;
	void setLot(const char* lot);
	void setDiesCaducitat(short diesCaducitat);
	void visualitzar() const;
};

