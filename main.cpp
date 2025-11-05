#include "Panaderia.h"
#include "Vista.h"
#include "Controlador.h"
#include <iostream>

int main() {
    // Crear instancias del modelo y la vista
    Panaderia panaderia;
    Vista vista;
    
    // Crear el controlador
    Controlador controlador(panaderia, vista);
    
    // Datos de prueba iniciales
    panaderia.agregarIngrediente("Harina", "kg", 50.0, 10.0);
    panaderia.agregarIngrediente("Levadura", "g", 500.0, 100.0);
    panaderia.agregarIngrediente("Azucar", "kg", 20.0, 5.0);
    panaderia.agregarIngrediente("Sal", "g", 1000.0, 200.0);
    panaderia.agregarIngrediente("Mantequilla", "kg", 15.0, 3.0);
    panaderia.agregarIngrediente("Agua", "L", 30.0, 5.0);
    
    // Recetas de ejemplo
    panaderia.agregarReceta("Pan Blanco");
    panaderia.agregarIngredienteAReceta("Pan Blanco", "Harina", 0.5);
    panaderia.agregarIngredienteAReceta("Pan Blanco", "Levadura", 10.0);
    panaderia.agregarIngredienteAReceta("Pan Blanco", "Sal", 5.0);
    panaderia.agregarIngredienteAReceta("Pan Blanco", "Agua", 0.3);
    
    panaderia.agregarReceta("Pan Dulce");
    panaderia.agregarIngredienteAReceta("Pan Dulce", "Harina", 0.4);
    panaderia.agregarIngredienteAReceta("Pan Dulce", "Levadura", 8.0);
    panaderia.agregarIngredienteAReceta("Pan Dulce", "Azucar", 0.1);
    panaderia.agregarIngredienteAReceta("Pan Dulce", "Mantequilla", 0.05);
    panaderia.agregarIngredienteAReceta("Pan Dulce", "Agua", 0.2);
    
    // Iniciar el sistema
    vista.mostrarMensaje("Bienvenido al Sistema de Gestion de Panaderia El Buen Trigo");
    controlador.iniciar();
    
    return 0;
}