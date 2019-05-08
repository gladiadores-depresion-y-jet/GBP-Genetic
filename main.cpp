#include <iostream>
#include <time.h>
#include <unistd.h>
#include <vector>
#include <random>
#include "Objects/Gladiator.h"
#include "Objects/Fitness.h"
#include "vector"
#include "Objects/Population.h"
#include "Objects/Algorithm.h"
#include "Serializador/SerialPort.h"


//std::vector<int> * Fitness::solution = new vector<int>(6,1);
static std::random_device rd;
static std::mt19937 rng(rd());

static std::uniform_int_distribution<int> uniNew(1,2);

int main() {/*    Gladiator f = Gladiator();
    f.init();

    cout<<f.getGene(4)<<endl;

    int num = 4;
    vector<int> * bin = f.decTobin(num);
    cout<<bin->size()<<endl;
    for(int i = 0; i< bin->size() ; i++){
        cout<<bin->at(i);
    }*/
/*    Gladiator f = Gladiator();
    f.init();

    cout<<f.getGene(4)<<endl;

    int num = 4;
    vector<int> * bin = f.decTobin(num);
    cout<<bin->size()<<endl;
    for(int i = 0; i< bin->size() ; i++){
        cout<<bin->at(i);
    }*/
    float solution = 6;
    Fitness::setSolution(solution);
    Population * mypop = new Population(100,true);
    int generation = 0;

    while(mypop->getFittest().getFitness() < 6){

        generation++;
        //Population p = Algorithm::sortPopulation(mypop);
        Algorithm::sortPopulation(mypop);
        cout<<"Generation: "<<generation <<"Fittest: "<< mypop->getFittest().getFitness()<<endl;
        cout<<"Gladiator Genes: "<<mypop->getFittest().genesToString()<<endl;
        *mypop = Algorithm::envolvePopulation(mypop);


    }

    cout<<" Solution found! "<<endl;
    cout<< " Generation: "<<generation;
    cout<< "Genes: "<< mypop->getFittest().genesToString()<<endl;

    SerialPort serial = SerialPort();
    serial.sendMessage("on");



    return 0;
}