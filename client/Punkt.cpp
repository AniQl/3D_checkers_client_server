#include "StdAfx.h"
#include "Punkt.h"


CPunkt::CPunkt(int x, int y, int z) // nasz konstruktor
{
	pozycja[0]=x;
	pozycja[1]=y;
	pozycja[2]=z;
}	

CPunkt::CPunkt(void)
{
}
CPunkt::~CPunkt(void)
{
}

void CPunkt::rysuj( double r, double g, double b)
{ //rysuje punkt w przestrzeni
glColor3f(r,g,b); //ustalamy kolor punktu
glBegin(GL_POINTS); //rysujemy punkt
glVertex3f(pozycja[0], pozycja[1], pozycja[2]);
glEnd();
} 

void CPunkt::przesun( int dx, int dy, int dz){
//przesuwa punkt w przestrzeni
pozycja[0]+=dx;
pozycja[1]+=dy;
pozycja[2]+=dz; 
}