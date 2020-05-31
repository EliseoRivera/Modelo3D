#include "point3d.h"
#include <iostream>
using namespace std;
point3d::point3d(double _x, double _y, double _z): x(_x), y(_y), z(_z) {};
point3d::point3d(){ x=0;  y=0; z=0;};
point3d::point3d (const point3d &p){x=p.x;y=p.y;z=p.z;};
point3d point3d::operator+(const point3d &p)const
{ return point3d(x + p.x, y + p.y, z + p.z); }
point3d point3d::operator*(const point3d &p)const
{ return point3d(y*p.z-z*p.y, z*p.x-x*p.z ,x*p.y-y*p.x); }
point3d point3d::operator-(const point3d &p) const
{ return point3d(x - p.x, y - p.y, z - p.z); }
point3d operator*(const double &s,const point3d &p){
    return point3d(s * p.x, s * p.y, s * p.z);
}
int point3d::operator==(point3d &p)
{ return ((x == p.x) && (y == p.y) && (z == p.z));}
int point3d::operator!=(point3d &p)
{ return !(*this == p); }
double& point3d::operator[](int i)
{ return ((i == 0) ? x : ((i == 1) ? y : z)); }
double point3d:: dotProduct(const point3d &p)
{ return (x*p.x + y*p.y + z*p.z); }

double point3d::magnitude() const
{ return sqrt(x*x + y*y + z*z);
};
point3d&   point3d::normalize(){
double a=magnitude();
if (a!=0){
     x=x/a;  y=y/a; z=z/a;
};
return *this;
 }
  point3d&  point3d::operator =( const point3d &B){
    x=B.x;  y=B.y; z=B.z;
 return *this;
 }
point3d::~point3d(){}
  void point3d::mostrar(){
          cout<<" x = "<<x<<endl;
          cout<<" y = "<<y<<endl;
          cout<<" z = "<<z<<endl;


      }
