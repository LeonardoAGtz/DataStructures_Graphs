#include "grafo.h"
using namespace std;

Grafo::Grafo() {
    lastVertice = -1;
}

bool Grafo::isEmpty() {
    return lastVertice == -1;
}


int Grafo::posicionVertice(const string& v) {
    int i = 0;

    while(i <= lastVertice) {
        if(vertices[i].getNombre() == v) {
            return i;
        }
        i++;
    }
    return -1;
}

bool Grafo::validarArista(const string& o, const string& d) {
    int origen, destino;

    origen = posicionVertice(o);
    destino = posicionVertice(d);

    if(aristas[origen][destino].getEstado() == true) {
        return true;
    }else {
        return false;
    }

}

void Grafo::insertarVertice(const string& v) {
    Vertice myVertice;

    lastVertice++;

    myVertice.setNombre(v);
    myVertice.setEstado(true);

    vertices[lastVertice] = myVertice;
}

void Grafo::insertarArista(const int& origen, const int& destino, const string& p, const bool& dirigida) {
    Arista myArista;

    myArista.setEstado(true);
    myArista.setPoneracion(p);

    aristas[origen][destino] = myArista;

    if(!dirigida) {
        aristas[destino][origen] = myArista;
    }

}

void Grafo::editarVertice(const int& origen, const string& v) {
    vertices[origen].setNombre(v);
}

void Grafo::editarArista(const int& origen, const int& destino, const string& peso) {
    aristas[origen][destino].setPoneracion(peso);
}

void Grafo::eliminarVertice(const int& p) {
    int i(p);
    while(i <= lastVertice) {
        vertices[i] = vertices[i+1];
        i++;
    }

    eliminarAristasDeVertices(p);


}

void Grafo::eliminarAristasDeVertices(const int& pos) {
    int i = 0;
    int p(pos);
    while(p <= lastVertice) {

        int i = 0;
        while(i < p) {
            aristas[i][p] = aristas[i][p+1];
            aristas[p][i] = aristas[p+1][i];
            i++;
        }

        aristas[p][p] = aristas[p+1][p+1];

        p++;
    }

    lastVertice--;
}

void Grafo::eliminarArista(const int& o, const int& d) {

    aristas[o][d].setEstado(false);
    aristas[o][d].setPoneracion("0");
    aristas[d][o].setEstado(false);
    aristas[d][o].setPoneracion("0");
}

string Grafo::verPonderacion(const int& o, const int& d) {
    string myStr;

    myStr = aristas[o][d].getPoneracion();

    return myStr;
}

void Grafo::imprimirVertices() {
    int i = 0;
    cout << "\t>\t";
    while(i <= lastVertice) {
         cout << vertices[i].getNombre() << "\t|\t";
        i++;
    }

}

void Grafo::imprimirAristas() {
    int y = 0;
    int x = 0;
    int columna;
    int renglon;

    gotoxy(12,2);
    for (int i = 0; i <= lastVertice; ++i) {
        cout << vertices[i].getNombre() << "    |    ";
    }

    renglon = 3;
    while(x <= lastVertice) {
        y = 0;
        columna = 8;

        gotoxy(1, renglon+1);
        cout << vertices[x].getNombre()<< " =>";

        gotoxy(columna, renglon);

        renglon++;
        while(y <= lastVertice) {

            if(aristas[x][y].getEstado()) {
                gotoxy(columna, renglon);
                cout << "| " << aristas[x][y].getPoneracion() << " / S ";
            }else {
                gotoxy(columna, renglon);
                 cout << "| 0 / N ";
            }

            columna += 10;
            y++;
        }
        cout << "|";
        x++;
        renglon++;
    }
}
void Grafo::imprimirListaA() {
    int y = 0;
    int x = 0;
    int x2 = 0;
    int columna;
    int renglon;

    renglon = 3;
    while(x <= lastVertice) {
        y = 0;
        columna = 8;

        gotoxy(1, renglon+1);
        cout << vertices[x2].getNombre()<< " =>";

        gotoxy(columna, renglon);

        renglon++;
        while(y <= lastVertice) {

            if(aristas[x][y].getEstado()) {
                gotoxy(columna, renglon);
                cout << vertices[y].getNombre() << ":" << aristas[x][y].getPoneracion() << " -> ";
                columna += 10;
            }

            y++;
        }
        x++;
        x2++;
        renglon++;
    }
}

void Grafo::recorridoAnchura(const string& v) {
    string actual;
    Collection lista;
    Collection cola;
    Nodo* aux;
    int i, j;

    cola.formarCola(v);
    cout << "\t-RECORRIDO ANCHURA-" << endl;
    cout << "\t> Recorrido: ";
    while(!cola.isEmpty()) {
        actual = cola.desformarCola();

        aux = lista.searchData(actual);
        if(aux == nullptr) {
            cout << " \t => " << actual;
            lista.insertData(actual);

            i = posicionVertice(actual);
            j = 0;

            while(j <= lastVertice) {
                if(aristas[i][j].getEstado()) {
                    cola.formarCola(vertices[j].getNombre());
                }
                j++;
            }

        }
    }
}

void Grafo::recorridoProfundidad(const string& v) {
    string actual;
    Collection lista;
    Collection pila;
    Nodo* aux;
    int i, j;

    pila.apilar(v);
    cout << "\t-RECORRIDO PROFUNDIDAD-" << endl;
    cout << "\t> Recorrido: ";
    while(!pila.isEmpty()) {
        actual = pila.desApilar();

        aux = lista.searchData(actual);
        if(aux == nullptr) {
            cout << " \t => " << actual;
            lista.insertData(actual);

            i = posicionVertice(actual);
            j = 0;

            while(j <= lastVertice) {
                if(aristas[i][j].getEstado()) {
                    pila.apilar(vertices[j].getNombre());
                }
                j++;
            }

        }
    }
}

void Grafo::rutaAnchura(const string& origen, const string& destino) {
    string actual;
    Collection lista;
    Collection cola;
    Collection pilaOrigen;
    Collection pilaDestino;
    Nodo* aux;
    bool flag(true);
    int i, j;

    cola.formarCola(origen);
    cout << "\t-RUTA ANCHURA-" << endl;
    cout << "\t> Ruta: ";
    while(!cola.isEmpty()) {
        actual = cola.desformarCola();

        aux = lista.searchData(actual);
        if(aux == nullptr) {

            if(actual == destino) {
                desplegarRuta(pilaOrigen, pilaDestino, destino);
                flag = true;
                break;
            }

            lista.insertData(actual);

            i = posicionVertice(actual);
            j = 0;

            while(j <= lastVertice) {
                if(aristas[i][j].getEstado()) {

                    cola.formarCola(vertices[j].getNombre());
                    pilaOrigen.apilar(actual);
                    pilaDestino.apilar(vertices[j].getNombre());

                }
                j++;
            }

        }

    }

    if(!flag) {
        cout << endl << "\t-ERROR: No se encontro una ruta." << endl;
    }
}

void Grafo::rutaProfundidad(const string& origen, const string& destino) {
    string actual;
    Collection lista;
    Collection pila;
    Collection pilaOrigen;
    Collection pilaDestino;
    Nodo* aux;
    bool flag(true);
    int i, j;

    pila.apilar(origen);
    cout << "\t-RUTA PROFUNDIDAD-" << endl;
    cout << "\t> Ruta: ";
    while(!pila.isEmpty()) {
        actual = pila.desApilar();

        aux = lista.searchData(actual);
        if(aux == nullptr) {
            if(actual == destino) {
                desplegarRuta(pilaOrigen, pilaDestino, destino);
                flag = true;
                break;
            }

            lista.insertData(actual);

            i = posicionVertice(actual);
            j = 0;

            while(j <= lastVertice) {
                if(aristas[i][j].getEstado()) {

                    pila.apilar(vertices[j].getNombre());
                    pilaOrigen.apilar(actual);
                    pilaDestino.apilar(vertices[j].getNombre());

                }
                j++;
            }
        }

    }

    if(!flag) {
        cout << endl << "ERROR: No se encontro una ruta." << endl;
    }
}

void Grafo::desplegarRuta(Collection pilaOrigen, Collection pilaDestino, const string& destino) {
    string actual, nulo, anterior;
    Collection lista;

    actual = destino;

    while(!pilaDestino.isEmpty() and !pilaOrigen.isEmpty()) {



        if(actual != anterior){
            cout << "\t"  << actual << " <= ";
        }

        anterior = actual;


        while(!pilaDestino.isEmpty() and (pilaDestino.getTope() != actual)) {
            nulo = pilaOrigen.desApilar();
            nulo = pilaDestino.desApilar();
        }

        if(!pilaOrigen.isEmpty() and !pilaDestino.isEmpty()) {
            actual = pilaOrigen.desApilar();
            nulo = pilaDestino.desApilar();
        }
    }

    if(actual != anterior){
        cout << "\t"  << actual << " <= ";
    }

}

void Grafo::gotoxy(int x, int y) {
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwpos;
    dwpos.X = x;
    dwpos.Y = y;
    SetConsoleCursorPosition(hcon, dwpos);
}
