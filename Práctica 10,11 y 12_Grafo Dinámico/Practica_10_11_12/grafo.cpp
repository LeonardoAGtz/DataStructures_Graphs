#include "grafo.h"

Grafo::Grafo()
{

}

void Grafo::inicializa()
{
    h = NULL; //Primer nodo Nulo
}

bool Grafo::vacio()
{
    if (h == NULL) {
        return true;
    }
    return false; ///Retornamos si el primer nodo ha sido creado o no, lo que significa si está vacio o no
}

int Grafo::tamanio()
{
    int cont(0);
    Vertice *aux;
    aux = h;

    while (aux != NULL) {
        cont++;
        aux = aux->siguiente;
    }
    return cont;
}

Vertice *Grafo::getVertce(string &nombre)
{
    Vertice *aux;
    aux = h;
    while (aux != NULL) {//Mientras que mi auxiliar sea diferente de Null
        if (aux->nombre == nombre) { //Validamos si el nombre coincide
            return aux;//Si coincide lo retornamos
        }
        aux = aux->siguiente;//Chicharronera de iteración
    }
    return NULL;
}

void Grafo::insertarArista(Vertice *&origen, Vertice *&destino, int &peso)
{
    Arista  *nueva = new Arista;
    nueva->peso = peso;
    nueva->siguiente = NULL;
    nueva->adyacente = NULL;

    Arista *aux;

    aux = origen->adyacente;
    if (aux == NULL) {
        origen->adyacente = nueva;
        nueva->adyacente = destino;
    }
    else {
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = nueva;
        nueva->adyacente = destino;
    }
}

void Grafo::insertarAristaContraria(Vertice *&origen, Vertice *&destino, int &peso)
{
    Arista  *nueva = new Arista;
    nueva->peso = peso;
    nueva->siguiente = NULL;
    nueva->adyacente = NULL;

    Arista *aux;

    aux = origen->adyacente;
    if (aux == NULL) {
        origen->adyacente = nueva;
        nueva->adyacente = destino;
    }
    else {
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = nueva;
        nueva->adyacente = destino;
    }
}

void Grafo::insertaVertice(string &nombre)
{
    Vertice *nuevo = new Vertice;
    nuevo->nombre = nombre;
    nuevo->siguiente = NULL;
    nuevo->adyacente = NULL;

    if (vacio()) {
        h = nuevo;
    }
    else {
        Vertice *aux;
        aux = h;

        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
}

void Grafo::listaAdyacencia()
{
    Vertice *vertAux;
    Arista *aristAux;

    vertAux = h;
    while (vertAux != NULL) {
        cout << vertAux->nombre << " -> "; //Imprimimos el vertice
        aristAux = vertAux->adyacente;
        while (aristAux != NULL) {
            cout << aristAux->adyacente->nombre << ":" << aristAux->peso << " -> ";//Imprimimos arista
            aristAux = aristAux->siguiente;
        }
        vertAux = vertAux->siguiente;
        cout << endl;
    }
}

void Grafo::eliminarArista(Vertice *&origen, Vertice *&destino)
{
    Arista *actual;
    Arista *anterior;
    int band = 0;

    actual = origen->adyacente;

    if (actual == NULL) {
        cout << "El vertice origen no tiene Aristas" << endl;
    }
    else if (actual->adyacente == destino) {
        origen->adyacente = actual->siguiente;
        delete(actual);
    }
    else {
        while (actual != NULL) {
            if (actual->adyacente == destino) {
                band = 1;
                anterior->siguiente = actual->siguiente;
                delete(actual);
                break;
            }
            anterior = actual;
            actual = actual->siguiente;
        }
        if (band == 0) {
            cout << "Esos dos vertices no estan conectados" << endl;
        }
    }
}

void Grafo::deleteAll()
{
    Vertice *aux;

    while (h != NULL) {
        aux = h;
        h = h->siguiente;
        delete(aux);
    }
}

void Grafo::eliminarVertice(Vertice *&vert)
{
    Vertice *actual, *anterior;
    Arista *aux;

    actual = h;
    while (actual != NULL) {
        aux = actual->adyacente;
        while (aux !=NULL) {
            if (aux->adyacente == vert) {
                eliminarArista(actual, aux->adyacente); //Se eliminan primero las conexiones
                eliminarArista(aux->adyacente, actual);
                break;
            }
            aux = aux->siguiente;
        }
        actual = actual->siguiente;
    }

    actual = h;
    if (h == vert) {
        h = h->siguiente;
        delete(actual);
    }
    else {
        while (actual != vert) {
            anterior = actual;
            actual = actual->siguiente;
        }
        anterior->siguiente = actual->siguiente;
        delete(actual);
    }
}

void Grafo::recorridoAnchura(Vertice *&origen)
{
    Vertice *actual;
    queue<Vertice*> cola;
    list<Vertice*> lista;
    list<Vertice*>::iterator i;
    int band, band2;

    cola.push(origen);

    while (!cola.empty()) {

        band = 0;
        actual = cola.front();
        cola.pop();

        for (i = lista.begin(); i != lista.end(); i++) {

            if (*i == actual) {
                band = 1;
            }
        }
        if (band == 0) {
            cout << actual->nombre << ", ";
            lista.push_back(actual);

            Arista *aux;
            aux = actual->adyacente;
            while (aux != NULL) {

                band2 = 0;
                for (i = lista.begin(); i != lista.end(); i++) {

                    if (aux->adyacente == *i) {
                        band2 = 1;
                    }
                }
                if (band2 == 0 ) {
                    cola.push(aux->adyacente);
                }
                aux = aux->siguiente;
            }
        }
    }
}

void Grafo::recorridoProfundidad(Vertice *&origen)
{
    Vertice *actual;
    stack<Vertice*> pila;
    list<Vertice*> lista;
    list<Vertice*>::iterator i;
    int band, band2;

    pila.push(origen);

    while (!pila.empty()) {
        band = 0;
        actual = pila.top();
        pila.pop();

        for (i = lista.begin(); i != lista.end(); i++){
            if (*i == actual) {
                band = 1;
            }
        }
        if (band == 0) {
            cout << actual->nombre << ", ";
            lista.push_back(actual);

            Arista *aux;
            aux = actual->adyacente;

            while (aux != NULL) {
                band2 = 0;
                for (i = lista.begin(); i !=lista.end();i++) {
                    if (*i == aux->adyacente) {
                        band2 = 1;
                    }
                }
                if (band2 == 0) {
                    pila.push(aux->adyacente);
                }

                aux = aux->siguiente;
            }
        }
    }
}

void Grafo::primeroAnchura(Vertice *&origen, Vertice *&destino)
{
    Vertice *verticeActual;
    Vertice *destinoActual;
    Arista *aux;
    typedef pair<Vertice*, Vertice*> VerticeVertice;
    queue<Vertice*> cola;
    stack<VerticeVertice> pila;
    list<Vertice*> lista;
    list<Vertice*>::iterator i;
    int band, band2, band3 = 0;

    cola.push(origen);

    while (!cola.empty()) {
        band = 0;
        verticeActual = cola.front();
        cola.pop();

        for (i = lista.begin(); i != lista.end(); i++){
            if (verticeActual == *i) {
                band = 1;
            }
        }
        if (band == 0) {
            if (verticeActual == destino) {
                band3 = 1;
                destinoActual = destino;

                while (!pila.empty()) {
                    cout << destinoActual->nombre << "<-";

                    while (!pila.empty() and pila.top().second != destinoActual) {
                        pila.pop();
                    }

                    if (!pila.empty()) {
                        destinoActual = pila.top().first;
                    }
                }
                break;
            }
            lista.push_back(verticeActual);
            aux = verticeActual->adyacente;
            while (aux != NULL) {
                band2 = 0;
                for (i = lista.begin(); i != lista.end(); i++){
                    if (aux->adyacente == *i) {
                        band2 = 1;
                    }
                }
                if (band2 == 0) {
                    cola.push(aux->adyacente);
                    pila.push(VerticeVertice(verticeActual, aux->adyacente));
                }
                aux = aux->siguiente;
            }
        }
    }
    if (band3 == 0) {
        cout << "No hay una ruta entre esos dos vertices" << endl;
    }
}

void Grafo::primeroProfundidad(Vertice *&origen, Vertice *&destino)
{
    Vertice *verticeActual;
    Vertice *destinoActual;
    Arista *aux;
    typedef pair<Vertice*, Vertice*> parVertices;
    stack<Vertice*> pila;
    list<Vertice*> lista;
    stack<parVertices> pilaPar;
    list<Vertice*>::iterator i;
    int band, band2, band3=0;

    pila.push(origen);

    while (!pila.empty()) {
        band = 0;
        verticeActual = pila.top();
        pila.pop();

        for (i = lista.begin(); i != lista.end(); i++){
            if (verticeActual == *i) {
                band = 1;
            }
        }
        if (band == 0) {
            if (verticeActual == destino) {
                band3 = 1;
                destinoActual = destino;

                while (!pilaPar.empty()) {
                    cout << destinoActual->nombre << "<-";

                    while (!pilaPar.empty() and  pilaPar.top().second != destinoActual) {
                        pilaPar.pop();
                    }
                    if (!pilaPar.empty()) {
                        destinoActual = pilaPar.top().first;
                    }
                }
                break;
            }
            lista.push_back(verticeActual);

            aux = verticeActual->adyacente;
            while (aux != NULL) {
                band2 = 0;
                for (i = lista.begin(); i != lista.end(); i++) {
                    if (aux->adyacente == *i) {
                        band2 = 1;
                    }
                }
                if (band2 == 0) {
                    pila.push(aux->adyacente);
                    pilaPar.push(parVertices(verticeActual, aux->adyacente));
                }
                aux = aux->siguiente;
            }
        }
    }
    if (band3 == 0) {
        cout << "No hay una ruta entre esos dos vertices" << endl;
    }
}

bool comparacion(pair<Vertice*, int> a, pair<Vertice*, int> b){
    return a.second < b.second;
}

void Grafo::primeroMejor(Vertice *&origen, Vertice *&destino)
{
    int costoActual(0);
    Vertice *verticeActual, *destinoActual;
    Arista *aux;
    typedef pair<Vertice*, int> verticeCosto;
    typedef pair<Vertice*, Vertice*> vertceVertice;
    list<verticeCosto> listaCostos;
    list<verticeCosto> listaOrdenada;
    stack<vertceVertice> pila;
    list<verticeCosto>::iterator i,j;
    int band, band2(0);

    listaCostos.push_back(verticeCosto(origen, 0));
    listaOrdenada.push_back(verticeCosto(origen, 0));

    while (!listaOrdenada.empty()) {
        verticeActual = listaOrdenada.front().first;
        costoActual = listaOrdenada.front().second;
        listaOrdenada.pop_front();

        if (verticeActual == destino) {
            cout << "Costo: " << costoActual << endl;
            band2 = 1;
            destinoActual = destino;

            while (!pila.empty()) {
                cout << destinoActual->nombre << "<-";

                while (!pila.empty() and pila.top().second != destinoActual) {
                    pila.pop();
                }
                if (!pila.empty()) {
                    destinoActual = pila.top().first;
                }
            }
            break;
        }
        aux = verticeActual->adyacente;
        while (aux != NULL) {
            band = 0;
            costoActual = costoActual + aux->peso;

            for(i = listaCostos.begin(); i != listaCostos.end(); i++){
                if (aux->adyacente == i->first) {

                    band = 1;
                    if (costoActual < i->second) {
                        (*i).second = costoActual;
                        for(j = listaOrdenada.begin(); j != listaOrdenada.end(); j++){
                            if (j->first == aux->adyacente) {
                                (*j).second = costoActual;
                            }
                        }
                        listaOrdenada.sort(comparacion);
                        pila.push(vertceVertice(verticeActual, aux->adyacente));
                        costoActual = costoActual - aux->peso;
                    }

                }
            }
            if (band == 0) {
                listaCostos.push_back(verticeCosto(aux->adyacente, costoActual));
                listaOrdenada.push_back(verticeCosto(aux->adyacente, costoActual));
                listaOrdenada.sort(comparacion);

                pila.push(vertceVertice(verticeActual, aux->adyacente));
                costoActual = costoActual - aux->peso;
            }

            aux = aux->siguiente;
        }

    }
    if (band2 == 0) {
        cout << "No hay rut entre esos dos vertices" << endl;
    }

}

//void Grafo::modificarArista()
//{

//}

//void Grafo::modificarVertice(string &nombre1, string &nombre2)
//{
//    Vertice *aux;
//    aux = h;

//    while (aux != NULL) {
//        if (aux->nombre ==nombre1) {
//            aux->nombre = nombre2;
//        }
//        aux = aux->siguiente;
//    }
//}

//void Grafo::matrizDyacencia()
//{
//    Vertice *vertAux;
//    Arista *aristAux;
//    int identificadorVert(0);
//    vertAux = h;

//    cout << "Indice de vertices" << endl;
//    while (vertAux != NULL) {
//        cout << identificadorVert << ":" << vertAux->nombre << endl;
//        identificadorVert++;
//        vertAux = vertAux->siguiente;
//    }

//    vertAux = h;
//    cout << "  ";
//    for (int i = 0; i <= 10; ++i) {
//        cout << i << "  ";
//    }
//    cout << endl;

//    for (int i = 0; i <=10; ++i) {
//        cout << i << ": ";
//        for (int j = 0; j <=10; ++j) {

//        }
//    }
//}
