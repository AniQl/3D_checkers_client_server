#include "stdafx.h"
#include "Kula.h"


CKula::CKula()
{
}


CKula::~CKula()
{
}


CKula::CKula(int x1, int y1, int p, double r, double g, double b)
{
	wierzcholek[0] = CPunkt(x1, y1, 0);

	kolor[0] = r;
	kolor[1] = g;
	kolor[2] = b;
	hide = false;
	translacja[0] = 0;
	translacja[1] = 0;
	translacja[2] = 0;
	rotacja[0] = 0;
	rotacja[1] = 0;
	rotacja[2] = 0;
}

void CKula::Rysuj()
{

}