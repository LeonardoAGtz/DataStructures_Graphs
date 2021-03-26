#ifndef GRAFOESTATICO_H_INCLUDED
#define GRAFOESTATICO_H_INCLUDED

#include <iostream>
#include "arista.h"
#include "vertice.h"
#include "collection.h"
#include "conio.h"
#include "windows.h"


using namespace std;

class Grafo {
    private:

        Vertice vertices[10];
        Arista aristas[10][10];

        int lastVertice;

    public:

        Grafo();

        bool isEmpty();

        int posicionVertice(const string&v);
        bool validarArista(const string&o, const string&d);

        void insertarVertice(const string&v);
        void insertarArista(const int& origen, const int& destino, const string& p, const bool& dirigida);

        void editarVertice(const int&origen, const string&v);
        void editarArista(const int&origen, const int&destino, const string&peso);

        void eliminarVertice(const int&p);
        void eliminarArista(const int&o, const int&d);
        void eliminarAristasDeVertices(const int&pos);

        string verPonderacion(const int&o, const int&d);

        void imprimirVertices();
        void imprimirAristas();
        void imprimirListaA();

        void recorridoAnchura(const string&v);
        void recorridoProfundidad(const string&v);

        void rutaAnchura(const string&origen, const string&destino);
        void rutaProfundidad(const string&origen, const string&destino);

        void desplegarRuta(Collection pilaOrigen, Collection pilaDestino, const string&origen);

        void gotoxy(int x, int y);



    };


#endif // GRAFOESTATICO_H_INCLUDED
