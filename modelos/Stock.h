#pragma once

#include <map>
#include <string>

class Stock {
private:
    std::map<std::string, int> panesDisponibles; // nombre pan -> cantidad

public:
    void agregarPanes(std::string nombrePan, int cantidad);
    int obtenerCantidad(std::string nombrePan) const;
    bool hayStock(std::string nombrePan) const;
    std::map<std::string, int> obtenerTodoElStock() const;
};