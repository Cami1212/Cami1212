#include <string>
#ifndef ListaLigada_h
#define ListaLigada_h
using namespace std;
#include "Nodo.h"
#include "Usuario.h"

class ListaLigada{

  private:
    Nodo *primerNodo;
    Nodo *buscarNodoPorUsuario(Usuario u);
    void *borrarNodo(Nodo *n);


  public:
    ListaLigada();
    Nodo *getPrimerNodo();
    bool esVacia();
    void insertar(Usuario u);
    void imprimirLista();
    Usuario buscarUsuario(Usuario u);
    void borrarUsuario(Usuario u);

};

#endif
