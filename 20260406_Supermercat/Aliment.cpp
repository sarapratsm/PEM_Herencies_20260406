#include "Aliment.h"
#include <iostream>
#include <cstring>

using namespace std;



// Constructor amb paràmetres
Aliment::Aliment(int codi, const char* nom, float pCompra, float pVenda, Data dAlta, const char* lotInput, short dies)
    : Producte(codi, nom, pCompra, pVenda, dAlta), lot(nullptr) {
    setDiesCaducitat(dies); // Utilitzem el setter per validar els dies de caducitat
	setLot(lotInput); // Utilitzem el setter per gestionar la memòria del lot
}

// Constructor de còpia (Deep Copy)
Aliment::Aliment(const Aliment& a) 
    : Producte(a), diesCaducitat(a.diesCaducitat), lot(nullptr) {
	setLot(a.lot);
}

// Destructor: Alliberem la memòria que hem reservat nosaltres
Aliment::~Aliment() {
    delete[] lot;
	lot = nullptr; 
}

Aliment& Aliment::operator=(const Aliment& a)
{
	if (this != &a) { // Evitem l'autoassignació
        Producte::operator=(a); // Assignem la part de la base
        setDiesCaducitat(a.diesCaducitat); // Assignem els dies de caducitat
        setLot(a.lot); // Assignem el lot (gestió de memòria)
    }
    return *this;
}

// Getters
const char* Aliment::getLot() const { return lot; }
short Aliment::getDiesCaducitat() const { return diesCaducitat  ; }

// Setters amb gestió de memòria
void Aliment::setLot(const char* nouLot) {
    if(lot==nullptr) {
        lot = new char[strlen(nouLot) + 1];
        strcpy(lot, nouLot);
    }
    else {
		if (strlen(nouLot) == 0) {
			throw invalid_argument("El lot no pot ser una cadena buida.");
        }
		if (strlen(nouLot) != strlen(lot)) {
            delete[] lot; // Alliberem l'antic lot
            lot = new char[strlen(nouLot) + 1]; // Reservem nova memòria
        }
		strcpy(lot, nouLot); // Copiem el nou lot
	}
}

void Aliment::setDiesCaducitat(short dies) {
    this->diesCaducitat = (dies >= 0) ? dies : 0;
}

// Operador <<
ostream& operator<<(ostream& out, const Aliment& a) {
    // Cridem a l'operador de la base (Producte)
    out << (const Producte&)a;
    out << " | Lot: " << (a.lot ? a.lot : "SENSE LOT");
    out << " | Caducitat: ";
    if (a.diesCaducitat) out << a.diesCaducitat << " dies"; else out << "Desconeguda";
    return out;
}

void Aliment::visualitzar() const {
    Producte::visualitzar(); // Mostra dades de la base
    cout << " -> Detall Aliment [Lot: " << (lot ? lot : "N/A")
        << ", Dies per caducar: " << (diesCaducitat ? diesCaducitat : 0) << "]" << endl;
}