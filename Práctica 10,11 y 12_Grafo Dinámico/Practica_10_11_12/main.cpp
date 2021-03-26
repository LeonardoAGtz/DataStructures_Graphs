#include <iostream>
#include <windows.h>
#include <fstream>
#include "grafo.h"
#define V "vertices.txt"
#define T "temporal.txt"
#define A "arista.txt"

using namespace std;

int main()
{
    Grafo G;
    G.inicializa();
    int opc;

    do
    {
        system("cls");
        cout << "Menu Practica 10, 11 y 12 by EvoSenpai(Leonardo Aranda 217761528 INNI)" << endl;
        cout<<"1.   Ingresar Vertice"<<endl;
        cout<<"2.   Ingresar arista"<<endl;
        cout<<"3.   Lista de adyacencia"<<endl;
        cout<<"4.   Size"<<endl;
        cout<<"5.   Eliminar vertice"<<endl;
        cout<<"6.   Eliminar arista"<<endl;
        cout<<"7.   Anular"<<endl;
        cout<<"8.   Recorrido en anchura"<<endl;
        cout<<"9.   Recorrido en profundidad"<<endl;
        cout<<"10.  Primero en anchura"<<endl;
        cout<<"11.  Primero en profundidad"<<endl;
        cout<<"12.  Primero el mejor"<<endl;
        cout<<"0.   Salir"<<endl;
        cout<<endl<<"Elija una opcion: ";
        cin>>opc;
        switch(opc)
        {
        case 1:
        {
            string nombre;
            system("cls");
            cin.get();
            if (G.tamanio() <=10) {
                cout<<"Ingrese el nombre del vertice: ";
                getline(cin, nombre);
                G.insertaVertice(nombre);

                ofstream s(V, ios::app);

                s << nombre << endl;

                s.close();
            }


            break;
        }
        case 2:
        {
            string origen, destino;
            int peso;
            system("cls");
            if(G.vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
                cin.get();
                cout<<"Ingrese del nombre del vertice origen: ";
                getline(cin, origen);
                cout<<"Ingrese el nombre del vertice destino: ";
                getline(cin, destino);
                cout<<"Ingrese el peso: ";
                cin>>peso;

                if(G.getVertce(origen) == NULL || G.getVertce(destino) == NULL)
                {
                    cout<<"Uno de los vertices no es valido"<<endl;
                }
                else
                {
                    Vertice *o;
                    Vertice *d;
                    o = G.getVertce(origen);
                    d = G.getVertce(destino);
                    G.insertarArista(o, d, peso);
                    G.insertarAristaContraria(d,o,peso);

                    ofstream s(A, ios::app);

                    s << origen << endl;
                    s << destino << endl;
                    s << peso << endl;
                    s << endl;

                    s.close();
                }
            }
            break;
        }
        case 3:
        {
            system("cls");
            if(G.vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
                G.listaAdyacencia();
                system("pause");
            }
            break;
        }
        case 4:
        {
            system("cls");
            if(G.vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
                cout<<"Tamano: "<<G.tamanio()<<endl;
                system("pause");
            }
            break;
        }
        case 5:
        {
            string nombre;
            system("cls");
            if(G.vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
                cin.get();
                cout<<"Ingrese el nombre del vertice a eliminar: ";
                getline(cin, nombre);
                if(G.getVertce(nombre) == NULL)
                {
                    cout<<"Vertice invalido"<<endl;
                }
                else
                {
                    Vertice *n;
                    n = G.getVertce(nombre);
                    G.eliminarVertice(n);

                    ifstream l(V, ios::in);
                    if (l.is_open()) {
                        while (!l.eof()) {
                            string temp;

                            getline(l, temp);

                            if (temp == nombre) {
                                continue;
                            }
                            else {
                                ofstream s (T, ios::app);
                                s << temp << endl;
                                s.close();
                            }
                        }
                    }
                }
            }
            remove(V);
            rename(T,V);
            break;
        }
        case 6:
        {
            string origen, destino;
            system("cls");
            if(G.vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
                cin.get();
                cout<<"Ingrese del nombre del vertice origen: ";
                getline(cin, origen);
                cout<<"Ingrese el nombre del vertice destino: ";
                getline(cin, destino);
                if(G.getVertce(origen) == NULL || G.getVertce(destino) == NULL)
                {
                    cout<<"Vertices no validos"<<endl;
                }
                else
                {
                    Vertice *o;
                    Vertice *d;
                    o = G.getVertce(origen);
                    d = G.getVertce(destino);
                    G.eliminarArista(o, d);
                    G.eliminarArista(d,o);

                    ifstream l(A, ios::in);
                    if (l.is_open()) {
                        while(!l.eof()){
                            string temp, ori, des;
                            int p;

                            getline(l,temp);
                            ori = temp;
                            if (l.eof()) {
                                break;
                            }

                            getline(l,temp);
                            des = temp;

                            getline(l, temp);
                            p = stoi(temp);

                            getline(l,temp);

                            if (ori == origen and des == destino) {
                                continue;
                            }
                            else {
                                ofstream s(T,ios::app);
                                s << ori << endl;
                                s << des << endl;
                                s << p << endl;
                                s << endl;
                            }
                        }
                    }
                }
            }
            remove(T);
            rename(T,A);
            break;
        }
        case 7:
        {
            system("cls");
            if(G.vacio())
            {
                cin.get();
                cout<<"El grafo esta vacio"<<endl;
                system("pause");
            }
            else
            {
               G.deleteAll();
            }
            break;
        }
        case 8:
        {
            string nombre;
            system("cls");
            if(G.vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
                cin.get();
                cout<<"Ingrese el nombre del vertice inicial: ";
                getline(cin, nombre);
                if(G.getVertce(nombre) == NULL)
                {
                    cout<<"Ese vertice es invalido"<<endl;
                }
                else
                {
                    Vertice *n;
                    n = G.getVertce(nombre);
                    G.recorridoAnchura(n);
                    system("pause");
                }
            }
            break;
        }
        case 9:
        {
            string nombre;
            system("cls");
            if(G.vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
                cin.get();
                cout<<"Ingrese el nombre del vertice inicial: ";
                getline(cin, nombre);
                if(G.getVertce(nombre) == NULL)
                {
                    cout<<"Ese vertice es invalido"<<endl;
                    system("pause");
                }
                else
                {
                    Vertice *n;
                    n = G.getVertce(nombre);
                    G.recorridoProfundidad(n);
                    system("pause");
                }
            }
            break;
        }
        case 10:
        {
            string origen, destino;
            system("cls");
            if(G.vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
                cin.get();
                cout<<"Ingrese el nombre del vertice origen: ";
                getline(cin, origen);
                cout<<"Ingrese el nombre del vertice destino: ";
                getline(cin, destino);
                if(G.getVertce(origen) == NULL || G.getVertce(destino) == NULL)
                {
                    cout<<"Vertices invalidos"<<endl;
                }
                else
                {
                    Vertice *o;
                    Vertice *d;
                    o = G.getVertce(origen);
                    d = G.getVertce(destino);
                    G.primeroAnchura(o,d);
                    system("pause");
                }
            }
            break;
        }
        case 11:
        {
            string origen, destino;
            system("cls");
            if(G.vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
                cin.get();
                cout<<"Ingrese el nombre del vertice origen: ";
                getline(cin, origen);
                cout<<"Ingrese el nombre del vertice destino: ";
                getline(cin, destino);
                if(G.getVertce(origen) == NULL || G.getVertce(destino) == NULL)
                {
                    cout<<"Vertices invalidos"<<endl;
                }
                else
                {
                    Vertice *o;
                    Vertice *d;
                    o = G.getVertce(origen);
                    d = G.getVertce(destino);
                    G.primeroProfundidad(o,d);
                    system("pause");
                }
            }
            break;
        }
        case 12:
        {
            string origen, destino;
            system("cls");
            if(G.vacio())
            {
                cout<<"El grafo esta vacio"<<endl;
            }
            else
            {
                cin.get();
                cout<<"Ingrese el nombre del vertice origen: ";
                getline(cin, origen);
                cout<<"Ingrese el nombre del vertice destino: ";
                getline(cin, destino);
                if(G.getVertce(origen) == NULL || G.getVertce(destino) == NULL)
                {
                    cout<<"Vertices invalidos"<<endl;
                }
                else
                {
                    Vertice *o;
                    Vertice *d;
                    o = G.getVertce(origen);
                    d = G.getVertce(destino);
                    G.primeroMejor(o,d);
                    system("pause");
                }
            }
            break;
        }
        case 13:
        {
            ifstream lv(V, ios::in);
            if (lv.is_open()) {
                while (!lv.eof()) {
                    string temp, vert;
                    getline(lv, temp);
                    vert = temp;

                    if (lv.eof()) {
                        break;
                    }

                    G.insertaVertice(vert);

                }
            }

            ifstream la(A,ios::in);
            if (la.is_open()) {
                while (!la.eof()) {
                    string temp, a1,a2;
                    int peso;

                    getline(la,temp);
                    a1 = temp;

                    if (la.eof()) {
                        break;
                    }

                    getline(la,temp);
                    a2 = temp;

                    getline(la, temp);
                    peso = stoi(temp);

                    getline(la,temp);

                    Vertice *o;
                    Vertice *d;
                    o = G.getVertce(a1);
                    d = G.getVertce(a2);
                    G.insertarArista(o, d, peso);
                    G.insertarAristaContraria(d,o,peso);
                }
            }
        }
        case 0:
        {
            break;
        }
        default:
        {
            cout<<"Elija una opcion valida"<<endl;
        }
        }
    }
    while(opc != 13);
    return 0;
}

/*
#include <iostream>
#include <windows.h>
#include "grafo.h"

Grafo graph;
void grafoType01();
void grafoType02();
void grafoType03();
void grafoType04();

using namespace std;

int main()
{
    string ponderado;
    string dirigido;
    cout << "El grafo va a ser ponderado? (S/N): ";
    getline(cin, ponderado);
    cout << "El grafo es dirigido?(S/N): ";
    getline(cin, dirigido);

    system("cls");
    if (dirigido == "S" and ponderado == "S") {
        grafoType01();
    }
    else if (dirigido == "S" and ponderado == "N") {
        grafoType02();
    }
    else if (dirigido == "N" and ponderado == "S") {
        grafoType03();
    }
    else if (dirigido == "N" and ponderado == "N") {
        grafoType04();
    }

    return 0;
}

void grafoType01(){
    string op;
    while (true) {
        system("cls");
        cout << "\t 1.- Ingresar Vertice" << endl;
        cout << "\t 2.- Ingresar Arista" << endl;
        cout << "\t 3.- Mostrar Grafo Lista" << endl;
        cout << "\t 4.- Tamanio" << endl;
        cout << "\t 5.- Modificar Vertice" << endl;
        cout << "\t 6.- Eliminar Vertice" << endl;
        cout << "\t 7.- Eliminar Arista" << endl;
        cout << "\t 8.- Recorrido Anchura" << endl;
        cout << "\t 9.- Recorrido Profundidad" << endl;
        cout << "\t 0.- Salir" << endl;
        getline(cin, op);

        if (op == "1") {
            string nombre;
            if (graph.tamanio() >= 10) {
                cout << "No hay espacio para mas Vertices";
            }
            else {
                cout << "Ingresa un ID para tu vertice: ";
                getline(cin, nombre);

                graph.insertaVertice(nombre);
            }
        }
        else if (op == "2") {
            string nombre1, nombre2;
            string temp;
            int peso;

            if (graph.vacio()) {
                cout << "Grafo vacio";
                system("pause");
                break;
            }

            cout << "Ingresa el Vertice Origen de la Arista: ";
            getline(cin, nombre1);
            cout << "Ingresa el Vertice Destino de la Arista: ";
            getline(cin, nombre2);
            cout << "Ingresa el Peso del Vertice: ";
            getline(cin, temp);
            peso = stoi(temp);

            if (graph.getVertce(nombre1) == NULL or graph.getVertce(nombre2) == NULL) {
                cout << "Vertices invalidos" << endl;
                system("pause");
            }
            else {
                graph.insertarArista(graph.getVertce(nombre1), graph.getVertce(nombre2), peso);
            }

        }
        else if (op == "3") {
            if (graph.vacio()) {
                cout << "Grafo vacio" << endl;
            }
            else {
                graph.listaAdyacencia();
                system("pause");
            }
        }
        else if (op == "4") {
            if (graph.vacio()) {
                cout << "Grafo vacio";
                system("pause");
            }
            else {
                cout << "Tamanio: " << graph.tamanio() << endl;
                system("pause");
            }
        }
        else if (op == "5") {
            string nombre1, nombre2;
            if (graph.vacio()) {
                cout << "Grafo vacio";
                system("pause");
            }
            else {
                cout << "Nombre del Vertice a modificar: ";
                getline(cin, nombre1);
                cout << "Nuevo ID para el vertice: ";
                getline(cin, nombre2);

                if (graph.getVertce(nombre) == NULL) {
                    cout << "Vertice Invalido" << endl;
                    system("pause");
                }
                else {
                    graph.modificarVertice(nombre1, nombre2);
                }
            }
        }
        else if (op == "6") {
            string nombre;
            if (graph.vacio()) {
                cout << "Grafo vacio";
                system("pause");
            }
            else {
                cout << "Nombre del Vertice a eliminar: ";
                getline(cin, nombre);

                if (graph.getVertce(nombre) == NULL) {
                    cout << "Vertice Invalido" << endl;
                    system("pause");
                }
                else {
                    graph.eliminarVertice(graph.getVertce(nombre));
                }
            }
        }
        else if (op == "7") {
            string origen, destino;
            if (graph.vacio()) {
                cout << "Grafo vacio";
                system("pause");
            }
            else {
                cout << "Nombre del Vertice origen: ";
                getline(cin, origen);
                cout << "Nombre del Vertice destino: ";
                getline(cin, destino);
                if (graph.getVertce(origen) == NULL or graph.getVertce(destino) == NULL) {
                    cout << "Vertices Invalido" << endl;
                    system("pause");
                }
                else {
                    graph.eliminarArista(graph.getVertce(origen), graph.getVertce(destino));
                }
            }
        }
        else if (op == "8") {
            string nombre;
            if (graph.vacio()) {
                cout << "Grafo vacio";
                system("pause");
            }
            else {
                cout << "Ingresa el nombre del Vertice origen: ";
                getline(cin, nombre);
                if (graph.getVertce(nombre) == NULL) {
                    cout << "Vertice Inexistente";
                    system("pause");
                }
                else {
                    graph.recorridoAnchura(graph.getVertce(nombre));
                }
            }

        }
        else if (op == "9") {
            string nombre;
            if (graph.vacio()) {
                cout << "Grafo vacio";
                system("pause");
            }
            else {
                cout << "Ingresa el nombre del Vertice origen: ";
                getline(cin, nombre);
                if (graph.getVertce(nombre) == NULL) {
                    cout << "Vertice Inexistente";
                    system("pause");
                }
                else {
                    graph.recorridoProfundidad(graph.getVertce(nombre));
                }
            }
        }
        else if (op == "0") {
         break;
        }
    }
}

void grafoType02(){
    string op;
    while (true) {
        system("cls");
        cout << "\t 1.- Ingresar Vertice" << endl;
        cout << "\t 2.- Ingresar Arista" << endl;
        cout << "\t 3.- Mostrar Grafo Lista" << endl;
        cout << "\t 4.- Mostrar Grafo Matriz" << endl;
        cout << "\t 5.- Tamanio" << endl;
        cout << "\t 6.- Modificar Arista" << endl;
        cout << "\t 7.- Eliminar Vertice" << endl;
        cout << "\t 8.- Eliminar Arista" << endl;
        cout << "\t 9.- Recorrido Anchura" << endl;
        cout << "\t 10.- Recorrido Profundidad" << endl;
        cout << "\t 0.- Salir" << endl;
        getline(cin, op);

        if (op == "1") {

        }
        else if (op == "2") {

        }
        else if (op == "3") {

        }
        else if (op == "4") {

        }
        else if (op == "5") {

        }
        else if (op == "6") {

        }
        else if (op == "7") {

        }
        else if (op == "8") {

        }
        else if (op == "9") {

        }
        else if (op == "10") {
            system("cls");

            system("pause");
        }
        else if (op == "0") {
         break;
        }
    }
}

void grafoType03(){
    string op;
    while (true) {
        system("cls");
        cout << "\t 1.- Ingresar Vertice" << endl;
        cout << "\t 2.- Ingresar Arista" << endl;
        cout << "\t 3.- Mostrar Grafo Lista" << endl;
        cout << "\t 4.- Mostrar Grafo Matriz" << endl;
        cout << "\t 5.- Tamanio" << endl;
        cout << "\t 6.- Modificar Arista" << endl;
        cout << "\t 7.- Eliminar Vertice" << endl;
        cout << "\t 8.- Eliminar Arista" << endl;
        cout << "\t 9.- Recorrido Anchura" << endl;
        cout << "\t 10.- Recorrido Profundidad" << endl;
        cout << "\t 0.- Salir" << endl;
        getline(cin, op);

        if (op == "1") {

        }
        else if (op == "2") {

        }
        else if (op == "3") {

        }
        else if (op == "4") {

        }
        else if (op == "5") {

        }
        else if (op == "6") {

        }
        else if (op == "7") {

        }
        else if (op == "8") {

        }
        else if (op == "9") {

        }
        else if (op == "10") {
            system("cls");

            system("pause");
        }
        else if (op == "0") {
         break;
        }
    }
}

void grafoType04(){
    string op;
    while (true) {
        system("cls");
        cout << "\t 1.- Ingresar Vertice" << endl;
        cout << "\t 2.- Ingresar Arista" << endl;
        cout << "\t 3.- Mostrar Grafo Lista" << endl;
        cout << "\t 4.- Mostrar Grafo Matriz" << endl;
        cout << "\t 5.- Tamanio" << endl;
        cout << "\t 6.- Modificar Arista" << endl;
        cout << "\t 7.- Eliminar Vertice" << endl;
        cout << "\t 8.- Eliminar Arista" << endl;
        cout << "\t 9.- Recorrido Anchura" << endl;
        cout << "\t 10.- Recorrido Profundidad" << endl;
        cout << "\t 0.- Salir" << endl;
        getline(cin, op);

        if (op == "1") {

        }
        else if (op == "2") {

        }
        else if (op == "3") {

        }
        else if (op == "4") {

        }
        else if (op == "5") {

        }
        else if (op == "6") {

        }
        else if (op == "7") {

        }
        else if (op == "8") {

        }
        else if (op == "9") {

        }
        else if (op == "10") {
            system("cls");

            system("pause");
        }
        else if (op == "0") {
         break;
        }
    }
}

*/
