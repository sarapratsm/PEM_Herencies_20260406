#include <iostream>
#include "Producte.h"
#include "Neteja.h"

#define MAIN1 // Canviar a MAINX segons l'exercici

int main() {
	
#ifdef MAIN1
	const int n = 6;
	Producte* taula[n]; 
	//No podem fer Producte[n] perquè no tenim constructor buit Producte().



	return 0;
	
#endif
#ifdef MAIN2

#endif
#ifdef MAIN3

#endif
#ifdef MAIN4

#endif


	// Neteja de memòria
	for (int i = 0; i < n; i++) delete taula[i];
	delete[] taula;

	return 0;
}