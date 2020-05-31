#ifndef MODELO3D_H
#define MODELO3D_H
#include"Triangle3D.h"
#include"Matrix.h"
#include<fstream>
#include <iostream>
#include <gl/gl.h>
#include<GL/GLU.h>
#define PI 3.14159265
//Copyright (C) <2017>  <Eliseo Rivera Silva> curso.tareas@gmail.com

using namespace std;
class modelo3D
{
    public:
int ntriangles;
Triangle3D* triangulos;
Matrix Rx,Ry,Rz;
modelo3D();

void leer();
virtual ~modelo3D();
modelo3D(int ntriangulos);
void dibujar();
void rotarX();  //local x axis rotation
void rotarY();  //local y axis rotation
void rotarZ();  //local z axis rotation
void definirRz(float theta);
void definirRy(float theta);
void definirRx(float theta);

void definir_x_LocalAxisRotation(float theta);
void x_LocalAxisRotation();
Matrix LARx;


void trasladar(point3d A);
ifstream archivo;

point3d ux,uy,uz,O; //local axis nad Origin
void BodyFramedefinirRx(float theta); //rotar marco de referencia alrededor del eje X
void BodyFramedefinirRy(float theta);
void BodyFramedefinirRz(float theta);
void BodyFrametrasladar(point3d A);
void BodyFramerotarX();
void BodyFramerotarY();
void BodyFramerotarZ();
Matrix BFRx,BFRy,BFRz,R;
point3d LocalMassCenter()const;
  point3d GlobalCenterMass()const;

};

#endif // MODELO3D_H
