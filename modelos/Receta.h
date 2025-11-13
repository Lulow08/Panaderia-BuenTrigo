/*
    Proyecto: Panaderia el Buen Trigo
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    
    Información CRC:

    Clase: Receta

    Responsabilidades:
        - Almacenar el nombre del tipo de pan
        - Gestionar la lista de ingredientes necesarios y sus cantidades
        - Permitir agregar, modificar y eliminar ingredientes de la receta
        - Proporcionar información sobre los ingredientes requeridos
        - Validar la existencia de ingredientes en la receta

    Colaboradores:
        - Panaderia: es contenida y gestionada por esta clase
        - Ingrediente: conoce por nombre para definir las proporciones

    @details
    Define las proporciones de ingredientes necesarios para producir una unidad de pan.
    Utiliza un mapa para asociar nombres de ingredientes con cantidades específicas.

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
#include <map>

class Receta {
private:
    std::string nombrePan;
    std::map<std::string, double> ingredientes; // nombre ingrediente -> cantidad

public:
    Receta(std::string nombrePan);
    
    std::string getNombrePan() const;
    std::map<std::string, double> getIngredientes() const;
    
    void agregarIngrediente(std::string nombreIngrediente, double cantidad);
    void modificarIngrediente(std::string nombreIngrediente, double cantidad);
    void eliminarIngrediente(std::string nombreIngrediente);
    bool tieneIngrediente(std::string nombreIngrediente) const;
    double getCantidadIngrediente(std::string nombreIngrediente) const;
};