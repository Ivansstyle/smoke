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
  Vec4 GetPos();
  void SetPos();


private:
  Vec4 m_pos;
  GLfloat r;


};

#endif // CONTROLSPHERE_H
