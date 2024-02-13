#include <fstream>
#include <list>
#include <iostream>
#include <string>
#include "evento.h"

// Getter para obtener la lista completa de strings
std::list<std::string> Evento::getNombresPonentes()
{
    return nombresPonentes_;
}

// Setter para establecer la lista completa de strings
void Evento::setNombresPonentes(std::list<std::string> ponentes)
{
    nombresPonentes_ = ponentes;
}

// Función para agregar un nuevo string a la lista
void Evento::addNombresPonentes(std::string ponentes)
{
    nombresPonentes_.push_back(ponentes);
}

// Getter para obtener la lista completa de strings
std::list<std::string> Evento::getNombresAsistentes()
{
    return nombresAsistentes_;
}

// Setter para establecer la lista completa de strings
void Evento::setNombresAsistentes(std::list<std::string> asistentes)
{
    nombresAsistentes_ = asistentes;
}

// Función para agregar un nuevo string a la lista
void Evento::addNombresAsistentes(std::string asistentes)
{
    nombresAsistentes_.push_back(asistentes);
}

// Getter para obtener la lista completa de strings
std::list<std::string> Evento::getNombresInscritos()
{
    return nombresInscritos_;
}

// Setter para establecer la lista completa de strings
void Evento::setNombresInscritos(std::list<std::string> inscritos)
{
    nombresInscritos_ = inscritos;
}

// Función para agregar un nuevo string a la lista
void Evento::addNombresInscritos(std::string inscritos)
{
    nombresInscritos_.push_back(inscritos);
}

// Getter para obtener la lista completa de strings
std::list<std::string> Evento::getNombresPreinscritos()
{
    return nombresPreinscritos_;
}

// Setter para establecer la lista completa de strings
void Evento::setNombresPreinscritos(std::list<std::string> preinscritos)
{
    nombresPreinscritos_ = preinscritos;
}

// Función para agregar un nuevo string a la lista
void Evento::addNombresPreinscritos(std::string preinscritos)
{
    nombresPreinscritos_.push_back(preinscritos);
}

// Funcion que me imprime las variables del evento
void Evento::getEventos()
{
    int i = 0;
    std::cout << "Nombre: " << nombre_ << std::endl;
    std::cout << "FechaInicio: " << fechaInicio_ << std::endl;
    std::cout << "FechaCierre: " << fechaCierre_ << std::endl;
    if (habilitado_ == true)
    {
        std::cout << "Habilitado: true" << std::endl;
    }
    else
    {
        std::cout << "Habilitado: false" << std::endl;
    }
    std::cout << "Aforo: " << std::to_string(aforo_) << std::endl;
    std::cout << "Ubicacion: " << ubicacion_ << std::endl;
    std::cout << "Tematica: " << tematica_ << std::endl;
    std::cout << "Precio: " << std::to_string(precio_) << std::endl;
    std::cout << "Categoria: " << categoria_ << std::endl;
    std::cout << "Organizador: " << nombreCreador_ << std::endl;
    std::cout << "Director Academico: " << nombreDirectorAcademico_ << std::endl;
    for (auto it = nombresPonentes_.begin(); it != nombresPonentes_.end(); it++)
    {
        std::cout << "Ponente " << i << ": " << (*it) << std::endl;
        i++;
    }
    i = 0;
    for (auto it = nombresAsistentes_.begin(); it != nombresAsistentes_.end(); it++)
    {
        std::cout << "Asistente " << i << ": " << (*it) << std::endl;
        i++;
    }
    i = 0;
    for (auto it = nombresInscritos_.begin(); it != nombresInscritos_.end(); it++)
    {
        std::cout << "Inscrito " << i << ": " << (*it) << std::endl;
        i++;
    }
    i = 0;
    for (auto it = nombresPreinscritos_.begin(); it != nombresPreinscritos_.end(); it++)
    {
        std::cout << "Preinscrito " << i << ": " << (*it) << std::endl;
        i++;
    }
    std::cout << "/****************************************************************************************************/" << std::endl;
}