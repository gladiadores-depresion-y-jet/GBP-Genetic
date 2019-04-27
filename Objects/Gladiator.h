//
// Created by sebas211288 on 24/04/19.
//

#ifndef GENETIC_GLADIATOR_H
#define GENETIC_GLADIATOR_H


#include <string>
#include <string.h>
#include <zconf.h>


using namespace std;

class Gladiator {
private:
    int id,  age, probability, estimatedG,
            emotionalI, physical , upper , lower, resistance;

    Byte * genes ;


public:
    Gladiator();
    Gladiator(int ag , int emot , int phy , int up , int low, int res);
    void init();
    void generateIndividual();
    Byte getGene(int index);
    void setGenes(int index , Byte gene);
    static void setDefaultGenLen(int def);
    int size();
    /*int getFitness();*/
    string genesToString();

    int getId();
    void setId(int id);
    int getAge();
    void setAge(int age);
    int getProbability();
    void setProbability(int probability);
    int getEstimatedG();
    void setEstimatedG(int estimatedG);
    int getEmotionalI();
    void setEmotionalI(int emotionalI);
    int getPhysical();
    void setPhysical(int physical);
    int getUpper();
    void setUpper(int upper);
    int getLower();
    void setLower(int lower);
    int getResistance();
    void setResistance(int resistance);


};


#endif //GENETIC_GLADIATOR_H
