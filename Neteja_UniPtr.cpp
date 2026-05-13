#include "Neteja_UniPtr.h"
#include "Producte_UniPtr.h"
#include "../Biblioteca_cpp/20260108_VS_Biblioteca_Sara/Data.h"



Neteja_UniPtr::Neteja_UniPtr(int codi, const char* nom, int grauPerillositat) : Producte_UniPtr(codi, nom)
{
	setGrauPerillositat(grauPerillositat);
}


Neteja_UniPtr::Neteja_UniPtr(const Neteja_UniPtr& n) : Producte_UniPtr(n)
{
	setGrauPerillositat(n.getGrauPerillositat());
}

int Neteja_UniPtr::getGrauPerillositat() const
{
	return grauPerillositat;
}

void Neteja_UniPtr::setGrauPerillositat(int grauPerillositat)
{
	if (grauPerillositat < 1 || grauPerillositat > 5) {
		throw invalid_argument("El grau de perillositat ha de ser entre 1 i 5.");
	}
	this->grauPerillositat = grauPerillositat;
}

void Neteja_UniPtr::visualitzar() const
{
	Producte_UniPtr::visualitzar(); // Visualitza la part de Producte_UniPtr
	cout << "Grau de perillositat: " << grauPerillositat << endl;
}

ostream& operator<<(ostream& out, const Neteja_UniPtr& n)
{
	// Visualitza la part de Producte_UniPtr
	out << (Producte_UniPtr*)&n; // Imprimeix la part de Producte_UniPtr	
	out << "Grau de perillositat: " << n.grauPerillositat << endl;
	return out;
}

