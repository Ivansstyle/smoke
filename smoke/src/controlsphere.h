#ifndef CONTROLSPHERE_H
#define CONTROLSPHERE_H
#include "Vec4.h"

class ControlSphere
{
public:
  ControlSphere();
  ~ControlSphere();
  void draw();
  void update();
  Vec4 GetPos() const;
  void SetPos(Vec4 _pos);
  GLdouble GetR() const;
  void SetR(GLdouble _r);
  void Move(Vec4 _move);


private:
  Vec4 m_pos;
  GLdouble m_r;


};

#endif // CONTROLSPHERE_H
