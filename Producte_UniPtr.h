#ifndef PRODUCTE_HPP_INCLUDED
#define PRODUCTE_HPP_INCLUDED

#include "../Biblioteca_cpp/20260108_VS_Biblioteca_Sara/Data.h"
#include <memory>

// ================================================================================
// 
// Implementació de la classe Producte_UniPtr utilitzant unique_ptr per gestionar la memòria de manera segura i eficient.
// Aquesta classe representa un producte amb un codi, nom, preu de compra, preu de venda i data d'alta.
// S'han implementat constructors, destructor, operador d'assignació, getters i setters, 
// així com un mètode per visualitzar la informació del producte. 
// La gestió de memòria es realitza automàticament gràcies a l'ús de unique_ptr, 
// evitant així possibles fugides de memòria i facilitant el manteniment del codi.
// 
// ================================================================================


class Producte_UniPtr
{
private:
	int codi; // Obligatori i estrictament positiu
	unique_ptr<char[]> nom;  // Amb contingut (no null)
	unique_ptr<double> preuCompra; // Optatius no negatius
	unique_ptr<double> preuVenda;  // Optatiu no negatiu
	unique_ptr<Data> dataAlta;     // Optativa

	friend ostream& operator<<(ostream& out, const Producte_UniPtr & p);

public:
	Producte_UniPtr(int codi, const char* nom);
	Producte_UniPtr(const Producte_UniPtr& p);
	virtual ~Producte_UniPtr();

	Producte_UniPtr& operator=(const Producte_UniPtr& p);

	void visualitzar();

	int getCodi() const;
	const char* getNom() const;
	const double* getPreuCompra() const;
	const double* getPreuVenda() const;
	const Data* getDataAlta() const;

	void setCodi(int codi);
	void setNom(const char* nom);
	void setPreuCompraNull(); //per deixar-ho a NULL
	void setPreuCompra(const double preuCompra);
	void setPreuVendaNull(); //per deixar-ho a NULL
	void setPreuVenda(const double preuVenda);
	void setDataAlta(const Data dataAlta);
	void setDataAltaNull(); //per deixar-ho a NULL	

	virtual void visualitzar() const; //Fem virtual perquè la classe Aliment_UniPtr pugui sobreescriure aquest mètode i mostrar també les seves dades específiques

};
#endif // PRODUCTE_HPP_INCLUDED


