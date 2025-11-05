#include "Panaderia.h"
#include <sstream>
#include <iomanip>

Panaderia::~Panaderia() {
    for (auto& par : recetas) {
        delete par.second;
    }
}

bool Panaderia::agregarIngrediente(std::string nombre, std::string unidadMedida, double cantidad, double nivelMinimo) {
    return inventario.agregarIngrediente(nombre, unidadMedida, cantidad, nivelMinimo);
}

bool Panaderia::modificarIngrediente(std::string nombre, double cantidad) {
    return inventario.modificarIngrediente(nombre, cantidad);
}

bool Panaderia::eliminarIngrediente(std::string nombre) {
    return inventario.eliminarIngrediente(nombre);
}

Inventario& Panaderia::getInventario() {
    return inventario;
}

bool Panaderia::agregarReceta(std::string nombrePan) {
    if (recetas.find(nombrePan) != recetas.end()) {
        return false;
    }
    recetas[nombrePan] = new Receta(nombrePan);
    return true;
}

bool Panaderia::eliminarReceta(std::string nombrePan) {
    auto it = recetas.find(nombrePan);
    if (it != recetas.end()) {
        delete it->second;
        recetas.erase(it);
        return true;
    }
    return false;
}

bool Panaderia::agregarIngredienteAReceta(std::string nombrePan, std::string nombreIngrediente, double cantidad) {
    auto it = recetas.find(nombrePan);
    if (it != recetas.end()) {
        it->second->agregarIngrediente(nombreIngrediente, cantidad);
        return true;
    }
    return false;
}

bool Panaderia::modificarIngredienteDeReceta(std::string nombrePan, std::string nombreIngrediente, double cantidad) {
    auto it = recetas.find(nombrePan);
    if (it != recetas.end()) {
        it->second->modificarIngrediente(nombreIngrediente, cantidad);
        return true;
    }
    return false;
}

bool Panaderia::eliminarIngredienteDeReceta(std::string nombrePan, std::string nombreIngrediente) {
    auto it = recetas.find(nombrePan);
    if (it != recetas.end()) {
        it->second->eliminarIngrediente(nombreIngrediente);
        return true;
    }
    return false;
}

Receta* Panaderia::buscarReceta(std::string nombrePan) {
    auto it = recetas.find(nombrePan);
    if (it != recetas.end()) {
        return it->second;
    }
    return nullptr;
}

std::map<std::string, Receta*> Panaderia::obtenerTodasLasRecetas() const {
    return recetas;
}

bool Panaderia::verificarDisponibilidadParaProduccion(std::string nombrePan, int cantidadUnidades) {
    Receta* receta = buscarReceta(nombrePan);
    if (!receta) return false;
    
    auto ingredientesReceta = receta->getIngredientes();
    for (const auto& par : ingredientesReceta) {
        std::string nombreIngrediente = par.first;
        double cantidadNecesaria = par.second * cantidadUnidades;
        
        Ingrediente* ingrediente = inventario.buscarIngrediente(nombreIngrediente);
        if (!ingrediente || ingrediente->getCantidadDisponible() < cantidadNecesaria) {
            return false;
        }
    }
    return true;
}

bool Panaderia::producirPan(std::string nombrePan, int cantidadUnidades) {
    if (!verificarDisponibilidadParaProduccion(nombrePan, cantidadUnidades)) {
        return false;
    }
    
    Receta* receta = buscarReceta(nombrePan);
    auto ingredientesReceta = receta->getIngredientes();
    
    for (const auto& par : ingredientesReceta) {
        std::string nombreIngrediente = par.first;
        double cantidadNecesaria = par.second * cantidadUnidades;
        inventario.consumirIngrediente(nombreIngrediente, cantidadNecesaria);
    }
    
    stock.agregarPanes(nombrePan, cantidadUnidades);
    return true;
}

Stock& Panaderia::getStock() {
    return stock;
}

int Panaderia::consultarStockPan(std::string nombrePan) const {
    return stock.obtenerCantidad(nombrePan);
}

std::vector<Ingrediente*> Panaderia::obtenerAlertasReposicion() const {
    return inventario.obtenerIngredientesBajosDeStock();
}

std::string Panaderia::generarReporteCompleto() const {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2);
    
    ss << "========================================\n";
    ss << "     REPORTE COMPLETO - EL BUEN TRIGO\n";
    ss << "========================================\n\n";
    
    ss << "--- INVENTARIO DE INGREDIENTES ---\n";
    auto ingredientes = inventario.obtenerTodosLosIngredientes();
    if (ingredientes.empty()) {
        ss << "No hay ingredientes registrados.\n";
    } else {
        for (const auto& par : ingredientes) {
            Ingrediente* ing = par.second;
            ss << "- " << ing->getNombre() << ": " 
               << ing->getCantidadDisponible() << " " 
               << ing->getUnidadMedida();
            if (ing->estaDebajoDeLimite()) {
                ss << " [ALERTA: BAJO STOCK]";
            }
            ss << "\n";
        }
    }
    
    ss << "\n--- STOCK DE PRODUCTOS TERMINADOS ---\n";
    auto stockPanes = stock.obtenerTodoElStock();
    if (stockPanes.empty()) {
        ss << "No hay panes en stock.\n";
    } else {
        for (const auto& par : stockPanes) {
            ss << "- " << par.first << ": " << par.second << " unidades\n";
        }
    }
    
    ss << "\n========================================\n";
    
    return ss.str();
}