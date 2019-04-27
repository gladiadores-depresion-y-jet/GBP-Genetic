//
// Created by sebas211288 on 24/04/19.
//


#include <cstdlib>
#include <time.h>
#include <zconf.h>
#include <random>
#include "Gladiator.h"
#include <math.h>

static int defaultGeneLen = 6;
static int individualID = 0;

static std::random_device rd;     // only used once to initialise (seed) engine
static std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
static std::uniform_int_distribution<int> uni(0,1); // guaranteed unbiased




Gladiator::Gladiator() {
    genes = vector<int>();
    this->id = individualID; individualID++;
    this->resistance = vector<int>();
    this->emotionalI = vector<int>();
    this->physical = vector<int>();
    this->upper = vector<int>();
    this->lower = vector<int>();
    this->age = 0;
    this->estimatedG = 0;
    this->probability = 0;
    this->init();
}


Gladiator::Gladiator(int ag, vector<int> emot, vector<int> phy, vector<int> up, vector<int> low, vector<int> res) {
    this->genes = vector<int>();
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

    for(int i = 0 ; i< defaultGeneLen ; i++){

        auto random_integer = uni(rng);
        genes.push_back(random_integer);
        resistance.push_back(random_integer);
    }
    for(int i = 0 ; i< defaultGeneLen ; i++){

        auto random_integer = uni(rng);
        upper.push_back(random_integer);
    }
    for(int i = 0 ; i< defaultGeneLen ; i++){

        auto random_integer = uni(rng);
        lower.push_back(random_integer);
    }
    for(int i = 0 ; i< defaultGeneLen ; i++){

        auto random_integer = uni(rng);
        physical.push_back(random_integer);
    }
    for(int i = 0 ; i< defaultGeneLen ; i++){

        auto random_integer = uni(rng);
        emotionalI.push_back(random_integer);
    }
}

int Gladiator::getGene(int index){
    return genes.at(index);
}
int Gladiator::binTodec(vector<int> v) {
    int result = 0;
    int exponent = v.size()-1;
    for(int i = 0 ; i<v.size() ; i++){
        if(v.at(i)){
            result += pow(2,exponent);
        }
        exponent--;
    }return result;

}

int Gladiator::size() {
    return defaultGeneLen;
}

void Gladiator::setGenes(int index , int gene) {
    this->genes.at(index) = gene;
}

/*int Gladiator::getFitness() {

}*/

string Gladiator::genesToString() {
    string geneString = "";
    for(int i = 0 ; i< defaultGeneLen ; i++){
        geneString += to_string(getGene(i));
    }
    return geneString;
}






//  Gets and Sets
int Gladiator::getId(){
    return id;
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
    return this->binTodec(emotionalI);
}

void Gladiator::setEmotionalI(vector<int> emotionalI) {
    this->emotionalI = emotionalI;
}

int Gladiator::getPhysical(){
    return this->binTodec(physical);
}

void Gladiator::setPhysical(vector<int> physical) {
    this->physical = physical;
}

int Gladiator::getUpper(){
    return this->binTodec(upper);
}

void Gladiator::setUpper(vector<int> upper) {
    this->upper = upper;
}

int Gladiator::getLower(){
    return this->binTodec(lower);
}

void Gladiator::setLower(vector<int> lower) {
    this->lower = lower;
}

int Gladiator::getResistance(){
    return this->binTodec(resistance);
}

void Gladiator::setResistance(vector<int> resistance) {
    this->resistance = resistance;
}