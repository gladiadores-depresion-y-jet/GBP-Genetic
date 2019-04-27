//
// Created by sebas211288 on 24/04/19.
//


#include <cstdlib>
#include <time.h>
#include <zconf.h>
#include "Gladiator.h"

static int defaultGeneLen = 64;
static int individualID = 0;




Gladiator::Gladiator() {
    genes = new Byte[defaultGeneLen];
    this->age = 0;
    this->emotionalI = 0;
    this->estimatedG = 0;
    this->id = individualID; individualID++;
    this->physical = 0;
    this->upper = 0;
    this->lower = 0;
    this->probability = 0;
    this->resistance = 0;
    this->init();
}


Gladiator::Gladiator(int ag, int emot, int phy, int up, int low, int res) {
    this->genes = new Byte[defaultGeneLen];
    this->id = individualID; individualID++;
    this->resistance = res;
    this->age = ag;
    this->lower = low;
    this->upper = up;
    this->emotionalI = emot;
    this->physical = phy;
    this->probability = 0;
    this->estimatedG = 0;
    this->init();
}

void Gladiator::init() {
    this->generateIndividual();
}

void Gladiator::generateIndividual() {
    for(int i = 0 ; i< size() ; i++){
        srand (time(0));
        int random = rand()%2;
        /*Byte gene = Byte();*/
        Byte gene = (Byte)random;
        genes[i] = gene;
    }
}

Byte Gladiator::getGene(int index){
    return genes[index];
}

void Gladiator::setGenes(int index , Byte gene) {
    this->genes[index] = gene;
}
void Gladiator::setDefaultGenLen(int def) {
    defaultGeneLen = def;
}

int Gladiator::size() {
    int len = sizeof(genes)/sizeof(genes[0]);
    return len;
}

/*int Gladiator::getFitness() {

}*/

string Gladiator::genesToString() {
    string geneString = "";
    for(int i = 0 ; i<size() ; i++){
        geneString += getGene(i);
    }
    return geneString;
}






//  Gets and Sets
int Gladiator::getId(){
    return id;
}

void Gladiator::setId(int id) {
    Gladiator::id = id;
}

int Gladiator::getAge(){
    return age;
}

void Gladiator::setAge(int age) {
    Gladiator::age = age;
}

int Gladiator::getProbability(){
    return probability;
}

void Gladiator::setProbability(int probability) {
    this->probability = probability;
}

int Gladiator::getEstimatedG(){
    return estimatedG;
}

void Gladiator::setEstimatedG(int estimatedG) {
    this->estimatedG = estimatedG;
}

int Gladiator::getEmotionalI(){
    return emotionalI;
}

void Gladiator::setEmotionalI(int emotionalI) {
    this->emotionalI = emotionalI;
}

int Gladiator::getPhysical(){
    return physical;
}

void Gladiator::setPhysical(int physical) {
    this->physical = physical;
}

int Gladiator::getUpper(){
    return upper;
}

void Gladiator::setUpper(int upper) {
    this->upper = upper;
}

int Gladiator::getLower(){
    return lower;
}

void Gladiator::setLower(int lower) {
    this->lower = lower;
}

int Gladiator::getResistance(){
    return resistance;
}

void Gladiator::setResistance(int resistance) {
    this->resistance = resistance;
}