//
// Created by daniel on 29/04/19.
//

#include <random>
#include <algorithm>
#include "Algorithm.h"

static std::random_device rd;
static std::mt19937 rng(rd());
static std::uniform_int_distribution<int> uni(10,99);

// Probabilidades de mutacion y cantidad a sumar y restar
static std::uniform_int_distribution<int> uniMut(0,99);
static std::uniform_int_distribution<int> uniSR(-20,20);
static std::uniform_int_distribution<int> uniGen(0,3);

// Probabilidades de inversion y rango de genes en el que puede ocurrir el cambio
static std::uniform_int_distribution<int> uniInv(0,200);
static std::uniform_int_distribution<int> uniGenInv(0,29);

//cantidad de años a sumar o restar
static std::uniform_int_distribution<int> uniAge(-2,2);

// torunament ya no se necesita
static int tournamentSize = 5;
//si el numero random sale entre estos valores entonces se produce una mutacion
static auto mutationRate = vector<int>{15, 50};
//si el numero random sale entre estos valores entonces se produce una inversion
static auto inversionRate = vector<int>{67};


Population Algorithm::envolvePopulation(Population * pop) {

    Population newPopulation = Population(pop->getSize() , false);
    //ordenar
    //Population sortPop = sortPopulation(pop);
    sortPopulation(pop);
    //reproducir a los diez mejores y sacar 10

    //añadiendo los cruces de los mejores
    //TODO::Realizar de manera distinta los cruces
    bool flag = true;
    for(int i = 0 ; i<4; i++){

        for(int j = i+1 ; j<5; j++){

            Gladiator newGladiator = mutate(crossover(pop->getGladiator(i),pop->getGladiator(j),flag));
            //introducirlos a la poblacion
            newPopulation.saveInitIndi(newGladiator);

        }
    }
    //añadiendo a los 5 mejores de la generacion pasada
    for(int i = 0 ; i<90 ; i++){
        newPopulation.saveInitIndi(pop->getGladiator(i));
    }

    //reproducir del 40 al 89 e introducir a la poblacion
//    for (int i = 40; i < sortPop.getSize()-10; i++) {
//
//        flag = i % 2 != 0;
//        Gladiator indiv1 = tournamentSelection(sortPop);
//        Gladiator indiv2 = tournamentSelection(sortPop);
//        Gladiator newIndiv = mutate(crossover(indiv1, indiv2 , flag));
//        //introducirlos a la poblacion
//        newPopulation.saveInitIndi(newIndiv);
//    }


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


//TODO:Cambiar con fors ya que los genes van a ser mas largos

Gladiator Algorithm::crossover(Gladiator glad1, Gladiator glad2, bool flag) {

    Gladiator  * result = new Gladiator();

    //how to crossover
    if(flag){
        result->setAtributeTovector(glad1.getGene(0) , glad2.getGene(1), glad1.getGene(2),glad2.getGene(3),glad1.getGene(4));
        result->setVectorToAtributes();
        result->calculateResistance();
    }else{
        result->setAtributeTovector(glad2.getGene(0) , glad1.getGene(1), glad2.getGene(2),glad1.getGene(3),glad2.getGene(4));
        result->setVectorToAtributes();
        result->calculateResistance();
    }
    return *result;

}
//TODO: hacer la funcion de inversion
Gladiator Algorithm::inversion(Gladiator indiv) {
    Gladiator glad = indiv;
    int invetir =  uniInv(rng);
    if(invetir== 67){
        int genInvertido = uniGenInv(rng);
        if(glad.getGene(genInvertido) == 1){
            glad.setGenes(genInvertido , 0);
        }else{
            glad.setGenes(genInvertido,1);
        }
    }
    return glad;


}

Gladiator Algorithm::mutate(Gladiator indiv) {

    Gladiator glad = indiv;
    int random = uniMut(rng);
    if(std::find(mutationRate.begin(), mutationRate.end(), random) != mutationRate.end()) {
            /* mutationRate contains random */
            int sum_rest = uniSR(rng);
            int randomGen = uniGen(rng);
            int ranAge = uniAge(rng);
            int genAge = glad.getGene(4)+ranAge;
            glad.setGenes(4,genAge);
            int gene = glad.getGene(randomGen)+sum_rest;
            if(gene>99){
                gene = 99;
            }else if(gene<0){
                gene = 0;
            }
            glad.setGenes(randomGen,gene);
        }return glad;

}

void Algorithm::sortPopulation(Population * pop) {
    //Population sortPop = pop;
    for(int i = 0 ; i< 100 ; i++){
        for(int j = i ; j< 100 ; j++){
            float g1 = pop->getGladiator(i).getFitness();
            float g2 = pop->getGladiator(j).getFitness();
            if(pop->getGladiator(i).getFitness()<pop->getGladiator(j).getFitness()){

                //swap the gladiator
                Gladiator temp = pop->getGladiator(i);
                pop->saveIndividual(i , pop->getGladiator(j));
                pop->saveIndividual(j , temp);

            }
        }//return sortPop;

    }
}
