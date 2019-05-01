//
// Created by daniel on 29/04/19.
//

#ifndef GENETIC_FITNESS_H
#define GENETIC_FITNESS_H

#include <iostream>
#include <vector>
#include "Gladiator.h"

using  namespace std;
class Fitness {

public:
    static void setSolution(float sol);
    //static void setSolution();
    static float getFitness(Gladiator gladiator);
    static float getMaxFitness();


};


#endif //GENETIC_FITNESS_H
