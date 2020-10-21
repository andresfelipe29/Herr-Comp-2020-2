#ifndef __PARTICLE_H_
#define __PARTICLE_H_

struct Particle
{
  double rad = 0.0;
  double mass = 0.0;
  double Rx = 0.0, Ry = 0.0, Rz = 0.0;
  double Vx = 0.0, Vy = 0.0, Vz = 0.0;
  double Fx = 0.0, Fy = 0.0, Fz = 0.0;
  double Ex = 0.0, Ey = 0.0, Ez = 0.0;
  double Kx = 0.0, Ky = 0.0, Kz = 0.0;
  double Py = 0.0;
};


#endif // __PARTICLE_H_
