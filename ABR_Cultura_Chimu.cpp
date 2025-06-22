#include <iostream>



// --------------------------------------------------
// INTEGRANTE: Halber David Ccapchi Rios– Funciones de Recorrido
// --------------------------------------------------

// Muestra el árbol en recorrido inorden (izq - raíz - der)
void inorden(Nodo* raiz) {
    if (raiz == NULL) return;
    inorden(raiz->izquierda);
    cout << raiz->id << " - " << raiz->nombre << endl;
    inorden(raiz->derecha);
}

//funcion de eliminacion
