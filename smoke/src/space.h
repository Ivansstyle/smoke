#ifndef SPACE_H
#define SPACE_H

#include "flowspace.h"
#include "Vec4.h"
#include "GLFunctions.h"

#ifdef __APPLE__ //OpenGL for MacOsX
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#endif

#ifdef __linux__
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
    Vec4 SetBackToSpace(Vec4 _ppos, Vec4 _normal);

    void initFlowSpace();


    void testDrawSpace();


    FlowSpace flowspace;

private:

    struct Normal{
      Vec4 floor;
      Vec4 ceiling;
      Vec4 front;
      Vec4 back;
      Vec4 left;
      Vec4 right;
      Vec4 zero;
    };

    Normal normal;

    Vec4 m_size;

    Vec4 m_origin;

    int m_resolution;
    GLfloat m_height;
    GLfloat m_width;



};

#endif // SPACE_H
