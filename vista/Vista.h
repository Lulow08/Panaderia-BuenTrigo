/*
    Proyecto: Panaderia el Buen Trigo
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    
    Información CRC:

    Clase: Vista

    Responsabilidades:
        - Mostrar menús específicos para cada tipo de usuario
        - Presentar mensajes, alertas, errores y confirmaciones
        - Capturar entradas del usuario (opciones, texto, números)
        - Gestionar la interfaz de consola (limpiar, pausar)
        - Formatear y mostrar información de forma legible

    Colaboradores:
        - Controlador: es usado para mostrar información y capturar entradas
        - Usuario: usa para mostrar menús según el tipo de usuario

    @details
    Componente Vista del patrón MVC. Maneja toda la interacción con el usuario.
    No contiene lógica de negocio, solo presentación y captura de datos.

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