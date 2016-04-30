
#include "particlesystem.h"
#include <sys/time.h>
#include <iostream>
#include "GLFunctions.h"

ParticleSystem::ParticleSystem() : m_isInit(false),m_startTime(0.0),m_elapsedTime(0.0)
{

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
  gluPerspective(75.0, float(w) / float(h), 0.1f, 20.0f);
  glViewport(0,0,w,h);
  glMatrixMode(GL_MODELVIEW);
}

ParticleSystem::~ParticleSystem()  {

}


void ParticleSystem::init()
{
    // Sanity check - if we've already initialised this class we shouldn't be here
    if (m_isInit) return;


    //SPACE INITIALISATION

    space = Space();
    space.SetSize(Vec4(1.8f,1.0f,1.0f));

    controlsphere = ControlSphere();
    controlsphere.SetPos(space.GetOrigin());

    TriggerSpeed = 0.1;



    // Enable texturing
    glDisable(GL_TEXTURE_2D);

    glPointSize(10);


    // Enable counter clockwise face ordering
    glFrontFace(GL_CCW);

    glDisable(GL_LIGHTING);
    glDisable(GL_NORMALIZE);

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

    // Set our start time by using the gettimeofday function (accurate to 10 nanosecs)
    struct timeval tim;
    gettimeofday(&tim, NULL);
    m_startTime = tim.tv_sec+(tim.tv_usec * 1e-6);


    m_particles.reserve(MAX_PARTICLES);


    m_isInit = true;
}

void ParticleSystem::update()
{
 //Timing Update
  TimingUpdate();

  //Passing controls to the ControlSphere
  controlsphere.update(controls.GiveControls());

  //Calling Particle creation
  CreateParticles();

  //Updating the particles
  ParticleUpdate();

  TriggerTick = ParticleTriggerTick();
  if (TriggerTick)
  {
    //std::cout<<"half tick is = "<<HalfSec<<std::endl;
  }


    //controls.KillControls();

}


void ParticleSystem::draw()
{
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    for (auto& i : m_particles)
    {
        i.draw();
    }

    controlsphere.draw();

    space.testDrawSpace();


}

bool ParticleSystem::isInit() const
{
    return m_isInit;
}

void ParticleSystem::takeControl(SDL_Event* _e)
{
  controls.TakeControls(_e);
}

void ParticleSystem::CreateParticles()
{
    if (controls.event.space && TriggerTick)
    {
      Particle p = Particle();
      p.SetPos(controlsphere.GetPos());
      p.SetVel(Vec4(0.2,0,0.2));
      m_particles.push_back(p);
    }
}

bool ParticleSystem::ParticleTriggerTick()
{
  static double elapsed = 0.0;
  if ((m_elapsedTime - elapsed) < TriggerSpeed)
  {
    elapsed -= TriggerSpeed;
    return true;
  }
  else return false;
}

void ParticleSystem::TimingUpdate()
{
  //Timing update
  // Some stuff we need to perform timings
      struct timeval tim;

      // Retrieve the current time in nanoseconds (accurate to 10ns)
      gettimeofday(&tim, NULL);
      double now =tim.tv_sec+(tim.tv_usec * 1e-6);

      // Increment the rotation based on the time elapsed since we started running
      m_elapsedTime = m_startTime - now;


     // printf("%G \n", m_elapsedTime);
}

void ParticleSystem::ParticleUpdate()
{
  for (auto& i : m_particles)
  {
      Vec4 totVel = Vec4(0,0,0);
      Vec4 _ppos = i.GetPos();
      Vec4 normal;
      normal = space.isInSpace(_ppos);



      if (normal != Vec4(0,0,0))
      {
          i.SetPos(space.SetBackToSpace(_ppos, normal));
          i.bounce(normal);
      }
      else
      {
          i.AddVel(totVel);
      }
          i.UpdateGravity(space.GetGravity());
          i.UpdatePos();
  }

}

/* TRASHBIN
 *
 *
//    glPushMatrix();
//    glTranslatef(0,0.0f,-6.0f);
//    GLFunctions::WiredCube(1.0f,1.0f,1.0f);
//    glPopMatrix();


      ///from ParticleUpdate
      std::cout<< " ppos x = "<<_ppos.m_x
               << " ppos y = "<<_ppos.m_y
               << " ppos z = "<<_ppos.m_z
               <<std::endl;
 *
   std::cout<<"ControlSphere Position: x = "<<controlsphere.GetPos().m_x
            <<" y = "<< controlsphere.GetPos().m_y
            <<" z = "<<controlsphere.GetPos().m_z<<std::endl;

      std::cout<< " normal x = "<<normal.m_x
               <<" normal y = "<<normal.m_y
               << " normal z = "<<normal.m_z
               <<std::endl;

       /// from timerTick
      //      std::cout<<elapsed<<"  is elapsed"<<std::endl;

*/

