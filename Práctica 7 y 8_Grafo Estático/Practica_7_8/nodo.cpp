#include "nodo.h"
using namespace std;

Nodo::Nodo() {
    next = nullptr;
    prev = nullptr;
    }

Nodo::Nodo(const string& s) {
    data = s;
    next = nullptr;
    prev = nullptr;
    }

string Nodo::getData() {
    return data;
    }

Nodo* Nodo::getNext() {
    return next;
    }

Nodo* Nodo::getPrev() {
    return prev;
    }

void Nodo::setData(const string& s) {
    data = s;
    }

void Nodo::setNext(Nodo* n) {
    next = n;
    }

void Nodo::setPrev(Nodo* n) {
    prev = n;
    }
