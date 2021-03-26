#ifndef VERTICE_H_INCLUDED
#define VERTICE_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class Vertice {

    private:

        char nombre[10];
        bool estado;

    public:

        Vertice();

        string getNombre();
        bool getEstado();

        void setNombre(const string&);
        void setEstado(const bool&);
    };

#endif // VERTICE_H_INCLUDED
