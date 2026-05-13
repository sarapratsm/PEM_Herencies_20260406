#pragma once
#include "TipusPropietat.h"
#include <ostream>
using namespace std;

class Propietat
{
	friend ostream& operator<<(ostream& os, const Propietat& p);

	char codi[6]; //obligatori de 6 digits alfanumèrics
	char* nomPropietari; //obligatori
	int* anyConstruccio; //nullable.
	/*considerarem que les administracions de finques només gestionen propietats construïdes a partir de l’any
del descobriment d’Amèrica...*/
	TipusPropietat *tipusPropietat;

	void setCodi(const char* codi); //Immutable!

public:
	//Per a fer els constructors, només es demanarà el codi, el nom del propietari i el tipus de propietat. La data de construcció serà opcional.
	Propietat(const char* codi, const char* nom, const TipusPropietat * tipus);
	Propietat(const Propietat& p);
	virtual ~Propietat() = 0; //Igualant a 0 el destructor, fem que la classe sigui abstracta i no es pugui instanciar. Així, només es podran crear objectes de les classes filles PropietatEnVenda i PropietatEnLloguer.
	Propietat& operator=(const Propietat& p);

	//Getters i setters
	virtual const char* getCodi() const final ;
	virtual const char* getNomPropietari() const final ;
	virtual const int* getAnyConstruccio() const final ;
	virtual const TipusPropietat* getTipusPropietat() const final ;

	//Com que el codi ha de ser immutable, el setter del codi serà privat i només es podrà utilitzar en el constructor i en l’operador d’assignació.
	virtual void setNomPropietari(const char* nom) final;
	virtual void setAnyConstruccio(int anyConstruccio) final;
	virtual void setAnyConstruccioNull() final;
	virtual void setTipusPropietat(const TipusPropietat* tipus) final;

	bool operator==(const Propietat& p) const;
	bool operator!=(const Propietat& p) const;
};

