/*
    Proyecto: Panaderia el Buen Trigo
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    
    Información CRC:

    Clase: Usuario

    Responsabilidades:
        - Definir la estructura común para todos los tipos de usuario
        - Almacenar nombre y tipo de usuario
        - Proporcionar métodos para consultar información del usuario
        - Servir como base para herencia de roles específicos

    Colaboradores:
        - Controlador: es usado para determinar permisos y menús
        - Vista: usa para mostrar información según tipo de usuario

    @details
    Implementa herencia para tres tipos de usuario: Panadero, EncargadoInventario y Administrador.
    Cada clase derivada representa un rol con permisos específicos en el sistema.

    Autores:
    Lesly Zapata
    Yostin Ramirez
    Juan Manuel Rosero
    Joseph Terreros
    Juan Esteban Mina

    Correos:
    lesly.zapata@correounivalle.edu.co
    yostin.ramirez@correounivalle.edu.co
    joseph.terreros@correounivalle.edu.co
    juan.encarnacion@correounivalle.edu.co
    juan.esteban.mina@correounivalle.edu.co

    @date Fecha: Noviembre 2025
*/

#pragma once

#include <string>

// Enum para facilitar la selección del tipo de usuario
enum TipoUsuario {
    PANADERO,
    ENCARGADO_INVENTARIO,
    ADMINISTRADOR
};

class Usuario {
protected:
    std::string nombre;
    TipoUsuario tipo;

public:
    Usuario(std::string nombre, TipoUsuario tipo);
    virtual ~Usuario() = default;
    
    std::string getNombre() const;
    TipoUsuario getTipo() const;
    std::string getTipoStr() const;
};

class Panadero : public Usuario {
public:
    Panadero(std::string nombre);
};

class EncargadoInventario : public Usuario {
public:
    EncargadoInventario(std::string nombre);
};

class Administrador : public Usuario {
public:
    Administrador(std::string nombre);
};