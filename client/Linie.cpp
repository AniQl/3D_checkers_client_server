#include "StdAfx.h"
#include "Linie.h"


CLinie::CLinie(void)
{
}


CLinie::~CLinie(void)
{
}
CLinie::CLinie(double r, double g, double b)
{
	kolor[0] = r;
	kolor[1] = g;
	kolor[2] = b;
	for (int i = 0; i<3; i++)
	{
		rotacja[i] = 0;
		translacja[i] = 0;
	}
	hide = 0;
}

void CLinie::Rysuj(){ // funkcja rysuj1ca figure
	glPushMatrix();
	glTranslatef(translacja[0], translacja[1], translacja[2]); //translacja I rotacje:
	glRotatef(rotacja[0], 1.0, 0.0, 0.0);//rotate about the X axis
	glRotatef(rotacja[1], 0.0, 1.0, 0.0);//rotate about the Y axis
	glRotatef(rotacja[2], 0.0, 0.0, 1.0);//rotate about the Z axis
	if (!hide) {
		glColor3f(kolor[0], kolor[1], kolor[2]);//ustawienie koloru

		// osie X i Y i Z
		//Y
		glLineWidth(3);
		int x = 0, y = 0;
		for (int i = 0; i < 7; i++)
		{
			glBegin(GL_LINES);
			glVertex3f(-75 + x, -75, 0.05);
			glVertex3f(-75 + x, 75, 0.05);
			x += 25;
			glEnd();

			glBegin(GL_LINES);
			glVertex3f(-75, -75 + y, 0.05);
			glVertex3f(75, -75 + y, 0.05);
			y += 25;
			glEnd();
		}


	}
	glPopMatrix();// restore matrix after transform, koniec przekszta³cen na wybranym obiekcie
}
