#include <iostream>
#include <fstream>
#include <string>
#pragma once

struct CONFIG{
  double tmin = 0.0;
  int xrange = 0;
  int nmolecules = 0;
  int latticesize = 0;
  int niterations = 0;
  int randomgeneratorseed = 0;
  double eps = 0;
  // method
  void read(const std::string & fname);
  //void print(const std::string & fname);
};
