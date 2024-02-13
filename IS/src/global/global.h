#ifndef GLOBAL_H
#define GLOBAL_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <list>
#include "evento.h"
#include "user.h"

User usuario;
std::list<Evento> listaEventos;
std::list<User> listaUsuarios;
//funcion que imprime todos los eventos de la lista
void imprimirEventos()
{

    for(auto it=listaEventos.begin(); it!=listaEventos.end(); ++it)
    {
        it->getEventos();
    }
}

void imprimirUsuarios()
{
    for(auto it=listaUsuarios.begin(); it!=listaUsuarios.end(); ++it)
    {
        it->getUsuarios();
    }
}
//
#endif