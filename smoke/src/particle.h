#ifndef PARTICLE_H
#define PARTICLE_H


class Particle
{
public:
  Particle();
  ~Particle();
  
private:
  int m_pos;
  int m_vel;
  int m_mass;
  bool m_inSphere;




};

#endif // PARTICLE_H
