#ifndef MODE_H
#define MODE_H

#include "grid.h"
#include<cstdlib>
#include<ctime>

class Mode{
    public:
        Mode();
        Mode(std::vector<std::vector<puyoType>>tableau);
        void Mode_Simulation(std::ifstream& abc);
        void Mode_IA(std::ifstream& abc);
        void Mode_Solo(std::ifstream& abc);
        Grille contient;
    private:
};


#endif
