//
// Created by sebas211288 on 27/04/19.
//

#ifndef GENETIC_LINKEDLIST_H
#define GENETIC_LINKEDLIST_H

#include "iostream"
#include "Node.h"

/**
 * @file LinkedList.h
 * @date 27/04/19
 * @author Daniel Garcia
 * @title Clase Lista enlazada
 * @brief Estructura Abstracta
 */
using  namespace std;
template<class T>
class LinkedList {

private:
    int size;
    int limit;
    Node<T>* head;
    bool * flag;

public:
    /**
     * Constructor de la clase
     */
    LinkedList(){
        limit=2; size = 0; this->head = 0 ; flag = new bool(false);
    }
    /**
     * Constructor con limite de elementos
     * @param l
     */
    LinkedList(int l){
        limit = l ; size = 0 ; head = 0; flag = new bool(false);

    }
    /**
     * Verifica si la lista está vacia o no
     * @return true si la cabeza es nula , si no false
     */
    bool isEmpty(){
        return this->head==0;
    }
    /**
     * Asigna el nodo cabeza de la lista enlazada
     * @param newNode
     */
    void setHEAD(Node<T> * newNode){
        head = newNode;
    }
    /**
     * Asigna si la lista enlazada es capaz de almacenar una cantidad indefinida de elementos
     * @param f true para agregar elementos sin limite
     */
    void setFlag(bool f){
        *flag = f;
    }

    /**
     * Asigna un limite entre 2 y 4 de elementos a la lista enlazada
     * Esto se hace solo para la lista de jugadores
     * @param i
     */
    void setLimit(int i){
        this->limit=i;
    }
    /**
     * Obtiene el limite de elementos de la lista
     * @return
     */
    int getLimit(){
        return this->limit;
    }
    /**
     * Resta 1 al size de la lista , esto para metodos personalizados de delete fuera de esta clase
     */
    void substractSize(){
        this->size--;
    }
    /**
     * Obtiene el nodo cabeza de la lista
     * @return head de la lista
     */
    Node<T>* getHead(){
        return this->head;
    }

    /**
     * Obtiene el size actual de la lista
     * @return tamaño de la lista
     */
    int getSize(){
        return this->size;
    }
    /**
     * Añade un nuevo elemento a la lista , lo inserta de ultimo
     * @param v elemento a añadir
     */
    void add(T v){

        if(size<limit || *flag) {
            if (isEmpty()) {
                this->head = new Node<T>(v);
            } else {
                Node<T> *temp = this->getHead();
                while (temp->getNext() != 0) {
                    temp = temp->getNext();
                }
                Node<T> *n = new Node<T>(v);
                temp->setNext(n);
            }
            size++;
        }
        else
        {
            cout<<"ERROR:Limite alcanzado."<<endl;
        }
    }
    /**
     * Añade un elemento a la lista , lo añade al inicio de la lista
     * @param v elemento a añadir
     */
    void addFirst(T v){
        if(isEmpty()){

            this->head = new Node<T>(v);

        }else{
            Node<T>* temp = this->getHead();
            Node<T>* n = new Node<T>(v);
            n->setNext(this->getHead());
            this->head = n;
        }size++;
    }
    /**
     * Elimina un nodo de la lista buscandolo por referencia
     * @param n nodo a eliminar
     */
    void delNode(T n){
        if(!this->isEmpty()){

            Node<T>* temp = this->getHead();

            if(temp->getValue()==n){
                delete(head);
                head = temp->getNext();
            }else{

                while(temp->getNext()->getValue()!=n){
                    temp = temp->getNext();

                    temp->setNext(temp->getNext()->getNext());
                    delete(temp->getNext());
                }

            }
        }
        size--;
    }
    /**
     * Verifica si un valor esta dentro de la lista
     * @param v valor a verificar
     * @return true si existe en la lista , false si no
     */
    bool in(T v){
        Node<T>* temp = this->getHead();
        while(temp!=0){
            if(temp->getValue() == v){
                return true;
            }
            temp = temp->getNext();

        }return false;
    }

    /**
     * Imprime en consola todos los valores almacenados en la lista
     */
    void see(){

        if(!isEmpty()){
            Node<T>* temp = this->getHead();
            cout<<"[";
            while(temp->getNext() != 0){
                cout<<temp->getValue()<<", ";
                temp = temp->getNext();
            }cout<<temp->getValue()<<"]";
        }else{
            cout<<"[]";
        }
    }



};


#endif //GENETIC_LINKEDLIST_H
