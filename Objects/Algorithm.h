//
// Created by daniel on 29/04/19.
//

#ifndef GENETIC_ALGORITHM_H
#define GENETIC_ALGORITHM_H


#include "Population.h"

class Algorithm {
    //parametos de GA

public:

public:
    /**
     * Crea una nueva generacion de individuos
     * @param pop poblacion de individuos
     * @return nueva poblacion
     */
    static Population envolvePopulation(Population * pop);
    /**
     * Selecciona 5 individuos al azar de la poblacion y toma el mejor
     * @param pop poblacion de la cual tomar al mejor individuo de los 5
     * @return el individuo con mejor fitness para ser cruzado
     */
    static Gladiator tournamentSelection(Population pop);
    /**
     * Funcion que cruza dos individuos
     * @param glad1 gladiador a cruzar
     * @param glad2 gladiador a cruzar
     * @return nuevo gladiador con las caracterizticas de ambos
     */
    static Gladiator crossover(Gladiator glad1 , Gladiator glad2 , bool flag);
    static Gladiator inversion(Gladiator indiv);
    /**
     * Bajo cierta tasa de probabilidad , la funcion suma o resta a un gen
     * @param indiv individuo al que se le realizara la mutacion
     */
    static Gladiator mutate(Gladiator indiv);
    /**
     * Funcion que ordena los individuos de una poblacion segun su fitness
     * @param pop
     */
    static void sortPopulation(Population * pop);







};


#endif //GENETIC_ALGORITHM_H
