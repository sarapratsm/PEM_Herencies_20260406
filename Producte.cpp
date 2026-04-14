#include "Producte.h"
#include <iostream>
#include <cstring>

using namespace std;

// Constructor 
Producte::Producte(int codi, char* nom) 
	: nom(nullptr), preuCompra(nullptr), preuVenda(nullptr), dataAlta(nullptr) {
	setCodi(codi);
	setNom(nom);
}

// Constructor amb paràmetres
Producte::Producte(int codi, const char* nom, float pCompra, float pVenda, Data dAlta) 
	: nom(nullptr), preuCompra(nullptr), preuVenda(nullptr), dataAlta(nullptr) {
	setCodi(codi);
	setNom(nom);
	setPreuCompra(pCompra);
	setPreuVenda(pVenda);
	setDataAlta(dAlta);
}

// Constructor de còpia (Deep Copy)
// IMPORTANT: Si no fem això, dos objectes apuntarien a la mateixa adreça de memòria.
Producte::Producte(const Producte& p) 
: nom(nullptr), preuCompra(nullptr), preuVenda(nullptr), dataAlta(nullptr) {
	setCodi(p.codi);
	setNom(p.nom);
	if (p.preuCompra) setPreuCompra(*p.preuCompra);
	if (p.preuVenda) setPreuVenda(*p.preuVenda);
	if (p.dataAlta != NULL) setDataAlta(*p.dataAlta);
}

// Destructor
Producte::~Producte() {
	delete[] nom;
	delete preuCompra;
	delete preuVenda;
	delete dataAlta;
	//posar-ho tot a null
	nom = nullptr;
	preuCompra = nullptr;
	preuVenda = nullptr;
	dataAlta = nullptr;
}

//Operador d'assignació (Deep Copy)
Producte& Producte::operator=(const Producte& p) {
	if (this == &p) return *this; // Evitem l'autoassignació
	setCodi(p.codi);
	setNom(p.nom);
	if (p.preuCompra) setPreuCompra(*p.preuCompra); else setPreuCompra();
	if (p.preuVenda) setPreuVenda(*p.preuVenda); else setPreuVenda();
	if (p.dataAlta != NULL) setDataAlta(*p.dataAlta); else setDataAlta(Data());
	return *this;
}

// Getters i Setters (exemple de gestió de memòria en el Setter)
void Producte::setCodi(int codi)
{
	if (codi > 0) {
		this->codi = codi;
	}
	else {
		throw invalid_argument("El codi ha de ser un enter positiu.");
	}
}

void Producte::setNom(const char* nouNom) {
	if (nouNom == NULL || strlen(nouNom) == 0) {
		throw invalid_argument("El nom ha de tenir contingut");
	}
	if (this->nom != NULL) delete[] this->nom; // Alliberem el que hi havia
	this->nom = new char[strlen(nouNom) + 1];
	strcpy(this->nom, nouNom);
}

void Producte::setPreuCompra()
{
	if (this->preuCompra) {
		delete this->preuCompra; // Alliberem el que hi havia
		this->preuCompra = nullptr; // Deixem-ho a nullptr per indicar que no està definit
	}
}

void Producte::setPreuCompra(float pCompra) {
	if (pCompra < 0) {
		throw invalid_argument("El preu de compra no pot ser negatiu.");
	}
	if (this->preuCompra == NULL)// Alliberem el que hi havia
		this->preuCompra = new float(pCompra);
	*(this->preuCompra) = pCompra;

}

void Producte::setPreuVenda()
{
	if (this->preuVenda) {
		delete this->preuVenda; // Alliberem el que hi havia
		this->preuVenda = nullptr; // Deixem-ho a nullptr per indicar que no està definit
	}
}

void Producte::setPreuVenda(float pVenda) {
	if (pVenda < 0) {
		throw invalid_argument("El preu de venda no pot ser negatiu.");
	}
	if (this->preuVenda == NULL)
		this->preuVenda = new float(pVenda);
	*(this->preuVenda) = pVenda;
}

//Set data
void Producte::setDataAlta(Data dataAlta) {
	if (this->dataAlta == NULL)
		this->dataAlta = new Data(dataAlta); //creem una nova Data a partir de la que ens passen
	else
		*(this->dataAlta) = dataAlta; //matxaquem la data que hi havia amb la nova data
}

//Getters
int Producte::getCodi() const {
	return codi;
}

const char* Producte::getNom() const {
	return nom;
}

float* Producte::getPreuCompra() const {
	return preuCompra;
}

float* Producte::getPreuVenda() const {
	return preuVenda;
}

Data Producte::getDataAlta() const {
	//Retornem una còpia de la data per evitar que l'usuari pugui modificar la data interna del producte a través del punter
	if (dataAlta) {
		return *dataAlta;
	}
	else {
		throw runtime_error("La data d'alta no està definida.");
	}
}


// Implementació de l'operador <<
ostream& operator<<(ostream& out, const Producte& p) {
	out << "[Codi: " << p.codi << "] Nom: " << (p.nom ? p.nom : "SENSE NOM");
	out << " | Preu Compra: ";
	if (p.preuCompra) out << *p.preuCompra; else out << "Desconegut";
	out << " | Preu Venda: ";
	if (p.preuVenda) out << *p.preuVenda; else out << "Desconegut";
	out << " | Data Alta: ";
	if (p.dataAlta) out << *p.dataAlta; else out << "Desconeguda";
	return out;
}

void Producte::visualitzar() const {
	cout << *this << endl;
}
