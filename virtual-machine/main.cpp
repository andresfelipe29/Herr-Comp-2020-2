#include <iostream>
#include <vector>
#include <array>

int main()
{
    srand(0);
    cuerpo std::vector<struct particle> configuracion(xrange*xrange,0);
    std::vector<int> distribucion(Xrange*Xrange,0);
    std::vector<double> probabilidades(Xrange*Xrange);
}

struct particle{
    int posicion[2];
    int celda;

    void move(int &posicion[2], int xrange){
        //q = número aleatorio 0 o 1;
        //p = número aleatorio 1 o -1;
        posicion[rand()%2] += rand()%2;
        celda = posicion[0] + posicion[1]*xrange;
    }
}

Location(particle,& std::vector distribucion[]){
    Cellsize = Xrange/Xdivitions;
    int  X = x/Cellsize;
    int Y = y/Cellsize;
    distribucion[X + Y*m] += 1;
}

Void initial_conditions(particle, vector)
{
For (int i=0; i < n; i++){
particle.inicie(dx*(ix+1), dy*(iy+1))
Vector celdas[]
}
}

void distribute(std::vector<particle> &configuracion, int Maxtime)
{
    std::mt19937 gen(0); //generador de números aleatorios con semilla 0
    std::uniform_real_distribution<double> dis(0, ParticleMax); //distribución de los números aleatoreos

    struct particle particulaj;
    int origin = 0;
    int destiny = 0;
    
    for(int t = 0; t < tmax; t++)
    {
        particulaj = dis(gen);//Genere un número aleatorio entero entre 0 y N-1;
        origin = particulaj.celda;
        particulaj.move(configuracion[j].posicion, xrange);
        destiny = particulaj.celda;

        if (origin == destiny){return S;}
        else{
            distribucion[origin] -= 1;
            distribucion[destiny] += 1;
            calcularprobsabilibada(pobabilidades[i] &, probabilidades[ii] &);
            
            S=Calcula entropia(vector probabildades);
        }
    }
    
}

void entropy(int origin, int destiny, std::vector<double> &PI, std::vector<double> distribucion)
{
    std::vector<double> original = PI;
    PI[origin] = distribucion;
}
