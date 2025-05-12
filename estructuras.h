#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#define MAX_NOMBRE 50

// Estructura para los productos
typedef struct Producto {
    char nombre[MAX_NOMBRE];
    float precio;
    struct Producto* siguiente;
} Producto;

// Estructura para el usuario
typedef struct Usuario {
    char nombre[MAX_NOMBRE];
    char direccion[100];
} Usuario;

#endif

