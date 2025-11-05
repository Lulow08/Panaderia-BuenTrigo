#include "Receta.h"

Receta::Receta(std::string nombrePan) : nombrePan(nombrePan) {}

std::string Receta::getNombrePan() const {
    return nombrePan;
}

std::map<std::string, double> Receta::getIngredientes() const {
    return ingredientes;
}

void Receta::agregarIngrediente(std::string nombreIngrediente, double cantidad) {
    ingredientes[nombreIngrediente] = cantidad;
}

void Receta::modificarIngrediente(std::string nombreIngrediente, double cantidad) {
    if (ingredientes.find(nombreIngrediente) != ingredientes.end()) {
        ingredientes[nombreIngrediente] = cantidad;
    }
}

void Receta::eliminarIngrediente(std::string nombreIngrediente) {
    ingredientes.erase(nombreIngrediente);
}

bool Receta::tieneIngrediente(std::string nombreIngrediente) const {
    return ingredientes.find(nombreIngrediente) != ingredientes.end();
}

double Receta::getCantidadIngrediente(std::string nombreIngrediente) const {
    auto it = ingredientes.find(nombreIngrediente);
    if (it != ingredientes.end()) {
        return it->second;
    }
    return 0.0;
}