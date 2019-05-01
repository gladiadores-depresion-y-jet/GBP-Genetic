#include <utility>

//
// Created by daniel on 29/04/19.
//

#include "Population.h"


Population::Population(int populationSize, bool initialise) {
    individuals =  vector<Gladiator>();
    if(initialise){
        for(int i = 0 ; i<populationSize ; i++){
            Gladiator newGlad = Gladiator();
            newGlad.init();
            this->saveInitIndi(newGlad);
        }
    }
}

Gladiator Population::getGladiator(int index) {
    return individuals.at(index);
}
//TODO: fijarse con debugin como escoge con el fitness
Gladiator Population::getFittest() {
    Gladiator fittest = individuals.at(0);
    float fit1 = fittest.getFitness();
    for(int i = 0 ; i<this->getSize() ; i++){
        float fit2 = individuals.at(i).getFitness();
        if(fittest.getFitness()<= individuals.at(i).getFitness()){
            fittest = getGladiator(i);
        }
    }
    return fittest;
}

int Population::getSize() {
    return static_cast<int>(individuals.size());
}

void Population::saveIndividual(int index, Gladiator gladiator) {
    individuals.at(index) = gladiator;
}

void Population::saveInitIndi(Gladiator gladiator) {
    individuals.push_back(gladiator);
}

vector<Gladiator> Population::getIndividuals() {
    return individuals;
}

