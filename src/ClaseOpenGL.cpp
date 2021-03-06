
#include "ClaseOpenGL.h"
///Copyright (C) <2017>  <Eliseo Rivera Silva> curso.tareas@gmail.com


ClaseOpenGL::ClaseOpenGL()
{
theta=0.0;
objeto=new modelo3D();
objeto->leer();

};
void ClaseOpenGL::inicializar(){

    /////Camera
Rcamera=15;
phiCamera=PI/4.0;
thetaCamera=PI/4.0;
camerafactor=0.005;
////

objeto->BodyFramedefinirRz(30*PI/180.0);
objeto->BodyFramerotarZ();
objeto->BodyFrametrasladar({2,5,5});
objeto->definir_x_LocalAxisRotation(0.01);
objeto->definirRx(0.01);

    glClearColor(1,1,1,0.5);
    glEnable( GL_LINE_SMOOTH );
    glHint( GL_LINE_SMOOTH_HINT, GL_NICEST );
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_DEPTH_TEST);					// hidden surface removal
    glShadeModel(GL_SMOOTH);					// use smooth shading
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
    glEnable(GL_COLOR_MATERIAL );

    }


ClaseOpenGL::~ClaseOpenGL()
{
delete objeto;
}
void ClaseOpenGL::renderizar(){


        radians =  double(PI*(angle-90.0f)/180.0f);

        // calculate the camera's position

         cameraX=Rcamera*cos(phiCamera)*cos(thetaCamera);
         cameraY=Rcamera*cos(phiCamera)*sin(thetaCamera);
         cameraZ=Rcamera*sin(phiCamera);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT );
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(cameraX ,cameraY  ,cameraZ , 0, 0,0 , 0.0, 0,fabs(cos(thetaCamera))*sin(phiCamera+0.1));

       Drawarrow3D({0,0,0},{4,0,0},rojo,0.03,0.05);
        Drawarrow3D({0,0,0},{0,4,0},verde,0.03,.05);
        Drawarrow3D({0,0,0},{0,0,4},azul,0.03,0.05);

       objeto->dibujar();
        dibujarBodyFrame(*objeto);

}
void ClaseOpenGL::preparar(float dt){
  objeto->x_LocalAxisRotation();

}
void ClaseOpenGL::Resize(int width, int height){

  glViewport(0, 0, width, height);		// reset the viewport to new dimensions
        glMatrixMode(GL_PROJECTION);			// set projection matrix current matrix
        glLoadIdentity();						// reset projection matrix
        // calculate aspect ratio of window
        gluPerspective(52.0f,(GLdouble)width/(GLdouble)height,1.0f,1000.0f);
        glMatrixMode(GL_MODELVIEW);				// set modelview matrix
        glLoadIdentity();						// reset modelview matrix
}
void ClaseOpenGL::Drawarrow3D( point3d A,  point3d B, point3d color, double cota1,double R)
{

double color1,color2,color3,a,b,c,d,e;



color1=color.x;//abs(color1/255);
color2=color.y;//abs(color2/255);
color3=color.z;//abs(color3/255);

glColor3f( color1,color2, color3);

point3d n=B-A,np,vertex[10],normallight;
n.normalize();
if(n.z!=0)np={1,1,(-1/n.z)*(n.x+n.y)};
else if(n.y!=0)np={1,(-1/n.y)*(n.x+n.z),1};
else np={(-1/n.x)*(n.y+n.z),1,1};

np.normalize();
vertex[0]=R*np;
vertex[2]=R*(n*np).normalize();
vertex[1]=R*((0.5)*(vertex[2]-vertex[0])+vertex[0]).normalize();
vertex[4]=R*(n*vertex[2]).normalize();
vertex[3]=R*((0.5)*(vertex[4]-vertex[2])+vertex[2]).normalize();
vertex[6]=R*(n*vertex[4]).normalize();
vertex[5]=R*((0.5)*(vertex[6]-vertex[4])+vertex[4]).normalize();
vertex[7]=R*((0.5)*(vertex[0]-vertex[6])+vertex[6]).normalize();
vertex[8]=vertex[0];
vertex[9]=vertex[1];
int nx=8;
double d_thetha,fraccion=0.1,radioflecha=R+.7*R;
d_thetha=2.0f*PI/nx;


  ///tubos
 glBegin( GL_TRIANGLE_STRIP );

         for(int i=0;i<9;i++)
               {

normallight=n*(vertex[i-1]-vertex[i+1]);
normallight.normalize();
glNormal3f(normallight.x, normallight.y, normallight.z);
                 glVertex3f(vertex[i].x+A.x,vertex[i].y+A.y,vertex[i].z+A.z);

glVertex3f(vertex[i].x+B.x-fraccion*(B.x-A.x),vertex[i].y+B.y-fraccion*(B.y-A.y),vertex[i].z+B.z-fraccion*(B.z-A.z));

    // top face

                }

glEnd();



//flecha
vertex[0]=radioflecha*np;
vertex[2]=radioflecha*(n*np).normalize();
vertex[1]=radioflecha*((0.5)*(vertex[2]-vertex[0])+vertex[0]).normalize();
vertex[4]=radioflecha*(n*vertex[2]).normalize();
vertex[3]=radioflecha*((0.5)*(vertex[4]-vertex[2])+vertex[2]).normalize();
vertex[6]=radioflecha*(n*vertex[4]).normalize();
vertex[5]=radioflecha*((0.5)*(vertex[6]-vertex[4])+vertex[4]).normalize();
vertex[7]=radioflecha*((0.5)*(vertex[0]-vertex[6])+vertex[6]).normalize();
vertex[8]=vertex[0];
vertex[9]=vertex[1];
point3d Ap(B-fraccion*(B-A));



 glBegin( GL_TRIANGLE_STRIP );  //flecha

         for(int i=0;i<9;i++)
               {

normallight=n*(vertex[i-1]-vertex[i+1]);
normallight.normalize();
glNormal3f(normallight.x, normallight.y, normallight.z);
                 glVertex3f(vertex[i].x+Ap.x,vertex[i].y+Ap.y,vertex[i].z+Ap.z);


glNormal3f(n.x, n.y, n.z);
glVertex3f(Ap.x+fraccion*(B-A).x,Ap.y+fraccion*(B-A).y,Ap.z+fraccion*(B-A).z);

    // top face

                }

glEnd();


}

void ClaseOpenGL::dibujarBodyFrame(const modelo3D &model){

        Drawarrow3D(model.O,model.O+model.ux,rojo,0.03,0.02);
        Drawarrow3D(model.O,model.O+model.uy,verde,0.03,.02);
        Drawarrow3D(model.O,model.O+model.uz,azul,0.03,0.02);

}


