#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <fstream>
#include <list>

// Clase para representar un usuario con métodos de acceso y modificación
class User
{
private:
    std::string ID_;
    std::string Password_;
    std::string Tipo_;
    bool Log_;
    std::list<std::string> listaEventosPreinscritos_;
    std::list<std::string> listaEventosInscritos_;

public:
    User(std::string ID = "", std::string Password = "", std::string Tipo = "", bool Log = false)
    {
        ID_ = ID;
        Password_ = Password;
        Tipo_ = Tipo;
        Log_ = Log;
        listaEventosPreinscritos_.clear();
        listaEventosInscritos_.clear();
    }

    // Métodos para obtener valores de la clase
    std::string GetID() const { return ID_; }
    std::string GetPassword() const { return Password_; }
    std::string GetTipo() const { return Tipo_; }
    bool GetLog() const { return Log_; }
    std::list<std::string> GrtListaEventosPreinscritos() { return listaEventosPreinscritos_; }
    std::list<std::string> GrtListaEventosInscritos() { return listaEventosInscritos_; }

    // Métodos para establecer valores en la clase
    void SetID(std::string ID) { ID_ = ID; }
    void SetPassword(std::string Password) { Password_ = Password; }
    void SetTipo(std::string Tipo) { Tipo_ = Tipo; }
    void SetLog(bool Log) { Log_ = Log; }

    // Getter para obtener la lista completa de strings
    std::list<std::string> getListaEventosPreinscritos()
    {
        return listaEventosPreinscritos_;
    }

    // Setter para establecer la lista completa de strings
    void setListaEventosPreinscritos(std::list<std::string> listaEventosPreinscritos)
    {
        listaEventosPreinscritos_ = listaEventosPreinscritos;
    }

    // Función para agregar un nuevo string a la lista
    void addlistaEventosPreinscritos(std::string eventoPreinscrito)
    {
        listaEventosPreinscritos_.push_back(eventoPreinscrito);
    }

    // Getter para obtener la lista completa de strings
    std::list<std::string> getListaEventosInscritos()
    {
        return listaEventosInscritos_;
    }

    // Setter para establecer la lista completa de strings
    void setListaEventosInscritos(std::list<std::string> listaEventosInscritos)
    {
        listaEventosInscritos_ = listaEventosInscritos;
    }

    // Función para agregar un nuevo string a la lista
    void addlistaEventosInscritos(std::string eventoInscrito)
    {
        listaEventosInscritos_.push_back(eventoInscrito);
    }

    void mostrarEventosPreinscrito()
    {
        int i = 1;
        for (auto it = listaEventosPreinscritos_.begin(); it != listaEventosPreinscritos_.end(); it++)
        {
            std::cout << "Evento Preinscrito" << i << ": " << (*it) << std::endl;
            i++;
        }
    }

    void mostrarEventosInscrito()
    {
        int i = 1;
        for (auto it = listaEventosInscritos_.begin(); it != listaEventosInscritos_.end(); it++)
        {
            std::cout << "Evento Inscrito" << i << ": " << (*it) << std::endl;
            i++;
        }
    }

    void getUsuarios()
    {
        int i = 0;
        std::cout << "Nombre: " << ID_ << std::endl;
        std::cout << "Contraseña: " << Password_ << std::endl;
        std::cout << "Permisos: " << Tipo_ << std::endl;
        for (auto it = listaEventosPreinscritos_.begin(); it != listaEventosPreinscritos_.end(); it++)
        {
            std::cout << "Preinscrito" << i << ": " << (*it) << std::endl;
            i++;
        }
        i = 0;
        for (auto it = listaEventosInscritos_.begin(); it != listaEventosInscritos_.end(); it++)
        {
            std::cout << "Inscrito " << i << ": " << (*it) << std::endl;
            i++;
        }
        std::cout << "/****************************************************************************************************/" << std::endl;
    }

    void ficheroUsuario()
    {
        std::ofstream archivo("Usuarios.txt", std::ios::app);
        if (!archivo.is_open())
        {
            std::cerr << "Error al abrir el archivo de usuarios para escritura." << std::endl;
            return;
        }

        archivo << ID_ << std::endl;
        archivo << Password_ << std::endl;
        archivo << Tipo_ << std::endl;
        for (auto et = listaEventosPreinscritos_.begin(); et != listaEventosPreinscritos_.end(); ++et)
        {
            archivo << (*et); // Escribe el elemento actual

            // Si no es el último elemento, escribe el separador '|'
            if (std::next(et) != listaEventosPreinscritos_.end())
            {
                archivo << "|";
            }
        }
        archivo << std::endl;
        for (auto et = listaEventosInscritos_.begin(); et != listaEventosInscritos_.end(); ++et)
        {
            archivo << (*et); // Escribe el elemento actual

            // Si no es el último elemento, escribe el separador '|'
            if (std::next(et) != listaEventosInscritos_.end())
            {
                archivo << "|";
            }
        }
        archivo << std::endl;
        archivo << "/****************************************************************************************************/" << std::endl;
        archivo.close();
    }

    void userClear()
    {
        listaEventosInscritos_.clear();
        listaEventosPreinscritos_.clear();
    }

    std::list<std::string>::iterator InicioInscritos()
    {
        return listaEventosInscritos_.begin();
    }
    std::list<std::string>::iterator FinalInscritos()
    {
        return listaEventosInscritos_.end();
    }
    std::list<std::string>::iterator InicioPreinscritos()
    {
        return listaEventosPreinscritos_.begin();
    }
    std::list<std::string>::iterator FinalPreinscritos()
    {
        return listaEventosPreinscritos_.end();
    }
};

#endif