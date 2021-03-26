#ifndef ARISTA_H_INCLUDED
#define ARISTA_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class Arista {

    private:

        char estado;
        char poneracion[10];

    public:

        Arista();

        string getPoneracion();
        bool getEstado();

        void setPoneracion(const string&);
        void setEstado(const bool&);

    };

#endif // ARISTA_H_INCLUDED

