#pragma once
#include "Propietat.h"
class PropietatEnVenda final:
    public Propietat
{
private:
    bool teCarregues;

public:
	PropietatEnVenda(const char* codi, const char* nom, const TipusPropietat& tipus, bool teCarregues);
    ~PropietatEnVenda();

    //Getters i setters
	bool getTeCarregues() const;
	void setTeCarregues(bool teCarregues);


};

