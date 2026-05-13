#include "Producte_UniPtr.h"



// ==========================================================================================
// Implementació de Producte_UniPtr basada en la gestió de propietat exclusiva (std::unique_ptr).
// S'utilitza 'std::make_unique' en els setters per a la reserva segura de memòria dinàmica 
// (tant per a l'array 'char[]' del nom com per als objectes 'double' i 'Data' opcionals). 
// S'aplica el mètode '.get()' en l'operador de sortida i en els 'getters' per exposar el 
// punter subjacent sense cedir-ne la propietat. Per a la clonació en el 
// constructor de còpia i l'operador d'assignació, s'usa la desreferenciació ('*') per extreure 
// els valors i realitzar una còpia profunda, mentre que l'alliberament de recursos vells 
// es gestiona automàticament mitjançant l'assignació a 'nullptr' o la pròpia destrucció 
// de l'objecte (RAII).
// ==========================================================================================


Producte_UniPtr::Producte_UniPtr(int codi, const char* nom)
{
	setCodi(codi);
	setNom(nom);
}



Producte_UniPtr::Producte_UniPtr(const Producte_UniPtr& p) : codi(p.codi)
{
	setNom(p.nom.get()); // Copia el contenido del nombre utilizando get() para obtener el puntero subyacente
	// Copia los precios si no son nulos
	if (p.preuCompra) {
		setPreuCompra(*p.preuCompra); // Desreferencia el puntero para obtener el valor
	}
	else {
		setPreuCompraNull();
	}
	if (p.preuVenda) {
		setPreuVenda(*p.preuVenda); // Desreferencia el puntero para obtener el valor

	}
	else {
		setPreuVendaNull();
	}
	// Copia la fecha de alta si no es nula
	if (p.dataAlta) {
		setDataAlta(*p.dataAlta); // Desreferencia el puntero para obtener el valor
	}
	else {
		setDataAltaNull();
	}
}

Producte_UniPtr::~Producte_UniPtr()
{
	// No es necesario liberar memoria manualmente, ya que unique_ptr se encarga de ello automáticamente
	nom = nullptr;
	preuCompra = nullptr;
	preuCompra = nullptr;
	dataAlta = nullptr;
}

Producte_UniPtr& Producte_UniPtr::operator=(const Producte_UniPtr& p)
{
	if (this == &p) {
		return *this; // Maneja la autoasignación
	}
	setCodi(p.codi);
	setNom(p.nom.get()); // Copia el contenido del nombre utilizando get() para obtener l'adreça del punter subjacent

	//Copiar contingut si no són nuls:
	if (p.preuCompra) {
		setPreuCompra(*p.preuCompra);
	}
	else {
		setPreuCompraNull();
	}
	if (p.preuVenda) {
		setPreuVenda(*p.preuVenda);
	}
	else {
		setPreuVendaNull();
	}
	if (p.dataAlta) {
		setDataAlta(*p.dataAlta);
	}
	else {
		setDataAltaNull();
	}
	return *this;
}

void Producte_UniPtr::visualitzar() {
	cout << "Codi.......: " << codi << endl;
	cout << "Nom........: " << nom.get() << endl;
	cout << "Preu compra: ";
	if (preuCompra == NULL) cout << "" << endl;
	else cout << *preuCompra << endl;
	cout << "Preu venda.: ";
	if (preuVenda == NULL) cout << "" << endl;
	else cout << *preuVenda << endl;
	cout << "Data alta..: ";
	if (dataAlta == NULL) cout << "" << endl;
	else cout << *dataAlta << endl;
}

int Producte_UniPtr::getCodi() const
{
	return codi;
}

const char* Producte_UniPtr::getNom() const
{
	return nom.get();
}

const double* Producte_UniPtr::getPreuCompra() const
{
	return preuCompra.get();
}

const double* Producte_UniPtr::getPreuVenda() const
{
	return preuVenda.get();
}

const Data* Producte_UniPtr::getDataAlta() const
{
	return dataAlta.get();
}

void Producte_UniPtr::setCodi(int codi)
{
	if (codi <= 0) {
		throw "Codi ha de ser estrictament positiu";
	}
	this->codi = codi;
}

void Producte_UniPtr::setNom(const char* nom)
{
	if (nom == nullptr || nom[0] == '\0' || strlen(nom) == 0) {
		throw "El nom no pot ser null ni buit";
	}
	this->nom = make_unique<char[]>(strlen(nom) + 1); // Asigna memoria para el nombre
	strcpy(this->nom.get(), nom); // Copia el contenido del nombre
}

void Producte_UniPtr::setPreuCompraNull()
{
	preuCompra = nullptr;
}

void Producte_UniPtr::setPreuCompra(const double preuCompra)
{
	if (preuCompra < 0) {
		throw "El preu de compra no pot ser negatiu";
	}
	this->preuCompra = make_unique<double>(preuCompra); // Asigna memoria y copia el valor
}

void Producte_UniPtr::setPreuVendaNull()
{
	preuVenda = nullptr;
}

void Producte_UniPtr::setPreuVenda(const double preuVenda)
{
	if (preuVenda < 0) {
		throw "El preu de venda no pot ser negatiu";
	}
	this->preuVenda = make_unique<double>(preuVenda); // Asigna memoria y copia el valor
}

void Producte_UniPtr::setDataAlta(const Data dataAlta)
{
	this->dataAlta = make_unique<Data>(dataAlta); // Asigna memoria y copia el valor

}

void Producte_UniPtr::setDataAltaNull()
{
	dataAlta = nullptr;
}

void Producte_UniPtr::visualitzar() const
{
	cout << "Codi.......: " << codi << endl;
	cout << "Nom........: " << nom.get() << endl;
	cout << "Preu compra: ";
	if (preuCompra == NULL) cout << "" << endl;
	else cout << *preuCompra << endl;
	cout << "Preu venda.: ";
	if (preuVenda == NULL) cout << "" << endl;
	else cout << *preuVenda << endl;
	cout << "Data alta..: ";
	if (dataAlta == NULL) cout << "" << endl;
	else cout << *dataAlta << endl;
}

ostream& operator<<(ostream& os, const Producte_UniPtr& p)
{
	os << "Codi: " << p.codi << " - Nom: " << p.nom.get();
	return os;
}
