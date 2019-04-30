//
// Created by daniel on 29/04/19.
//

#ifndef GENETIC_POPULATION_H
#define GENETIC_POPULATION_H


#include "Gladiator.h"

class Population {
    // Se creara una poblacion con un tamaño de 90 para poder juntar siempre los nueve mejores de forma
    // 1 con todos , 2 con todos .. . sucesivamente sumando 45 , pero de cada cruce se pueden generar dos individuos
    // dando 90 otra vez
    vector<Gladiator> * individuals;

public:

    Population(int populationSize , bool initialise);
    Gladiator getGladiator(int index);
    Gladiator getFittest();
    int getSize();
    void saveIndividual(int index , Gladiator gladiator);

};


#endif //GENETIC_POPULATION_H
