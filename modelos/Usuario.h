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