/*
    Proyecto: Panaderia el Buen Trigo
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    
    Información CRC:

    Clase: Panaderia

    Responsabilidades:
        - Coordinar todas las operaciones del sistema (clase principal del Modelo)
        - Gestionar el inventario de ingredientes
        - Administrar las recetas de panes
        - Controlar el stock de productos terminados
        - Validar disponibilidad de ingredientes antes de producir
        - Ejecutar el proceso de producción descontando ingredientes
        - Generar reportes completos del estado del sistema
        - Proporcionar alertas de reposición

    Colaboradores:
        - Inventario: contiene y delega la gestión de ingredientes
        - Stock: contiene y delega el control de productos terminados
        - Receta: contiene y gestiona múltiples recetas
        - Ingrediente: usa para verificar disponibilidad
        - Controlador: es usado para ejecutar la lógica de negocio

    @details
    Clase central del patrón MVC (Modelo). Implementa composición con Inventario, Stock y Receta.
    Responsable de la lógica de producción y validación de recursos.

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

#include "Inventario.h"
#include "Stock.h"
#include "Receta.h"
#include <map>
#include <string>
#include <vector>

class Panaderia {
private:
    Inventario inventario;
    Stock stock;
    std::map<std::string, Receta*> recetas;

public:
    ~Panaderia();
    
    // Gestión de ingredientes
    bool agregarIngrediente(std::string nombre, std::string unidadMedida, double cantidad, double nivelMinimo);
    bool modificarIngrediente(std::string nombre, double cantidad);
    bool eliminarIngrediente(std::string nombre);
    Inventario& getInventario();
    
    // Gestión de recetas
    bool agregarReceta(std::string nombrePan);
    bool eliminarReceta(std::string nombrePan);
    bool agregarIngredienteAReceta(std::string nombrePan, std::string nombreIngrediente, double cantidad);
    bool modificarIngredienteDeReceta(std::string nombrePan, std::string nombreIngrediente, double cantidad);
    bool eliminarIngredienteDeReceta(std::string nombrePan, std::string nombreIngrediente);
    Receta* buscarReceta(std::string nombrePan);
    std::map<std::string, Receta*> obtenerTodasLasRecetas() const;
    
    // Producción
    bool producirPan(std::string nombrePan, int cantidadUnidades);
    bool verificarDisponibilidadParaProduccion(std::string nombrePan, int cantidadUnidades);
    
    // Consultas de stock
    Stock& getStock();
    int consultarStockPan(std::string nombrePan) const;
    
    // Alertas y reportes
    std::vector<Ingrediente*> obtenerAlertasReposicion() const;
    std::string generarReporteCompleto() const;
};