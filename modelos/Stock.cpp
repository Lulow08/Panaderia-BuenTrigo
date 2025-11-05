#include "Stock.h"

void Stock::agregarPanes(std::string nombrePan, int cantidad) {
    panesDisponibles[nombrePan] += cantidad;
}

int Stock::obtenerCantidad(std::string nombrePan) const {
    auto it = panesDisponibles.find(nombrePan);
    if (it != panesDisponibles.end()) {
        return it->second;
    }
    return 0;
}

bool Stock::hayStock(std::string nombrePan) const {
    return obtenerCantidad(nombrePan) > 0;
}

std::map<std::string, int> Stock::obtenerTodoElStock() const {
    return panesDisponibles;
}