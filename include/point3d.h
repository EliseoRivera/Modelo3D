#ifndef POINT3D_H
#define POINT3D_H
#include <math.h>
class point3d
{
    public:
    double x;
    double y;
    double z;
    point3d(double _x, double _y, double _z);
    point3d();
    ~point3d();
    point3d (const point3d &p);
    point3d operator+(const point3d &p)const;
    point3d operator*(const point3d &p)const;
    point3d operator-(const point3d &p)const;
    friend point3d operator*(const double &s, const point3d &p);
    int operator==(point3d &p);
    int operator!=(point3d &p);
    double& operator[](int i);
    double dotProduct(const point3d &p);
    double magnitude() const;
    point3d&   normalize();
    point3d&  operator =( const point3d &B);
 void mostrar();
};
#endif // POINT3D_H
