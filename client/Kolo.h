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
void Rysuj(void); // funkcja rysuj¹ca figurê
CKolo(double p, int x, int y, int z, double r, double g, double b); //prze³adowany konstruktor (ppromieñ,x, y, z - pozycja œrodka okrêgu)
CPunkt srodek; // wspó³rzêdne œrodka
double promien; // promieñ

};

