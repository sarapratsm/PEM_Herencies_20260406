#pragma once
#include "../Biblioteca_cpp/20260108_VS_Biblioteca_Sara/Data.h"

class Producte
{
private:
	int codi;
	char* nom;
	float* preuCompra;
	float* preuVenda;
	Data* dataAlta;

	friend ostream& operator<<(ostream& out, const Producte& p);

public:
	Producte(int codi, char* nom);
	Producte(int codi, const char* nom, float preuCompra, float preuVenda, Data dataAlta);
	Producte(const Producte& p);
	virtual ~Producte();

	Producte& operator=(const Producte& p);

	int getCodi() const;
	const char* getNom() const;
	float* getPreuCompra() const;
	float* getPreuVenda() const;
	Data getDataAlta() const;

	void setCodi(int codi);
	void setNom(const char* nom);
	void setPreuCompra(); //per deixar-ho a NULL
	void setPreuCompra(const float preuCompra);
	void setPreuVenda(); //per deixar-ho a NULL
	void setPreuVenda(const float preuVenda);
	void setDataAlta(const Data dataAlta);

	virtual void visualitzar() const;

};

