#ifndef FLOW_H
#define FLOW_H
#include "controlsphere.h"
#include "Vec4.h"

#ifdef __APPLE__
  #include <OpenGL/gl.h>
  #include <OpenGL/glu.h>
#endif

#ifdef __linux__
  #include <GL/gl.h>
  #include <GL/glu.h>
#endif

typedef struct FlowID{
 int row;
 int col;
 int seg;
  bool operator ==(const FlowID &_rhs) const;
}FlowID;


class Flow
{
public:
  Flow();
  //~Flow();

  void SetFlowID(int _r, int _c, int _s);
  FlowID GetFlowID();

  void update();
  void draw();
  void drawVectors();
  void SetPos(Vec4 _pos);
  Vec4 GetPos();
  float GetSize();
  Vec4 CalculateParticleVector(Vec4 _ppos);
  void SetFlowVecPos(float _size);
  void GetSpherePtr(ControlSphere* _ptr);
  void InteractWithSphere();
  void Decoy();


private:

  struct FlowVectorPos{ //L - left,  R - Right, T - top, D - Down, F - front, B - back
    Vec4 ltf;           // To have easy access to vector position, and no need to
    Vec4 rtf;           // calculate positions again;
    Vec4 ldf;
    Vec4 rdf;
    Vec4 ltb;
    Vec4 rtb;
    Vec4 ldb;
    Vec4 rdb;
  };

  struct FlowVectors{ //L - left,  R - Right, T - top, D - Down, F - front, B - back.
    Vec4 ltf;
    Vec4 rtf;
    Vec4 ldf;
    Vec4 rdf;
    Vec4 ltb;
    Vec4 rtb;
    Vec4 ldb;
    Vec4 rdb;
  };

  float m_fsize;
  float m_sphere_attraction_factor;
  float m_particle_interaction_factor;
  FlowID m_id;
  Vec4 m_position;
  GLfloat m_decoy;
  FlowVectors fvec;
  FlowVectorPos fvec_p;
  ControlSphere* controlSphere;


};

#endif // FLOW_H

/* TRASHBIN
 *
 *
 *
 *
 */
