//
// Created by daniel on 29/04/19.
//

#include <random>
#include <algorithm>
#include "Algorithm.h"

static std::random_device rd;
static std::mt19937 rng(rd());
static std::uniform_int_distribution<int> uni(10,99);
static std::uniform_int_distribution<int> uniSR(-20,20);
static std::uniform_int_distribution<int> uniGen(0,4);


static int tournamentSize = 5;
static auto mutationRate = vector<int>{15, 50};


Population Algorithm::envolvePopulation(Population pop) {

    Population newPopulation = Population(pop.getSize() , false);
    //ordenar
    Population sortPop = sortPopulation(pop);
    //reproducir a los diez mejores y sacar 10
    int cont = 0;
    for(int i = 0 ; i<4; i++){

        for(int j = i+1 ; j<5; j++){

            Gladiator newGladiator = crossover(sortPop.getGladiator(i),sortPop.getGladiator(j));
            //introducirlos a la poblacion
            newPopulation.saveInitIndi(newGladiator);
            cont++;

        }
    }

    //TODO:flag para cambiar el corte de genes
    //reproducir del 10 al 99 e introducir a la poblacion
    for (int i = 10; i < sortPop.getSize(); i++) {

        Gladiator indiv1 = tournamentSelection(sortPop);
        Gladiator indiv2 = tournamentSelection(sortPop);
        Gladiator newIndiv = crossover(indiv1, indiv2);
        //introducirlos a la poblacion
        newPopulation.saveInitIndi(newIndiv);
    }

    // Mutate population
    for (int i = 10; i < newPopulation.getSize(); i++) {
        mutate(newPopulation.getGladiator(i));
    }

    return newPopulation;

}


Gladiator Algorithm::tournamentSelection(Population pop) {
    Population tournament = Population(tournamentSize,false);
    for(int i = 0 ; i<tournamentSize ; i++){
        auto random = uni(rng);
        tournament.saveInitIndi(pop.getGladiator(random));
    }
    Gladiator g = tournament.getFittest();
    return g;
}


Gladiator Algorithm::crossover(Gladiator glad1, Gladiator glad2) {
    Gladiator  result =  Gladiator();
    //TODO: si se agrega un flag cambiar las partes que se juntan
    //how to crossover
    result.setAtributeTovector(glad1.getGENES().at(0) , glad1.getGENES().at(1), glad1.getGENES().at(2),glad2.getGENES().at(3),glad2.getGENES().at(4));
    result.setVectorToAtributes();
    result.calculateResistance();
    return result;

}

void Algorithm::mutate(Gladiator indiv) {


    int random = uni(rng);
    if(std::find(mutationRate.begin(), mutationRate.end(), random) != mutationRate.end()) {
            /* mutationRate contains random */
            int sum_rest = uniSR(rng);
            int randomGen = uniGen(rng);
            int gene = indiv.getGene(randomGen)+sum_rest;
            if(gene>99){
                gene = 99;
            }else if(gene<0){
                gene = 0;
            }
            indiv.setGenes(randomGen,gene);
        }

}

Population Algorithm::sortPopulation(Population pop) {
    Population sortPop = pop;
    for(int i = 0 ; i< 100 ; i++){
        for(int j = i ; j< 100 ; j++){
            if(sortPop.getIndividuals().at(i).getFitness()<sortPop.getIndividuals().at(j).getFitness()){

                //swap the gladiator
                Gladiator temp = sortPop.getIndividuals().at(i);

                sortPop.saveIndividual(i , pop.getIndividuals().at(j));
                //pop.getIndividuals().at(i) = pop.getIndividuals().at(j);
                //pop.getIndividuals().at(j) = temp;
                sortPop.saveIndividual(j , temp);

            }
        }return sortPop;

    }
}
