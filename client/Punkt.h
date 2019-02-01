#pragma once
#include "GL/glut.h" // GL/glut.h includes gl.h and glu.h
class CPunkt
{
public: //metody i atrybuty dostepne dla wszystkich
CPunkt(void); //konstruktor domyslny
CPunkt(int x, int y, int z); //nasz konstruktor

public:

~CPunkt(void);
int pozycja[3]; //tablica ze wspolrzednymi punktu
void rysuj(double r, double g, double b); // metoda rysujaca punkt
void przesun(int dx, int dy, int dz);//metoda zmieniajaca wspolrzedne punktu
};