#include "particle.h"


Particle::Particle()
{

}
Particle::~Particle()
{
}

void Particle::UpdatePos()
{
    UpdateGravity();
    m_pos += m_vel;


    //May create a timestep
}

Vec4 Particle::GetPos()
{
    return m_pos;
}

void Particle::AddVel(Vec4 _vel)
{
    m_vel += _vel;
}

void Particle::SetPos(Vec4 _pos)
{
    m_pos = _pos;
}

void Particle::draw()
{
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINT);
    glVertex3f(m_pos[0],m_pos[1],m_pos[2]);
            glEnd();
}

void Particle::UpdateGravity()
{
    m_vel += Vec4(0,-0.02,0);
}

void Particle::SetVel(Vec4 _vel)
{
    m_vel = _vel;
}
