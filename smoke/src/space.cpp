#include "space.h"

Space::Space() : m_size(0,0,0), m_origin(0,0,0.0f)
{

}

Space::~Space()
{

}

void Space::init()
{

}


Vec4 Space::GetSize()
{
    return m_size;
}

void Space::SetSize(Vec4 _size)
{
    m_size = _size;
}

Vec4 Space::isInSpace(Vec4 _ppos)
{
    if      (_ppos.m_x > m_size.m_x) {_ppos.m_x = m_size.m_x; _ppos.m_w = -2;return _ppos;}
    else if (_ppos.m_y > m_size.m_y) {_ppos.m_y = m_size.m_y; _ppos.m_w = -2;return _ppos;}
    else if (_ppos.m_z > m_size.m_z) {_ppos.m_z = m_size.m_z; _ppos.m_w = -2;return _ppos;}
    else if (_ppos.m_x < -m_size.m_x){_ppos.m_x = -m_size.m_x;_ppos.m_w = -2;return _ppos;}
    else if (_ppos.m_y < -m_size.m_y){_ppos.m_y = -m_size.m_y;_ppos.m_w = -2;return _ppos;}
    else if (_ppos.m_z < -m_size.m_z){_ppos.m_z = -m_size.m_z;_ppos.m_w = -2;return _ppos;}
    else _ppos.m_w=1;return _ppos;
}

void Space::testDrawSpace()
{
  glPushMatrix();
  glTranslatef(0,0,-3);
  glLineWidth(3.0f);
  glColor3f(1.0f,1.0f,1.0f);
  glBegin(GL_LINE_LOOP);

  glVertex3f(m_size.m_x, m_size.m_y, -m_size.m_z);
  glVertex3f(-m_size.m_x, m_size.m_y, -m_size.m_z);
  glVertex3f(-m_size.m_x, -m_size.m_y, -m_size.m_z);
  glVertex3f(m_size.m_x, -m_size.m_y, -m_size.m_z);
  glVertex3f(m_size.m_x, -m_size.m_y, m_size.m_z);
  glVertex3f(m_size.m_x, m_size.m_y, m_size.m_z);
  glVertex3f(-m_size.m_x, m_size.m_y, m_size.m_z);

  glVertex3f(-m_size.m_x, -m_size.m_y, m_size.m_z);
  glVertex3f(-m_size.m_x, -m_size.m_y, -m_size.m_z);
  glVertex3f(-m_size.m_x, m_size.m_y, -m_size.m_z);
  glVertex3f(-m_size.m_x, m_size.m_y, m_size.m_z);
  glVertex3f(-m_size.m_x, -m_size.m_y, m_size.m_z);
  glVertex3f(m_size.m_x, -m_size.m_y, m_size.m_z);
  glVertex3f(m_size.m_x, -m_size.m_y, -m_size.m_z);
  glVertex3f(m_size.m_x, m_size.m_y, -m_size.m_z);

  glVertex3f(m_size.m_x, m_size.m_y, m_size.m_z);


  glEnd(); //GL_LINE_LOOP
  glPopMatrix();

}

Vec4 Space::GetOrigin() const
{
  return m_origin;
}

void Space::SetOrigin(Vec4 _origin)
{
  m_origin = _origin;
}





