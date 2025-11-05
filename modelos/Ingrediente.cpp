#include "Ingrediente.h"

Ingrediente::Ingrediente(std::string nombre, std::string unidadMedida, double cantidadDisponible, double nivelMinimo)
    : nombre(nombre), unidadMedida(unidadMedida), cantidadDisponible(cantidadDisponible), nivelMinimo(nivelMinimo) {}

std::string Ingrediente::getNombre() const {
    return nombre;
}

std::string Ingrediente::getUnidadMedida() const {
    return unidadMedida;
}

double Ingrediente::getCantidadDisponible() const {
    return cantidadDisponible;
}

double Ingrediente::getNivelMinimo() const {
    return nivelMinimo;
}

void Ingrediente::setNombre(std::string nombre) {
    this->nombre = nombre;
}

void Ingrediente::setUnidadMedida(std::string unidadMedida) {
    this->unidadMedida = unidadMedida;
}

void Ingrediente::setCantidadDisponible(double cantidad) {
    this->cantidadDisponible = cantidad;
}

void Ingrediente::setNivelMinimo(double nivel) {
    this->nivelMinimo = nivel;
}

void Ingrediente::agregarCantidad(double cantidad) {
    cantidadDisponible += cantidad;
}

bool Ingrediente::restarCantidad(double cantidad) {
    if (cantidadDisponible >= cantidad) {
        cantidadDisponible -= cantidad;
        return true;
    }
    return false;
}

bool Ingrediente::estaDebajoDeLimite() const {
    return cantidadDisponible < nivelMinimo;
}