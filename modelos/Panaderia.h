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