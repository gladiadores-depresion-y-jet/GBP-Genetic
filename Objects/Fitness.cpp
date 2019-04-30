//
// Created by daniel on 29/04/19.
//

#include "Fitness.h"

static std::vector<int> * solution = new std::vector<int>(6,1);

void Fitness::setSolution(vector<int> sol) {
    *solution = sol;
}

int Fitness::getFitness(Gladiator gladiator) {
    int fitness = 0;
    for(int i = 0 ; i < gladiator.size() ; i++){
        if(gladiator.getGene(i) == solution->at(i)){
            fitness++;
        }
    }return fitness;
}

int Fitness::getMaxFitness() {

    int maxFitness = static_cast<int>(solution->size());
    return maxFitness;
}