#include "StdAfx.h"
#include "openGLview.h"
#include <math.h>

int x = -75, y = -75, x1 = -25, y2 = -25;


openGLview::openGLview(void)
{
	int x = 0;
	int y = -25;
	int kolor = 0;
	//figury[0] = new CKolo(20,30,30,0,1,0,0);



	for (int k = 0; k < 36; k++)
	{
		if (k % 6 == 0)
		{
			y += 25;
			x = 0;
		}
		figury[k] = new CKwadrat(-75 + y, -75 + x, -50 + y, -50 + x, 0, 0, 1);
		//figury[k] = new CKwadrat(-75 + y, -75 + x, -50 + y, -50 + x, 0, 0, 1);
		x += 25;

	}
	x = 0;
	y = -25;
	for (int k = 36; k < 72; k++)
	{
		if (k % 6 == 0)
		{
			y += 25;
			x = 0;
		}
		figury[k] = new CProstopad(-65 + y, -65 + x, -55 + y, -55 + x, 1, 0, 0);
		figury[k]->Ukryj();
		//figury[k] = new CKwadrat(-75 + y, -75 + x, -50 + y, -50 + x, 0, 0, 1);
		x += 25;

	}
	x = 0;
	y = -25;
	for (int k = 72; k < 108; k++)
	{
		if (k % 6 == 0)
		{
			y += 25;
			x = 0;
		}
		figury[k] = new CKolo(8, -60 + y, -60 + x, 1, 1, 1, 1);
		figury[k]->Ukryj();
		//figury[k] = new CKwadrat(-75 + y, -75 + x, -50 + y, -50 + x, 0, 0, 1);
		x += 25;

	}

	linie = new CLinie(1, 0, 0);

	//pola[0] = 1;
	//pola[1] = 1;
	//pola[2] = 1;
	//pola[3] = 1;

}
openGLview::~openGLview(void)
{
	for (int i = 1; i < 108; i++) { //usuwany wszystkie dynamiczne obiekty
		delete figury[i];
	}
	delete linie;
}

void openGLview::rysuj_figury(void){

	for (int i = 0; i < 108; i++) {
		glPushName(i); //id obiektu - oblsuga myszki 
		figury[i]->rotacja[0] = -40;
		figury[i]->Rysuj();
	}

	linie->rotacja[0] = -40;
	linie->Rysuj();

	/*char nap[40];
	sprintf(nap, "Gracz1: %d", gracz1);
	drawText(0, 70, nap);

	char nap1[40];
	sprintf(nap1, "Gracz2: %d", gracz2);
	drawText(0, 60, nap1);*/



	char napis[40];
	glColor3f(1, 0.5, 0.5);
	if (dostep == 1)
	{
		sprintf(napis, "Twoja runda");
	}
	else if (dostep == 0)
	{
		sprintf(napis, "Czekaj");
	}
	drawText(-40, 70, napis);

	char napi[40];
	if (winner == 1)
	{
		sprintf(napi, "Wygrales");
		reset(1);
		drawText(-40, 0, napi);
		
	}
	else if (winner == 2)
	{
		sprintf(napi, "Przegrales");
		reset(1);
		drawText(-40, 0, napi);
	
	}
	//sprawdz();

}
void openGLview::display(void) {
	glClearColor(0, 0, 0, 0); //ustawiamy kolor t³a na czarny
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //czyœcimy bufory
	glEnable(GL_DEPTH_TEST); //uruchamiamy bufor g³êbi
	rysuj_figury(); //testowe rysowanie figur
	glutSwapBuffers();//przerzuca bufor do okna u¿ywanego
	glutPostRedisplay(); // oznacz okno jako to, które bêdzie aktualizowane.
}

void openGLview::resize(int width, int height) {
	glViewport(0, 0, width, height); //parametry okna
	glMatrixMode(GL_PROJECTION); //ustawienie kontekstu obliczeñ macierzowych na stos projekcji
	glLoadIdentity(); //za³adowanie macierzy jednostkowej jako aktulanej macierzy
	gluPerspective(45.0, (float)width / (float)height, 0.1, 1000.0); //ustawienie macierzy projekcji
	glMatrixMode(GL_MODELVIEW); //ustawienie kontekstu obliczeñ macierzowych na stos modelu
	glLoadIdentity(); //za³adowanie macierzy jednostkowej jako aktulanej macierzy
	gluLookAt( // ustawienie pocz¹tkowe kamery (po³o¿enie oka, punktu ref oraz kierunku wektora )
		0.0, 0.0, 200.0,
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0);
}

void openGLview::keyboard(unsigned char key, int x, int y)
{
	if (key == 109) { numer++; if (numer > 3) numer = 0; } //key m 
	if (key == 27) { exit(0); }// escape key is ascii 27 } 
}

/*void openGLview::animacja(void)
{
if (dostep==1)
{
char napis[40];
sprintf(napis, "Runda Gracza1");
drawText(0, 40, napis);
}
else if (dostep == 0)
{
char napis[40];
sprintf(napis, "Runda Gracza2");
drawText(0, 40, napis);
}
}*/


void openGLview::reset(int gracz)
{
	for (int i = 0; i < 108; i++)
	{
		figury[i]->hide = 1;
	}
	linie->hide = 1;

	WSACleanup();

}

void openGLview::drawText(int x, int y, char *string) // rysuje napis "string" w pozycji x, y 
{
	glRasterPos2f(x, y);//pozycja napisu 
	for (int i = 0; i < strlen(string); i++)//literka po literce 
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
};