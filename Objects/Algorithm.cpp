//
// Created by daniel on 29/04/19.
//

#include <random>
#include <algorithm>
#include <time.h>
#include "Algorithm.h"

//si el numero random sale entre estos valores entonces se produce una mutacion
static auto mutationRate = vector<int>{15, 50,2,77,99,80};
static auto inversionRate = vector<int>{5, 60,3,81,94};

Population Algorithm::envolvePopulation(Population * pop) {

    Population newPopulation = Population(pop->getSize() , false);
    //ordenar
    //Population sortPop = sortPopulation(pop);
    sortPopulation(pop);
    //reproducir a los diez mejores y sacar 10

    //añadiendo los cruces de los mejores

    bool flag = true;
    for(int i = 0 ; i<4; i++){

        for(int j = i+1 ; j<5; j++){
            flag = !flag;

            Gladiator newGladiator = mutate(crossover(pop->getGladiator(i),pop->getGladiator(j),flag));
            //introducirlos a la poblacion
            newPopulation.saveInitIndi(newGladiator);

        }
    }
    //añadiendo a los 5 mejores de la generacion pasada
    for(int i = 0 ; i<90 ; i++){
        newPopulation.saveInitIndi(pop->getGladiator(i));
    }
    return newPopulation;

}

Gladiator Algorithm::crossover(Gladiator glad1, Gladiator glad2, bool flag) {

    Gladiator  * result = new Gladiator();

    //how to crossover
    if(flag){
        result->setAtributeTovector(glad1.getAtribute(0) , glad2.getAtribute(1), glad1.getAtribute(2),glad2.getAtribute(3),glad1.getAtribute(4));
        result->setVectorToAtributes();
        result->calculateResistance();
    }else{
        result->setAtributeTovector(glad2.getAtribute(0) , glad1.getAtribute(1), glad2.getAtribute(2),glad1.getAtribute(3),glad2.getAtribute(4));
        result->setVectorToAtributes();
        result->calculateResistance();
    }
    return *result;

}

Gladiator Algorithm::inversion(Gladiator indiv) {


    srand (time(0));
    int invertir= rand() % 100;
    if(std::find(inversionRate.begin(), inversionRate.end(), invertir) != inversionRate.end()) {
        Gladiator * glad = new Gladiator();
        glad->setGenesVector(indiv.getGENES());
        glad->setID(indiv.getId());
        int init = rand() % 35;
        int end = rand() % 35;
        if(init > end){
            int temp = end;
            end = init;
            init = temp;
        }
        int final = end;
        for(int i = init ; i<end+1 ; i++ ){
            int t = glad->getGene(i);
            glad->setGenes(i,glad->getGene(final));
            glad->setGenes(final , t);
            final--;
        }return *glad;
    }return indiv;


/*    srand (time(0));
    int invertir= rand() % 200;
    if(invertir == 67){
        Gladiator * glad = new Gladiator();
        glad->setGenesVector(indiv.getGENES());
        glad->setID(indiv.getId());

        int cantidad = rand() % 4 +1;

        for(int i = 0 ; i<cantidad ; i++){

            int genInvertido= rand() %35 ;

            if(glad->getGene(genInvertido) == 1){
                glad->setGenes(genInvertido , 0);
            }else{
                glad->setGenes(genInvertido,1);
            }
        }
        glad->setVectorToAtributes();
        glad->verifyAtributesLimit();
        glad->calculateResistance();
        return *glad;

    }return indiv;*/



}


Gladiator Algorithm::mutate(Gladiator indiv) {


    //TODO probabilidad de que cada bit mute (esto produce que hayan cadenas que no estaban antes)
    srand (time(0));
    //int random= rand() % 100;
    Gladiator * glad = new Gladiator();

    glad->setGenesVector(indiv.getGENES());
    glad->setID(indiv.getId());
    glad->setVectorToAtributes();
    for(int i = 0; i<34 ; i++){
        int random = rand() %100;
        if(std::find(mutationRate.begin(), mutationRate.end(), random) != mutationRate.end()) {
            if(glad->getGene(i) == 0){
                glad->setGenes(i,1);
            }else{
                glad->setGenes(i ,0);
            }
        }
    }
    glad->setVectorToAtributes();
    glad->verifyAtributesLimit();
    glad->calculateResistance();
    return *glad;


//    if(std::find(mutationRate.begin(), mutationRate.end(), random) != mutationRate.end()) {
//        Gladiator * glad = new Gladiator();
//        glad->setGenesVector(indiv.getGENES());
//        glad->setID(indiv.getId());
//        glad->setVectorToAtributes();
//
//            /* mutationRate contains random */
//
//            srand (time(0));
//            int sum_rest= rand() % 21;
//
//            int randomGen = rand() % 4;
//
//            int ranAge = rand() % 3;
//
//            int genAge = glad->getAtribute(4)+ranAge;
//            if(genAge > 99){
//                genAge = 99;
//            }else if(genAge<0){
//                genAge = 0;
//            }
//            glad->setAtribute(4,genAge);
//            int gene = glad->getAtribute(randomGen)+sum_rest;
//            if(gene>99){
//                gene = 99;
//            }else if(gene<0){
//                gene = 0;
//            }
//            glad->setAtribute(randomGen,gene);
//        glad->verifyAtributesLimit();
//        glad->setAtributeTovector();
//        glad->calculateResistance();
//
//        return *glad;
//        }return indiv;


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
