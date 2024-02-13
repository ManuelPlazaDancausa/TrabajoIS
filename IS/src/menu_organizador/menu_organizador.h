#ifndef MENUORGANIZADOR_H
#define MENUORGANIZADOR_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <list>
#include "user.h"
#include "global.h"
#include "organizador.h"

class menu_organizador
{

public:
    Organizador organizador_;
    std::string nombreEvento_;
    bool n_;
    std::string nombre_;
    std::list<std::string>::iterator ii = usuario.InicioInscritos();
    std::list<std::string>::iterator ip = usuario.InicioPreinscritos();
    std::list<std::string>::iterator fi = usuario.FinalInscritos();
    std::list<std::string>::iterator fp = usuario.FinalPreinscritos();
    void Opciones()
    {
        system("clear");
        int opcion;
        bool continuar = true;
        while (continuar)
        {
            std::cout << "******************************************" << std::endl;
            std::cout << "*                                        *" << std::endl;
            std::cout << "*   ¡MENU DE SELECCION DE ORGANIZADOR!   *" << std::endl;
            std::cout << "*                                        *" << std::endl;
            std::cout << "******************************************" << std::endl;
            std::cout << "Ingresa 0: para volver " << std::endl;
            std::cout << "Ingresa 1: para ver las actividades" << std::endl;
            std::cout << "Ingresa 2: para ver tus prescripciones" << std::endl;
            std::cout << "Ingresa 3: para ver tus inscripciones" << std::endl;
            std::cout << "Ingresa 4: para prescribirte" << std::endl;
            std::cout << "Ingresa 5: para crear un evento" << std::endl;
            std::cout << "Ingresa 6: para ascender a un usuario a Director Académico" << std::endl;
            std::cout << "Ingresa 7: para borrar el evento" << std::endl;

            std::cin >> opcion;
            switch (opcion)
            {
            case 0:
                continuar = false;
                break;
            case 1:
                system("clear");
                std::cout << "Ha ingresado el número 1." << std::endl;

                imprimirEventos();

                break; // La instrucción 'break' finaliza el switch

            case 2:
                system("clear");
                std::cout << "Ha ingresado el número 2." << std::endl;

                usuario.mostrarEventosPreinscrito();

                break;

            case 3:
                system("clear");
                std::cout << "Ha ingresado el número 3. " << std::endl;

                usuario.mostrarEventosInscrito();
                break;
            case 4:
                system("clear");
                std::cout << "Ha ingresado el número 4. " << std::endl;
                std::cout << "" << std::endl;
                std::cout << "Eventos disponibles: " << std::endl;
                for (auto it = listaEventos.begin(); it != listaEventos.end(); it++)
                {
                    if (it->getHabilitado())
                    {
                        it->getEventos();
                    }
                }
                std::cout << "Elija un evento: " << std::endl;

                while (nombreEvento_.empty())
                {
                    std::getline(std::cin, nombreEvento_);
                }

                for (auto it = listaEventos.begin(); it != listaEventos.end(); it++)
                {
                    if (it->getNombre() == nombreEvento_)
                    {
                        n_ = true;
                    }
                }
                if (n_)
                {
                    for (auto it = ip; it != fp; it++)
                    {
                        if (*it == nombreEvento_)
                        {
                            std::cout << "Evento ya Preinscrito. " << std::endl;
                            n_ = false;
                        }
                        else
                        {
                            break;
                        }
                    }
                    for (auto it = ii; it != fi; it++)
                    {
                        if (*it == nombreEvento_)
                        {
                            std::cout << "Evento ya Inscrito. " << std::endl;
                            n_ = false;
                        }
                        else
                        {
                            break;
                        }
                    }
                    if (n_)
                    {
                        usuario.addlistaEventosInscritos(nombreEvento_);
                        std::cout << "AÑADIDO CORRECTAMENTE" << std::endl;
                    }
                }
                else
                {
                    std::cout << "Evento no existente. " << std::endl;
                }
                break;
            case 5:
                system("clear");
                std::cout << "Ha ingresado el número 5. " << std::endl;

                organizador_.crearEvento();

                break;
            case 6:
                std::cout << "Ha ingresado el número 6. " << std::endl;
                cout << "Estos son los usuarios actuales: " << endl;

                imprimirUsuarios();
                cout << "" << endl;
                cout << "Introduzca el nombre del usuario" << endl;
                while (nombre_.empty())
                {
                    std::getline(std::cin, nombre_);
                }
                if (organizador_.cambiarEstado(nombre_))
                {
                    std::cout << "Usuario ascendido con exito. " << std::endl;
                }
                else
                {
                    std::cout << "Usuario no coincide con ninguno existente. " << std::endl;
                }

                break;
            case 7:
                system("clear");
                std::cout << "Ha ingresado el número 7. " << std::endl;
                std::cout << "" << std::endl;
                std::cout << "Eventos disponibles: " << std::endl;
                for (auto it = listaEventos.begin(); it != listaEventos.end(); it++)
                {
                    it->getEventos();
                }
                std::cout << "Elija un evento: " << std::endl;

                while (nombreEvento_.empty())
                {
                    std::getline(std::cin, nombreEvento_);
                }
                for (auto it = listaEventos.begin(); it != listaEventos.end();)
                {
                    if (nombreEvento_ == it->getNombre())
                    {
                        it=listaEventos.erase(it);
                    }
                    else
                    {
                        it++;
                    }
                }
            break;
            default:
                system("clear");
                std::cout << "Opción no válida." << std::endl;
                break;
            }
        }
    }
};

#endif