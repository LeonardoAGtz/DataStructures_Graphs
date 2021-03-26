#include "menu.h"
using namespace std;
#define CL system("cls");
Menu::Menu() {}

void Menu::mostrarMenu() {

    system("cls");

    cout << "Menu Practica 7 y 8 by EvoSenpai(Leonardo Aranda 217761528 INNI)" << endl;
    cout << "1) AGREGAR." << endl;
    cout << "2) EDITAR." << endl;
    cout << "3) ELIMINAR." << endl;
    cout << "4) VER." << endl;
    cout << "5) RECORRIDOS." << endl;
    cout << "6) RUTAS." << endl;
    cout << "7) GUARDAR/CARGAR." << endl;
    cout << "8) SALIR." << endl;
    cout << " >> Opcion: ";
    string op; getline(cin, op);
    if (op == "1") {
        CL;
        cout << "1) Agregar Vertice." << endl;
        cout << "2) Agregar Arista. " << endl;
        cout << " >> Opcion: ";
        getline(cin, op);
        if (op == "1") {
            crearVertice();
        }else if (op == "2") {
            crearArista();
        }else{
            mostrarMenu();
        }

    }else if (op == "2") {
        CL;
        cout << "1) Editar Vertice." << endl;
        cout << "2) Editar Arista." << endl;
        cout << " >> Opcion: ";
        getline(cin, op);
        if (op == "1") {
            editarVertice();
        }else if (op == "2") {
            editarArista();
        }else{
            mostrarMenu();
        }

    }else if (op == "3") {
        CL;
        cout << "1) Eliminar Vertice." << endl;
        cout << "2) Eliminar Arista." << endl;
        cout << " >> Opcion: ";
        getline(cin, op);
        if (op == "1") {
            eliminarVertice();
        }else if (op == "2") {
            eliminarArista();
        }else{
            mostrarMenu();
        }
    }else if (op == "4") {
        CL;
        cout << "1) Mostrar Vertices. " << endl;
        cout << "2) Mostrar Aristas. " << endl;
        cout << "3) Lista Adyacencia. " << endl;
        cout << " >> Opcion: ";
        getline(cin, op);
        if (op == "1") {
            imprimirVertices();
        }else if (op == "2") {
            imprimirAristas();
        }else if(op == "3"){
            imprimirListaA();
        }else{
            mostrarMenu();
        }
    }else if (op == "5") {
        CL;
        cout << "1) Recorrido en Anchura." << endl;
        cout << "2) Recorrido en Profundidad." << endl;
        cout << " >> Opcion: ";
        getline(cin, op);
        if (op == "1") {
            recorridoAnchura();
        }else if (op == "2") {
            recorridoProfundidad();
        }else{
            mostrarMenu();
        }
    }else if (op == "6") {
        CL;
        cout << "1) Ruta en Anchura." << endl;
        cout << "2) Ruta en Profundidad." << endl;
        cout << " >> Opcion: ";
        getline(cin, op);
        if (op == "1") {
            rutaAnchura();
        }else if (op == "2") {
            rutaProfundidad();
        }else{
            mostrarMenu();
        }
    }else if (op == "7") {
        CL;
        cout << "1) Guardar Grafo." << endl;
        cout << "2) Cargar Grafo." << endl;
        cout << " >> Opcion: ";
        getline(cin, op);
        if (op == "1") {
            guardarGrafo();
        }else if (op == "2") {
            cargarGrafo();
        }else{
            mostrarMenu();
        }
    }else if (op == "8") {
        return;
    }else{
        mostrarMenu();
    }
}

void Menu::crearVertice() {
    string myVer;
    string myStr;

    system("cls");

    cout << "Ingresa el nombre del vertice: ";
    cin >> myVer;
    cin.ignore(256,'\n');
    cout << endl;

    if(myGrafo.posicionVertice(myVer) == -1) {
        myGrafo.insertarVertice(myVer);
        cout << "-MENSAJE: Vertice creado correctamente." << endl;
    }
    else {
        cout << "-ERROR: Ya existe ese nombre" << endl;
    }
    system("PAUSE");
    mostrarMenu();

}

void Menu::crearArista() {
    string origen, destino, peso, myStr;
    bool dirigida(false);
    int posOrigen, posDestino;
    bool flag(true);
    char op;

    system("cls");
    imprimirVertices2();
    if(myGrafo.isEmpty()) {
        cout << "-ERROR: No existen vertices." << endl;
        system("PAUSE");
        return;
    }

    do {
        cout << "Ingresa el origen: ";
        cin >> origen;
        cin.ignore(256,'\n');
        cout << endl;
        flag = false;
        if(myGrafo.posicionVertice(origen) == -1) {
            flag = true;
            cout << "\t-ERROR: Ese origen no existe." << endl;
            system("PAUSE");
        }
    }while(flag);

    flag = true;

    do {
        cout << "Ingresa el destino: ";
        cin >> destino;
        cin.ignore(256,'\n');
        cout << endl;
        flag = false;
        if(myGrafo.posicionVertice(destino) == -1) {
            flag = true;
            cout << "ERROR: Ese destino no existe." << endl;
            system("PAUSE");
        }
    }while(flag);

    if(myGrafo.validarArista(origen, destino)) {
        cout << "ERROR: Esa arista ya existe." << endl;
        system("PAUSE");
        mostrarMenu();
    }

    cout << "Es dirigida? S|N: ";
    cin >> op;
    cin.ignore(256,'\n');
    cout << endl;
    op = tolower(op);

    if(op == 's') {
        dirigida = true;
    }

    cout << "Es ponderada? S|N: ";
    cin >> op;
    cin.ignore(256,'\n');
    cout << endl;
    op = tolower(op);

    if(op == 's') {
        cout << "Ingresa el peso: ";
        cin >> peso;
        cin.ignore(256,'\n');
        cout << endl;
    }
    else {
        peso = '0';
    }

    posOrigen = myGrafo.posicionVertice(origen);
    posDestino = myGrafo.posicionVertice(destino);

    myGrafo.insertarArista(posOrigen, posDestino, peso, dirigida);
    cout << "MENSAJE: Arista creada." << endl;

    system("PAUSE");
    mostrarMenu();
}

void Menu::imprimirVertices() {

    system("cls");
    cout << "IMPRIMIR VERTICES-" << endl << endl;

    myGrafo.imprimirVertices();
    cout << endl;

    system("PAUSE");
    mostrarMenu();
}

void Menu::imprimirVertices2() {

    system("cls");
    cout << "IMPRIMIR VERTICES-" << endl << endl;

    myGrafo.imprimirVertices();
    cout << endl;
}

void Menu::imprimirAristas() {

    system("cls");
    cout << "\t-MATRIZ DE ARISTAS-" << endl << endl;

    myGrafo.imprimirAristas();
    cout << endl;
    system("PAUSE");
    mostrarMenu();
}
void Menu::imprimirAristas2() {

    system("cls");
    cout << "MATRIZ DE ARISTAS-" << endl << endl;

    myGrafo.imprimirAristas();
    cout << endl;
}

void Menu::imprimirListaA(){
    system("cls");
    cout << "LISTA ADYACENCIA-" << endl << endl;
    myGrafo.imprimirListaA();
    cout << endl;
    system("PAUSE");
    mostrarMenu();
}

void Menu::guardarGrafo() {
    cout << "GUARDAR GRAFO-" << endl << endl;
    cout << "Ingresa el nombre del grafo a guardar (ejemplo): ";
    string nombreG; getline(cin, nombreG);

    ofstream myFile(nombreG + ".txt", ios::app);

    myFile.write((char*)&myGrafo, sizeof(myGrafo));
    myFile.close();

    cout << "MENSAJE: Grafo guardado" << endl;

    system("PAUSE");
    mostrarMenu();
}

void Menu::cargarGrafo() {
    cout << "CARGAR GRAFO-" << endl << endl;
    cout << "Ingresa el nombre del grafo a cargar (ejemplo): ";
    string nombreC; getline(cin, nombreC);

    ifstream myFile(nombreC + ".txt");
    if (myFile.is_open()) {
        myFile.read((char*)&myGrafo, sizeof(myGrafo));
        myFile.close();
    }else{
        cout << "ERROR: Ese archivo no existe." << endl;
        system("PAUSE");
        cargarGrafo();
    }

    cout << "MENSAJE: Grafo cargado." << endl;

    system("PAUSE");
    mostrarMenu();
}

void Menu::editarVertice() {
    string myVer;
    string myStr;
    int origen;

    system("cls");
    cout << "DITAR VERTICES-" << endl << endl;
    imprimirVertices2();
    cout << "Ingresa el nombre del vertice a editar: ";
    cin >> myVer;
    cin.ignore(256,'\n');
    cout << endl;

    origen = myGrafo.posicionVertice(myVer);

    if(origen != -1) {
        cout << "Ingresa el nuevo nombre: ";
        cin >> myVer;
        cin.ignore(256,'\n');
        cout << endl;
        myGrafo.editarVertice(origen, myVer);
        cout << "MENSAJE: Vertice editado." << endl;
    }
    else {
        cout << "ERROR: No existe el vertice" << endl;
        system("PAUSE");
        editarVertice();
    }
    cout << endl;
    system("PAUSE");
    mostrarMenu();
}

void Menu::editarArista() {
    string origen, destino, peso, myStr;
    bool dirigida(false);
    bool flag(true);
    int posOrigen, posDestino;
    char op;

    system("cls");
    cout << "EDITAR ARISTA-" << endl << endl;

    if(myGrafo.isEmpty()) {
        cout << "ERROR: No existen vertices." << endl;
        system("PAUSE");
        mostrarMenu();
    }

    do {
        cout << "Ingresa el origen: ";
        cin >> origen;
        cin.ignore(256,'\n');
        cout << endl;
        flag = false;
        if(myGrafo.posicionVertice(origen) == -1) {
            flag = true;
            cout << "ERROR: Ese origen no existe." << endl;
            system("PAUSE");
        }
    }while(flag);

    flag = true;

    do {
        cout << "Ingresa el destino: ";
        cin >> destino;
        cin.ignore(256,'\n');
        cout << endl;
        flag = false;
        if(myGrafo.posicionVertice(destino) == -1) {
            flag = true;
            cout << "ERROR: Ese destino no existe." << endl;
            system("PAUSE");
        }
    }while(flag);

    if(!myGrafo.validarArista(origen, destino)) {
        cout << "Error: Esa arista no existe." << endl;
        system("PAUSE");
        return;
    }


    cout << "Ingresa el nuevo peso: ";
    cin >> peso;
    cin.ignore(256,'\n');
    cout << endl;

    posOrigen = myGrafo.posicionVertice(origen);
    posDestino = myGrafo.posicionVertice(destino);
    myGrafo.editarArista(posOrigen, posDestino, peso);

    if(myGrafo.validarArista(destino, origen)) {
        myGrafo.editarArista(posDestino, posOrigen, peso);
    }

    cout << "MENSAJE: Arista editada." << endl;
    system("PAUSE");
    mostrarMenu();

}

void Menu::eliminarVertice() {
    string myVer;
    int origen;
    char op;

    system("cls");
    cout << "ELIMINAR VERTICE-" << endl << endl;
    imprimirVertices2();
    cout << "Ingresa el nombre del vertice a eliminar: ";
    cin >> myVer;
    cin.ignore(256,'\n');
    cout << endl;

    origen = myGrafo.posicionVertice(myVer);

    if(origen != -1) {
        cout << "Estas seguro de eliminar el vertice y las aristas? S|N: ";
        cin >> op;
        cin.ignore(256,'\n');
        cout << endl;
        op = tolower(op);

        if(op == 's') {
            myGrafo.eliminarVertice(origen);
            cout << endl << "MENSAJE: Vertice eliminado." << endl;
        }
    }
    else {
        cout << "ERROR: Ese vertice no existe" << endl;
        system("PAUSE");
        eliminarVertice();
    }
    cout << endl;
    system("PAUSE");
    mostrarMenu();
}

void Menu::eliminarArista() {
    string origen, destino, poneracion, myStr;
    bool dirigida(false);
    bool flag(true);
    int o, d;
    char op;

    system("cls");
    cout << "ELIMINAR ARISTA-" << endl << endl;
    imprimirAristas2();
    if(myGrafo.isEmpty()) {
        cout << "ERROR: No existen vertices." << endl;
        system("PAUSE");
        return;
    }

    do {
        cout << "Ingresa el origen de la arista: ";
        cin >> origen;
        cin.ignore(256,'\n');
        cout << endl;
        flag = false;
        if(myGrafo.posicionVertice(origen) == -1) {
            flag = true;
            cout << "ERROR: Ese origen no existe." << endl;
            system("PAUSE");
        }
    }
    while(flag);

    flag = true;

    do {
        cout << "Ingresa el destino de la arista: ";
        cin >> destino;
        cin.ignore(256,'\n');
        cout << endl;
        flag = false;
        if(myGrafo.posicionVertice(destino) == -1) {
            flag = true;
            cout << "\-ERROR: Ese destino no existe." << endl;
            system("PAUSE");
        }
    }
    while(flag);

    if(!myGrafo.validarArista(origen, destino)) {
        cout << "ERROR: Esa arista no existe." << endl;
        system("PAUSE");
        mostrarMenu();
    }

    cout << "Estas seguro de eliminar la arista? S|N: ";
    cin >> op;
    cin.ignore(256,'\n');
    cout << endl;
    op = tolower(op);

    if(op == 's') {
        o = myGrafo.posicionVertice(origen);
        d = myGrafo.posicionVertice(destino);
        myGrafo.eliminarArista(o, d);
        cout << endl << "MENSAJE: Arista eliminada." << endl;
    }
    cout << endl;
    system("PAUSE");
    mostrarMenu();
}

void Menu::recorridoAnchura() {
    string myVer;
    int origen;

    system("cls");
    cout << "RERRCORRIDO ANCHURA-" << endl << endl;
    imprimirVertices2();
    cout << "Ingresa el vertice origen: ";
    cin >> myVer;
    cin.ignore(256,'\n');
    cout << endl;

    origen = myGrafo.posicionVertice(myVer);

    if(origen != -1) {
        cout << endl;
        myGrafo.recorridoAnchura(myVer);
        cout << endl;
    }
    else {
        cout << "\t-ERROR: Ese Vertice no existe." << endl;
        system("PAUSE");
        recorridoAnchura();
    }
    cout << endl;
    system("PAUSE");
    mostrarMenu();
}

void Menu::recorridoProfundidad() {
    string myVer;
    int origen;

    system("cls");
    cout << "\t-RECORRIDO PROFUNDIDAD-" << endl << endl;
    imprimirVertices2();
    cout << "Ingresa el origen: ";
    cin >> myVer;
    cin.ignore(256,'\n');
    cout << endl;

    origen = myGrafo.posicionVertice(myVer);

    if(origen != -1) {
        cout << endl;
        myGrafo.recorridoProfundidad(myVer);
        cout << endl;
    }
    else {
        cout << "\t-ERROR: Ese vertice no existe." << endl;
        system("PAUSE");
        recorridoProfundidad();
    }
    cout << endl;
    system("PAUSE");
    mostrarMenu();
}

void Menu::rutaAnchura() {
    string origen, destino;
    bool flag;
    system("cls");
    cout << "RUTA ANCHURA-" << endl << endl;
    imprimirVertices2();
    do {
        cout << "Ingresa el origen: ";
        cin >> origen;
        cin.ignore(256,'\n');
        cout << endl;
        flag = false;
        if(myGrafo.posicionVertice(origen) == -1) {
            flag = true;
            cout << "ERROR: Ese origen no existe." << endl;
            system("PAUSE");
        }
    }
    while(flag);

    flag = true;

    do {
        cout << "Ingresa el destino: ";
        cin >> destino;
        cin.ignore(256,'\n');
        cout << endl;
        flag = false;
        if(myGrafo.posicionVertice(destino) == -1) {
            flag = true;
            cout << "\t-ERROR: Ese destino no existe." << endl;
            system("PAUSE");
        }
    }
    while(flag);

    cout << endl;
    myGrafo.rutaAnchura(origen, destino);
    cout << endl;

    system("PAUSE");
    mostrarMenu();
}

void Menu::rutaProfundidad() {
    string origen, destino;
    bool flag;
    system("cls");
    cout << "RUTA PROFUNDIDAD-" << endl << endl;
    imprimirVertices2();
    do {
        cout << "Ingresa el origen: ";
        cin >> origen;
        cin.ignore(256,'\n');
        cout << endl;
        flag = false;
        if(myGrafo.posicionVertice(origen) == -1) {
            flag = true;
            cout << "\t-ERROR: Ese origen no existe." << endl;
            system("PAUSE");
        }
    }
    while(flag);

    flag = true;

    do {
        cout << "Ingresa el destino: ";
        cin >> destino;
        cin.ignore(256,'\n');
        cout << endl;
        flag = false;
        if(myGrafo.posicionVertice(destino) == -1) {
            flag = true;
            cout << "\t-ERROR: Ese destino no existe." << endl;
            system("PAUSE");
        }
    }
    while(flag);

    cout << endl;
    myGrafo.rutaProfundidad(origen, destino);
    cout << endl;

    system("PAUSE");
    mostrarMenu();
}

