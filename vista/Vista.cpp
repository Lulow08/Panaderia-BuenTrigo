#include "Vista.h"
#include <iostream>
#include <limits>

void Vista::mostrarMensaje(std::string mensaje) const {
    std::cout << mensaje << std::endl;
}

void Vista::mostrarError(std::string mensaje) const {
    std::cout << "[ERROR] " << mensaje << std::endl;
}

void Vista::mostrarExito(std::string mensaje) const {
    std::cout << "[EXITO] " << mensaje << std::endl;
}

void Vista::mostrarAlerta(std::string mensaje) const {
    std::cout << "[ALERTA] " << mensaje << std::endl;
}

void Vista::limpiarPantalla() const {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void Vista::pausar() const {
    std::cout << "\nPresione Enter para continuar...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void Vista::mostrarMenuSeleccionUsuario() const {
    std::cout << "\n========================================\n";
    std::cout << "      PANADERIA EL BUEN TRIGO\n";
    std::cout << "========================================\n";
    std::cout << "Seleccione tipo de usuario:\n";
    std::cout << "1. Panadero\n";
    std::cout << "2. Encargado de Inventario\n";
    std::cout << "3. Administrador\n";
    std::cout << "0. Salir\n";
    std::cout << "Opcion: ";
}

void Vista::mostrarMenuPanadero() const {
    std::cout << "\n========================================\n";
    std::cout << "         MENU PANADERO\n";
    std::cout << "========================================\n";
    std::cout << "1. Registrar receta\n";
    std::cout << "2. Agregar ingrediente a receta\n";
    std::cout << "3. Modificar ingrediente de receta\n";
    std::cout << "4. Eliminar receta\n";
    std::cout << "5. Ver recetas\n";
    std::cout << "6. Registrar produccion\n";
    std::cout << "7. Consultar stock de panes\n";
    std::cout << "0. Volver\n";
    std::cout << "Opcion: ";
}

void Vista::mostrarMenuEncargadoInventario() const {
    std::cout << "\n========================================\n";
    std::cout << "    MENU ENCARGADO DE INVENTARIO\n";
    std::cout << "========================================\n";
    std::cout << "1. Registrar ingrediente\n";
    std::cout << "2. Modificar cantidad de ingrediente\n";
    std::cout << "3. Eliminar ingrediente\n";
    std::cout << "4. Consultar inventario\n";
    std::cout << "5. Ver alertas de reposicion\n";
    std::cout << "6. Ver resumen completo\n";
    std::cout << "0. Volver\n";
    std::cout << "Opcion: ";
}

void Vista::mostrarMenuAdministrador() const {
    std::cout << "\n========================================\n";
    std::cout << "         MENU ADMINISTRADOR\n";
    std::cout << "========================================\n";
    std::cout << "1. Ver resumen completo\n";
    std::cout << "2. Exportar reporte a archivo\n";
    std::cout << "3. Consultar stock de panes\n";
    std::cout << "4. Consultar inventario\n";
    std::cout << "0. Volver\n";
    std::cout << "Opcion: ";
}

int Vista::leerOpcion() const {
    int opcion;
    std::cin >> opcion;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return opcion;
}

std::string Vista::leerTexto(std::string prompt) const {
    std::cout << prompt;
    std::string texto;
    std::getline(std::cin, texto);
    return texto;
}

double Vista::leerDouble(std::string prompt) const {
    std::cout << prompt;
    double valor;
    std::cin >> valor;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return valor;
}

int Vista::leerEntero(std::string prompt) const {
    std::cout << prompt;
    int valor;
    std::cin >> valor;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return valor;
}