#include <iostream>
using namespace std;

#include <string>
#include<cstdlib>
#include "Usuario.h"


Usuario::Usuario(){
  
}
Usuario::Usuario(string u, string p){
  username=u;
  password=p;
}

Usuario::~Usuario(){
}
string Usuario::getUsername(){
  return username;
}
void Usuario::setUsername(string s){
  username =s;
}
string Usuario::getPassword(){
  return password;
}
void Usuario::setPassword(string p){
  password =p;
}
string Usuario::toString(){
  return username + " " + password;
}

