#ifndef MATRIX_H
#define MATRIX_H
#include"point3d.h"
#include<iostream>
class Matrix
{
   public:
   double **aij;
   int n;
   int m;
   Matrix(point3d v);
   double cofactor (int i, int j);
   Matrix inversa();
   int size () const;
   Matrix Mij(int a,int b);
   point3d operator *(const point3d &P);
   Matrix(int nn,int mm);
   Matrix();
   void zero(int nn, int mm);
   void identity(int nn);
   void definir();
   void mostrar();
   double& ij(int i,int j);
   Matrix(const Matrix &B);
   Matrix operator +( const Matrix &A);
   Matrix& operator =( const Matrix &A);
   Matrix operator -( Matrix A);
   Matrix operator *( Matrix B);
   friend  Matrix operator*(double tt, Matrix &A);
  ~Matrix();
   double determinante();
};

#endif // MATRIX_H
