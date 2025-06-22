//Prototipo de primer codigo
#include <iostream>
using namespace std;

// Estructura básica de una persona
struct Persona {
    string nombre;
    string genero; // "M" o "F"
    Persona* conyuge;
    Persona* primerHijo;
    Persona* siguienteHermano;

    Persona(string nom, string gen) {
        nombre = nom;
        genero = gen;
        conyuge = NULL;
        primerHijo = NULL;
        siguienteHermano = NULL;
    }
};

// Función para agregar un hijo a una persona
void agregarHijo(Persona* padre, Persona* hijo) {
    if (!padre->primerHijo) {
        padre->primerHijo = hijo;
    } else {
        Persona* actual = padre->primerHijo;
        while (actual->siguienteHermano) {
            actual = actual->siguienteHermano;
        }
        actual->siguienteHermano = hijo;
    }
}

// Función para mostrar el árbol con sangría
void mostrarArbol(Persona* persona, int nivel = 0) {
    if (!persona) return;

    for (int i = 0; i < nivel; i++) cout << "  ";
    cout << "- " << persona->nombre;

    if (persona->conyuge) {
        cout << " (pareja: " << persona->conyuge->nombre << ")";
    }

    cout << endl;

    // Mostrar hijos
    Persona* hijo = persona->primerHijo;
    while (hijo) {
        mostrarArbol(hijo, nivel + 1);
        hijo = hijo->siguienteHermano;
    }
}

int main() {
    // Crear nodos
    Persona* tu = new Persona("Tú", "M");
    Persona* papa = new Persona("Papá", "M");
    Persona* mama = new Persona("Mamá", "F");

    // Pareja
    papa->conyuge = mama;
    mama->conyuge = papa;

    // Agregar hijo (tú)
    agregarHijo(papa, tu);
    agregarHijo(mama, tu); // También a la madre para mantener el árbol

    // Tíos paternos
    Persona* tio1 = new Persona("Tío Juan", "M");
    Persona* tio2 = new Persona("Tío Pedro", "M");

    // Abuelo paterno
    Persona* abuelo = new Persona("Abuelo", "M");

    // Pareja del abuelo
    Persona* abuela = new Persona("Abuela", "F");
    abuelo->conyuge = abuela;
    abuela->conyuge = abuelo;

    // Agregar hijos del abuelo
    agregarHijo(abuelo, papa);
    agregarHijo(abuelo, tio1);
    agregarHijo(abuelo, tio2);
    agregarHijo(abuela, papa); // también desde la abuela
    agregarHijo(abuela, tio1);
    agregarHijo(abuela, tio2);

    // Mostrar árbol desde el abuelo
    cout << "Árbol genealógico desde el abuelo:\n";
    mostrarArbol(abuelo);

    return 0;
}
