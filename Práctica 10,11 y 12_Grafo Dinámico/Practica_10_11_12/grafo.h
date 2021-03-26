#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include <queue>
#include <list>
#include <stack>

using namespace std;

class Arista; ///Declaro prototipo de la clase Arista

class Vertice
{
    Vertice *siguiente;
    Arista *adyacente;
    string nombre;
    friend class Grafo; ///Grafo puede usar estos atributos
};

class Arista
{
    Arista * siguiente;
    Vertice * adyacente;
    int peso;
    friend class Grafo; ///Grafo puede usar estos atributos
};

class Grafo
{
    Vertice *h;
public:
    Grafo();
    void inicializa(); //Inicialización del grafo con el primer vertice en Null                    1
    bool vacio(); //Indica si el grafo está vacio o no                                             1
    int tamanio(); //Retorna el tamaño del grafo(Numero de vertices sin acontar adyacencias)       1
    Vertice *getVertce(string &nombre); ///Retorna el nombre de un vertice a buscar si es que este existe  2
    void insertarArista(Vertice* &origen, Vertice* &destino, int &peso); //Insertamos una nueva Arista     2
    void insertarAristaContraria(Vertice* &origen, Vertice* &destino, int &peso);
    void insertaVertice(string &nombre);//Insertamos un nuevo Vertice                                      2
    void listaAdyacencia();//Me muestra una lista con todas las conexiones                                    3
    void eliminarArista(Vertice* &origen, Vertice* &destino); //Eliminamos las conexiones                     3
    void deleteAll();//destructor                                                                             3
    void eliminarVertice(Vertice *&vert);//Eliminamos un vertice y todas las conexiones relacionadas con el     4
    void recorridoAnchura(Vertice *&origen);//                                                                    5
    void recorridoProfundidad(Vertice *&origen);//                                                                   6
    void primeroAnchura(Vertice *&origen, Vertice*&destino);//                                                         7
    void primeroProfundidad(Vertice *&origen, Vertice *&destino);//                                                      8
    void primeroMejor(Vertice *&origen, Vertice *&destino);//                                                              9
//    void matrizDyacencia();
//    void modificarArista();
//    void modificarVertice(string &nombre1, string &nombre2);
};

#endif // GRAFO_H
