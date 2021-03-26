#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>
#include "grafo.h"
#include <fstream>
#include "stdlib.h"
#include <stdio.h>
#include <string.h>

using namespace std;

class Menu {
    private:

        Grafo myGrafo;

        void crearVertice();
        void crearArista();

        void imprimirVertices();
        void imprimirVertices2();
        void imprimirAristas();
        void imprimirAristas2();
        void imprimirListaA();
        void guardarGrafo();
        void cargarGrafo();

        void editarVertice();
        void editarArista();

        void eliminarVertice();
        void eliminarArista();

        void recorridoAnchura();
        void recorridoProfundidad();

        void rutaAnchura();
        void rutaProfundidad();

    public:

        Menu();
        void mostrarMenu();

    };


#endif // MENU_H_INCLUDED
