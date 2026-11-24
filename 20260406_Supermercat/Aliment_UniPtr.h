#pragma once
#include "Producte_UniPtr.h"
#include "../../Biblioteca_cpp/20260108_VS_Biblioteca_Sara/Data.h"

class Aliment_UniPtr : public Producte_UniPtr
{

private:
	unique_ptr<char[]> lot; //Optativa o amb contingut, és a dir, no buida
	short diesCaducitat; //no negatiu

	friend ostream& operator<<(ostream& out, const Aliment_UniPtr& a);

public:
	Aliment_UniPtr(int codi, const char* nom, int diesCaducitat);
	Aliment_UniPtr(const Aliment_UniPtr& a);
	~Aliment_UniPtr();
	Aliment_UniPtr& operator=(const Aliment_UniPtr& a);

	const char* getLot() const;
	const short getDiesCaducitat() const;

	void setLot(const char* lot);
	void setDiesCaducitat(short diesCaducitat);

	void visualitzar() const;

	
};

