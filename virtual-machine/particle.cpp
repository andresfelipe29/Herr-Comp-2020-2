#include "particle.h"

void PARTICLE::move(const int randomgeneratorseed, const int xrange)
{
  std::mt19937 q(0);
  std::mt19937 p(1);
  std::uniform_int_distribution<int> gen(0, 1); // uniform, unbiased

  posicion[gen(q)] += 2*gen(p)-1;
  if(posicion[0] < -xrange/2 || posicion[0] > xrange/2){
    posicion[0] += (posicion[0] < -xrange/2) ? 2 : -2;
  }
  if(posicion[1] < -xrange/2 || posicion[1] > xrange/2){
    posicion[1] += (posicion[0] < -xrange/2) ? 2 : -2;
  }
  posicion[2] = posicion[0] + posicion[1]*xrange; 
}

void PARTICLE::initialize(const int xrange, const int nmolecules, const int i, const int j)
{
  posicion[0] = xrange/2 - std::sqrt(nmolecules)/2 + i;
  posicion[1] = xrange/2 - std::sqrt(nmolecules)/2 + j;
  posicion[2] = posicion[0] + posicion[1]*xrange;
}
