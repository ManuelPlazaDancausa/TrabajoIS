#ifndef DIRECTORACADEMICO_H
#define DIRECTORACADEMICO_H

#include "global.h"
#include "evento.h"
#include "user.h"
#include <string>
#include <list>

using namespace std;

class DirectorAcademico : public User
{

public:
    void modificarEvento(string nombre)
    {
        for (auto it = listaEventos.begin(); it != listaEventos.end(); ++it)
        {
            if (it->getNombre() == nombre)
            {
                string var = "";
                int varInt = 0;
                float varFlo = 0.0;
                std::string fi;
                std::string fc;
                std::string a;
                std::string u;
                std::string t;
                std::string p;
                std::string c;
                cout << "******************************************" << endl;
                cout << "*                                        *" << endl;
                cout << "* ¡MENU DE ASIGNACIÓN DE DATOS DE EVENTO!*" << endl;
                cout << "*                                        *" << endl;
                cout << "******************************************" << endl;
                cout << "" << endl;
                do
                {
                    std::cout << "Ingresa la fecha de inicio: " << std::endl;
                    std::getline(std::cin, fi);
                } while (fi.empty());
                it->setFechaInicio(fi);
                do
                {
                    std::cout << "Ingresa la fecha de cierre: " << std::endl;
                    std::getline(std::cin, fc);
                } while (fc.empty());
                it->setFechaCierre(fc);
                do
                {
                    std::cout << "Ingresa el aforo: " << std::endl;
                    std::getline(std::cin, a);
                } while (a.empty());
                it->setAforo(stoi(a));
                do
                {
                    std::cout << "Ingresa la ubicacion: " << std::endl;
                    std::getline(std::cin, u);
                } while (u.empty());
                it->setUbicacion(u);
                do
                {
                    std::cout << "Ingresa la tematica: " << std::endl;
                    std::getline(std::cin, t);
                } while (t.empty());
                it->setTematica(t);
                do
                {
                    std::cout << "Ingresa el precio: " << std::endl;
                    std::getline(std::cin, p);
                } while (p.empty());
                it->setPrecio(stof(p));
                do
                {
                    std::cout << "Ingresa la categoria: " << std::endl;
                    std::getline(std::cin, c);
                } while (c.empty());
                it->setCategoria(c);
            }
        }
    }

    void habilitar_desahabilitar_Evento(Evento evento, bool habilitado)
    {
        for (auto it = listaEventos.begin(); it != listaEventos.end(); ++it)
        {
            if (it->getNombre() == evento.getNombre())
            {
                it->setHabilitado(habilitado);
            }
        }
    }

    void checkListEvento(string nombreEvento)
    {
        int var =0;
        cout << "******************************************" << endl;
        cout << "*                                        *" << endl;
        cout << "*   ¡MENU PARA PASAR LISTA DE EVENTO!    *" << endl;
        cout << "*                                        *" << endl;
        cout << "******************************************" << endl;
        cout << "" << endl;
        for (auto it = listaEventos.begin(); it != listaEventos.end(); ++it)
        {
            if (it->getNombre() == nombreEvento)
            {
                list<string> aux;
                aux=it->getNombresInscritos();
                for (auto et = aux.begin(); et != aux.end(); et++)
                {
                    cout << "El usuario " << (*et) << ", "
                         << "¿Ha asistido? (Ingrese 1 en caso afirmativo o ingrese cualquier otra cosa en caso contrario)" << endl;
                    cin >> var;
                    if (var == 1)
                    {
                        it->addNombresAsistentes(*et);

                        // No se si al volcar de ina lista a otra borrar de la incial. No tiene sentido no?
                        // it->getNombresInscritos().erase(et);
                    }
                }
                std::cout << "FIN DE LA LISTA DE ASISTENTES" << std::endl;
            }
        }
    }

    void inscripcionEvento(string nombreEvento)
    {
        int var=0;
        cout << "******************************************" << endl;
        cout << "*                                        *" << endl;
        cout << "*  ¡MENU DE INTRODUCCION DE ASISTENTES!  *" << endl;
        cout << "*                                        *" << endl;
        cout << "******************************************" << endl;
        cout << "" << endl;
        for (auto it = listaEventos.begin(); it != listaEventos.end(); ++it)
        {
            if (it->getNombre() == nombreEvento)
            {
                list<string> aux;
                aux=it->getNombresPreinscritos();
                for (auto et = aux.begin(); et != aux.end();)
                {
                    cout << "El usuario " << (*et) << ", "
                         << "¿Autoriza a asistir? (Ingrese 1 en caso afirmativo o ingrese cualquier otra cosa en caso contrario)" << endl;
                    cin >> var;
                    if (var == 1)
                    {
                        it->addNombresInscritos(*et);
                        et=aux.erase(et);
                        // No se si eliminar al usuario de la lista de preinscritos. Si quisiera tendria que hace una funcion delete
                        // que no esta en la clase evento
                    }
                    else
                    {
                        et++;
                    }
                }
                it->setNombresPreinscritos(aux);
            }
        }
    }
};

#endif