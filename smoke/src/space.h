#ifndef SPACE_H
#define SPACE_H
#include "Vec4.h"

class Space
{
public:
    Space();
    ~Space();

    Vec4 GetSpace();
    void SetSpace(Vec4);
    Vec4 isInSpace(Vec4 _ppos);
    void initFlowSpace();

private:

    Vec4 m_size;
    int m_resolution;

};

#endif // SPACE_H
