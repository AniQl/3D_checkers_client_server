#pragma once
#include "figura.h"
class CKwadrat: public CFigura
{
public:
CKwadrat(void); //domyslny konstruktor
CKwadrat(int x1, int y1, int x2, int y2,double r, double g, double b); // konstruktor, kt�ryautomatycznie przypisuje warto�ci wierzcho�kom i ustala kolor kwadratu
~CKwadrat(void); //destruktor
void Rysuj(void); // funkcja rysuj�ca figur�
private:
CPunkt wierzcholek[4]; // wsp�lrz�dne wierzcho�k�w
};