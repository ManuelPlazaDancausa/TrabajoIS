#ifndef ORGANIZADOR_H
#define ORGANIZADOR_H

#include "user.h"
#include "evento.h"
#include "global.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

class Organizador : public User
{
public:
    Organizador(string ID = "", string Password = "", string Tipo = "", bool Log = false) : User(ID, Password, Tipo, Log)
    {
    }

    // Funcion que crea evento
    void crearEvento()
    {
        string nombreDirectorAcademico;
        string nombreEvento;
        bool encontrado=false;
        cout << "******************************************" << endl;
        cout << "*                                        *" << endl;
        cout << "*     ¡MENU DE CREACION DE EVENTO!       *" << endl;
        cout << "*                                        *" << endl;
        cout << "******************************************" << endl;
        cout << "" << endl;
        for (auto it = listaUsuarios.begin(); it != listaUsuarios.end(); it++)
        {
            if (it->GetTipo() == "Director Academico")
            {
                cout << "Usuario: " << it->GetID() << endl;
            }
        }
        cout << "" << endl;
        cout << "Elija el nombre del directorAcademico: " << endl;
        while (nombreDirectorAcademico.empty())
        {
            std::getline(std::cin, nombreDirectorAcademico);
        }
        cout << "Elija el nombre del nuevo evento" << endl;
        while (nombreEvento.empty())
        {
            std::getline(std::cin, nombreEvento);
        }

        for (auto it = listaUsuarios.begin(); it != listaUsuarios.end(); it++)
        {
            if (it->GetID() == nombreDirectorAcademico && it->GetTipo() == "Director Academico")
            {
                cout<<""<<endl;
                std::cout<<"Evento creado con exito"<<std::endl;
                cout<<""<<endl;
                Evento p(nombreEvento, "00/00/0000", "00/00/0000", false, 0, "empty", "empty", 0.0, "empty", usuario.GetID(), nombreDirectorAcademico);
                listaEventos.push_back(p);
                encontrado=true;
            }

        }            
        if(!encontrado)
            {
                std::cout << "No hay ningun Director Academico con ese Usuario" << std::endl;
                return;
            }

    }

    // Funcion que asciende a usuario a directorAcademico
    bool cambiarEstado(string nombre)
    {
        for (auto it = listaUsuarios.begin(); it != listaUsuarios.end(); it++)
        {
            if (it->GetID() == nombre)
            {
                it->SetTipo("Director Academico");
                return true;
            }
        }
        return false;
    }
};

#endif