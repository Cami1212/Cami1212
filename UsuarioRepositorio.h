#include <string>
#ifndef UsuarioRepositorio_h
#define UsuarioRepositorio_h
using namespace std;
#include "Usuario.h"
#include "ListaLigada.h"
#include <fstream>

class UsuarioRepositorio{

public:
  UsuarioRepositorio();
  ~UsuarioRepositorio();
  void insertarUsuario(Usuario usuario);
  Usuario obtenerUsuarioPorUsernameYPassword(string username, string password);
  bool eliminarUsuario(Usuario u);
  ListaLigada obtenerUsuarios();
  void escribirEnArchivo();
  ListaLigada getListaDeUsuarios();

  
