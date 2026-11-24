#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Producte.h"
#include "Aliment.h"
#include "Neteja.h"
#include <string.h>
#include <memory>

#define MAIN3 // Canviar a MAINX segons l'exercici

int main() {

#ifdef MAIN1
	const int n = 6;
	Producte* taula[n];
	//No podem fer Producte[n] perquè no tenim constructor buit Producte().

	//2 Productes
	taula[0] = new Producte(1, "Taula", 100.0f, 150.0f, Data(1, 1, 2024));
	taula[1] = new Producte(2, "Cadira", 50.0f, 75.0f, Data(2, 1, 2024));

	//2 aliments
	//Aliment::Aliment(int codi, const char* nom, float pCompra, float pVenda, Data dAlta, const char* lotInput, short dies)
	taula[2] = new Aliment(2, "Llet", 0.5f, 1.0f, Data(2, 1, 2024), "LLOT123", 7);
	taula[3] = new Aliment(3, "Pa", 0.8f, 1.5f, Data(3, 1, 2024), "LLOT124", 3);

	//2 neteja
	//Neteja::Neteja(int codi, const char* nom, float preuCompra, float preuVenda, Data dataAlta, int grau)
	taula[4] = new Neteja(4, "Detergent", 2.0f, 3.5f, Data(4, 1, 2024), 3);
	taula[5] = new Neteja(5, "Desinfectant", 3.0f, 5.0f, Data(5, 1, 2024), 4);

	//Per a utilitzar els mètodes de cada classe, hem de fer un downcast, ja que taula és un array de Producte*.
	((Aliment*)taula[2])->setCodi(10); //Downcast per a accedir al mètode setCodi d'Aliment
	((Neteja*)taula[4])->setGrauPerillositat(5); //Downcast per a accedir al mètode setGrauPerillositat de Neteja

	//Exemple visualitzant els productes
	cout << "Visualitzant els productes:" << std::endl;
	for (int i = 0; i < n; i++) {
		taula[i]->visualitzar(); //Polimorfisme: crida al mètode visualitzar de cada classe concreta
		//Això és gràcies a que el mètode visualitzar és virtual a la classe Producte, i cada classe derivada el sobreescriu amb la seva pròpia implementació.
	}

	//Exemple utilitzant l'operador <<
	cout << "Utilitzant l'operador <<:" << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << *taula[i] << std::endl; //Tots es mostren com a Producte
	}

	//Exemple utiilitzant if (typeid ( *p ) == typeid( nomClasse )
	cout << "Utilitzant typeid:" << std::endl;
	for (int i = 0; i < n; i++) {
		if (typeid(*taula[i]) == typeid(Aliment)) {
			cout << "És un Aliment: " << *taula[i] << endl;
		}
		else if (typeid(*taula[i]) == typeid(Neteja)) {
			cout << "És un Neteja: " << *taula[i] << endl;
		}
		else {
			cout << "És un Producte genèric: " << *taula[i] << endl;
		}
	}

	//netejar memoria
	for (int i = 0; i < n; i++) {
		delete taula[i];
	}

#endif

#ifdef MAIN2
	//Preguntar la capacitat de la taula a l'usuari i crear-la dinàmicament amb new.
	int capacitat;
	cout << "Introdueix la capacitat de la taula: ";
	cin >> capacitat;
	Producte** taula = new Producte * [capacitat]; //Taula de punters a Producte

	//Crear productes i assignar-los a la taula
	for (int i = 0; i < capacitat; i++) {
		//Producte::Producte(int codi, char* nom) 
		char* nom = new char[20];
		sprintf(nom, "Producte %d", i + 1);
		taula[i] = new Producte(i + 1, nom);
		delete[] nom;
	}

	//mostrar tots els productes
	for (int i = 0; i < capacitat; i++) {
		taula[i]->visualitzar();
	}

	//netejar memoria
	for (int i = 0; i < capacitat; i++) {
		delete taula[i];
	}
	delete[] taula;

#endif
#ifdef MAIN3
	unique_ptr<Producte> t[6];
	t[0] = make_unique<Producte>(1, "Taula", 100.0f, 150.0f, Data(1, 1, 2024));
	t[1] = make_unique<Producte>(2, "Cadira", 50.0f, 75.0f, Data(2, 1, 2024));
	t[2] = make_unique<Aliment>(2, "Llet", 0.5f, 1.0f, Data(2, 1, 2024), "LLOT123", 7);
	t[3] = make_unique<Aliment>(3, "Pa", 0.8f, 1.5f, Data(3, 1, 2024), "LLOT124", 3);
	t[4] = make_unique<Neteja>(4, "Detergent", 2.0f, 3.5f, Data(4, 1, 2024), 3);
	t[5] = make_unique<Neteja>(5, "Desinfectant", 3.0f, 5.0f, Data(5, 1, 2024), 4);



#endif
#ifdef MAIN4

#endif




	return 0;
}