/*
    Proyecto: Panaderia el Buen Trigo
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    
    Información CRC:

    Clase: Inventario

    Responsabilidades:
        - Gestionar la colección completa de ingredientes
        - Agregar, modificar y eliminar ingredientes del sistema
        - Buscar ingredientes por nombre
        - Consumir ingredientes durante la producción
        - Identificar ingredientes con stock bajo
        - Proporcionar listados completos del inventario

    Colaboradores:
        - Panaderia: es contenido y usado por esta clase para gestionar materias primas
        - Ingrediente: contiene y administra el ciclo de vida de múltiples instancias

    @details
    Implementa composición con Ingrediente, siendo responsable de la gestión de memoria.
    Utiliza un mapa para acceso rápido a ingredientes por nombre.

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

#include "Ingrediente.h"
#include <map>
#include <string>
#include <vector>

class Inventario {
private:
    std::map<std::string, Ingrediente*> ingredientes;

public:
    ~Inventario();
    
    bool agregarIngrediente(std::string nombre, std::string unidadMedida, double cantidad, double nivelMinimo);
    bool modificarIngrediente(std::string nombre, double cantidad);
    bool eliminarIngrediente(std::string nombre);
    
    Ingrediente* buscarIngrediente(std::string nombre);
    bool existeIngrediente(std::string nombre) const;
    
    bool consumirIngrediente(std::string nombre, double cantidad);
    std::vector<Ingrediente*> obtenerIngredientesBajosDeStock() const;
    std::map<std::string, Ingrediente*> obtenerTodosLosIngredientes() const;
};