#include "vertice.h"
using namespace std;

Vertice::Vertice() {
    estado = false;
    }

string Vertice::getNombre() {
    string myStr;
    myStr = nombre;
    return myStr;
    }

bool Vertice::getEstado() {
    return estado;
    }

void Vertice::setNombre(const string& s) {
    strcpy(nombre, s.c_str());
    }

void Vertice::setEstado(const bool& b) {
    estado = b;
    }
