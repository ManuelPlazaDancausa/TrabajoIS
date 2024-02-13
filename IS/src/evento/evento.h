#ifndef EVENTO_H
#define EVENTO_H

#include <fstream>
#include <list>
#include <iostream>
#include <string>

class Evento
{
private:
    std::string nombre_;
    std::string fechaInicio_;
    std::string fechaCierre_;
    bool habilitado_;
    int aforo_;
    std::string ubicacion_;
    std::string tematica_;
    float precio_;
    std::string categoria_;
    std::string nombreCreador_;
    std::string nombreDirectorAcademico_;
    std::list<std::string> nombresPonentes_;
    std::list<std::string> nombresAsistentes_;
    std::list<std::string> nombresInscritos_;
    std::list<std::string> nombresPreinscritos_;

public:
    Evento(std::string nombre = "empty", std::string fechaInicio = "00/00/0000", std::string fechaCierre = "00/00/0000", bool habilitado=false, int aforo = 0, std::string ubicacion = "empty", std::string tematica = "empty", float precio = 0.0, std::string categoria = "empty", std::string nombreCreador = "empty", std::string nombreDirectorAcademico = "empty")
    {
        // Inicialización de variables en el constructor por defecto
        nombre_ = nombre;
        fechaInicio_ = fechaInicio;
        fechaCierre_ = fechaCierre;
        habilitado_=habilitado;
        aforo_ = aforo;
        ubicacion_ = ubicacion;
        tematica_ = tematica;
        precio_ = precio;
        categoria_ = categoria;
        nombreCreador_ = nombreCreador;
        nombreDirectorAcademico_ = nombreDirectorAcademico;
    }

    // Getters
    std::string getNombre() { return nombre_; }
    std::string getFechaInicio() { return fechaInicio_; }
    std::string getFechaCierre() { return fechaCierre_; }
    bool getHabilitado(){return habilitado_;}
    int getAforo() { return aforo_; }
    std::string getUbicacion() { return ubicacion_; }
    std::string getTematica() { return tematica_; }
    float getPrecio() { return precio_; }
    std::string getCategoria() { return categoria_; }
    std::string getNombreCreador() { return nombreCreador_; }
    std::string getNombreDirectorAcademico() { return nombreDirectorAcademico_; }
    void getEventos();

    std::list<std::string> getNombresPonentes();
    std::list<std::string> getNombresAsistentes();
    std::list<std::string> getNombresInscritos();
    std::list<std::string> getNombresPreinscritos();

    // Setters
    void setNombre(std::string nombre) { nombre_ = nombre; }
    void setFechaInicio(std::string fechaInicio) { fechaInicio_ = fechaInicio; }
    void setFechaCierre(std::string fechaCierre) { fechaCierre_ = fechaCierre; }
    void setHabilitado(bool habilitado){habilitado_=habilitado; }
    void setAforo(int aforo) { aforo_ = aforo; }
    void setUbicacion(std::string ubicacion) { ubicacion_ = ubicacion; }
    void setTematica(std::string tematica) { tematica_ = tematica; }
    void setPrecio(float precio) { precio_ = precio; }
    void setCategoria(std::string categoria) { categoria_ = categoria; }
    void setNombreCreador(std::string nombreCreador) { nombreCreador_ = nombreCreador; }
    void setNombreDirectorAcademico(std::string nombreDirectorAcademico) { nombreDirectorAcademico_ = nombreDirectorAcademico; }

    void setNombresPonentes(std::list<std::string> ponentes);
    void setNombresAsistentes(std::list<std::string> asistentes);
    void setNombresInscritos(std::list<std::string> inscritos);
    void setNombresPreinscritos(std::list<std::string> preinscritos);

   // Adders para las listas
    void addNombresPonentes(std::string ponentes);
    void addNombresAsistentes(std::string asistentes);
    void addNombresInscritos(std::string inscritos);
    void addNombresPreinscritos(std::string preinscritos);

    void ficheroEventos(){
        std::ofstream archivo("Eventos.txt", std::ios::app);
        if (!archivo.is_open())
        {
            std::cerr << "Error al abrir el archivo de eventos para escritura." << std::endl;
            return;
        }
        archivo << nombre_ << std::endl;
            archivo << fechaInicio_ << std::endl;
            archivo << fechaCierre_ << std::endl;
            std::string texto;
            if (habilitado_)
            {
                texto = "true";
            }
            else
            {
                texto = "false";
            }
            archivo << texto << std::endl;
            archivo << aforo_ << std::endl;
            archivo << ubicacion_ << std::endl;
            archivo << tematica_ << std::endl;
            archivo << precio_ << std::endl;
            archivo << categoria_ << std::endl;
            archivo << nombreCreador_ << std::endl;
            archivo << nombreDirectorAcademico_ << std::endl;
            for (auto et = nombresPonentes_.begin(); et != nombresPonentes_.end(); ++et)
            {
                archivo << (*et); // Escribe el elemento actual

                // Si no es el último elemento, escribe el separador '|'
                if (std::next(et) != nombresPonentes_.end())
                {
                    archivo << "|";
                }
            }
            archivo << std::endl;
            for (auto et = nombresAsistentes_.begin(); et != nombresAsistentes_.end(); ++et)
            {
                archivo << (*et); // Escribe el elemento actual

                // Si no es el último elemento, escribe el separador '|'
                if (std::next(et) != nombresAsistentes_.end())
                {
                    archivo << "|";
                }
            }
            archivo << std::endl;
            for (auto et = nombresInscritos_.begin(); et != nombresInscritos_.end(); ++et)
            {
                archivo << (*et); // Escribe el elemento actual

                // Si no es el último elemento, escribe el separador '|'
                if (std::next(et) != nombresInscritos_.end())
                {
                    archivo << "|";
                }
            }
            archivo << std::endl;
            for (auto et = nombresPreinscritos_.begin(); et != nombresPreinscritos_.end(); ++et)
            {
                archivo << (*et); // Escribe el elemento actual

                // Si no es el último elemento, escribe el separador '|'
                if (std::next(et) != nombresPreinscritos_.end())
                {
                    archivo << "|";
                }
            }
            archivo << std::endl;
            archivo << "/****************************************************************************************************/" << std::endl;
        archivo.close();
    }
    void eventoClear(){
        nombresPonentes_.clear();
        nombresAsistentes_.clear();
        nombresInscritos_.clear();
        nombresPreinscritos_.clear();
    }
    std::list<std::string>::iterator InicioInscritos()
    {
        return nombresInscritos_.begin();
    }
    std::list<std::string>::iterator FinalInscritos()
    {
        return nombresInscritos_.end();
    }
    std::list<std::string>::iterator InicioPreinscritos()
    {
        return nombresPreinscritos_.begin();
    }
    std::list<std::string>::iterator FinalPreinscritos()
    {
        return nombresPreinscritos_.end();
    }
};

#endif