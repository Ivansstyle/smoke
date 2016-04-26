#ifndef FLOW_H
#define FLOW_H


#include "Vec4.h"



class Flow
{
public:
  Flow();
  //~Flow();
  void SetFlowID();

  Vec4 CalculateParticleVector(Vec4 _ppos);

  struct FlowID{
   int row;
   int col;
    bool operator ==(const FlowID &_rhs) const;
  };



};

#endif // FLOW_H
