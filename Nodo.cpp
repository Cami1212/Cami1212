#include <iostream>
using namespace std;
#include <string>
#include "Usuario.h"
#include "Nodo.h"

Nodo::Nodo(Usuario u){
  usuario = u;
  siguienteNodo = NULL;
}

void Nodo::setUsuario(Usuario u){
  usuario = u;
}
Usuario Nodo::getUsuario(){
  return usuario;
}
Nodo *Nodo::getSiguiente(){
  return siguienteNodo;
}
void Nodo::setSiguiente(Nodo *sig){
  siguienteNodo = sig;
}
string Nodo::toString(){
  string data = usuario.toString();
  
  return data;
}

