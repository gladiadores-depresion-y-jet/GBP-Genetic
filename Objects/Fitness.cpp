//
// Created by daniel on 29/04/19.
//

#include "Fitness.h"





static float * solution = new float();

void Fitness::setSolution(float sol) {
    *solution = sol;
}

float Fitness::getFitness(Gladiator gladiator) {

    float fitness = 0;
    float v = 25;
    float f = 45;
    float n = 99;

    // se añade un -1 para que no llegue a tomar la edad ,
    // ya que con esta se calcula diferente el fitnes
    for(int i = 0 ; i < gladiator.size()-1 ; i++){
        fitness += (float)gladiator.getGene(i)/n;
    }

    //añadiendo resistencia
    fitness+=gladiator.getResistance()/n;


    //analisis de la edad del gladiador
    if(gladiator.getAge()>=0 & gladiator.getAge()<25){
        fitness += (float)gladiator.getAge()/v;
    }else if(gladiator.getAge()>=25 & gladiator.getAge() <=40){
        fitness+=1;
    }else if(gladiator.getAge()>40 & gladiator.getAge()<=99){
        fitness += f/(float)gladiator.getAge();
    }
    return fitness;
}

float getMaxFitness() {
    return 6;
}

