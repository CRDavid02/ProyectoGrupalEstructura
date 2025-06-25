// PROYECTO FINAL
// Ãrbol GenealÃ³gico usando Ãrbol Binario de BÃºsqueda
// CivilizaciÃ³n Ficticia: Cultura ChimÃº
// GRUPO 3 â€“ IngenierÃ­a de Sistemas


#include <iostream>
using namespace std;

struct Nodo {
    int id;               // Identificador Ãºnico del miembro
    string nombre;        // Nombre del personaje
    Nodo* izquierda;      // Puntero al hijo izquierdo
    Nodo* derecha;        // Puntero al hijo derecho

    Nodo(int _id, string _nombre) {
        id = _id;
        nombre = _nombre;
        izquierda = derecha = NULL;
    }
};

// Inserta un nuevo miembro al Ã¡rbol segÃºn su ID
Nodo* insertar(Nodo* raiz, int id, string nombre) {
    if (raiz == NULL)
        return new Nodo(id, nombre);

    if (id < raiz->id)
        raiz->izquierda = insertar(raiz->izquierda, id, nombre);
    else
        raiz->derecha = insertar(raiz->derecha, id, nombre);

    return raiz;
}

// Busca si un miembro con ID especÃ­fico existe en el Ã¡rbol
bool buscar(Nodo* raiz, int id) {
    if (raiz == NULL) return false;
    if (raiz->id == id) return true;

    if (id < raiz->id)
        return buscar(raiz->izquierda, id);
    else
        return buscar(raiz->derecha, id);
}

// Muestra el Ã¡rbol en recorrido inorden (izq - raÃ­z - der)
void inorden(Nodo* raiz) {
    if (raiz == NULL) return;
    inorden(raiz->izquierda);
    cout << raiz->id << " - " << raiz->nombre << endl;
    inorden(raiz->derecha);
}

// Muestra el Ã¡rbol en recorrido preorden (raÃ­z - izq - der)
void preorden(Nodo* raiz) {
    if (raiz == NULL) return;
    cout << raiz->id << " - " << raiz->nombre << endl;
    preorden(raiz->izquierda);
    preorden(raiz->derecha);
}

// Muestra el Ã¡rbol en recorrido postorden (izq - der - raÃ­z)
void postorden(Nodo* raiz) {
    if (raiz == NULL) return;
    postorden(raiz->izquierda);
    postorden(raiz->derecha);
    cout << raiz->id << " - " << raiz->nombre << endl;
}

// Encuentra el nodo mÃ­nimo del subÃ¡rbol derecho (usado en eliminaciÃ³n)
Nodo* encontrarMin(Nodo* raiz) {
    while (raiz->izquierda != NULL)
        raiz = raiz->izquierda;
    return raiz;
}

// Elimina un nodo segÃºn su ID, manteniendo la estructura del ABB
Nodo* eliminar(Nodo* raiz, int id) {
    if (!raiz) return NULL;

    if (id < raiz->id)
        raiz->izquierda = eliminar(raiz->izquierda, id);
    else if (id > raiz->id)
        raiz->derecha = eliminar(raiz->derecha, id);
    else {
        // Nodo con solo un hijo o sin hijos
        if (!raiz->izquierda) {
            Nodo* temp = raiz->derecha;
            delete raiz;
            return temp;
        } else if (!raiz->derecha) {
            Nodo* temp = raiz->izquierda;
            delete raiz;
            return temp;
        }
        // Nodo con dos hijos: buscar sucesor inorden
        Nodo* temp = encontrarMin(raiz->derecha);
        raiz->id = temp->id;
        raiz->nombre = temp->nombre;
        raiz->derecha = eliminar(raiz->derecha, temp->id);
    }
    return raiz;
}

int main() {
    Nodo* raiz = NULL;

    // Cargar 10 miembros de la genealogÃ­a ChimÃº
    raiz = insertar(raiz, 50, "Rey Tacaynamo");
    insertar(raiz, 30, "Hijo Taycanamo");
    insertar(raiz, 70, "Sacerdote Mayor");
    insertar(raiz, 20, "Jefe de Guerreros");
    insertar(raiz, 40, "Esposa Real");
    insertar(raiz, 60, "Consejero Real");
    insertar(raiz, 80, "CapitÃ¡n del EjÃ©rcito");
    insertar(raiz, 10, "NiÃ±o Heredero");
    insertar(raiz, 25, "TÃ­a de la Reina");
    insertar(raiz, 35, "AstrÃ³nomo Real");

    // Recorridos
    cout << "\nRecorrido INORDEN (JerarquÃ­a ordenada):\n";
    inorden(raiz);

    cout << "\nRecorrido PREORDEN (Ancestros primero):\n";
    preorden(raiz);

    cout << "\nRecorrido POSTORDEN (Descendientes):\n";
    postorden(raiz);

    // Prueba de bÃºsqueda
    cout << "\nÂ¿Existe el ID 25 (TÃ­a de la Reina)? ";
    cout << (buscar(raiz, 25) ? "SÃ­" : "No") << endl;

    // Eliminar un nodo con 2 hijos
    cout << "\nEliminando el nodo con ID 30 (Hijo Taycanamo)...\n";
    raiz = eliminar(raiz, 30);

    cout << "\nNuevo recorrido INORDEN tras la eliminaciÃ³n:\n";
    inorden(raiz);

    return 0;
}
