#include "flow.h"

Flow::Flow()
{

}

void Flow::SetFlowID()
{

}

Vec4 Flow::CalculateParticleVector(Vec4 _ppos)
{

}




bool Flow::FlowID::operator ==(const FlowID &_rhs) const
{
  if(row == _rhs.row &&
     col == _rhs.col)
    return true;
  else return false;
}
