#pragma once
#include "figura.h"
#include <math.h>

class CKolo :
	public CFigura
{
public:
	CKolo(void);
	~CKolo(void);
	public:
void Rysuj(void); // funkcja rysuj�ca figur�
CKolo(double p, int x, int y, int z, double r, double g, double b); //prze�adowany konstruktor (ppromie�,x, y, z - pozycja �rodka okr�gu)
CPunkt srodek; // wsp�rz�dne �rodka
double promien; // promie�

};

