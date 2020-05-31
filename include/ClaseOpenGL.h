#ifndef CLASEOPENGL_H
#define CLASEOPENGL_H
#include <gl/gl.h>
#include<GL/GLU.h>
//Copyright (C) <2017>  <Eliseo Rivera Silva> curso.tareas@gmail.com


/// Usted puede distribuir este código libre y gratuitamente, no obstante no puede omitir la autoría del programador
///Eliseo Rivera Silva 2017 curso.tareas@gmail.com
#include"modelo3D.h"
#define PI 3.14159265
class ClaseOpenGL
{
    public:
        ClaseOpenGL();
        virtual ~ClaseOpenGL();
        void inicializar();
        void preparar(float dt);
        void renderizar();
        void Resize(int width, int height);
        float theta;
        void  Drawarrow3D( point3d A,  point3d B, point3d color, double cota1,double R=0.01);

        float  cameraX,  cameraZ, cameraY ,   mouseX,mouseY, camerafactor,angle;
        float Rcamera, phiCamera, thetaCamera;
        float radians;
        modelo3D *objeto;
        point3d rojo={1,0.0,0.0};
        point3d verde={0.0,1,0.0};
        point3d azul={0.0,0.0,1};
        void dibujarBodyFrame(const modelo3D &modelo);

};

#endif // CLASEOPENGL_H
