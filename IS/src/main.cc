#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <list>
#include "user.h"
#include "menus.h"
#include "programa.h"
#include "userManager.h"

int main(void)
{
    system("clear");
    Programa p;
    UserManager u;
    p.copiaDeSeguridadEventos();
    p.copiaDeSeguridadUsuarios();
    p.inicioProgramaEvento();
    p.inicioProgramaUsuarios();
    p.verify();
    std::cout << "************************************" << std::endl;
    std::cout << "*                                  *" << std::endl;
    std::cout << "*        ¡Hola, bienvenido!        *" << std::endl;
    std::cout << "*                                  *" << std::endl;
    std::cout << "************************************" << std::endl;
    Menu menu;
    bool continuar = true;
    int select;
    while (continuar)
    {
        std::cout << "************************************" << std::endl;
        std::cout << "*                                  *" << std::endl;
        std::cout << "*         ¡Menú Principal!         *" << std::endl;
        std::cout << "*                                  *" << std::endl;
        std::cout << "************************************" << std::endl;
        std::cout << "Ingresa 0: Para Iniciar el programa" << std::endl;
        std::cout << "Ingresa 1: Para Cerrar el programa" << std::endl;
        std::cout << "Ingresa 2: Para Cerrar Sesión" << std::endl;

        std::cin >> select;
        switch (select)
        {
        case 0:

            if (usuario.GetLog() == false)
            {
                menu.NoLog();
            }
            else if (usuario.GetLog() == true)
            {
                menu.selectMenu();
            }
            break;
        case 1:
            continuar = false;
            break;
        case 2:
            u.logout();
        break;
        default:
            std::cout << "Opción no válida." << std::endl;
            break;
        }
    }
    p.cerrarProgramaUsuarios();
    p.cerrarProgramaEventos();

    exit(EXIT_SUCCESS);
}