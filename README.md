# Agentes Inteligentes en un Laberinto

Proyecto del curso Fundamentos de Programación Orientada a Objetos (FPOO) de la Universidad del Valle.

---

Sistema de gestión en C++ para automatizar las operaciones de una panadería, implementando el patrón de diseño MV (Modelo-Vista-Controlador).
El programa permite gestionar el inventario de materias primas, crear y administrar recetas de diferentes tipos de pan, controlar el proceso de producción con descuento automático de ingredientes, llevar registro del stock de productos terminados, y generar alertas cuando los ingredientes están por debajo del nivel mínimo establecido.

## Estructura del Sistema

El proyecto tiene **8 clases principales** organizadas bajo el patrón MVC:

**Modelo:**
- **Panaderia**: Clase central que coordina todo el sistema. Contiene y gestiona el Inventario, Stock y Recetas. Es responsable de validar la disponibilidad de ingredientes y ejecutar la producción.
- **Inventario**: Administra la colección completa de ingredientes mediante composición. Contiene múltiples objetos Ingrediente y gestiona su ciclo de vida (creación y destrucción).
- **Ingrediente**: Representa una materia prima individual con nombre, cantidad disponible, unidad de medida y nivel mínimo para alertas.
- **Receta**: Define las proporciones de ingredientes necesarios para producir un tipo de pan. Conoce los ingredientes por nombre y almacena sus cantidades en un mapa.
- **Stock**: Gestiona el inventario de productos terminados listos para la venta. Registra la cantidad disponible de cada tipo de pan producido.
- **Usuario** (Superclase): Define la estructura común de todos los usuarios.
- **Panadero, EncargadoInventario, Administrador**: Clases derivadas que representan los roles solicitados con permisos y funciones específicas.

**Vista:**
- **Vista**: Maneja toda la interfaz con el usuario. Muestra menús específicos según el tipo de usuario, captura entradas y presenta información formateada (mensajes, alertas, errores).

**Controlador:**
- **Controlador**: Intermediario entre Modelo y Vista. Implementa la lógica de las historias de usuario, procesa las opciones de los menús y coordina las operaciones entre Panaderia y Vista.

---

## Relaciones Principales

El sistema implementa **composición** (Panaderia contiene Inventario, Stock y Recetas; Inventario contiene Ingredientes), **asociación** (Receta conoce ingredientes por nombre), **agregación** (Controlador usa Panaderia y Vista sin poseerlos) y **herencia** (tipos de Usuario).

## Integrantes
* Yostin Ramirez - 2519674
* Lesly Zapata - 2516574
* Joseph Terreros - 2521011
* Juan Manuel Rosero - 2520822
* Juan Esteban Mina - 2518466