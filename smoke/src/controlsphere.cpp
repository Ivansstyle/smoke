#include "controlsphere.h"

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

ControlSphere::ControlSphere() : m_pos(0.0,0.0,-3) , m_r(0.25)
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
