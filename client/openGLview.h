#pragma once
#include "figura.h"
#include "Kwadrat.h"
#include "Kolo.h"
#include "Prostopad.h"
#include "Kula.h"
#include "Linie.h"
#include"GL/glut.h"

class openGLview
{
public:
	CFigura * figury[108]; 
	CFigura * linie;

	char pola[36];


	int numer;
	int numerek = -1;
	int dostep = 1;

	int winner = 0;
	int gracz1 = 0;
	int gracz2 = 0;

	openGLview(void);
	~openGLview(void);
	void keyboard( unsigned char key, int x, int y); 
	void openGLview::display(void);
	void resize(int width, int height);
	void rysuj_figury(void);
	void animacja(void);
	void drawText(int x, int y, char *string);
	void sprawdz();
	void reset(int gracz);
	
};

