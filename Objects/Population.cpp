#include <utility>
#include <iostream>

//
// Created by daniel on 29/04/19.
//

#include "Population.h"


Population::Population(int populationSize, bool initialise) {
    individuals =  vector<Gladiator>();
    fittest = new Gladiator();
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

    Gladiator fit = individuals.at(0);
    for(int i = 1 ; i<this->getSize() ; i++){
        float fit1 = fit.getFitness();
        float fit2 = individuals.at(i).getFitness();
        if(fit.getFitness() <= this->getGladiator(i).getFitness()){
            fit = getGladiator(i);
        }
    }
    *fittest  = fit;
    return *fittest;
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

void Population::deleteGladiator(int num) {
    for(int i = 0 ; i<num ; i++){
        this->individuals.erase(this->individuals.begin()+this->individuals.size()-1);
    }cout<<"se han eliminado "<<num<<" individuos"<<endl;
}

vector<Gladiator> Population::getIndividuals() {
    return individuals;
}

