#include "particle.h"


Particle::Particle() : m_bouncieness(0.88)
{

}
Particle::~Particle()
{
}

void Particle::UpdatePos()
{
    m_pos += m_vel;
}

Vec4 Particle::GetPos()
{
    return m_pos;
}
void Particle::SetPos(Vec4 _pos)
{
    m_pos = _pos;
}


void Particle::SetVel(Vec4 _vel)
{
    m_vel = _vel;
}
void Particle::AddVel(Vec4 _vel)
{
    m_vel += _vel;
}


void Particle::draw()
{

    glBegin(GL_POINTS);
    glVertex3f(m_pos[0],m_pos[1],m_pos[2]);
            glEnd();
}

void Particle::UpdateGravity(Vec4 _gravity)
{
    //m_vel += _gravity;
}


void Particle::bounce(Vec4 _normal)
{

    m_vel = (m_vel.refl(_normal)) * m_bouncieness;
}
