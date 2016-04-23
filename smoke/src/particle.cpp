#include "particle.h"


Particle::Particle() : m_bouncieness(0.88)
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

    glBegin(GL_POINTS);
    glVertex3f(m_pos[0],m_pos[1],m_pos[2]);
            glEnd();
}

void Particle::UpdateGravity()
{
    m_vel += Vec4(0,-0.002,0);
}

void Particle::SetVel(Vec4 _vel)
{
    m_vel = _vel;
}

void Particle::bounce()
{

    m_vel = Vec4(-m_vel.m_x * m_bouncieness,
                 -m_vel.m_y * m_bouncieness,
                 -m_vel.m_z * m_bouncieness,
                 1);
}
