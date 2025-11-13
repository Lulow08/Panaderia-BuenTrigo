/*
    Link de proyecto: Panaderia-BuenTrigo
    https://github.com/Lulow08/Panaderia-BuenTrigo.git
*/

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
    
    // Datos de prueba iniciales y/o ejemplos para tests o referencias de formato para agregar ingredientes y recetas

    /*
    panaderia.agregarIngrediente("Harina", "kg", 50.0, 10.0);
    panaderia.agregarIngrediente("Azucar", "kg", 20.0, 5.0);
    panaderia.agregarIngrediente("Mantequilla", "kg", 15.0, 3.0);
    
    // Recetas de ejemplo
    panaderia.agregarReceta("Almojabana");
    panaderia.agregarIngredienteAReceta("Almojabana", "Harina", 0.5);
    
    panaderia.agregarReceta("Buñuelo");
    panaderia.agregarIngredienteAReceta("Buñuelo", "Harina", 0.4);
    panaderia.agregarIngredienteAReceta("Buñuelo", "Mantequilla", 0.2);
    */
    
    // Iniciar el sistema
    vista.mostrarMensaje("Bienvenido al Sistema de Gestion de Panaderia El Buen Trigo");
    controlador.iniciar();
    
    return 0;
}