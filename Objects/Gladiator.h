//
// Created by daniel on 24/04/19.
//

#ifndef GENETIC_GLADIATOR_H
#define GENETIC_GLADIATOR_H


#include <string>
#include <string.h>
//#include <zconf.h>
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
public:
    void setFitness(int fitness);

private:
    int id, age ,probability ,estimatedG , emotionalI, physical , upper , lower, resistance;

    float fitness;
    vector<int> genes ;


public:
    /**
     * @brief Constructores de la clase gladiator
     */
    Gladiator();
    Gladiator(int ag , int emot , int phy , int up , int low, int res);
    /**
     * @brief Inicializa los atributos del gladiador
     */
    void init();
    /**
     * @brief Inicializa al gladiador de manera aleatoria
     */
    void generateIndividual();
    int binTodec(vector<int> v);
    vector<int> decTobin(int num);
    /**
     * Calcula la resistencia en base a sus atributos
     * @return la resistencia calculada
     */
    bool calculateResistance();
    /**
     * Retorna el largo de la cadena de genes
     * @return
     */
    int size();
    /**
     * Setea valor a un gen especifico de la cadena
     */
    void setGenes(int index , int gene);
    /**
     * Obtiene un gen especifico de la cadena
     * @param index
     * @return
     */
    int getGene(int index);
    /**
     * Devuelve el fitness del individuo
     * @return fitness
     */
    float getFitness();
    /**
     * Imprime los genes del individuo , los genes se refiere a cada atributo del individuo
     * @return
     */
    string genesToString();

    void setAtributeTovector(int upper , int lower , int emoti , int phy , int age);
    void setAtributeTovector();
    vector<int> getGENES();

    void setVectorToAtributes();


    //setters y getters comunes

    int getId();
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

    int getAtribute(int index);
    void setAtribute(int index , int gen);
    void addTOgenes(vector<int> vector);
    vector<int> getVectorIndex(int index1 , int index2);
    void verifyAtributesLimit();
    void setGenesVector(vector<int> vector);
    void setID(int id);




};


#endif //GENETIC_GLADIATOR_H
