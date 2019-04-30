//
// Created by daniel on 29/04/19.
//

#include <random>
#include "Algorithm.h"

static std::random_device rd;     // only used once to initialise (seed) engine
static std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
static std::uniform_int_distribution<int> uni(0,90); // guaranteed unbiased

static double uniformRate = 0.5;
static double mutationRate = 0.015;
static int tournamentSize = 5;
static bool elitism = true;




Population Algorithm::envolvePopulation(Population pop) {
    Population newPopulation = Population(pop.getSize() , false);

    if(elitism){
        newPopulation.saveIndividual(0,pop.getFittest());
    }
    int elitismOffset;
    if(elitism){
        elitismOffset = 1;
    }else{
        elitismOffset = 0;
    }

    /**
     * Funcion de ordenamiento (cambiar tournament)
     * For i
     * For j
     * añadir al population
     */
    for (int i = elitismOffset; i < pop.getSize(); i++) {
/*        Gladiator indiv1 = tournamentSelection(pop);
        Gladiator indiv2 = tournamentSelection(pop);
        Gladiator newIndiv = crossover(indiv1, indiv2);
        newPopulation.saveIndividual(i, newIndiv);*/
    }

    // Mutate population
    for (int i = elitismOffset; i < newPopulation.getSize(); i++) {
        mutate(newPopulation.getGladiator(i));
    }

    return newPopulation;

}

//crear funcion de ordenamiento por fitness
// modificar
Gladiator Algorithm::tournamentSelection(Population pop) {
    Population tournament = Population(tournamentSize,false);
    for(int i = 0 ; i<tournamentSize ; i++){
        auto random = uni(rng);
        tournament.saveIndividual(i,pop.getGladiator(random));
    }
    Gladiator g = tournament.getFittest();
}

//investigar si se pueden retornar dos valores al mismo tiempo
Gladiator Algorithm::crossover(Gladiator glad1, Gladiator glad2) {
    Gladiator * result = new Gladiator();
    //how to crossover
    // que pasa con la edad ? y demás atributos que no se cruzan , o se inicializan en 0 ?
    vector<int> newUpper = vector<int>();
    vector<int> newLower = vector<int>();
    vector<int> newEmotional = vector<int>();
    vector<int> newPhysical = vector<int>();
    vector<int> newResistance = vector<int>();
    
    //CREAR GETTERS Y SETTERS PERO DE VECTOR
    for(int i = 0 ; i<3 ; i++){
        newUpper.at(i) = glad1.
        newLower
        newEmotional
        newPhysical
        newResistance

    }
    for(int j = 0 ; j<3 ; j++){
        newUpper
        newLower
        newEmotional
        newPhysical
        newResistance
    }
    result->setUpper(newUpper);
    result->setLower(newLower);
    result->setEmotionalI(newEmotional);
    result->setPhysical(newPhysical);
    result->setResistance(newResistance);
}
