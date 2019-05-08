//
// Created by daniel on 24/04/19.
//


#include <cstdlib>
#include <time.h>
#include <zconf.h>
#include <random>
#include "Gladiator.h"
#include "Fitness.h"
#include <math.h>
#include <sstream>

static int defaultGeneLen = 5;
static int individualID = 0;

static std::random_device rd;     // only used once to initialise (seed) engine
static std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
static std::uniform_int_distribution<int> uni(0,25); // guaranteed unbiased


Gladiator::Gladiator() {
    genes = vector<int>();
    this->id = individualID; individualID++;
    this->resistance = 0;
    this->emotionalI = 0;
    this->physical = 0;
    this->upper = 0;
    this->lower = 0;
    this->age = 0;
    this->estimatedG = 0;
    this->probability = 0;
    this->fitness = 0;
    //this->init();
}


Gladiator::Gladiator(int ag, int emot, int phy, int up, int low, int res) {
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
    this->fitness = 0;
    //this->init();
}

void Gladiator::init() {
    this->generateIndividual();
}

void Gladiator::generateIndividual() {

    //TODO: crear ruleta de porcentajes

    upper = uni(rng);
    lower = uni(rng);
    physical = uni(rng);
    emotionalI = uni(rng);
    age = uni(rng);
    //aqui se tiene que calcula la resistencia y setearla , averiguar como calcular fuerza
    if(this->calculateResistance()){
        cout<<"resistencia de gladiador : "<<resistance<<endl;
    }else{
        cout<<"no se calculo la resistencia"<<endl;
    }


    //seteando a los genes
    this->setAtributeTovector(upper,lower,emotionalI,physical,age);
    cout<<this->genesToString()<<endl;
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
vector<int> * Gladiator::decTobin(int num) {

    vector<int> * binario = new vector<int>();
    vector<int>  aux =  vector<int>();
    while(num != 0 ){
        int bit = num%2;
        num = num/2;
        aux.push_back(bit);

    }for(int i = aux.size()-1 ;i>=0 ; i-- ){

        binario->push_back(aux.at(i));
    }
    return binario;
}
//TODO: metodo para calcular la resistencia podria cambiar
bool Gladiator::calculateResistance() {
    int multi = 0;
    if(this->age >= 0 & this->age<=10){
        multi = 3;

    }else if(this->age >= 11 & this->age<=24){
        multi = 2;
    }else if(this->age >= 25 & this->age<=40){
        multi = 1;

    }else if(this->age >= 26 & this->age<=60){
        multi = 2;
    }else if(this->age >= 61 & this->age<=99){
        multi = 3;
    }

    resistance = (upper+lower+emotionalI+physical)/(4*multi);

    if(resistance<0){
        resistance = 0;
    }else if(resistance >99){
        resistance = 99;
    }

    return true;
}

int Gladiator::size() {
    return defaultGeneLen;
}

void Gladiator::setGenes(int index , int gene) {
    this->genes.at(index) = gene;
    fitness = 0;
}

float Gladiator::getFitness() {
        if(fitness == 0){
            this->fitness = Fitness::getFitness(*this);
        }
    return this->fitness;
}

string Gladiator::genesToString() {
    string geneString = "[";
    for(int i = 0 ; i< defaultGeneLen-1 ; i++){
        geneString += to_string(getGene(i))+",";
    }geneString+=to_string(getGene(defaultGeneLen-1))+"]";
    return geneString;
}
//TODO: cambiar metodo , convertir a binario y añadir cada cadena a la cadena de genes
void Gladiator::setAtributeTovector(int upper, int lower, int emoti, int phy, int age) {
    genes.push_back(upper);
    genes.push_back(lower);
    genes.push_back(emoti);
    genes.push_back(phy);
    genes.push_back(age);
}

vector<int> Gladiator::getGENES() {
    return this->genes;
}

//TODO: cambiar metodo , dividir el array de genes en 5 partes y convertir cada parte a decimal y asignar al atributo
void Gladiator::setVectorToAtributes() {
    this->upper = this->genes.at(0);
    this->lower = this->genes.at(1);
    this->emotionalI = this->genes.at(2);
    this->physical = this->genes.at(3);
    this->age = this->genes.at(4);


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

void Gladiator::setFitness(int fitness) {
    this->fitness = fitness;
}

ptree Gladiator::stringToPtree(string s)
{
    std::istringstream iss(s);
    ptree document;
    read_json(iss, document);
    return document;
}

string Gladiator::ptreeToString(ptree pt) {
    std::ostringstream oss;
    write_json(oss, pt);
    return oss.str();
}



