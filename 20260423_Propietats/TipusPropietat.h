#pragma once

class TipusPropietat final
{
	char* tipus;

public:
	TipusPropietat(const char* tipus);
	TipusPropietat(const TipusPropietat& tp);
	virtual ~TipusPropietat();
	TipusPropietat& operator=(const TipusPropietat& tp);

	//Getters i setters
	const char* getTipus() const;
	void setTipus(const char* tipus);

	//Operador == per comparar dos tipus de propietat
	bool operator==(const TipusPropietat& tp) const;
	bool operator!=(const TipusPropietat& tp) const;

};

