/*
    Proyecto: Panaderia el Buen Trigo
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    
    Información CRC:

    Clase: Controlador

    Responsabilidades:
        - Coordinar la interacción entre el Modelo (Panaderia) y la Vista
        - Gestionar el flujo de ejecución del programa
        - Manejar la selección y cambio de tipo de usuario
        - Implementar la lógica de cada opción de los menús
        - Validar entradas y ejecutar operaciones según el rol del usuario
        - Mostrar menús específicos para cada tipo de usuario
        - Capturar datos del usuario y procesarlos

    Colaboradores:
        - Panaderia: usa para ejecutar operaciones del modelo
        - Vista: usa para mostrar información y capturar datos
        - Usuario: gestiona para determinar permisos y menús
        - Receta: usa indirectamente a través de Panaderia
        - Inventario: usa indirectamente a través de Panaderia
        - Stock: usa indirectamente a través de Panaderia

    @details
    Componente Controlador del patrón MVC. Intermediario entre Vista y Modelo.
    Implementa toda la lógica de las historias de usuario según el rol activo.

    Autores:
    Lesly Zapata
    Yostin Ramirez
    Juan Manuel Rosero
    Joseph Terreros
    Juan Esteban Mina

    Correos:
    lesly.zapata@correounivalle.edu.co
    yostin.ramirez@correounivalle.edu.co
    joseph.terreros@correounivalle.edu.co
    juan.encarnacion@correounivalle.edu.co
    juan.esteban.mina@correounivalle.edu.co

    @date Fecha: Noviembre 2025
*/

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