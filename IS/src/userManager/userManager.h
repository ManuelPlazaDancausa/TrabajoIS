#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <string>
#include <fstream>
#include "user.h" // Suponiendo que aquí está la definición de la clase User
#include "global.h"

// Variables globales declaradas en otro archivo
extern std::list<User> listaUsuarios; // Lista global de usuarios
extern User usuario;                  // Usuario global

// Clase para manejar la gestión de usuarios
class UserManager
{
public:
    // Función para iniciar sesión
    bool login(std::string username, std::string password)
    {
        bool userFound = false;

        // Iterar a través de la lista global de usuarios
        for (auto it = listaUsuarios.begin(); it != listaUsuarios.end(); ++it)
        {
            // Verificar si se encuentra un usuario con el nombre de usuario y contraseña proporcionados
            if ((*it).GetID() == username && (*it).GetPassword() == password)
            {
                usuario = (*it);      // Actualiza el usuario global con el usuario conectado
                usuario.SetLog(true); // Establece el estado de conexión en verdadero
                userFound = true;
                break; // Se encontró el usuario, se puede salir del bucle
            }
        }

        // Devolver el usuario si se encontró coincidencia, de lo contrario, devuelve un usuario vacío
        if (userFound)
        {
            std::cout << "LOGUEADO CON EXITO" << std::endl;
            return true;
        }
        else
        {
            std::cout << "Usuario o contraseña incorrectos." << std::endl;
            return false;
        }
    }

    // Función para cerrar sesión
    void logout()
    {
        bool encontrado = false;

        // Iterar a través de la lista global de usuarios
        for (auto it = listaUsuarios.begin(); it != listaUsuarios.end(); it++)
        {
            // Buscar el usuario actual en la lista de usuarios
            if ((*it).GetID() == usuario.GetID())
            {
                usuario.SetID("");
                usuario.SetPassword("");
                usuario.SetTipo("");
                usuario.userClear();
                usuario.SetLog(false); // Establece el estado de conexión en falso
                (*it) = usuario;       // Actualiza el usuario en la lista global
                encontrado = true;
            }
        }

        // Informar sobre el resultado de la desconexión
        if (encontrado)
        {
            std::cout << "Desconexión exitosa." << std::endl;
        }
        else
        {
            std::cout << "Ningún usuario conectado." << std::endl;
        }
    }

    // Funcion para crear un usuario
    void crearUsuario(std::string nombre, std::string password)
    {
        User usuario(nombre, password, "Usuario");
        listaUsuarios.push_back(usuario);
    }
};

#endif