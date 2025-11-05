#include "Inventario.h"

Inventario::~Inventario() {
    for (auto& par : ingredientes) {
        delete par.second;
    }
}

bool Inventario::agregarIngrediente(std::string nombre, std::string unidadMedida, double cantidad, double nivelMinimo) {
    if (ingredientes.find(nombre) != ingredientes.end()) {
        return false; // Ya existe
    }
    ingredientes[nombre] = new Ingrediente(nombre, unidadMedida, cantidad, nivelMinimo);
    return true;
}

bool Inventario::modificarIngrediente(std::string nombre, double cantidad) {
    auto it = ingredientes.find(nombre);
    if (it != ingredientes.end()) {
        it->second->setCantidadDisponible(cantidad);
        return true;
    }
    return false;
}

bool Inventario::eliminarIngrediente(std::string nombre) {
    auto it = ingredientes.find(nombre);
    if (it != ingredientes.end()) {
        delete it->second;
        ingredientes.erase(it);
        return true;
    }
    return false;
}

Ingrediente* Inventario::buscarIngrediente(std::string nombre) {
    auto it = ingredientes.find(nombre);
    if (it != ingredientes.end()) {
        return it->second;
    }
    return nullptr;
}

bool Inventario::existeIngrediente(std::string nombre) const {
    return ingredientes.find(nombre) != ingredientes.end();
}

bool Inventario::consumirIngrediente(std::string nombre, double cantidad) {
    auto it = ingredientes.find(nombre);
    if (it != ingredientes.end()) {
        return it->second->restarCantidad(cantidad);
    }
    return false;
}

std::vector<Ingrediente*> Inventario::obtenerIngredientesBajosDeStock() const {
    std::vector<Ingrediente*> bajos;
    for (const auto& par : ingredientes) {
        if (par.second->estaDebajoDeLimite()) {
            bajos.push_back(par.second);
        }
    }
    return bajos;
}

std::map<std::string, Ingrediente*> Inventario::obtenerTodosLosIngredientes() const {
    return ingredientes;
}