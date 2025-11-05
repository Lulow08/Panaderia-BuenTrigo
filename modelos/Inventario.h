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