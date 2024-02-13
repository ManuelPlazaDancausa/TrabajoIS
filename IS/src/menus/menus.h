#ifndef MENUS_H
#define MENUS_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <list>
#include "menu_user.h"
#include "menu_organizador.h"
#include "menu_director.h"
#include "user.h"
#include "userManager.h"
#include "global.h"

class Menu
{
public:
    UserManager Usuario;
    std::string nombre;
    std::string password;
    void NoLog()
    {
        int opcion;
        system("clear");
        bool continuar = true;
        while (continuar == true)
        {
            std::cout << "************************************" << std::endl;
            std::cout << "*                                  *" << std::endl;
            std::cout << "*        ¡MENU DE SELECCION!       *" << std::endl;
            std::cout << "*                                  *" << std::endl;
            std::cout << "************************************" << std::endl;
            std::cout << "Ingresa 0 para volver " << std::endl;
            std::cout << "Ingresa 1 para loguearte" << std::endl;
            std::cout << "Ingresa 2 para ver las Actividades" << std::endl;
            std::cout << "Ingresa 3 para crear usuario" << std::endl;
            std::cin >> opcion;
            switch (opcion)
            {
            case 0:
                system("clear");
                continuar = false;
                break;
            case 1:
                system("clear");
                std::cout << "Ha ingresado el número 1." << std::endl;
                std::cout << "Introduzca el nombre de usuario" << std::endl;
                while (nombre.empty())
                {
                    std::getline(std::cin, nombre);
                }
                std::cout << "Introduzca la contraseña" << std::endl;
                while (password.empty())
                {
                    std::getline(std::cin, password);
                }
                if (Usuario.login(nombre, password))
                {
                    std::cout << "Se ha logueado como " << usuario.GetID() << " de tipo: " << usuario.GetTipo() << std::endl;
                    continuar = false;
                }
                break; // La instrucción 'break' finaliza el switch

            case 2:
                system("clear");
                std::cout << "Ha ingresado el número 2." << std::endl;

                imprimirEventos();
                break;
            case 3:
                std::cout << "Ha ingresado el número 3." << std::endl;
                std::cout << "Introduzca el nombre de usuario" << std::endl;
                std::cin >> nombre;
                std::cout << "Introduzca la contraseña" << std::endl;
                std::cin >> password;
                Usuario.crearUsuario(nombre, password);
                break;
            default:
                system("clear");
                std::cout << "Opción no válida." << std::endl;
                break;
            }
        }
    }

    void selectMenu()
    {
        if (usuario.GetTipo() == "Usuario")
        {
            menu_user menu;
            menu.Opciones();
        }
        else if (usuario.GetTipo() == "Organizador")
        {
            menu_organizador menu;
            menu.Opciones();
        }
        else if (usuario.GetTipo() == "Director Academico")
        {
            menu_director menu;
            menu.Opciones();
        }
        else
        {
            std::cout << "ERROR EN EL TIPO DE USUARIO\n"
                      << std::endl;
            return;
        }
    }
};

#endif
