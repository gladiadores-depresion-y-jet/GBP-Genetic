//
// Created by sebas211288 on 27/04/19.
//

#ifndef GENETIC_NODE_H
#define GENETIC_NODE_H

/**
 * @file Node.h
 * @date 27/04/19
 * @author Daniel Garcia
 * @title Clase nodo
 * @brief Estructura Abstracta
 * @tparam T
 */
template <class T>
class Node {

private:
    Node<T>* next;
    T value;

public:

    /**
     * Constructor del nodo
     */
    Node(){
        this->value = 0;
        this->next = 0;
    }
    /**
     * Segundo constructor que inicializa el valor del nodo
     * @param v
     */
    Node(T v){
        this->value = v;
        this->next = 0;
    }
    /**
     * Constructor que inicializa el valor del nodo y el nodo al que apunta
     * @param v
     * @param n
     */
    Node(T v , Node<T>* n ){
        this->value = v;
        this->next = n;
    }
    /**
     * Retorna el puntero al siguiente
     * @return nodo siguiente
     */
    Node<T>* getNext(){
        return this->next;
    }
    /**
     * Retorna el valor que almacena el nodo
     * @return
     */
    T getValue(){
        return value;
    }
    /**
     * Asigna el valor que almacena el nodo
     * @param t
     */
    void setValue(T t){
        this->value = t;
    }
    /**
     * Asigna un puntero siguiente
     * @param n
     */
    void setNext(Node<T>* n){
        this->next = n;
    }
    /**
     * Destructor de la clase nodo , libera la memoria del heap
     */
    virtual ~Node(){
        delete next;
    }

};


#endif //GENETIC_NODE_H
