#include "StdAfx.h"
#include "Kolo.h"


CKolo::CKolo(void)
{
}


CKolo::~CKolo(void)
{
}

CKolo::CKolo(double p, int x, int y, int z, double r, double g, double b){ //prze³adowany konstruktor (r-promieñ,x,y, z - pozycja œrodka okrêgu)
promien=p;
srodek.pozycja[0]=x;
srodek.pozycja[1]=y;
srodek.pozycja[2]=z;
kolor[0]=r;
kolor[1]=g;
kolor[2]=b;
for (int i=0;i<3;i++){
translacja[i]=0;
rotacja[i]=0;
}
hide=0;
}
void CKolo::Rysuj(){ // funkcja rysuj¹ca figurê
double angle, vectorX, vectorY, vectorX1, vectorY1;
glPushMatrix();// save matrix prior to transform, pozwala na zmianê pozycji i orientacji tylko jednego obiektu
glTranslatef(translacja[0],translacja[1],translacja[2]); //kolejnoœæ wykonania operacji translacji i rotacji definiuje wzglêdem którego uk³adu obracany jest obiekt
glRotatef( rotacja[0], 1.0, 0.0, 0.0 );//rotate about the X axis
glRotatef( rotacja[1], 0.0, 1.0, 0.0 );//rotate about the Y axis
glRotatef( rotacja[2], 0.0, 0.0, 1.0 );//rotate about the Z axis
if (!hide) {
glColor3f(kolor[0],kolor[1],kolor[2]);//ustawienie koloru
glBegin(GL_TRIANGLES);
vectorX1=srodek.pozycja[0];
vectorY1=srodek.pozycja[1];
for(int i=0;i<=360;i++)//rysujemy ko³o sk³adaj¹ce sie z 360 trójk¹tów
{
angle=i/57.29577957795135;
vectorX=srodek.pozycja[0]+(promien*sin(angle));
vectorY=srodek.pozycja[1]+(promien*cos(angle));
glVertex3d(srodek.pozycja[0],srodek.pozycja[1],srodek.pozycja[2]);
glVertex3d(vectorX1,vectorY1,srodek.pozycja[2]);
glVertex3d(vectorX,vectorY,srodek.pozycja[2]);
vectorY1=vectorY;
vectorX1=vectorX;
}
glEnd();
}
glPopMatrix();// restore matrix after transform, koniec przekszta3cen na wybranym obiekcie
}
