#include "config.h"

void CONFIG::read(const std::string &fname)
{
  // open file (for reading)
  std::ifstream fin(fname);
  
  // read it
  std::string line;

  std::getline(fin, line);
  xrange = std::stoi( line.erase(line.find('#'), line.size()) );
  std::getline(fin, line);
  nmolecules = std::stoi( line.erase(line.find('#'), line.size()) );
  std::getline(fin, line);
  latticesize = std::stoi( line.erase(line.find('#'), line.size()) );
  std::getline(fin, line);
  niterations = std::stoi( line.erase(line.find('#'), line.size()) );
  std::getline(fin, line);
  randomgeneratorseed = std::stoi( line.erase(line.find('#'), line.size()) );
  std::getline(fin, line);
  eps = std::stod( line.erase(line.find('#'), line.size()) );
  
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
