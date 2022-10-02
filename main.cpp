#include <iostream>
using namespace std;
#include <string>
#include<cstdlib>
#include "Usuario.h"
#include "UsuarioRepositorio.h"
#include "Nodo.h"
#include "ListaLigada.h"
#include <chrono>
#include <thread>



int main(){
  UsuarioRepositorio repo;
  while(true){
    int opcion;
    cout<<"Bienvenido ingrese una opcion del menu"<<endl;
    cin>>opcion;
    string username;
    string password;
    Usuario user;
    Usuario userFind;
    switch(opcion){
      
      case 1:
        
        cout<<"Ingresaste a la opcion de crear usuario";
        cout<<"Ingrese el username"<<endl;
        cin>>username;
        cout<<"Ingrese el password"<<endl;
        cin>>password;
        user.setUsername(username);
        user.setPassword(password);
        repo.insertarUsuario(user);
        break;

      case 2:
        cout<<"Ingresaste a la opcion de buscar usuario por username y pw";
        cout<<"Ingrese el username"<<endl;
        cin>>username;
        cout<<"Ingrese el password"<<endl;
        cin>>password;
        userFind = repo.obtenerUsuarioPorUsernameYPassword(username,password);
        if(userFind.getUsername().empty() && userFind.getPassword().empty()){
          cout<<"Usuario no encontrado"<<endl;
        }else{
          cout<<userFind.toString();
        }
      case 9:
        repo.escribirEnArchivo();

        exit(1);
    }
  }

