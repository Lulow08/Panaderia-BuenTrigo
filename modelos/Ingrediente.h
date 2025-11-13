/*
    Proyecto: Panaderia el Buen Trigo
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    Información CRC:

    Clase: Ingrediente

    Responsabilidades:
        - Almacenar información de un ingrediente individual (nombre, unidad, cantidad)
        - Gestionar la cantidad disponible del ingrediente
        - Controlar el nivel mínimo de stock
        - Notificar cuando la cantidad está por debajo del nivel mínimo
        - Permitir agregar o restar cantidades
    Colaboradores:

        - Inventario: es contenido y gestionado por esta clase

    @details
    Representa una materia prima básica utilizada en la producción de pan.
    Implementa el sistema de alertas mediante la comparación con el nivel mínimo.

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

class Ingrediente {
private:
    std::string nombre;
    std::string unidadMedida;
    double cantidadDisponible;
    double nivelMinimo;

public:
    Ingrediente(std::string nombre, std::string unidadMedida, double cantidadDisponible, double nivelMinimo);
    
    std::string getNombre() const;
    std::string getUnidadMedida() const;
    double getCantidadDisponible() const;
    double getNivelMinimo() const;
    
    void setNombre(std::string nombre);
    void setUnidadMedida(std::string unidadMedida);
    void setCantidadDisponible(double cantidad);
    void setNivelMinimo(double nivel);
    
    void agregarCantidad(double cantidad);
    bool restarCantidad(double cantidad);
    bool estaDebajoDeLimite() const;
};