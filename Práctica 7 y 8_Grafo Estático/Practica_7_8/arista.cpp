#include "arista.h"
using namespace std;
Arista::Arista() {
    estado = 'F';
    poneracion[0] = '0';
    }

string Arista::getPoneracion() {
    string myStr;
    myStr = poneracion;
    return myStr;
    }

bool Arista::getEstado() {
    bool myBool;
    if(estado == 'F'){
        return false;
    }
    return true;
    }

void Arista::setPoneracion(const string& s) {
    strcpy(poneracion, s.c_str());
    }

void Arista::setEstado(const bool& b) {
    if(b){
        estado = 'V';
    }else{
    estado = 'F';
    }
    }
