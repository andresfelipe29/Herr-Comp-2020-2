#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <string>
#include "particle.h"
#include "config.h"

double initial_conditions(const CONFIG &object, std::vector<PARTICLE> &configuracion, std::vector<int> &distribucion, std::vector<double> &PI);
int Locate(const CONFIG object, PARTICLE j);
void distribute(const CONFIG object, std::vector<PARTICLE> &configuracion, std::vector<int> &distribucion, std::vector<double> &PI);
double entropy(const CONFIG &object, double entropia, int origin, int destiny, std::vector<double> &PI, std::vector<int> distribucion);

int main()
{
  CONFIG config;
  config.read("config.txt");
  std::vector<PARTICLE> configuracion(config.nmolecules); //configuracion de las particulas en el espacio
  std::vector<int> Distribucion(config.latticesize*config.latticesize); //distribucion de las particulas en el Lattice
  std::vector<double> PI(config.latticesize*config.latticesize); //probabilidades por celda del Lattice
  initial_conditions(config, configuracion, Distribucion, PI);
  distribute(config, configuracion, Distribucion, PI);
}

double initial_conditions(const CONFIG &object, std::vector<PARTICLE> &configuracion, std::vector<int> &distribucion, std::vector<double> &PI)
{
  double S = 0.0;
  double eps = 0.0005;
  
  for(int j = 0; j < std::sqrt(object.nmolecules); j++){ //ubicacion inicial de las particulas en el espacio
    for(int i = 0; i < std::sqrt(object.nmolecules); i++){
      configuracion[i+j*std::sqrt(object.nmolecules)].initialize(object.xrange, object.nmolecules, i, j);
    }
  }
  for(int i = 0; i < object.nmolecules; i++){ //calcula la distribucion inicial en el lattice
    
    distribucion[Locate(object, configuracion[i])] += 1;
  }
  for(int i = 0; i < object.latticesize*object.latticesize; i++){ //calcula la entropia inicial
    PI[i] = distribucion[i]/object.nmolecules;
    if(PI[i] < eps){
      S += PI[i];
    }
    else{
      S += PI[i]*std::log(PI[i]);
    }
  }
  
  return S;
}

int Locate(const CONFIG object, PARTICLE j)
{
  //int Cellsize = xrange/Xrange;
  int X = j.posicion[0]/object.latticesize;
  int Y = j.posicion[1]/object.latticesize;
  return X + Y*object.xrange;
}

void distribute(const CONFIG object, std::vector<PARTICLE> &configuracion, std::vector<int> &distribucion, std::vector<double> &PI)
{
  std::mt19937 eng(object.randomgeneratorseed); //generador de numeros aleatorios con semilla 0
  std::uniform_real_distribution<double> gen(0, object.nmolecules-1); //distribuci�n
  
  int particulaj = 0;
  int origin = 0;
  int destiny = 0;
  double S = 0;
  
  for(int t = 0; t < object.niterations; t++){
    particulaj = gen(eng);//Genera un numero aleatorio entero entre 0 y N-1;
    origin = Locate(object, configuracion[particulaj]);
    configuracion[particulaj].move(object.randomgeneratorseed, object.xrange);
    destiny = Locate(object, configuracion[particulaj]);
    
    if(origin == destiny){std::cout<< S << "\n";}
    else{
      S = entropy(object, S, origin, destiny, PI, distribucion);
      std::cout << S << "\n";
      distribucion[origin] -= 1;
      distribucion[destiny] += 1;
    }
  }
}

double entropy(const CONFIG &object, double entropia, int origin, int destiny, std::vector<double> &PI, std::vector<int> distribucion)
{
  if(PI[origin] < object.eps){
    entropia -= PI[origin];
  }
  else{entropia -= PI[origin]*std::log(PI[origin]);}
  if(PI[destiny] < object.eps){
    entropia -= PI[destiny];
  }
  else{entropia -= PI[destiny]*std::log(PI[destiny]);}
  
  PI[origin] = (distribucion[origin] - 1.0)*PI[origin] / distribucion[origin];
  PI[destiny] = (distribucion[destiny] + 1.0)*PI[destiny] / distribucion[destiny];

  if(PI[origin] < object.eps){
    entropia += PI[origin];
  }
  else{entropia += PI[origin]*std::log(PI[origin]);}
  if(PI[destiny] < object.eps){
    entropia += PI[destiny];
  }
  else{entropia += PI[destiny]*std::log(PI[destiny]);}
  return entropia;
}
