#pragma once

#include "Figura.h"

class CProstopad : public CFigura
{
public:
	CProstopad(void);
	~CProstopad(void);
	CProstopad(int x1, int y1, int x2, int y2, double r, double g, double b);
	void Rysuj();
private:
	CPunkt wierzcholek[8]; // wspolrzedne wierzcholkow 
};
