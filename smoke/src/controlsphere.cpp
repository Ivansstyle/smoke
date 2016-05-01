#include "controlsphere.h"

#ifdef __APPLE__
  #include <OpenGL/gl.h>
  #include <OpenGL/glu.h>
#endif

#ifdef __linux__
  #include <GL/gl.h>
  #include <GL/glu.h>
#endif

#include <iostream>
#include <cmath>

ControlSphere::ControlSphere() : m_pos(0.0,0.0,-3) , m_r(0.1) , m_speed(0.005f)
{

}

ControlSphere::~ControlSphere()
{

}

Vec4 ControlSphere::GetPos() const
{
    return m_pos;
}

void ControlSphere::SetPos(Vec4 _pos)
{
    m_pos = _pos;
}

GLdouble ControlSphere::GetR() const
{
    return m_r;
}

void ControlSphere::SetR(GLdouble _r)
{
    m_r = _r;
}

void ControlSphere::draw()
{
      glPushMatrix();
      glTranslatef(m_pos.m_x,m_pos.m_y,m_pos.m_z);

      GLUquadricObj *quadric;
      quadric = gluNewQuadric();
      gluQuadricDrawStyle(quadric, GLU_FILL );
      gluSphere( quadric , m_r , 16 , 16 );
      gluDeleteQuadric(quadric);
      glPopMatrix();
}

void ControlSphere::Move(Vec4 _move)
{
  m_pos.m_x += _move.m_x;
  m_pos.m_y += _move.m_y;
  m_pos.m_z += _move.m_z;
}

void ControlSphere::update(Event* event)
{
 if (event->left) {Move(Vec4(-1.0f*m_speed,0.0,0.0));}
 else if (event->right) {Move(Vec4(1.0f*m_speed,0.0,0.0));}
 else if (event->down) {Move(Vec4(0.0,0.0,1.0f *m_speed));}
 else if (event->up) {Move(Vec4(0.0,0.0,-1.0f * m_speed));}
 else if (event->shift) {Move(Vec4 (0.0,1.0f * m_speed, 0.0));}
 else if (event->ctrl) {Move(Vec4 (0.0, -1.0f * m_speed, 0.0));}
}

Vec4 ControlSphere::SphereCollisionNormal(Vec4 _ppos)
{
  if (SphereCollision(_ppos))
  {
    if ((m_pos - _ppos) == Vec4(0,0,0))
    {
      return Vec4(0,1.0f,0);
    }
    else return Vec4((_ppos.m_x - m_pos.m_x) / m_collision_distance,
                     (_ppos.m_y - m_pos.m_y) / m_collision_distance,
                     (_ppos.m_z - m_pos.m_z) / m_collision_distance);
  }
  else
  {
    m_collision_distance = 0;
    return Vec4(0,0,0);
  }
}

bool ControlSphere::SphereCollision(Vec4 _ppos)
{
  if ((m_pos - _ppos) == Vec4(0,0,0))
  {
    return true;
  }
  else
  {
    m_collision_distance = sqrt(pow((_ppos.m_x - m_pos.m_x),2) +
                                pow((_ppos.m_y - m_pos.m_y),2) +
                                pow((_ppos.m_z - m_pos.m_z),2));

    if (m_collision_distance <= m_r) {return true;}
    else return false;
  }
}

Vec4 ControlSphere::SetBackToSpace(Vec4 _normal)
{
  return (_normal * (m_r + 0.01) + m_pos);
}

