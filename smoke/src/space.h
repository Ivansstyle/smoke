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
    void SetSize(Vec4 _size);
    Vec4 GetOrigin() const;
    void SetOrigin(Vec4 _origin);
    void SetSpace();


    Vec4 isInSpace(Vec4 _ppos);

    void initFlowSpace();


    void testDrawSpace();


    FlowSpace flowspace;

private:


    Vec4 m_size;

    Vec4 m_origin;

    int m_resolution;
    GLfloat m_height;
    GLfloat m_width;



};

#endif // SPACE_H
