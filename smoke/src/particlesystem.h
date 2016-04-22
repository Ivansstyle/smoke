#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H



#ifdef __APPLE__ //OpenGL for MacOsX

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>


#else

#include <GL/gl.h>
#include <GL/glu.h>

#endif


#include "particle.h"
#include <stdlib.h>
#include <vector>


class ParticleSystem
{
public:

  ParticleSystem();

  ~ParticleSystem();

 void init();

 void update();

 void draw();

 void resize(int w, int h);

 bool const isInit();

private:

std::vector<Particle> m_particles;


protected:

 bool m_isInit;




 /// The time since the object was initialised, which is used for animation purposes
 double m_startTime;

 /// A member that is updated when update() is called indicating the elapsed time
 double m_elapsedTime;


};

#endif // PARTICLESYSTEM_H
