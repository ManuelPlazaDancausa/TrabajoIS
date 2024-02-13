#ifndef MENUDIRECTOR_H
#define MENUDIRECTOR_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <list>
#include "user.h"
#include "global.h"
#include "directorAcademico.h"

class menu_director
{
private:
    DirectorAcademico director_;
    std::string nombreEvento_;

public:
    void Opciones()
    {
        system("clear");
        int opcion;
        bool continuar = true;
        bool n_ = false;
        int select = 0;
        std::list<std::string>::iterator ii = usuario.InicioInscritos();
        std::list<std::string>::iterator ip = usuario.InicioPreinscritos();
        std::list<std::string>::iterator fi = usuario.FinalInscritos();
        std::list<std::string>::iterator fp = usuario.FinalPreinscritos();
        while (continuar)
        {
            std::cout << "**********************************************" << std::endl;
            std::cout << "*                                            *" << std::endl;
            std::cout << "*   ¡MENU DE SELECCION DIRECTOR ACADEMICO!   *" << std::endl;
            std::cout << "*                                            *" << std::endl;
            std::cout << "**********************************************" << std::endl;
            nombreEvento_="";
            std::cout << "Ingresa 0: para volver " << std::endl;
            std::cout << "Ingresa 1: para ver las actividades" << std::endl;
            std::cout << "Ingresa 2: para ver tus presinscripciones" << std::endl;
            std::cout << "Ingresa 3: para ver tus inscripciones" << std::endl;
            std::cout << "Ingresa 4: para preinscribirte" << std::endl;
            std::cout << "Ingresa 5: para editar un evento" << std::endl; // solo puede tocar eventos a los que ha sido asignado
            std::cout << "Ingresa 6: para abrir o cerrar la inscripcion" << std::endl;
            std::cout << "Ingresa 7: para ver los eventos que aún no han sido editados" << std::endl;
            std::cout << "Ingresa 8: para pasar lista a los asistentes" << std::endl;
            std::cout << "Ingresa 9: para tramitar las inscripciones del evento" << std::endl;
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
                std::cout << "" << std::endl;
                std::cout << "Eventos: " << std::endl;
                imprimirEventos();
                std::cout << "" << std::endl;
                std::cout << "Elija un evento: " << std::endl;
                nombreEvento_="";
                while (nombreEvento_.empty())
                {
                    std::getline(std::cin, nombreEvento_);
                }

                director_.modificarEvento(nombreEvento_);

                break;
            case 6:
                system("clear");
                std::cout << "Ha ingresado el número 6. " << std::endl;
                std::cout << "" << std::endl;
                std::cout << "Eventos: " << std::endl;
                imprimirEventos();
                std::cout << "" << std::endl;
                std::cout << "Elija un evento: " << std::endl;
                while (nombreEvento_.empty())
                {
                    std::getline(std::cin, nombreEvento_);
                }
                std::cout << "Ingresa 1 si quiere abrir la inscripción o ingresa 2 para cerrarla. " << std::endl;
                cin >> select;
                if (select == 1)
                {
                    n_ = true;
                    director_.habilitar_desahabilitar_Evento(nombreEvento_, n_);
                }
                else if (select == 2)
                {
                    n_ = false;
                    director_.habilitar_desahabilitar_Evento(nombreEvento_, n_);
                }
                else
                {
                    std::cout<<"ERROR. No has introducido ni 1 ni 2."<<std::endl;
                }
                break;
            case 7:
                system("clear");
                std::cout << "Ha ingresado el número 7. " << std::endl;
                std::cout << "" << std::endl;
                std::cout << "Eventos pendientes de edición: " << std::endl;
                for (auto it = listaEventos.begin(); it != listaEventos.end(); it++)
                {
                    if (it->getFechaInicio() == "00/00/0000")
                    {
                        it->getEventos();
                    }
                }
                break;
            case 8:
                system("clear");
                std::cout << "Ha ingresado el número 7. " << std::endl;
                std::cout << "" << std::endl;
                std::cout << "Eventos: " << std::endl;
                imprimirEventos();
                std::cout << "" << std::endl;
                std::cout << "Elija un evento: " << std::endl;
                while (nombreEvento_.empty())
                {
                    std::getline(std::cin, nombreEvento_);
                }
                director_.checkListEvento(nombreEvento_);
                break;
            case 9:
                system("clear");
                std::cout << "Ha ingresado el número 7. " << std::endl;
                std::cout << "" << std::endl;
                std::cout << "Eventos: " << std::endl;
                imprimirEventos();
                std::cout << "" << std::endl;
                std::cout << "Elija un evento: " << std::endl;
                while (nombreEvento_.empty())
                {
                    std::getline(std::cin, nombreEvento_);
                }
                director_.inscripcionEvento(nombreEvento_);
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