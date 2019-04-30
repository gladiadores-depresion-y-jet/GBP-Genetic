#include <utility>

//
// Created by daniel on 29/04/19.
//

#include "Population.h"


Population::Population(int populationSize, bool initialise) {
    individuals = new vector<Gladiator>();
    if(initialise){
        for(int i = 0 ; i<this->getSize() ; i++){
            Gladiator newGlad = Gladiator();
            newGlad.init();
            this->saveIndividual(i,newGlad);
        }
    }
}

Gladiator Population::getGladiator(int index) {
    return individuals->at(index);
}

Gladiator Population::getFittest() {
    Gladiator fittest = individuals->at(0);
    for(int i = 0 ; i<this->getSize() ; i++){
        if(fittest.getFitness()<= individuals->at(i).getFitness()){
            fittest = getGladiator(i);
        }
    }
}

int Population::getSize() {
    return static_cast<int>(individuals->size());
}

void Population::saveIndividual(int index, Gladiator gladiator) {
    individuals->at(static_cast<unsigned long>(index)) = std::move(gladiator);
}

