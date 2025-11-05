#include "Usuario.h"

Usuario::Usuario(std::string nombre, TipoUsuario tipo) : nombre(nombre), tipo(tipo) {}

std::string Usuario::getNombre() const {
    return nombre;
}

TipoUsuario Usuario::getTipo() const {
    return tipo;
}

std::string Usuario::getTipoStr() const {
    switch(tipo) {
        case PANADERO: return "Panadero";
        case ENCARGADO_INVENTARIO: return "Encargado de Inventario";
        case ADMINISTRADOR: return "Administrador";
        default: return "Desconocido";
    }
}

Panadero::Panadero(std::string nombre) : Usuario(nombre, PANADERO) {}

EncargadoInventario::EncargadoInventario(std::string nombre) : Usuario(nombre, ENCARGADO_INVENTARIO) {}

Administrador::Administrador(std::string nombre) : Usuario(nombre, ADMINISTRADOR) {}