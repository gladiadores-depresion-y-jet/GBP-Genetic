//
// Created by sebas211288 on 24/04/19.
//

#ifndef GENETIC_GLADIATOR_H
#define GENETIC_GLADIATOR_H


#include <string>
#include <string.h>
#include <zconf.h>
#include <vector>


/**
 * @file Gladiator.h
 * @date 26/04/19
 * @author Daniel garcia
 * @title Clase individuo
 * @brief Clase que abstrae la informacion de un individuo
 */
using namespace std;

class Gladiator {
private:
    int id, age ,probability ,estimatedG;
    vector<int> emotionalI, physical , upper , lower, resistance;

    vector<int> genes ;


public:
    /**
     * @brief Constructores de la clase gladiator
     */
    Gladiator();
    Gladiator(int ag , vector<int> emot , vector<int> phy , vector<int> up , vector<int> low, vector<int> res);
    /**
     * @brief Inicializa los atributos del gladiador
     */
    void init();
    /**
     * @brief Inicializa al gladiador de manera aleatoria
     */
    void generateIndividual();
    /**
     * Obtiene un gen especifico de la cadena
     * @param index
     * @return
     */
    int getGene(int index);
    int binTodec(vector<int> v);
    int size();
    /**
     * Setea valor a un gen especifico de la cadena
     */
    void setGenes(int index , int gene);
    /*int getFitness();*/
    string genesToString();
    int getId();
    int getAge();
    void setAge(int age);
    int getProbability();
    void setProbability(int probability);
    int getEstimatedG();
    void setEstimatedG(int estimatedG);
    int getEmotionalI();
    void setEmotionalI(vector<int> emotionalI);
    int getPhysical();
    void setPhysical(vector<int> physical);
    int getUpper();
    void setUpper(vector<int> upper);
    int getLower();
    void setLower(vector<int> lower);
    int getResistance();
    void setResistance(vector<int> resistance);


};


#endif //GENETIC_GLADIATOR_H
