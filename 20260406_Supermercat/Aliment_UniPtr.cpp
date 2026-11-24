#include "Aliment_UniPtr.h"

ostream& operator<<(ostream& out, const Aliment_UniPtr& aliment)
{
	out << (Producte_UniPtr*)&aliment; // Imprimeix la part de Producte_UniPtr
	if (aliment.getLot() != nullptr) {
		out << "Lot: " << aliment.getLot() << endl;
	}
	out << "Dies de caducitat: " << aliment.getDiesCaducitat() << endl;
}

Aliment_UniPtr::Aliment_UniPtr(int codi, const char* nom, int diesCaducitat) : Producte_UniPtr(codi, nom)
{
	setDiesCaducitat(diesCaducitat);
}

Aliment_UniPtr::Aliment_UniPtr(const Aliment_UniPtr& a) : Producte_UniPtr(a)
{
	setDiesCaducitat(a.getDiesCaducitat());
}

Aliment_UniPtr::~Aliment_UniPtr()
{
	// No cal definir un destructor personalitzat ja que no tenim recursos dinàmics
}

Aliment_UniPtr& Aliment_UniPtr::operator=(const Aliment_UniPtr& a)
{
	if (this != &a) { // Evitar auto-assignació
		Producte_UniPtr::operator=(a); // Assignar la part de Producte_UniPtr
		setDiesCaducitat(a.getDiesCaducitat()); // utilitzar el getter per obtenir el valor de diesCaducitat i el setter per assignar-lo
	}
	return *this;

}

const char* Aliment_UniPtr::getLot() const
{
	return lot.get();
}

const short Aliment_UniPtr::getDiesCaducitat() const
{
	return diesCaducitat;
}

void Aliment_UniPtr::setLot(const char* lot)
{
	if (lot == nullptr) {
		this->lot.reset(); // Alliberar el lot actual
	} else {
		this->lot = make_unique<char[]>(strlen(lot) + 1); // Crear un nou lot amb la mida adequada
		strcpy(this->lot.get(), lot); // Copiar el nou lot
	}
}

void Aliment_UniPtr::setDiesCaducitat(short diesCaducitat)
{
	if (diesCaducitat < 0) {
		throw invalid_argument("Els dies de caducitat no poden ser negatius.");
	}
	this->diesCaducitat = diesCaducitat;
}

void Aliment_UniPtr::visualitzar() const
{
	Producte_UniPtr::visualitzar(); // Visualitza la part de Producte_UniPtr
	if (getLot() != nullptr) {
		cout << "Lot: " << getLot() << endl;
	}
	cout << "Dies de caducitat: " << getDiesCaducitat() << endl;
}
