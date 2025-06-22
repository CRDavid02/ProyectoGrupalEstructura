//Integrante 1
//Integrante 2
//Integrante 3= Halber David Ccapchi Rios
void inorden (nodo* raiz) {
    if(!raiz) return;
    inorden(raiz-> izquierda);
    cout << raiz->id << "-" << raiz -> nombre <<endl;
    inorden(raiz->derecha);
}

void preorden(Nodo* raiz) {
  if (!raiz) return;
  cout << raiz->id<< "-" << raiz->nombre << endl;
  preorden(raiz->izquierda);
  preorden(raiz->derecha);
}

void postorden(Nodo* raiz) {
  if (!raiz) return; 
  postorden(raiz->izquierda);
  postorden(raiz->derecha);
  cout << raiz-id << "-" << raiz->nombre << endl;
}
//Integrante 4
//Integrante 5
  
