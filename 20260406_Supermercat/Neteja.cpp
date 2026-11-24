#include "Neteja.h"
#include <iostream>

using namespace std;



// Constructor amb paràmetres: Cridem al constructor de la base
Neteja::Neteja(int codi, const char* nom, float preuCompra, float preuVenda, Data dataAlta, int grau)
    : Producte(codi, nom, preuCompra, preuVenda, dataAlta) {
    this->grauPerillositat = (grau >= 0 && grau <= 5) ? grau : 0;
}

// Constructor de còpia
Neteja::Neteja(const Neteja& n) : Producte(n) {
    this->grauPerillositat = n.grauPerillositat;
}



int Neteja::getGrauPerillositat() const
{
	return grauPerillositat;
}

void Neteja::setGrauPerillositat(int grauPerillositat)
{
    if (grauPerillositat >= 0 && grauPerillositat <= 5) {
        this->grauPerillositat = grauPerillositat;
    }
    else {
        cout << "Grau de perillositat no vàlid. Ha de ser entre 0 i 5." << endl;
	}
}

// Operador <<
ostream& operator<<(ostream& out, const Neteja& n) {
    // Cridem explicitament a l'operador de la classe base Producte
    out << (const Producte&)n;
    out << " | Perillositat: " << n.grauPerillositat;
    return out;
}

void Neteja::visualitzar() const {
    // Aprofitem el visualitzar de Producte i afegim el nostre
    Producte::visualitzar();
    cout << " -> Detall Neteja [Grau Perillositat: " << grauPerillositat << "]" << endl;
}