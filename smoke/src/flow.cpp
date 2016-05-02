#include "flow.h"
#include "GLFunctions.h"
#include <iostream>
#include <cmath>
#warning "remove iostream after"

Flow::Flow() : m_sphere_attraction_factor(10.5f) , m_decoy(0.99f) ,controlSphere(NULL),
               m_particle_interaction_factor(0.0003f)
{
  fvec.ltf = Vec4(0,0,0);
  fvec.rtf = Vec4(0,0,0);

  fvec.ldf = Vec4(0,0,0);
  fvec.rdf = Vec4(0,0,0);


  fvec.ltb = Vec4(0,0,0);
  fvec.rtb = Vec4(0,0,0);

  fvec.ldb = Vec4(0,0,0);
  fvec.rdb = Vec4(0,0,0);
}


Vec4 Flow::CalculateParticleVector(Vec4 _ppos)
{
  // Calculate Resoluting Power times Interaction Factor
  Vec4 respow = ( fvec.ltf * (fvec.ltf + fvec_p.ltf).dist(_ppos) * m_particle_interaction_factor +
                  fvec.rtf * (fvec.rtf + fvec_p.rtf).dist(_ppos) * m_particle_interaction_factor +
                  fvec.ldf * (fvec.ldf + fvec_p.ldf).dist(_ppos) * m_particle_interaction_factor +
                  fvec.rdf * (fvec.rdf + fvec_p.rdf).dist(_ppos) * m_particle_interaction_factor +
                  fvec.ltb * (fvec.ltb + fvec_p.ltb).dist(_ppos) * m_particle_interaction_factor +
                  fvec.rtb * (fvec.rtb + fvec_p.rtb).dist(_ppos) * m_particle_interaction_factor +
                  fvec.ldb * (fvec.ldb + fvec_p.ldb).dist(_ppos) * m_particle_interaction_factor +
                  fvec.rdb * (fvec.rdb + fvec_p.rdb).dist(_ppos) * m_particle_interaction_factor
                 );
  respow = Vec4(respow.m_x / 8.0f,
                respow.m_y / 8.0f,
                respow.m_z /8.0f);
  return respow;
}

void Flow::update()
{
 InteractWithSphere();
 Decoy();
}

void Flow::draw()
{
  glPushMatrix();

  glColor4f(0.0f,0.0f,1.0f,0.8f);
  glLineWidth(0.1f);

  glTranslatef(m_position.m_x, m_position.m_y, m_position.m_z);

  GLFunctions::WiredCube(0.2f,0.2f,0.2f);
  glLineWidth(3.0f);

  glColor4f(1.0f,0.9f,0.0f,0.8f);
  glPointSize(2.0f);

  glBegin(GL_POINTS);
    glVertex3f(m_position.m_x,m_position.m_y,m_position.m_z);
    glColor4f(1.0f,1.0f,1.0f,1.0f);
  glEnd(); //glPoint

  glPointSize(10.0f);

  // Vector Draw
  drawVectors();

  glPopMatrix();
}

void Flow::InteractWithSphere()
{
  float interaction_distance = m_fsize + controlSphere->GetR() + 0.4f; // it works
                                                  // but returns number that is -0.2f

  if (m_position.dist(controlSphere->GetPos()) < interaction_distance)
  {
    fvec.ltf += (controlSphere->GetVel() *
(2.0f/((fvec.ltf + fvec_p.ltf).dist(controlSphere->GetPos()) * m_sphere_attraction_factor))) ;


    fvec.rtf += controlSphere->GetVel() *
(2.0f/((fvec.rtf + fvec_p.rtf).dist(controlSphere->GetPos()) * m_sphere_attraction_factor));


    fvec.ldf += controlSphere->GetVel() *
(2.0f/((fvec.ldf + fvec_p.ldf).dist(controlSphere->GetPos()) * m_sphere_attraction_factor));


    fvec.rdf += controlSphere->GetVel() *
(2.0f/((fvec.rdf + fvec_p.rdf).dist(controlSphere->GetPos()) * m_sphere_attraction_factor));


    fvec.ltb += controlSphere->GetVel() *
(2.0f/((fvec.ltb + fvec_p.ltb).dist(controlSphere->GetPos()) * m_sphere_attraction_factor));


    fvec.rtb += controlSphere->GetVel() *
(2.0f/((fvec.rtb + fvec_p.rtb).dist(controlSphere->GetPos()) * m_sphere_attraction_factor));


    fvec.ldb += controlSphere->GetVel() *
(2.0f/((fvec.ldb + fvec_p.ldb).dist(controlSphere->GetPos()) * m_sphere_attraction_factor));


    fvec.rdb += controlSphere->GetVel() *
(2.0f/((fvec.rdb + fvec_p.rdb).dist(controlSphere->GetPos()) * m_sphere_attraction_factor));
  }
}

void Flow::Decoy()
{
  fvec.ltf = Vec4(fvec.ltf.m_x * m_decoy, fvec.ltf.m_y * m_decoy, fvec.ltf.m_z * m_decoy);
  fvec.rtf = Vec4(fvec.rtf.m_x * m_decoy, fvec.rtf.m_y * m_decoy, fvec.rtf.m_z * m_decoy);
  fvec.ldf = Vec4(fvec.ldf.m_x * m_decoy, fvec.ldf.m_y * m_decoy, fvec.ldf.m_z * m_decoy);
  fvec.rdf = Vec4(fvec.rdf.m_x * m_decoy, fvec.rdf.m_y * m_decoy, fvec.rdf.m_z * m_decoy);
  fvec.ltb = Vec4(fvec.ltb.m_x * m_decoy, fvec.ltb.m_y * m_decoy, fvec.ltb.m_z * m_decoy);
  fvec.rtb = Vec4(fvec.rtb.m_x * m_decoy, fvec.rtb.m_y * m_decoy, fvec.rtb.m_z * m_decoy);
  fvec.ldb = Vec4(fvec.ldb.m_x * m_decoy, fvec.ldb.m_y * m_decoy, fvec.ldb.m_z * m_decoy);
  fvec.rdb = Vec4(fvec.rdb.m_x * m_decoy, fvec.rdb.m_y * m_decoy, fvec.rdb.m_z * m_decoy);
}

void Flow::drawVectors()
{
  glLineWidth(1.0f);
  glColor4f(1.0f,1.0f,0.1f,1.0f);
  glBegin(GL_LINES);

  Vec4 o, x;

  o =  fvec_p.ltf;
  x =  fvec_p.ltf + fvec.ltf;
  glVertex3f(o.m_x, o.m_y, o.m_z);
  glVertex3f(x.m_x, x.m_y, x.m_z);

  o =  fvec_p.rtf;
  x =  fvec_p.rtf + fvec.rtf;
  glVertex3f(o.m_x, o.m_y, o.m_z);
  glVertex3f(x.m_x, x.m_y, x.m_z);


  o =  fvec_p.ldf;
  x =  fvec_p.ldf + fvec.ldf;
  glVertex3f(o.m_x, o.m_y, o.m_z);
  glVertex3f(x.m_x, x.m_y, x.m_z);


  o =  fvec_p.rdf;
  x =  fvec_p.rdf + fvec.rdf;
  glVertex3f(o.m_x, o.m_y, o.m_z);
  glVertex3f(x.m_x, x.m_y, x.m_z);


  o =  fvec_p.ltb;
  x =  fvec_p.ltb + fvec.ltb;
  glVertex3f(o.m_x, o.m_y, o.m_z);
  glVertex3f(x.m_x, x.m_y, x.m_z);


  o =  fvec_p.rtb;
  x =  fvec_p.rtb + fvec.rtb;
  glVertex3f(o.m_x, o.m_y, o.m_z);
  glVertex3f(x.m_x, x.m_y, x.m_z);

  o =  fvec_p.ldb;
  x =  fvec_p.ldb + fvec.ldb;
  glVertex3f(o.m_x, o.m_y, o.m_z);
  glVertex3f(x.m_x, x.m_y, x.m_z);


  o =  fvec_p.rdb;
  x =  fvec_p.rdb + fvec.rdb;
  glVertex3f(o.m_x, o.m_y, o.m_z);
  glVertex3f(x.m_x, x.m_y, x.m_z);
  glEnd(); //GL_LINES
}

void Flow::SetFlowID(int _r, int _c, int _s)
{
  m_id.col = _c;
  m_id.row = _r;
  m_id.seg = _s;
}

void Flow::SetFlowVecPos(float _size)
{
  fvec_p.ltf = Vec4 (-1, 1, 1) * _size;
  fvec_p.rtf = Vec4 ( 1, 1, 1) * _size;
  fvec_p.ldf = Vec4 (-1,-1, 1) * _size;
  fvec_p.rdf = Vec4 ( 1,-1, 1) * _size;
  fvec_p.ltb = Vec4 (-1, 1,-1) * _size;
  fvec_p.rtb = Vec4 ( 1, 1,-1) * _size;
  fvec_p.ldb = Vec4 (-1,-1,-1) * _size;
  fvec_p.rdb = Vec4 ( 1,-1,-1) * _size;
  m_fsize = _size;
}


void Flow::SetPos(Vec4 _pos)
{
  m_position = _pos;
}

void Flow::GetSpherePtr(ControlSphere *_ptr)
{
  controlSphere = _ptr;
}

Vec4 Flow::GetPos()
{
  return m_position;
}

float Flow::GetSize()
{
  return m_fsize;
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

/* TRASHBIN
 *
 * std::cout<<"~~~~~~~~~~~## VECTOR L T F _ pos == "<<fvec_p.ltf.m_x<< " "
          <<fvec_p.ltf.m_y<<" "<<fvec_p.ltf.m_z <<std::endl;
 *
 *std::cout<<"interact d ="<<interaction_distance
          <<" controlsphere pos x from here is "<<controlSphere->GetPos().m_x
         <<"2 random vectors dist is = "<<Vec4(1,1,1).dist(Vec4(-1,-1,-1))
        <<"m_position is "<<m_position.m_x<<std::endl;

        std::cout<<"interaction is happening"<< std::endl;

        // std::cout<<"distance calculated is = "<< m_position.dist(controlSphere->GetPos()) << std::endl;
 *
 */
