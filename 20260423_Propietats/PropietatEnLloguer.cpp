#include "PropietatEnLloguer.h"

PropietatEnLloguer::PropietatEnLloguer(const char* codi, const char* nomPropietari,
	const TipusPropietat* tipus, double preu)
	: Propietat(codi, nomPropietari, tipus),
	llogada(false), dataInici(nullptr)
{
	setPreu(preu);
}

PropietatEnLloguer::PropietatEnLloguer(const PropietatEnLloguer& p) :Propietat(p), dataInici(nullptr)
{
	if (p.dataInici != nullptr) {
		this->setDataInici(*(p.dataInici));
	}
	else {
		this->setDataIniciNull();
		llogada = false;
	}
}

PropietatEnLloguer::~PropietatEnLloguer()
{
	if (this->dataInici != nullptr) {
		delete this->dataInici;
		this->dataInici = nullptr;
	}
}

PropietatEnLloguer& PropietatEnLloguer::operator=(const PropietatEnLloguer& p)
{
	if (this != &p) {
		Propietat::operator=(p);
		if (p.dataInici != nullptr) {
			this->setDataInici(*(p.dataInici));
		}
		else {
			this->setDataIniciNull();
		}
		this->preu = p.preu;
	}
	return *this;
}

const double PropietatEnLloguer::getPreu() const
{
	return this->preu;
}

const bool PropietatEnLloguer::isLlogada() const
{
	if (this->dataInici != nullptr) {
		return true;
	}
	else {
		return false;
	}
}

const Data* PropietatEnLloguer::getDataInici() const
{
	if (this->dataInici != nullptr) {
		return this->dataInici;
	}
	else {
		return nullptr;
	}
}



void PropietatEnLloguer::setPreu(double preu)
{
	if (preu >= 0) {
		this->preu = preu;
	}
	else {
		throw new invalid_argument("El preu no pot ser negatiu.");
	}

}

void PropietatEnLloguer::setDataInici(const Data& dataInici)
{
	//En C++ estàndard, una referència no pot ser nul·la, així que no cal comprovar si dataInici és null.
	if (this->dataInici == nullptr) {
		this->dataInici = new Data(dataInici);
	}
	else {
		*(this->dataInici) = dataInici; //Matxaquem el valor de la dataInici actual amb el nou valor, sense necessitat de crear un nou objecte Data.
	}
	llogada = true;

}

void PropietatEnLloguer::setDataIniciNull()
{
	if (this->dataInici != nullptr) {
		delete this->dataInici;
		this->dataInici = nullptr;
		llogada = false;
	}
}

ostream& operator<<(ostream& os, const PropietatEnLloguer& p)
{
	os << "En lloguer: ";
	os << (Propietat&)p; //Fem un cast a Propietat per poder utilitzar l'operador << de Propietat, que és el que ens interessa mostrar.
	os << "Preu: " << p.getPreu() << "€" << endl;
	if (p.isLlogada()) {
		os << "Data d'inici del lloguer: " << *(p.getDataInici()) << endl;
	}
	else {
		os << "La propietat no està llogada." << endl;
	}
	return os;

}
