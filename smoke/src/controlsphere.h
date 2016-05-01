#ifndef CONTROLSPHERE_H
#define CONTROLSPHERE_H
#include "Vec4.h"
#include "controls.h"



class ControlSphere
{
public:
  ControlSphere();
  ~ControlSphere();

  void draw();
  void update(Event* event);

  Vec4 GetPos() const;
  void SetPos(Vec4 _pos);
  GLdouble GetR() const;
  void SetR(GLdouble _r);
  Vec4 SetBackToSpace(Vec4 _normal);

  void Move(Vec4 _move);

  Vec4 SphereCollisionNormal(Vec4 _ppos);
  bool SphereCollision(Vec4 _ppos);




private:
  Vec4 m_pos;
  GLdouble m_r;
  GLfloat m_collision_distance;
  float m_speed;



};

#endif // CONTROLSPHERE_H
