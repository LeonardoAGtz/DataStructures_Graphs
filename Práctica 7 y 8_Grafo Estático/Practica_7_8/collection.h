#ifndef COLLECTION_H_INCLUDED
#define COLLECTION_H_INCLUDED

#include <iostream>
#include "nodo.h"

using namespace std;

class Collection {

    private:

        Nodo* first;
        Nodo* last;

    public:

        Collection();

        bool isEmpty();

        Nodo* getFirstPos();
        Nodo* getLastPos();

        void insertData(const string&);
        void deleteData(Nodo*);

        void formarCola(const string&);
        string desformarCola();

        void apilar(const string&);
        string desApilar();
        string getTope();

        Nodo* searchData(const string&);

    };


#endif // COLLECTION_H_INCLUDED
