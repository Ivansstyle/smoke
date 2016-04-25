
#include "particlesystem.h"
#include <sys/time.h>

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
  gluPerspective(60.0, float(w) / float(h), 0.1, 10.0);

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
    space.SetSize(Vec4(2,1,1));

    controlsphere = ControlSphere();


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
    //m_startTime = tim.tv_sec+(tim.tv_usec * 1e-6);

for (int i = 0; i < 10; ++i)
    {
     Particle p = Particle();
     p.SetPos(Vec4(i*0.5 / 3,0,-2));
     p.SetVel(Vec4(i*0,0,0.5));
     m_particles.push_back(p);
    }


    m_isInit = true;
}

void ParticleSystem::update()
{
    //Update the particles
    for (auto& i : m_particles)
    {
        Vec4 totVel = Vec4(0,0,0);
        Vec4 _ppos = i.GetPos();
        _ppos = space.isInSpace(_ppos);
//        if (_ppos.m_w == -2)
//        {
//            i.SetPos(_ppos);
//            i.bounce();
//        }
//        else
//        {
//            i.AddVel(totVel);
//        }
//            i.UpdatePos();
    }

}


void ParticleSystem::draw()
{
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    for (auto& i : m_particles)
    {
        i.draw();
    }

    controlsphere.draw();
}

bool ParticleSystem::isInit() const
{
    return m_isInit;
}


