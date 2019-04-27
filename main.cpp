#include <iostream>
#include <time.h>
#include <unistd.h>
#include "headers/Gladiator.h"
int main() {
    Gladiator * g = new Gladiator();
    Gladiator * g1 = new Gladiator();
    Gladiator * g2 = new Gladiator();
    cout<<"id: "<<g->getId()<<endl;
    cout<<"id: "<<g1->getId()<<endl;
    g->setAge(11);
    cout<<"age of "<<g->getId()<<" is "<< g->getAge()<< endl;
    cout<<"age of "<<g1->getId()<<" is "<< g2->getAge()<< endl;
    cout<<"lenGenes: "<<g->size()<<endl;
    cout<<"genes of gladiator: "<<g->getId()<<" is "<<g->genesToString()<<endl;
    cout<<"genes of gladiator: "<<g1->getId()<<" is "<<g1->genesToString()<<endl;
    cout<<"genes of gladiator: "<<g2->getId()<<" is "<<g2->genesToString()<<endl;

    return 0;
}