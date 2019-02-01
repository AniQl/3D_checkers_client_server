#pragma once
#include "figura.h"
class CLinie : public CFigura
{
public:
	CLinie(void); //domyslny konstruktor
	CLinie(double r, double g, double b); //domyslny konstruktor
	~CLinie(void); //destruktor
	void Rysuj(void); // funkcja rysuj¹ca figurê
private:
};

