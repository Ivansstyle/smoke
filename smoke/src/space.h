#ifndef SPACE_H
#define SPACE_H

#include "flowspace.h"
#include "Vec4.h"



class Space
{
public:
    Space();
    ~Space();

    void init();

    Vec4 GetSpace();
    void SetSpace(Vec4);
    Vec4 isInSpace(Vec4 _ppos);
    void initFlowSpace();

private:

    Vec4 m_size;
    int m_resolution;


};

#endif // SPACE_H
