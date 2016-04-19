
#include "particlesystem.h"
#include <sys/time.h>

ParticleSystem::ParticleSystem()
{
  // Sanity check - if we've already initialised this class we shouldn't be here
  //if (m_isInit) return;

  // Enable texturing
  glDisable(GL_TEXTURE_2D);

  // Enable counter clockwise face ordering
  glFrontFace(GL_CCW);

  glEnable(GL_LIGHTING);
  glEnable(GL_NORMALIZE);

  glEnable(GL_LIGHT0);
  glEnable (GL_BLEND);
  glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  GLfloat lightpos[] = {0.0f, 1.0f, 1.0f, 1.0f};
  GLfloat lightdiff[] = {0.5f, 0.5f, 0.5f, 1.0f};
  GLfloat lightamb[] = {0.2f, 0.2f, 0.2f, 1.0f};
  GLfloat lightspec[] = {1.0f, 1.0f, 1.0f, 1.0f};
  glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, lightdiff);
  glLightfv(GL_LIGHT0, GL_AMBIENT, lightamb);
  glLightfv(GL_LIGHT0, GL_SPECULAR, lightspec);


  // Make our points lovely and smooth
  glEnable( GL_POINT_SMOOTH );
  glEnable( GL_MULTISAMPLE_ARB);
  glEnable(GL_DEPTH_TEST);

  // Set the background colour
  glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

//  // Set our start time by using the gettimeofday function (accurate to 10 nanosecs)
//  struct timeval tim;
//  gettimeofday(&tim, NULL);
//  //m_startTime = tim.tv_sec+(tim.tv_usec * 1e-6);

  //m_isInit = true;
}

/**
* @brief Scene::resize needs to set up the camera paramaters (i.e. projection matrix) and the viewport
* @param w Width of window
* @param h Height of window
*/
void ParticleSystem::resize(int w, int h) {
  if (!m_isInit) return;

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, float(w) / float(h), 0.1, 10.0);

  glViewport(0,0,w,h);

  glMatrixMode(GL_MODELVIEW);
}

ParticleSystem::~ParticleSystem(){

}


void ParticleSystem::init(){}

void ParticleSystem::update(){}


void ParticleSystem::draw()
{

}
