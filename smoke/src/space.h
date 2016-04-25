#ifndef SPACE_H
#define SPACE_H

#include "flowspace.h"
#include "Vec4.h"


#ifdef __APPLE__ //OpenGL for MacOsX

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>


#else

#include <GL/gl.h>
#include <GL/glu.h>

#endif


class Space
{
public:
    Space();
    ~Space();

    void init();

    Vec4 GetSize();
    void SetSize(Vec4);
    Vec4 isInSpace(Vec4 _ppos);
    void initFlowSpace();

private:

    Vec4 m_size;
    int m_resolution;
    GLfloat m_height;
    GLfloat m_width;



};

#endif // SPACE_H
