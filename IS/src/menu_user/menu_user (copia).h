#ifndef MENUUSER_H
#define MENUUSER_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <list>
#include "user.h"
#include "global.h"

class menu_user
{

public:
    void Opciones()
    {
        std::string nombreEvento_;
        bool n_;
        std::list<std::string>::iterator ii = usuario.InicioInscritos();
        std::list<std::string>::iterator ip = usuario.InicioPreinscritos();
        std::list<std::string>::iterator fi = usuario.FinalInscritos();
        std::list<std::string>::iterator fp = usuario.FinalPreinscritos();
        system("clear");
        std::cout << "************************************" << std::endl;
        std::cout << "*                                  *" << std::endl;
        std::cout << "*  ¡MENU DE SELECCION DE USUARIO!  *" << std::endl;
        std::cout << "*                                  *" << std::endl;
        std::cout << "************************************" << std::endl;
        int opcion;
        bool continuar = true;
        while (continuar)
        {
            std::cout << "Ingresa 0: para volver " << std::endl;
            std::cout << "Ingresa 1: para ver las actividades" << std::endl;
            // copiar de menu organizador
            std::cout << "Ingresa 2: para ver tus prescripciones" << std::endl;
            std::cout << "Ingresa 3: para ver tus inscripciones" << std::endl;
            std::cout << "Ingresa 4: para prescribirte" << std::endl;
            //
            std::cin >> opcion;
            switch (opcion)
            {
            case 0:
                continuar = false;
                break;
            case 1:
                system("clear");
                std::cout << "Ha ingresado el número 1." << std::endl;
                std::cout << "Eventos: " << std::endl;
                imprimirEventos();
                std::cout << "" << std::endl;
                break; // La instrucción 'break' finaliza el switch

            case 2:
                system("clear");
                std::cout << "Ha ingresado el número 2." << std::endl;

                usuario.mostrarEventosPreinscrito();

                break;
            case 3:
                system("clear");
                std::cout << "Ha ingresado el número 3." << std::endl;

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
                        for (auto it = listaEventos.begin(); it != listaEventos.end(); it++)
                        {
                            if (nombreEvento_==it->getNombre())
                            {
                                std::cout << "Evento preinscrito con exito. " << std::endl;
                                it->addNombresPreinscritos(usuario.GetID());
                            }
                        }
                    }
                }
                else
                {
                    std::cout << "Evento no existente. " << std::endl;
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