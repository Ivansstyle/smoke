#include "flowspace.h"
#include "GLFunctions.h"
#include <vector>
#include <cmath>
#include <iostream>
#warning "remove iostream after"

FlowSpace::FlowSpace()
{
//  Flow f = Flow();
//  f.SetPos(Vec4(0.0f,0.0f,-1.0f));
//  m_flows.push_back(f);
}

FlowSpace::~FlowSpace()
{

}

void FlowSpace::init(Vec4 _size, int _resolution, Vec4 _origin)
{
  CalculateFlowSize(_size, _resolution);
  createFlows(_size, _origin);
}


void FlowSpace::drawFlows()
{
  for (auto& i : m_flows)
  {
      i.draw();
  }
}


void FlowSpace::createFlows(const Vec4 _size,Vec4 _origin)
{
  Vec4 _size_in_space;
  if (_size.m_z > 0)
    {
    _size_in_space = Vec4
        (_size.m_x,
         _size.m_y,
         -_size.m_z);
    }
  else
    {
    _size_in_space = Vec4
        (_size.m_x,
         _size.m_y,
         _size.m_z);
    }
  GLfloat w = _size_in_space.m_x / 2.0f;
  GLfloat h = _size_in_space.m_y / 2.0f;
  GLfloat d = _size_in_space.m_z / 2.0f;



  int r_max = int(ceil(float(_size.m_x / (2.0f * m_flowsize)))) ; //Rows
  int c_max = int(ceil(float(_size.m_y / (2.0f * m_flowsize)))) ; //Colls
  int s_max = int(ceil(float(_size.m_z / (2.0f * m_flowsize)))) ; //Segmemnts

  std::cout<< " #### test '#### m_flowsize = "<<m_flowsize<<std::endl;
  std::cout<< " #### test '#### _size.m_x = "<<_size.m_x<<std::endl;
  std::cout<< " #### test '#### r_Max = "<<r_max<<std::endl;
  std::cout<< " #### test '#### c_Max = "<<c_max<<std::endl;
  std::cout<< " #### test '#### s_Max = "<<s_max<<std::endl;

    for (int s = 0; s < s_max; ++s)
    {
      for (int c = 0; c < c_max; ++c)
      {
        std::cout<< " #### test '#### c = "<<c<<std::endl;
        for (int r = 0; r < r_max; ++r)
        {
          Flow f = Flow();
          f.SetFlowID(r, c, s);
          f.SetPos(Vec4(-w + m_flowsize + ((2.0f * m_flowsize) * r),
                         h - m_flowsize - ((2.0f * m_flowsize) * c),
                        -d - m_flowsize - ((2.0f * m_flowsize) * s))
                        + _origin);
          m_flows.push_back(f);
        }
      }
    }

}

void FlowSpace::CalculateFlowSize(Vec4 _size, int _resolution)
{
  // Implemet an algorythm
#warning "do this"

  m_flowsize = 0.1f;

}



/* TRASHBIN
 *
 *
 *
 */
