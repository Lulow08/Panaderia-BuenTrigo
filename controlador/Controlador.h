#pragma once

#include "Panaderia.h"
#include "Vista.h"
#include "Usuario.h"

class Controlador {
private:
    Panaderia& panaderia;
    Vista& vista;
    Usuario* usuarioActual;

public:
    Controlador(Panaderia& panaderia, Vista& vista);
    ~Controlador();
    
    void iniciar();
    void seleccionarUsuario();
    
    // Funciones para Panadero
    void menuPanadero();
    void registrarReceta();
    void agregarIngredienteAReceta();
    void modificarIngredienteDeReceta();
    void eliminarReceta();
    void verRecetas();
    void registrarProduccion();
    void consultarStockPanes();
    
    // Funciones para Encargado de Inventario
    void menuEncargadoInventario();
    void registrarIngrediente();
    void modificarIngrediente();
    void eliminarIngrediente();
    void consultarInventario();
    void verAlertasReposicion();
    void verResumenCompleto();
    
    // Funciones para Administrador
    void menuAdministrador();
    void verResumenCompletoAdmin();
    void exportarReporte();
    void consultarStockPanesAdmin();
    void consultarInventarioAdmin();
};