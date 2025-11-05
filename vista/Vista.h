#pragma once

#include "Usuario.h"
#include <string>

class Vista {
public:
    void mostrarMensaje(std::string mensaje) const;
    void mostrarError(std::string mensaje) const;
    void mostrarExito(std::string mensaje) const;
    void mostrarAlerta(std::string mensaje) const;
    void limpiarPantalla() const;
    void pausar() const;
    
    void mostrarMenuSeleccionUsuario() const;
    void mostrarMenuPanadero() const;
    void mostrarMenuEncargadoInventario() const;
    void mostrarMenuAdministrador() const;
    
    int leerOpcion() const;
    std::string leerTexto(std::string prompt) const;
    double leerDouble(std::string prompt) const;
    int leerEntero(std::string prompt) const;
};