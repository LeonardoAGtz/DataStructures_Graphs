#include "collection.h"
using namespace std;

Collection::Collection() {
    first = nullptr;
    last = nullptr;
    }

bool Collection::isEmpty() {
    return first == nullptr;
    }

Nodo* Collection::getFirstPos() {
    if(isEmpty()) {
        ///Error
        return nullptr;
        }

    return first;
    }

Nodo* Collection::getLastPos() {
    if(isEmpty()) {
        ///Error
        return nullptr;
        }

    return last;
    }

void Collection::insertData(const string& s) {
    Nodo* nuevo = new Nodo(s);

    if(isEmpty()) {
        first = nuevo;
        last = nuevo;
        }
    else {
        last->setNext(nuevo);
        nuevo->setPrev(last);

        last = nuevo;
        }

    }

void Collection::deleteData(Nodo* p) {
    if(p == first) {
        first = p->getNext();
        delete p;
        return;
        }
    if(p == last) {
        last = p->getPrev();
        delete p;
        return;
        }

    ///cualquier posicion

    p->getPrev()->setNext(p->getNext());
    p->getNext()->setPrev(p->getPrev());
    delete p;
    return;

    }

void Collection::formarCola(const string& s) {
    Nodo* nuevo = new Nodo(s);

    if(isEmpty()) {
        first = nuevo;
        last = nuevo;
        }
    else {
        last->setNext(nuevo);
        nuevo->setPrev(last);

        last = nuevo;
        }
    }

string Collection::desformarCola() {
    Nodo* aux;
    string myStr;

    aux = first;

    first = aux->getNext();
    myStr = aux->getData();

    delete aux;
    return myStr;

    }

void Collection::apilar(const string& s) {
    Nodo* nuevo = new Nodo(s);

    if(isEmpty()) {
        first = nuevo;
        last = nuevo;
        }
    else {
        first->setPrev(nuevo);
        nuevo->setNext(first);

        first = nuevo;
        }
    }

string Collection::desApilar() {
    Nodo* aux;
    string myStr;

    aux = first;

    first = aux->getNext();
    myStr = aux->getData();

    delete aux;
    return myStr;
    }

string Collection::getTope() {
    return first->getData();
    }

Nodo* Collection::searchData(const string& s) {
    Nodo* aux(first);

    while(aux != nullptr) {
        if(aux->getData() == s) {
            return aux;
            }
        aux = aux->getNext();
        }

    return nullptr;
    }
