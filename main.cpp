#include <iostream>
using namespace std;
#include <string>
#include "Usuario.h"
#include "UsuarioRepositorio.h"
#include "Nodo.h"
#include "ListaLigada.h"





int main(){
  ListaLigada adres;
  UsuarioRepositorio repo;
  while(true){
    int opcion;
    cout<<"Bienvenido ingrese una opcion del menu"<<endl;
    cout<<"-------------------------------------"<<endl;
    cout<<"1. Ingresar nuevo usuario"<<endl;
    cout<<"2. Buscar usuario existente con username y password "<<endl;
    cout<<"3. Eliminar usuario existente con username y password "<<endl;
    cout<<"4. Mostrar lista "<<endl;
    cout<<"9.salir "<<endl;
    
    cin>>opcion;
    string username;
    string password;
    Usuario user;
    Usuario userFind;
    switch(opcion){
      
      case 1:
        
        cout<<"Ingresaste a la opcion de crear usuario"<<endl;
        cout<<"Ingrese el username"<<endl;
        cin>>username;
        cout<<"Ingrese el password"<<endl;
        cin>>password;
        user.setUsername(username);
        user.setPassword(password);
        repo.insertarUsuario(user);
        break;

      case 2:
        cout<<"Ingresaste a la opcion de buscar usuario por username y password";
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
      case 3:
      cout<<"Ingresaste a la opcion de eliminar usuario por username y password";
      cout<<"Ingrese el username"<<endl;
      cin>>username;
      cout<<"Ingrese el password"<<endl;
      cin>>password;

      case 4:
      adres.imprimirLista();
      
      
      
      case 9:
        repo.escribirEnArchivo();

        exit(1);
    }
  }

  return 0;
}

