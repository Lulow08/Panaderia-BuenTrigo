#include "Controlador.h"
#include <fstream>
#include <iostream>

Controlador::Controlador(Panaderia& panaderia, Vista& vista) 
    : panaderia(panaderia), vista(vista), usuarioActual(nullptr) {}

Controlador::~Controlador() {
    if (usuarioActual) {
        delete usuarioActual;
    }
}

void Controlador::iniciar() {
    bool continuar = true;
    while (continuar) {
        vista.limpiarPantalla();
        vista.mostrarMenuSeleccionUsuario();
        int opcion = vista.leerOpcion();
        
        switch (opcion) {
            case 1:
                if (usuarioActual) delete usuarioActual;
                usuarioActual = new Panadero("Panadero");
                menuPanadero();
                break;
            case 2:
                if (usuarioActual) delete usuarioActual;
                usuarioActual = new EncargadoInventario("Encargado");
                menuEncargadoInventario();
                break;
            case 3:
                if (usuarioActual) delete usuarioActual;
                usuarioActual = new Administrador("Administrador");
                menuAdministrador();
                break;
            case 0:
                continuar = false;
                vista.mostrarMensaje("Gracias por usar el sistema!");
                break;
            default:
                vista.mostrarError("Opcion invalida");
                vista.pausar();
        }
    }
}

void Controlador::seleccionarUsuario() {
    vista.mostrarMenuSeleccionUsuario();
}

void Controlador::menuPanadero() {
    bool continuar = true;
    while (continuar) {
        vista.limpiarPantalla();
        vista.mostrarMenuPanadero();
        int opcion = vista.leerOpcion();
        
        switch (opcion) {
            case 1: registrarReceta(); break;
            case 2: agregarIngredienteAReceta(); break;
            case 3: modificarIngredienteDeReceta(); break;
            case 4: eliminarReceta(); break;
            case 5: verRecetas(); break;
            case 6: registrarProduccion(); break;
            case 7: consultarStockPanes(); break;
            case 0: continuar = false; break;
            default:
                vista.mostrarError("Opcion invalida");
                vista.pausar();
        }
    }
}

void Controlador::registrarReceta() {
    std::string nombrePan = vista.leerTexto("Nombre del pan: ");
    
    if (panaderia.agregarReceta(nombrePan)) {
        vista.mostrarExito("Receta registrada exitosamente");
    } else {
        vista.mostrarError("La receta ya existe");
    }
    vista.pausar();
}

void Controlador::agregarIngredienteAReceta() {
    std::string nombrePan = vista.leerTexto("Nombre del pan: ");
    Receta* receta = panaderia.buscarReceta(nombrePan);
    
    if (!receta) {
        vista.mostrarError("La receta no existe");
        vista.pausar();
        return;
    }
    
    std::string nombreIngrediente = vista.leerTexto("Nombre del ingrediente: ");
    
    if (!panaderia.getInventario().existeIngrediente(nombreIngrediente)) {
        vista.mostrarError("El ingrediente no existe en el inventario");
        vista.pausar();
        return;
    }
    
    double cantidad = vista.leerDouble("Cantidad por unidad de pan: ");
    
    if (panaderia.agregarIngredienteAReceta(nombrePan, nombreIngrediente, cantidad)) {
        vista.mostrarExito("Ingrediente agregado a la receta");
    } else {
        vista.mostrarError("No se pudo agregar el ingrediente");
    }
    vista.pausar();
}

void Controlador::modificarIngredienteDeReceta() {
    std::string nombrePan = vista.leerTexto("Nombre del pan: ");
    std::string nombreIngrediente = vista.leerTexto("Nombre del ingrediente: ");
    double cantidad = vista.leerDouble("Nueva cantidad: ");
    
    if (panaderia.modificarIngredienteDeReceta(nombrePan, nombreIngrediente, cantidad)) {
        vista.mostrarExito("Ingrediente modificado en la receta");
    } else {
        vista.mostrarError("No se pudo modificar el ingrediente");
    }
    vista.pausar();
}

void Controlador::eliminarReceta() {
    std::string nombrePan = vista.leerTexto("Nombre del pan a eliminar: ");
    
    if (panaderia.eliminarReceta(nombrePan)) {
        vista.mostrarExito("Receta eliminada exitosamente");
    } else {
        vista.mostrarError("La receta no existe");
    }
    vista.pausar();
}

void Controlador::verRecetas() {
    auto recetas = panaderia.obtenerTodasLasRecetas();
    
    if (recetas.empty()) {
        vista.mostrarMensaje("No hay recetas registradas");
    } else {
        vista.mostrarMensaje("\n=== RECETAS REGISTRADAS ===");
        for (const auto& par : recetas) {
            vista.mostrarMensaje("\nPan: " + par.first);
            auto ingredientes = par.second->getIngredientes();
            if (ingredientes.empty()) {
                vista.mostrarMensaje("  Sin ingredientes");
            } else {
                for (const auto& ing : ingredientes) {
                    vista.mostrarMensaje("  - " + ing.first + ": " + std::to_string(ing.second));
                }
            }
        }
    }
    vista.pausar();
}

void Controlador::registrarProduccion() {
    std::string nombrePan = vista.leerTexto("Nombre del pan: ");
    int cantidad = vista.leerEntero("Cantidad a producir: ");
    
    if (!panaderia.verificarDisponibilidadParaProduccion(nombrePan, cantidad)) {
        vista.mostrarAlerta("No hay suficientes ingredientes para producir " + std::to_string(cantidad) + " unidades");
        
        Receta* receta = panaderia.buscarReceta(nombrePan);
        if (receta) {
            vista.mostrarMensaje("\nIngredientes faltantes:");
            auto ingredientes = receta->getIngredientes();
            for (const auto& ing : ingredientes) {
                double necesaria = ing.second * cantidad;
                Ingrediente* ingrediente = panaderia.getInventario().buscarIngrediente(ing.first);
                if (ingrediente) {
                    double disponible = ingrediente->getCantidadDisponible();
                    if (disponible < necesaria) {
                        vista.mostrarMensaje("  - " + ing.first + ": Necesita " + 
                                           std::to_string(necesaria) + ", disponible " + 
                                           std::to_string(disponible));
                    }
                }
            }
        }
        vista.pausar();
        return;
    }
    
    if (panaderia.producirPan(nombrePan, cantidad)) {
        vista.mostrarExito("Produccion registrada exitosamente");
        vista.mostrarMensaje("Se produjeron " + std::to_string(cantidad) + " unidades de " + nombrePan);
    } else {
        vista.mostrarError("Error al registrar la produccion");
    }
    vista.pausar();
}

void Controlador::consultarStockPanes() {
    auto stockPanes = panaderia.getStock().obtenerTodoElStock();
    
    if (stockPanes.empty()) {
        vista.mostrarAlerta("No hay panes en stock");
    } else {
        vista.mostrarMensaje("\n=== STOCK DE PANES ===");
        for (const auto& par : stockPanes) {
            std::string mensaje = par.first + ": " + std::to_string(par.second) + " unidades";
            if (par.second == 0) {
                vista.mostrarAlerta(mensaje + " [SIN STOCK]");
            } else {
                vista.mostrarMensaje(mensaje);
            }
        }
    }
    vista.pausar();
}

void Controlador::menuEncargadoInventario() {
    bool continuar = true;
    while (continuar) {
        vista.limpiarPantalla();
        vista.mostrarMenuEncargadoInventario();
        int opcion = vista.leerOpcion();
        
        switch (opcion) {
            case 1: registrarIngrediente(); break;
            case 2: modificarIngrediente(); break;
            case 3: eliminarIngrediente(); break;
            case 4: consultarInventario(); break;
            case 5: verAlertasReposicion(); break;
            case 6: verResumenCompleto(); break;
            case 0: continuar = false; break;
            default:
                vista.mostrarError("Opcion invalida");
                vista.pausar();
        }
    }
}

void Controlador::registrarIngrediente() {
    std::string nombre = vista.leerTexto("Nombre del ingrediente: ");
    std::string unidadMedida = vista.leerTexto("Unidad de medida (kg, g, L, ml, etc): ");
    double cantidad = vista.leerDouble("Cantidad disponible: ");
    double nivelMinimo = vista.leerDouble("Nivel minimo de alerta: ");
    
    if (panaderia.agregarIngrediente(nombre, unidadMedida, cantidad, nivelMinimo)) {
        vista.mostrarExito("Ingrediente registrado exitosamente");
    } else {
        vista.mostrarError("El ingrediente ya existe");
    }
    vista.pausar();
}

void Controlador::modificarIngrediente() {
    std::string nombre = vista.leerTexto("Nombre del ingrediente: ");
    double cantidad = vista.leerDouble("Nueva cantidad: ");
    
    if (panaderia.modificarIngrediente(nombre, cantidad)) {
        vista.mostrarExito("Ingrediente modificado exitosamente");
    } else {
        vista.mostrarError("El ingrediente no existe");
    }
    vista.pausar();
}

void Controlador::eliminarIngrediente() {
    std::string nombre = vista.leerTexto("Nombre del ingrediente a eliminar: ");
    
    if (panaderia.eliminarIngrediente(nombre)) {
        vista.mostrarExito("Ingrediente eliminado exitosamente");
    } else {
        vista.mostrarError("El ingrediente no existe");
    }
    vista.pausar();
}

void Controlador::consultarInventario() {
    auto ingredientes = panaderia.getInventario().obtenerTodosLosIngredientes();
    
    if (ingredientes.empty()) {
        vista.mostrarMensaje("No hay ingredientes en el inventario");
    } else {
        vista.mostrarMensaje("\n=== INVENTARIO DE INGREDIENTES ===");
        for (const auto& par : ingredientes) {
            Ingrediente* ing = par.second;
            std::string mensaje = ing->getNombre() + ": " + 
                                std::to_string(ing->getCantidadDisponible()) + " " + 
                                ing->getUnidadMedida();
            
            if (ing->estaDebajoDeLimite()) {
                vista.mostrarAlerta(mensaje + " [BAJO STOCK - Minimo: " + 
                                  std::to_string(ing->getNivelMinimo()) + "]");
            } else {
                vista.mostrarMensaje(mensaje);
            }
        }
    }
    vista.pausar();
}

void Controlador::verAlertasReposicion() {
    auto alertas = panaderia.obtenerAlertasReposicion();
    
    if (alertas.empty()) {
        vista.mostrarExito("No hay alertas de reposicion");
    } else {
        vista.mostrarMensaje("\n=== ALERTAS DE REPOSICION ===");
        for (Ingrediente* ing : alertas) {
            vista.mostrarAlerta(ing->getNombre() + ": " + 
                              std::to_string(ing->getCantidadDisponible()) + " " + 
                              ing->getUnidadMedida() + 
                              " (Minimo: " + std::to_string(ing->getNivelMinimo()) + ")");
        }
    }
    vista.pausar();
}

void Controlador::verResumenCompleto() {
    std::string reporte = panaderia.generarReporteCompleto();
    vista.mostrarMensaje(reporte);
    vista.pausar();
}

void Controlador::menuAdministrador() {
    bool continuar = true;
    while (continuar) {
        vista.limpiarPantalla();
        vista.mostrarMenuAdministrador();
        int opcion = vista.leerOpcion();
        
        switch (opcion) {
            case 1: verResumenCompletoAdmin(); break;
            case 2: exportarReporte(); break;
            case 3: consultarStockPanesAdmin(); break;
            case 4: consultarInventarioAdmin(); break;
            case 0: continuar = false; break;
            default:
                vista.mostrarError("Opcion invalida");
                vista.pausar();
        }
    }
}

void Controlador::verResumenCompletoAdmin() {
    std::string reporte = panaderia.generarReporteCompleto();
    vista.mostrarMensaje(reporte);
    vista.pausar();
}

void Controlador::exportarReporte() {
    std::string nombreArchivo = vista.leerTexto("Nombre del archivo (sin extension): ");
    nombreArchivo += ".txt";
    
    std::ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        archivo << panaderia.generarReporteCompleto();
        archivo.close();
        vista.mostrarExito("Reporte exportado exitosamente a " + nombreArchivo);
    } else {
        vista.mostrarError("No se pudo crear el archivo");
    }
    vista.pausar();
}

void Controlador::consultarStockPanesAdmin() {
    consultarStockPanes();
}

void Controlador::consultarInventarioAdmin() {
    consultarInventario();
}