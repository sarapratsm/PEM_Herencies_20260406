#define _CRT_SECURE_NO_WARNINGS
#include "Propietat.h"

Propietat::Propietat(const char* codi, const char* nom, const TipusPropietat* tipus) : nomPropietari(NULL), anyConstruccio(nullptr), tipusPropietat(nullptr)
{
	setCodi(codi);
	setNomPropietari(nom);
	setTipusPropietat(tipus);
}

Propietat::Propietat(const Propietat& p) : nomPropietari(NULL), anyConstruccio(nullptr), tipusPropietat(nullptr)
{
	//Es pot fer directament usant els camps (sense getters) perquè estem dins de la classe.
	setCodi(p.getCodi());
	setNomPropietari(p.getNomPropietari());
	if (p.getAnyConstruccio() != nullptr) {
		setAnyConstruccio(*(p.getAnyConstruccio()));
	}
	if (p.getTipusPropietat() != nullptr) {
		setTipusPropietat(p.getTipusPropietat());
	}
}

Propietat::~Propietat()
{
	delete[] nomPropietari;
	delete anyConstruccio;
	nomPropietari = nullptr;
	anyConstruccio = nullptr;
	tipusPropietat = nullptr; //No cal eliminar el tipus de propietat perquè no és propietat de la classe Propietat, sinó que és un punter a un objecte que es gestiona externament. Per tant, només posem el punter a nullptr per evitar dangling pointers.
}

Propietat& Propietat::operator=(const Propietat& p)
{
	if (this == &p) //Comprovem que no s'estigui assignant a si mateix
		return *this;
	
	setCodi(p.getCodi());
	setNomPropietari(p.getNomPropietari());
	setTipusPropietat(p.getTipusPropietat());
	if (p.getAnyConstruccio() != nullptr) {
		setAnyConstruccio(*(p.getAnyConstruccio()));
		//setAnyConstruccio(*p.anyConstruccio); //També es podria fer així, sense getter.
	}
	else {
		setAnyConstruccioNull();
	}
	return *this; //Retornem l'objecte actual per permetre encadenar assignacions (a = b = c)
}

//========Setters i getters========

void Propietat::setCodi(const char* codi)
{
	if (codi == nullptr) {
		throw invalid_argument("El codi no pot ser nul.");
	}
	if (strlen(codi) != 6)
	{
		throw invalid_argument("El codi ha de ser de 6 digits alfanumèrics.");
	}
	strcpy(this->codi, codi);
}

void Propietat::setNomPropietari(const char* nom)
{
	if (nom == nullptr) {
		throw invalid_argument("El nom del propietari no pot ser nul.");
	}
	if(strlen(nom) == 0) {
		throw invalid_argument("El nom del propietari no pot ser buit.");
	}
	delete[] nomPropietari;
	nomPropietari = new char[strlen(nom) + 1];
	strcpy(nomPropietari, nom);
}

void Propietat::setAnyConstruccio(int anyConstruccio)
{
	if (anyConstruccio < 1492) {
		throw invalid_argument("L'any de construcció ha de ser a partir de l'any del descobriment d'Amèrica (1492).");
	}
	if (this->anyConstruccio == nullptr) {
		this->anyConstruccio = new int(anyConstruccio);
	}
	else {
		*(this->anyConstruccio) = anyConstruccio;
	}
}

void Propietat::setAnyConstruccioNull()
{
	delete anyConstruccio;
	anyConstruccio = nullptr;
}

void Propietat::setTipusPropietat(const TipusPropietat *tipus)
{
	if (tipus == nullptr) {
		throw invalid_argument("El tipus de propietat no pot ser nul.");
	}
	this->tipusPropietat = (TipusPropietat*)tipus;
	
}

//======== Getters ========
char const* Propietat::getCodi() const
{
	return codi;
}

char const* Propietat::getNomPropietari() const
{
	return nomPropietari;
}

const int* Propietat::getAnyConstruccio() const
{
	return anyConstruccio; 
	//retornem un punter const perquè el camp és nullable. 
	//Si fos un int normal, podríem retornar un int normal.
}

const TipusPropietat* Propietat::getTipusPropietat() const
{
	return tipusPropietat;
}


//========Operadors de comparació--------
bool Propietat::operator==(const Propietat& p) const
{
	return strcmp(codi, p.codi) == 0;
}

bool Propietat::operator!=(const Propietat& p) const
{
	return !(*this == p);
}

//========Operador d'streaming========
ostream& operator<<(ostream& os, const Propietat& p)
{
	os << "Codi: " << p.getCodi();
	os << "- " << *p.getTipusPropietat()->getTipus();
	//    os << "- " << *prop.tipusPropietat; //Tal i com ho te Isidre, però no funciona perquè el tipus de propietat és un punter. Hauríem de sobrecarregar l'operador d'streaming per a la classe TipusPropietat per poder fer això.
	os << "\tNom del propietari: " << p.getNomPropietari() << endl;
	if (p.getAnyConstruccio() != nullptr) {
		os << "\tAny de construcció: " << *(p.getAnyConstruccio()) << endl;
	}
	return os;
}
