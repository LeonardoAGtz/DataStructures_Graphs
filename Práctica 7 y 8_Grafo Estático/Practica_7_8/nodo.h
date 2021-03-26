#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include <iostream>

using namespace std;

class Nodo {

    private:

        string data;

        Nodo* next;
        Nodo* prev;

    public:

        Nodo();
        Nodo(const string&);

        string getData();
        Nodo* getNext();
        Nodo* getPrev();

        void setData(const string&);
        void setNext(Nodo*);
        void setPrev(Nodo*);

    };



#endif // NODO_H_INCLUDED
