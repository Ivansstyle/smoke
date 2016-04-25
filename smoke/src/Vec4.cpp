#include "Vec4.h"
#include "Mat4.h"

void Vec4::colourGL() const
{
  #warning "implement this"
}

Vec4 Vec4::cross(const Vec4 &_rhs) const
{

}

float Vec4::dot(const Vec4 &_rhs) const
{

}

float Vec4::length() const
{

}

float Vec4::lengthSquared() const
{

}

void Vec4::normalGL()
{

}

void Vec4::normalize()
{

}

Vec4 Vec4::operator *(const Mat4 &_r) const
{

    //return Vec4(m_x * _r,
             //   m_y * _r,
               // m_z * _r,)
}

Vec4 Vec4::operator *(GLfloat _rhs) const
{
 return Vec4(m_x*_rhs,m_y*_rhs,m_z*_rhs);
}

void Vec4::operator *=(GLfloat _rhs)
{
    m_x *= _rhs;
    m_y *= _rhs;
    m_z *= _rhs;
}

Vec4 Vec4::operator +(const Vec4 &_r) const
{

}

void Vec4::operator +=(const Vec4 &_r)
{
    m_x += _r.m_x;
    m_y += _r.m_y;
    m_z += _r.m_z;
    m_w += _r.m_w;
}

Vec4 Vec4::operator -(const Vec4 &_rhs) const
{
  return Vec4(m_x-_rhs.m_x,
              m_y-_rhs.m_y,
              m_z-_rhs.m_z,
              m_w);
}

void Vec4::operator -=(const Vec4 &_r) const
{

}

bool Vec4::operator ==(const Vec4 &_rhs) const
{

}

GLfloat & Vec4::operator [](int _i)
{
    assert(_i>=0 && _i<=2);
    return m_openGL[_i];
}

void Vec4::set(GLfloat _x, GLfloat _y, GLfloat _z, GLfloat _w)
{

}

void Vec4::vertexGL() const
{

}

Vec4 Vec4::refl(Vec4 _vec)
{
    Vec4 reflected(1,1,1
                );
    return reflected;
}
