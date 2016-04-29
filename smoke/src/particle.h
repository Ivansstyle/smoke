#ifndef PARTICLE_H
#define PARTICLE_H

#ifdef __APPLE__
  #include <OpenGL/gl.h>
  #include <OpenGL/glu.h>
#endif

#ifdef __linux__
  #include <GL/gl.h>
  #include <GL/glu.h>
#endif

#include "flow.h"
#include "Vec4.h"

class Particle
{
public:
  Particle();
  ~Particle();

  bool m_inSphere;

  void UpdatePos();

  void SetVel(Vec4 _vel);
  void AddVel(Vec4 _vel);
  void SetPos(Vec4 _pos);
  void AddPos(Vec4 _pos);
  Vec4 GetVel();
  Vec4 GetPos();
  void draw();
  void bounce();


private:

  //Flow::FlowID m_pFlowID;
  Vec4 m_pos;
  Vec4 m_vel;
  float m_mass;
  float m_bouncieness;

  void UpdateGravity();






};

#endif // PARTICLE_H
