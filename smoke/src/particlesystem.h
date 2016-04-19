#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H



#ifdef __APPLE__ //OpenGL for MacOsX

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

#else

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>

#endif

class ParticleSystem
{
public:

  ParticleSystem();

  ~ParticleSystem();

 void virtual init();

 void virtual update();

 void draw();

 void resize(int w, int h);

private:

protected:

 bool m_isInit;


};

#endif // PARTICLESYSTEM_H
