//
// Created by daniel on 29/04/19.
//

#ifndef GENETIC_ALGORITHM_H
#define GENETIC_ALGORITHM_H


#include "Population.h"

class Algorithm {
    //parametos de GA

public:

private:
    static Population envolvePopulation(Population pop);
    static Gladiator tournamentSelection(Population pop);
    static Gladiator crossover(Gladiator glad1 , Gladiator glad2);







};


#endif //GENETIC_ALGORITHM_H
