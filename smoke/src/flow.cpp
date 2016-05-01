#include "flow.h"
#include "GLFunctions.h"

Flow::Flow()
{

}


Vec4 Flow::CalculateParticleVector(Vec4 _ppos)
{

}

void Flow::draw()
{
  glPushMatrix();
  glColor4f(0.0f,0.0f,1.0f,0.8f);
  glLineWidth(0.1f);
  glTranslatef(m_position.m_x, m_position.m_y, m_position.m_z);
  GLFunctions::WiredCube(0.2f,0.2f,0.2f);
  glColor4f(1.0f,1.0f,1.0f,1.0f);
  glLineWidth(3.0f);
  glColor4f(1.0f,0.9f,0.0f,0.8f);
  glPointSize(2.0f);
  glBegin(GL_POINTS);
  glVertex3f(m_position.m_x,m_position.m_y,m_position.m_z);
  glColor4f(1.0f,1.0f,1.0f,1.0f);
  glEnd(); //glPoint
  glPointSize(10.0f);

  // Implement Vector draw

  glPopMatrix();

}

void Flow::SetFlowID(int _r, int _c, int _s)
{
  m_id.col = _c;
  m_id.row = _r;
  m_id.seg = _s;
}



void Flow::SetPos(Vec4 _pos)
{
  m_position = _pos;

}
FlowID Flow::GetFlowID()
{
  return m_id;
}

bool FlowID::operator ==(const FlowID &_rhs) const
{
  if(row == _rhs.row &&
     col == _rhs.col)
    return true;
  else return false;
}
