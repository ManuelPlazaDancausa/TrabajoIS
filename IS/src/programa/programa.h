#ifndef PROGRAMA_H
#define PROGRAMA_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <list>
#include "user.h"
#include "evento.h"
#include "userManager.h"
#include "global.h"

// listaEvento es una variable global

class Programa
{
public:
    void verify()
    {
        std::list<std::string>::iterator Ii;
        std::list<std::string>::iterator If;
        std::list<std::string>::iterator Pi;
        std::list<std::string>::iterator Pf;

        usuario.userClear(); // Assuming this function clears user-related data

        for (auto et = listaEventos.begin(); et != listaEventos.end(); et++)
        {
            Ii = et->InicioInscritos();
            If = et->FinalInscritos();
            Pi = et->InicioPreinscritos();
            Pf = et->FinalPreinscritos(); // Corrected: Assuming there's a function to get the end iterator for pre-registered list

            for (auto it = Ii; it != If; it++)
            {
                if ((*it) == usuario.GetID())
                {
                    usuario.addlistaEventosPreinscritos(et->getNombre());
                    break; // Exit the loop if the user is pre-registered
                }
            }

            for (auto it = Pi; it != Pf; it++)
            {
                if (*it == usuario.GetID())
                {
                    usuario.addlistaEventosInscritos(et->getNombre());
                    break; // Exit the loop if the user is registered
                }
            }
        }
    }
    // Carga el contenido de los ficheros en una lista que es variable global
    void inicioProgramaEvento()
    {
        std::string linea;
        std::string valor;
        Evento evento;
        std::ifstream archivo("Eventos.txt");
        if (!archivo.is_open())
        {
            std::cerr << "Error al abrir el archivo." << std::endl;
            return;
        }
        User currentUser("", "", "", false);
        bool userFound = false;

        while (getline(archivo, linea))
        {
            evento.eventoClear();
            evento.setNombre(linea);
            getline(archivo, linea);
            evento.setFechaInicio(linea);
            getline(archivo, linea);
            evento.setFechaCierre(linea);
            getline(archivo, linea);
            std::stringstream st;
            st.str(linea);
            st >> valor;
            if (valor == "true")
            {
                evento.setHabilitado(true);
            }
            else if (valor == "false")
            {
                evento.setHabilitado(false);
            }
            else
            {
                std::cout << "Contenido no válido en la parte de habilitado." << std::endl;
            }
            getline(archivo, linea);
            evento.setAforo(std::stof(linea));
            getline(archivo, linea);
            evento.setUbicacion(linea);
            getline(archivo, linea);
            evento.setTematica(linea);
            getline(archivo, linea);
            evento.setPrecio(std::stof(linea));
            getline(archivo, linea);
            evento.setCategoria(linea);
            getline(archivo, linea);
            evento.setNombreCreador(linea);
            getline(archivo, linea);
            evento.setNombreDirectorAcademico(linea);

            std::stringstream ss;
            getline(archivo, linea);
            ss.str(linea);
            std::string nombrePonente;
            while (getline(ss, nombrePonente, '|'))
            {
                evento.addNombresPonentes(nombrePonente);
            }

            ss.clear();
            getline(archivo, linea);
            ss.str(linea);
            std::string nombreAsistente;
            while (getline(ss, nombreAsistente, '|'))
            {
                evento.addNombresAsistentes(nombreAsistente);
            }

            ss.clear();
            getline(archivo, linea);
            ss.str(linea);
            std::string nombreInscrito;
            while (getline(ss, nombreInscrito, '|'))
            {
                evento.addNombresInscritos(nombreInscrito);
            }

            ss.clear();
            getline(archivo, linea);
            ss.str(linea);
            std::string nombrePreinscrito;
            while (getline(ss, nombrePreinscrito, '|'))
            {
                evento.addNombresPreinscritos(nombrePreinscrito);
            }
            getline(archivo, linea);
            listaEventos.push_back(evento);
        }
        archivo.close();
    }

    void inicioProgramaUsuarios()
    {
        std::string linea;
        User currentUser("", "", "", false);
        std::ifstream archivo("Usuarios.txt");

        if (!archivo.is_open())
        {
            std::cerr << "Error al abrir el archivo." << std::endl;
            return;
        }
        else
        {
            while (getline(archivo, linea))
            {
                currentUser.userClear();
                currentUser.SetID(linea);
                getline(archivo, linea);
                currentUser.SetPassword(linea);
                getline(archivo, linea);
                currentUser.SetTipo(linea);

                std::stringstream ss;
                getline(archivo, linea);
                ss.str(linea);
                std::string nombreEventoPreinscrito;
                while (getline(ss, nombreEventoPreinscrito, '|'))
                {
                    currentUser.addlistaEventosPreinscritos(nombreEventoPreinscrito);
                }

                ss.clear();
                getline(archivo, linea);
                ss.str(linea);
                std::string nombreEventoInscrito;
                while (getline(ss, nombreEventoInscrito, '|'))
                {
                    currentUser.addlistaEventosInscritos(nombreEventoInscrito);
                }
                getline(archivo, linea);
                listaUsuarios.push_back(currentUser);
            }
            archivo.close();
        }
    }

    void cerrarProgramaEventos()
    {
        std::ofstream archivo("Eventos.txt", std::ios::trunc);
        if (!archivo.is_open())
        {
            std::cerr << "Error al abrir el archivo de eventos para escritura." << std::endl;
            return;
        }
        archivo.close();
        for (auto it = listaEventos.begin(); it != listaEventos.end(); it++)
        {
            (*it).ficheroEventos();
        }
    }

    void cerrarProgramaUsuarios()
    {
        if (usuario.GetLog() == true)
        {
            UserManager log;
            log.logout();
        }
        std::ofstream archivo("Usuarios.txt", std::ios::trunc);
        if (!archivo.is_open())
        {
            std::cerr << "Error al abrir el archivo de usuarios para escritura." << std::endl;
            return;
        }
        archivo.close();
        for (auto it = listaUsuarios.begin(); it != listaUsuarios.end(); it++)
        {
            (*it).ficheroUsuario();
        }
    }

    void copiaDeSeguridadEventos()
    {
        std::ifstream archivoOriginal("Eventos.txt");
        if (!archivoOriginal.is_open())
        {
            std::cerr << "Error al abrir el archivo de eventos para copia de seguridad." << std::endl;
            return;
        }

        std::ofstream archivoCopia("Eventos_Copia.txt");
        if (!archivoCopia.is_open())
        {
            std::cerr << "Error al abrir el archivo de copia de seguridad de eventos para escritura." << std::endl;
            archivoOriginal.close(); // Cerrar archivo original antes de salir
            return;
        }

        std::string linea;

        while (std::getline(archivoOriginal, linea))
        {
            archivoCopia << linea << std::endl;
        }

        archivoOriginal.close();
        archivoCopia.close();

        std::cout << "Copia del archivo realizada exitosamente." << std::endl;

        return;
    }

    void copiaDeSeguridadUsuarios()
    {
        std::ifstream archivoOriginal("Usuarios.txt");
        if (!archivoOriginal.is_open())
        {
            std::cerr << "Error al abrir el archivo de usuarios para copia de seguridad." << std::endl;
            return;
        }

        std::ofstream archivoCopia("Usuarios_Copia.txt");
        if (!archivoCopia.is_open())
        {
            std::cerr << "Error al abrir el archivo de copia de seguridad de usuarios para escritura." << std::endl;
            archivoOriginal.close(); // Cerrar archivo original antes de salir
            return;
        }

        std::string linea;

        while (std::getline(archivoOriginal, linea))
        {
            archivoCopia << linea << std::endl;
        }

        archivoOriginal.close();
        archivoCopia.close();

        std::cout << "Copia del archivo realizada exitosamente." << std::endl;

        return;
    }
};
#endif