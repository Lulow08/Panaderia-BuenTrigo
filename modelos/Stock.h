/*
    Proyecto: Panaderia el Buen Trigo
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    
    Información CRC:

    Clase: Stock

    Responsabilidades:
        - Almacenar las cantidades de panes terminados por tipo
        - Incrementar el stock cuando se producen panes
        - Consultar la cantidad disponible de cada tipo de pan
        - Verificar si hay stock disponible de un pan específico
        - Proporcionar el listado completo de productos terminados

    Colaboradores:
        - Panaderia: es contenido y usado para registrar productos terminados

    @details
    Gestiona únicamente productos finales listos para la venta.
    No maneja la lógica de producción, solo el registro de cantidades.

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