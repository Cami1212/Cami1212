#include <iostream>
using namespace std;
#include <string>
#include "Nodo.h"
#include "ListaLigada.h"

ListaLigada::ListaLigada()
{
    primerNodo = NULL;
}

bool ListaLigada::esVacia()
{
    if (primerNodo == NULL)
    {
        return true;
    }
    return false;
}

void ListaLigada::insertar(Usuario u)
{
    Nodo *temp = new Nodo(u);
    temp->setSiguiente(primerNodo);
    primerNodo = temp;
}

void ListaLigada::borrarUsuario(Usuario u)
{
    Nodo *nodoABorrar = buscarNodoPorUsuario(u);
    if (nodoABorrar == NULL)
    {
        cerr << "No existe el nodo que quieres borrar" << endl;
        return;
    }
    borrarNodo(nodoABorrar);
}

void *ListaLigada::borrarNodo(Nodo *n)
{
    if (primerNodo == NULL)
    {
        cerr << "No hay cabeza" << endl;
        return 0;
    }
    if (primerNodo == n)
    {
        primerNodo = primerNodo->getSiguiente();
        cerr << "Es la cabeza" << endl;
        return 0;
    }
    Nodo *temp = primerNodo;
    while (temp != NULL && temp->getSiguiente() != NULL)
    {
        if (temp->getSiguiente() == n)
        {
            temp->setSiguiente(temp->getSiguiente()->getSiguiente());
        }
        temp = temp->getSiguiente();
    }
}

Usuario ListaLigada::buscarUsuario(Usuario u)
{
    if (!esVacia())
    {
        Nodo *temp = primerNodo;
        while (temp != NULL)
        {
            if (temp->getUsuario().getUsername() == u.getUsername() && temp->getUsuario().getPassword() == u.getPassword())
            {
                return temp->getUsuario();
            }
            temp = temp->getSiguiente();
        }

        
    }
  Usuario user;
        return user;
}

void ListaLigada::imprimirLista()
{
    if (!esVacia())
    {
        Nodo *temp = primerNodo;
        while (temp != NULL)
        {
            cout << temp->toString() << endl;
            temp = temp->getSiguiente();
        }
    }
}

Nodo *ListaLigada::getPrimerNodo()
{
    return primerNodo;
}

Nodo *ListaLigada::buscarNodoPorUsuario(Usuario u)
{
    if (!esVacia())
    {
        Nodo *temp = primerNodo;
        while (temp != NULL)
        {
            if (temp->getUsuario().getUsername() == u.getUsername() && temp->getUsuario().getPassword() == u.getPassword())
            {
                return temp;
            }
            temp = temp->getSiguiente();
        }
    }
    return NULL;
}

