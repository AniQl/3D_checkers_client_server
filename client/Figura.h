#pragma once
#include"Punkt.h"

class CFigura
{
public:
	CFigura(void);
	~CFigura(void);
	public:
virtual void Rysuj()=0;//rysuje figure
void Ukryj();//ukrywa figure
void Pokaz();//pokazuje figure
void Przesun(int dx, int dy, int dz);//ustawia zmienna odpowiedzialna za przesuniecie figury
void Obroc(double alfa, double beta, double gamma); //ustawia zmienna odpowiedzialna za obrot
public:
int kolor[3]; //kolor figury
bool hide; //okresla czy figura ma byc wyswietlana 1 - nie, 0 - tak
double translacja[3]; // przechowuje wspolrzedne przesuniecia w trzech osiach
double rotacja[3]; //przechowuje wspolrzedne obrotow w trzech osiach

};

