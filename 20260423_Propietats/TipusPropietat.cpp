#define _CRT_SECURE_NO_WARNINGS
#include "TipusPropietat.h"
#include <string.h>	

TipusPropietat::TipusPropietat(const char* tipus) : tipus(nullptr)
{
	setTipus(tipus);
}

TipusPropietat::TipusPropietat(const TipusPropietat& tp) : tipus(nullptr)
{
	setTipus(tp.tipus);
}	

/*No oblidar inicialitzar tots els valors a nullptr*/

TipusPropietat::~TipusPropietat()
{
	if (tipus != nullptr) //Isidre no té aquesta comprovació
	{
		delete[] tipus;
		tipus = nullptr;
	}
}

void TipusPropietat::setTipus(const char* tipus)
{
	if (tipus == nullptr || strlen(tipus) == 0)
	{
		throw "El tipus és obligatori!";
	}
	if (this->tipus != nullptr) //Isidre no té aquesta comprovació
	{
		delete[] this->tipus;
	}
	this->tipus = new char[strlen(tipus) + 1];
	strcpy(this->tipus, tipus);
}

const char* TipusPropietat::getTipus() const
{
	return tipus;
}

TipusPropietat& TipusPropietat::operator=(const TipusPropietat& tp)
{
	if (this != &tp)
	{
		setTipus(tp.tipus);
	}
	return *this;
}

bool TipusPropietat::operator==(const TipusPropietat& tp) const
{
	if (tipus == nullptr || tp.tipus == nullptr)
	{
		return false;
	}
	return strcmp(tipus, tp.tipus) == 0;

}

bool TipusPropietat::operator!=(const TipusPropietat& tp) const
{
	return !(*this == tp);
}



