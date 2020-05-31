#ifndef TRIANGLE3D_H
#define TRIANGLE3D_H
#include"point3d.h"

class Triangle3D
{
public:
Triangle3D();
~Triangle3D();
point3d vertices[3];
point3d N;
point3d normal();
void definirRz(float dtheta);
void dibujar();
void rotar(float dtheta);
};

#endif // TRIANGLE3D_H
