//Prototipo de primer codigo
#include <iostream>
using namespace std;

struct Nodo {
    int id;
    string nombre;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int _id, string _nombre) {
        id = _id;
        nombre = _nombre;
        izquierda = derecha = NULL;
    }
};

// Insertar miembro
Nodo* insertar(Nodo* raiz, int id, string nombre) {
    if (raiz == NULL)
        return new Nodo(id, nombre);
    if (id < raiz->id)
        raiz->izquierda = insertar(raiz->izquierda, id, nombre);
    else
        raiz->derecha = insertar(raiz->derecha, id, nombre);
    return raiz;
}

// Buscar miembro
bool buscar(Nodo* raiz, int id) {
    if (raiz == NULL) return false;
    if (raiz->id == id) return true;
    if (id < raiz->id)
        return buscar(raiz->izquierda, id);
    else
        return buscar(raiz->derecha, id);
}

// Recorridos
void inorden(Nodo* raiz) {
    if (raiz == NULL) return;
    inorden(raiz->izquierda);
    cout << raiz->id << " - " << raiz->nombre << endl;
    inorden(raiz->derecha);
}

void preorden(Nodo* raiz) {
    if (raiz == NULL) return;
    cout << raiz->id << " - " << raiz->nombre << endl;
    preorden(raiz->izquierda);
    preorden(raiz->derecha);
}

void postorden(Nodo* raiz) {
    if (raiz == NULL) return;
    postorden(raiz->izquierda);
    postorden(raiz->derecha);
    cout << raiz->id << " - " << raiz->nombre << endl;
}

// Eliminar miembro
Nodo* encontrarMin(Nodo* raiz) {
    while (raiz->izquierda != NULL)
        raiz = raiz->izquierda;
    return raiz;
}

Nodo* eliminar(Nodo* raiz, int id) {
    if (!raiz) return NULL;
    if (id < raiz->id)
        raiz->izquierda = eliminar(raiz->izquierda, id);
    else if (id > raiz->id)
        raiz->derecha = eliminar(raiz->derecha, id);
    else {
        if (!raiz->izquierda) {
            Nodo* temp = raiz->derecha;
            delete raiz;
            return temp;
        } else if (!raiz->derecha) {
            Nodo* temp = raiz->izquierda;
            delete raiz;
            return temp;
        }
        Nodo* temp = encontrarMin(raiz->derecha);
        raiz->id = temp->id;
        raiz->nombre = temp->nombre;
        raiz->derecha = eliminar(raiz->derecha, temp->id);
    }
    return raiz;
}

// MAIN - Etapa 3
int main() {
    Nodo* raiz = NULL;

    // 10 miembros ficticios de la cultura Chimú
    raiz = insertar(raiz, 50, "Rey Tacaynamo");
    insertar(raiz, 30, "Hijo Taycanamo");
    insertar(raiz, 70, "Sacerdote Mayor");
    insertar(raiz, 20, "Jefe de Guerreros");
    insertar(raiz, 40, "Esposa Real");
    insertar(raiz, 60, "Consejero Real");
    insertar(raiz, 80, "Capitán del Ejército");
    insertar(raiz, 10, "Niño Heredero");
    insertar(raiz, 25, "Tía de la Reina");
    insertar(raiz, 35, "Astrónomo Real");

    cout << "\nRecorrido INORDEN:\n";
    inorden(raiz);

    cout << "\nRecorrido PREORDEN:\n";
    preorden(raiz);

    cout << "\nRecorrido POSTORDEN:\n";
    postorden(raiz);

    cout << "\n¿Existe el ID 25? ";
    cout << (buscar(raiz, 25) ? "Sí" : "No") << endl;

    cout << "\nEliminando el nodo con ID 30 (Hijo Taycanamo)...\n";
    raiz = eliminar(raiz, 30);

    cout << "\nNuevo recorrido INORDEN:\n";
    inorden(raiz);

    return 0;
}
