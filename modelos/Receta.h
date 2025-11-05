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