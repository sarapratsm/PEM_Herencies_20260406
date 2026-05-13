#include "PropietatEnVenda.h"

PropietatEnVenda::PropietatEnVenda(const char* codi, const char* nom, const TipusPropietat& tipus, bool teCarregues)
	: Propietat(codi, nom, &tipus), teCarregues(teCarregues)
{
	setTeCarregues(teCarregues);
}

PropietatEnVenda::~PropietatEnVenda()
{
	Propietat::~Propietat();
}

bool PropietatEnVenda::getTeCarregues() const
{
	return this->teCarregues;
}

void PropietatEnVenda::setTeCarregues(bool teCarregues)
{
	this->teCarregues = teCarregues;
}
