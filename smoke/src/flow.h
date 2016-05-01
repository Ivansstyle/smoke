#ifndef FLOW_H
#define FLOW_H

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

  void draw();
  void SetPos(Vec4 _pos);
  Vec4 CalculateParticleVector(Vec4 _ppos);



  struct FlowVectors{


  };
private:
  FlowID m_id;
  Vec4 m_position;
  GLfloat bb;



};

#endif // FLOW_H

/* TRASHBIN
 *
 *
 *
 *
 */
