#include "StdAfx.h"
#include "Prostopad.h"


CProstopad::CProstopad(void)
{
}


CProstopad::~CProstopad(void)
{
}

CProstopad::CProstopad(int x1, int y1, int x2, int y2, double r, double g, double b)
{
	wierzcholek[0] = CPunkt(x1, y1, 0);
	wierzcholek[1] = CPunkt(x2, y1, 0);
	wierzcholek[2] = CPunkt(x2, y2, 0);
	wierzcholek[3] = CPunkt(x1, y2, 0);
	wierzcholek[4] = CPunkt(x1, y1, 10);
	wierzcholek[5] = CPunkt(x2, y1, 10);
	wierzcholek[6] = CPunkt(x2, y2, 10);
	wierzcholek[7] = CPunkt(x1, y2, 10);

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

void CProstopad::Rysuj()
{
	glPushMatrix();// save matrix prior to transform, pozwala na zmiane pozycji i orientacji tylko jednego obiektu 
	glTranslatef(translacja[0], translacja[1], translacja[2]); //translacja I rotacje: 
	glRotatef(rotacja[0], 1.0, 0.0, 0.0);//rotate about the X axis 
	glRotatef(rotacja[1], 0.0, 1.0, 0.0);//rotate about the Y axis 
	glRotatef(rotacja[2], 0.0, 0.0, 1.0);//rotate about the Z axis 
	if (!hide) {
		glColor3f(kolor[0], kolor[1], kolor[2]);//ustawienie koloru 
		glBegin(GL_POLYGON); //rysujemy czworok¹t 
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glVertex3f(wierzcholek[0].pozycja[0], wierzcholek[0].pozycja[1], wierzcholek[0].pozycja[2]);
		glVertex3f(wierzcholek[1].pozycja[0], wierzcholek[1].pozycja[1], wierzcholek[1].pozycja[2]);
		glVertex3f(wierzcholek[2].pozycja[0], wierzcholek[2].pozycja[1], wierzcholek[2].pozycja[2]);
		glVertex3f(wierzcholek[3].pozycja[0], wierzcholek[3].pozycja[1], wierzcholek[3].pozycja[2]);
		glVertex3f(wierzcholek[4].pozycja[0], wierzcholek[4].pozycja[1], wierzcholek[4].pozycja[2]);
		glVertex3f(wierzcholek[5].pozycja[0], wierzcholek[5].pozycja[1], wierzcholek[5].pozycja[2]);
		glVertex3f(wierzcholek[6].pozycja[0], wierzcholek[6].pozycja[1], wierzcholek[6].pozycja[2]);
		glVertex3f(wierzcholek[7].pozycja[0], wierzcholek[7].pozycja[1], wierzcholek[7].pozycja[2]);



		glVertex3f(wierzcholek[0].pozycja[0], wierzcholek[0].pozycja[1], wierzcholek[0].pozycja[2]);
		glVertex3f(wierzcholek[4].pozycja[0], wierzcholek[4].pozycja[1], wierzcholek[4].pozycja[2]);
		glVertex3f(wierzcholek[1].pozycja[0], wierzcholek[1].pozycja[1], wierzcholek[1].pozycja[2]);
		glVertex3f(wierzcholek[5].pozycja[0], wierzcholek[5].pozycja[1], wierzcholek[5].pozycja[2]);
		glVertex3f(wierzcholek[2].pozycja[0], wierzcholek[2].pozycja[1], wierzcholek[2].pozycja[2]);
		glVertex3f(wierzcholek[6].pozycja[0], wierzcholek[6].pozycja[1], wierzcholek[6].pozycja[2]);
		glVertex3f(wierzcholek[3].pozycja[0], wierzcholek[3].pozycja[1], wierzcholek[3].pozycja[2]);
		glVertex3f(wierzcholek[7].pozycja[0], wierzcholek[7].pozycja[1], wierzcholek[7].pozycja[2]);

		glVertex3f(wierzcholek[0].pozycja[0], wierzcholek[0].pozycja[1], wierzcholek[0].pozycja[2]);
		glVertex3f(wierzcholek[3].pozycja[0], wierzcholek[3].pozycja[1], wierzcholek[3].pozycja[2]);
		glVertex3f(wierzcholek[1].pozycja[0], wierzcholek[1].pozycja[1], wierzcholek[1].pozycja[2]);
		glVertex3f(wierzcholek[2].pozycja[0], wierzcholek[2].pozycja[1], wierzcholek[2].pozycja[2]);
		glVertex3f(wierzcholek[4].pozycja[0], wierzcholek[4].pozycja[1], wierzcholek[4].pozycja[2]);
		glVertex3f(wierzcholek[7].pozycja[0], wierzcholek[7].pozycja[1], wierzcholek[7].pozycja[2]);
		glVertex3f(wierzcholek[5].pozycja[0], wierzcholek[5].pozycja[1], wierzcholek[5].pozycja[2]);
		glVertex3f(wierzcholek[6].pozycja[0], wierzcholek[6].pozycja[1], wierzcholek[6].pozycja[2]);
		glEnd();


		glColor3f(0, 0, 0);
		glBegin(GL_LINES); //rysujemy czworok¹t 

		glVertex3f(wierzcholek[0].pozycja[0], wierzcholek[0].pozycja[1], wierzcholek[0].pozycja[2]);
		glVertex3f(wierzcholek[1].pozycja[0], wierzcholek[1].pozycja[1], wierzcholek[1].pozycja[2]);
		glVertex3f(wierzcholek[2].pozycja[0], wierzcholek[2].pozycja[1], wierzcholek[2].pozycja[2]);
		glVertex3f(wierzcholek[3].pozycja[0], wierzcholek[3].pozycja[1], wierzcholek[3].pozycja[2]);
		glVertex3f(wierzcholek[4].pozycja[0], wierzcholek[4].pozycja[1], wierzcholek[4].pozycja[2]);
		glVertex3f(wierzcholek[5].pozycja[0], wierzcholek[5].pozycja[1], wierzcholek[5].pozycja[2]);
		glVertex3f(wierzcholek[6].pozycja[0], wierzcholek[6].pozycja[1], wierzcholek[6].pozycja[2]);
		glVertex3f(wierzcholek[7].pozycja[0], wierzcholek[7].pozycja[1], wierzcholek[7].pozycja[2]);



		glVertex3f(wierzcholek[0].pozycja[0], wierzcholek[0].pozycja[1], wierzcholek[0].pozycja[2]);
		glVertex3f(wierzcholek[4].pozycja[0], wierzcholek[4].pozycja[1], wierzcholek[4].pozycja[2]);
		glVertex3f(wierzcholek[1].pozycja[0], wierzcholek[1].pozycja[1], wierzcholek[1].pozycja[2]);
		glVertex3f(wierzcholek[5].pozycja[0], wierzcholek[5].pozycja[1], wierzcholek[5].pozycja[2]);
		glVertex3f(wierzcholek[2].pozycja[0], wierzcholek[2].pozycja[1], wierzcholek[2].pozycja[2]);
		glVertex3f(wierzcholek[6].pozycja[0], wierzcholek[6].pozycja[1], wierzcholek[6].pozycja[2]);
		glVertex3f(wierzcholek[3].pozycja[0], wierzcholek[3].pozycja[1], wierzcholek[3].pozycja[2]);
		glVertex3f(wierzcholek[7].pozycja[0], wierzcholek[7].pozycja[1], wierzcholek[7].pozycja[2]);

		glVertex3f(wierzcholek[0].pozycja[0], wierzcholek[0].pozycja[1], wierzcholek[0].pozycja[2]);
		glVertex3f(wierzcholek[3].pozycja[0], wierzcholek[3].pozycja[1], wierzcholek[3].pozycja[2]);
		glVertex3f(wierzcholek[1].pozycja[0], wierzcholek[1].pozycja[1], wierzcholek[1].pozycja[2]);
		glVertex3f(wierzcholek[2].pozycja[0], wierzcholek[2].pozycja[1], wierzcholek[2].pozycja[2]);
		glVertex3f(wierzcholek[4].pozycja[0], wierzcholek[4].pozycja[1], wierzcholek[4].pozycja[2]);
		glVertex3f(wierzcholek[7].pozycja[0], wierzcholek[7].pozycja[1], wierzcholek[7].pozycja[2]);
		glVertex3f(wierzcholek[5].pozycja[0], wierzcholek[5].pozycja[1], wierzcholek[5].pozycja[2]);
		glVertex3f(wierzcholek[6].pozycja[0], wierzcholek[6].pozycja[1], wierzcholek[6].pozycja[2]);
		glEnd();



	}


	glPopMatrix();// restore matrix after transform, koniec przekszta³cen na wybranym obiekcie 

}