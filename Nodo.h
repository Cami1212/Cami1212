#include <string>
#ifndef Nodo_h
#define Nodo_h
using namespace std;
#include "Usuario.h"

class Nodo
{
  private:
    Usuario usuario;
    Nodo *siguienteNodo;
    
    
  public:
    Nodo(Usuario u);
    void setUsuario(Usuario u);
    Usuario getUsuario();
    Nodo *getSiguiente();
    void setSiguiente(Nodo *sig);
    string toString();
};

#endif

