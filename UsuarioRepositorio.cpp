#include <iostream>
using namespace std;
#include <string>
#include "Usuario.h"
#include "Nodo.h"
#include <fstream>
#include "UsuarioRepositorio.h"
#include <chrono>
#include <thread>


UsuarioRepositorio::UsuarioRepositorio(){
  listaDeUsuarios = obtenerUsuarios();
}
UsuarioRepositorio::~UsuarioRepositorio(){
  
}

ListaLigada UsuarioRepositorio::getListaDeUsuarios(){
  return listaDeUsuarios;
}

ifstream UsuarioRepositorio::openFileStream(string filename){
  ifstream inFile;
  inFile.open(filename);
  if(inFile.fail()){
    std::ofstream outfile ("usuario.txt");
  }
  return inFile;
}

 ofstream UsuarioRepositorio::openOutputStream(string nombreArchivo){
  ofstream outFile;
  outFile.open(nombreArchivo);
  return outFile;
 }

void UsuarioRepositorio::escribirEnArchivo(){
  
  
  
  
  std::ofstream outFile ("usuario.txt", std::ofstream::out | std::ofstream::trunc);


  if(!listaDeUsuarios.esVacia()){
    Nodo *temp = listaDeUsuarios.getPrimerNodo();
    cout<<temp->getUsuario().getUsername()<<temp->getUsuario().getPassword()<<endl;
    int count = 1;
    while(temp != NULL){

        outFile << temp->getUsuario().getUsername() <<endl;
        outFile << temp->getUsuario().getPassword() <<endl;

      
      temp = temp->getSiguiente();
      count++;
    }
  }
  outFile.close();

}

void UsuarioRepositorio::insertarUsuario(Usuario usuario){
  Usuario usuarioGuardado = obtenerUsuarioPorUsernameYPassword(usuario.getUsername(),usuario.getPassword());
  if(usuarioGuardado.getUsername().empty() && usuarioGuardado.getPassword().empty()){
    listaDeUsuarios.insertar(usuario);
    
    
  }else{
    cout<<"este usuario ya existe"<<endl;
  }
  
}

Usuario UsuarioRepositorio::crearUsuario(string username, string password){
  Usuario usuario(username,password);
  return usuario;
}

ListaLigada UsuarioRepositorio::obtenerUsuarios(){
  ifstream inFile = openFileStream("usuario.txt");
  
  string item;
  Usuario user;
  Nodo nodo(user);

  string username;
  string password;
  ListaLigada lista;
  int counter = 0;
  while(!inFile.eof()){
    inFile >> item ;
    if(counter%2!=0){
      username = item;
    }else{
      password = item;
      user = crearUsuario(username, password);
      lista.insertar(user);
    }
    
    counter++;
    
  }
  inFile.close();
  return lista;
}

Usuario UsuarioRepositorio::obtenerUsuarioPorUsernameYPassword(string username, string password){
  Usuario user(username,password);
  Usuario aBuscar = listaDeUsuarios.buscarUsuario(user);
  
  return aBuscar;
}



bool UsuarioRepositorio::eliminarUsuario(Usuario u){
  listaDeUsuarios.borrarUsuario(u);
  return true;
}
