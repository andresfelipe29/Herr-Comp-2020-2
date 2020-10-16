#include "config.h"

void CONFIG::read(const std::string &fname)
{
  // open file (for reading)
  std::ifstream fin(fname);
  
  // read it
  std::string line;

  std::getline(fin, line);
  xrange = std::stod( line.erase(line.find('#')) );
  std::getline(fin, line);
  nmolecules = std::stod( line.erase(line.find('#')) );
  std::getline(fin, line);
  latticesize = std::stod( line.erase(line.find('#')) );
  std::getline(fin, line);
  niterations = std::stod( line.erase(line.find('#')) );
  std::getline(fin, line);
  randomgeneratorseed = std::stod( line.erase(line.find('#')) );
  std::getline(fin, line);
  eps = std::stod( line.erase(line.find('#')) );
  
  // close it
  fin.close();
}

/*void CONFIG::print(const std::string & fname)
{
  // open file (for writing)
  std::ofstream fout(fname);
  
  // read it
  fout << tmin << "\n";
  fout << nmolecules << "\n";
  fout << laticesize << "\n";
  fout << niterations << "\n";
  fout << randomgeneratorseed << "\n";

  // close it
  fout.close();
  }*/
