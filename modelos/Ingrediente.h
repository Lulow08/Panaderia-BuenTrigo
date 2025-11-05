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