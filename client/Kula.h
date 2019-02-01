#pragma once
//ahahahha
#include "Figura.h"

class CKula : public CFigura
{
public:
	CKula(void);
	~CKula(void);
	CKula(int x1, int y1, int p, double r, double g, double b);
	void Rysuj();
private:
	CPunkt wierzcholek[1]; // wspolrzedne wierzcholkow 
};

