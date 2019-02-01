#include "StdAfx.h"
#include "Kwadrat.h"


CKwadrat::CKwadrat(void)
{
}


CKwadrat::~CKwadrat(void)
{
}
CKwadrat::CKwadrat(int x1, int y1, int x2, int y2, double r, double g, double b) 
{ 
	wierzcholek[0]=CPunkt(x1,y1,0); 
	wierzcholek[1]=CPunkt(x1,y2,0); 
	wierzcholek[2]=CPunkt(x2,y2,0); 
	wierzcholek[3]=CPunkt(x2,y1,0); 
	kolor[0]=r; 
	kolor[1]=g; 
	kolor[2]=b; 
	for(int i=0;i<3;i++) 
	{ 
		rotacja[i]=0; 
		translacja[i]=0; 
	} 
	hide=0;
}

void CKwadrat::Rysuj(){ // funkcja rysuj1ca figure
glPushMatrix();
glTranslatef(translacja[0],translacja[1],translacja[2]); //translacja I rotacje:
glRotatef( rotacja[0], 1.0, 0.0, 0.0 );//rotate about the X axis
glRotatef( rotacja[1], 0.0, 1.0, 0.0 );//rotate about the Y axis
glRotatef( rotacja[2], 0.0, 0.0, 1.0 );//rotate about the Z axis
if (!hide) {
glColor3f(kolor[0],kolor[1],kolor[2]);//ustawienie koloru



glBegin( GL_QUADS ); //rysujemy czworok¹t

glVertex3f( wierzcholek[0].pozycja[0], wierzcholek[0].pozycja[1],wierzcholek[0].pozycja[2] );

glVertex3f( wierzcholek[1].pozycja[0], wierzcholek[1].pozycja[1],wierzcholek[1].pozycja[2] );

glVertex3f( wierzcholek[2].pozycja[0], wierzcholek[2].pozycja[1],wierzcholek[2].pozycja[2] );

glVertex3f( wierzcholek[3].pozycja[0], wierzcholek[3].pozycja[1],wierzcholek[3].pozycja[2] );
glEnd();


}
glPopMatrix();// restore matrix after transform, koniec przekszta³cen na wybranym obiekcie
}
