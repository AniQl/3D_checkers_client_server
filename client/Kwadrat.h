#pragma once
#include "figura.h"
class CKwadrat: public CFigura
{
public:
CKwadrat(void); //domyslny konstruktor
CKwadrat(int x1, int y1, int x2, int y2,double r, double g, double b); // konstruktor, któryautomatycznie przypisuje wartoœci wierzcho³kom i ustala kolor kwadratu
~CKwadrat(void); //destruktor
void Rysuj(void); // funkcja rysuj¹ca figurê
private:
CPunkt wierzcholek[4]; // wspólrzêdne wierzcho³ków
};