#include "Vec4.h"
#include "Mat4.h"
#include <cmath>
#include <cassert>

void Vec4::colourGL() const
{
  glColor4fv(m_openGL);
}

Vec4 Vec4::cross(const Vec4 &_rhs) const
{
  return Vec4(m_y * _rhs.m_z - m_z * _rhs.m_y,
              m_z * _rhs.m_x - m_x * _rhs.m_z,
              m_x * _rhs.m_y - m_y * _rhs.m_x,
              m_w);
}

float Vec4::dot(const Vec4 &_rhs) const
{
  return m_x *_rhs.m_x + m_y*_rhs.m_y + m_z*_rhs.m_z;
}

float Vec4::length() const
{
  return sqrt(m_x*m_x + m_y*m_y + m_z*m_z);
}

float Vec4::lengthSquared() const
{
  return m_x*m_x + m_y*m_y + m_z*m_z;
}

void Vec4::normalGL()
{
  glNormal3f(m_x, m_y, m_z);
}

void Vec4::normalize()
{
  float l = length();
  assert(l != 0.0f);
  m_x /= l;
  m_y /= l;
  m_z /= l;
}

//Vec4 Vec4::operator *(const Mat4 &_r) const
//{

//    return Vec4(m_x * _r,
//                m_y * _r,
//                m_z * _r,)
//}

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
  return Vec4(
        m_x + _r.m_x,
        m_y + _r.m_y,
        m_z + _r.m_z);

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

void Vec4::operator -=(const Vec4 &_r)
{

  m_x -= _r.m_x;
  m_y -= _r.m_y;
  m_z -= _r.m_z;
}

bool Vec4::operator ==(const Vec4 &_rhs) const
{
  if (m_x == _rhs.m_x &&
      m_y == _rhs.m_y &&
      m_z == _rhs.m_z) return true;
  else return false;

}

bool Vec4::operator !=(const Vec4 &_rhs) const
{
  if (m_x != _rhs.m_x ||
      m_y != _rhs.m_y ||
      m_z != _rhs.m_z) return true;
  else return false;

}

GLfloat & Vec4::operator [](int _i)
{
    assert(_i>=0 && _i<=2);
    return m_openGL[_i];
}

void Vec4::set(GLfloat _x, GLfloat _y, GLfloat _z, GLfloat _w)
{
  m_x = _x;
  m_y = _y;
  m_z = _z;
  m_w = _w;

}

void Vec4::vertexGL() const
{

}

Vec4 Vec4::refl(Vec4 _normal)
{
  Vec4 v = Vec4(m_x,m_y,m_z);
  return v - (_normal * 2.0f * (v.dot(_normal)));

}
