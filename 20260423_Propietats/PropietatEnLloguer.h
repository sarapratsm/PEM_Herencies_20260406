#pragma once
#include "Propietat.h"
#include "../Biblioteca_cpp/20260108_VS_Biblioteca_Sara/Data.h"
class PropietatEnLloguer final :
    public Propietat
{
private:
	friend ostream& operator<<(ostream& os, const PropietatEnLloguer& p);
	double preu;
	bool llogada;
	Data *dataInici;

public:
	PropietatEnLloguer(const char* codi, const char* nomPropietari, const TipusPropietat* tipus, double preu);
	PropietatEnLloguer(const PropietatEnLloguer& p);
	~PropietatEnLloguer();
	PropietatEnLloguer& operator=(const PropietatEnLloguer& p);

	//Getters i setters	
	const double getPreu() const;
	const bool isLlogada() const;
	const Data* getDataInici() const;

	void setPreu(double preu);
	void setDataInici(const Data& dataInici);
	void setDataIniciNull();
	//void setLlogada(bool llogada); //No cal, ja que el llogat es pot deduir de si la data d'inici és null o no.

};

