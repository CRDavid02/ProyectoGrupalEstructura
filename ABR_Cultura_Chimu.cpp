#include <iostream>

// Muestra el árbol en recorrido inorden (izq - raíz - der)
void inorden(Nodo* raiz) {
    if (raiz == NULL) return;
    inorden(raiz->izquierda);
    cout << raiz->id << " - " << raiz->nombre << endl;
    inorden(raiz->derecha);
}

// Muestra el árbol en recorrido preorden (raíz - izq - der)
void preorden(Nodo* raiz) {
    if (raiz == NULL) return;
    cout << raiz->id << " - " << raiz->nombre << endl;
    preorden(raiz->izquierda);
    preorden(raiz->derecha);
}

// Muestra el árbol en recorrido postorden (izq - der - raíz)
void postorden(Nodo* raiz) {
    if (raiz == NULL) return;
    postorden(raiz->izquierda);
    postorden(raiz->derecha);
    cout << raiz->id << " - " << raiz->nombre << endl;
}
// --------------------------------------------------
//INTEGRANTE: JOHAN AIME LOPEZ
// --------------------------------------------------
//funcion de eliminacion
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



// Menú principal y pruebas del sistema
int main() {
    Nodo* raiz = NULL;

    // Cargar 10 miembros de la genealogía Chimú
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

    // Recorridos
    cout << "\nRecorrido INORDEN (Jerarquía ordenada):\n";
    inorden(raiz);

    cout << "\nRecorrido PREORDEN (Ancestros primero):\n";
    preorden(raiz);

    cout << "\nRecorrido POSTORDEN (Descendientes):\n";
    postorden(raiz);

    // Prueba de búsqueda
    cout << "\n¿Existe el ID 25 (Tía de la Reina)? ";
    cout << (buscar(raiz, 25) ? "Sí" : "No") << endl;

    // Eliminar un nodo con 2 hijos
    cout << "\nEliminando el nodo con ID 30 (Hijo Taycanamo)...\n";
    raiz = eliminar(raiz, 30);

    cout << "\nNuevo recorrido INORDEN tras la eliminación:\n";
    inorden(raiz);

    return 0;
}
