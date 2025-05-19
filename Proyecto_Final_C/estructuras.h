#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#define MAX_NOMBRE 50

// estructura para los productos
typedef struct Producto {
    char nombre[MAX_NOMBRE];
    float precio;
    struct Producto* siguiente;
} Producto;

// estructura para el usuario
typedef struct Usuario {
    char nombre[MAX_NOMBRE];
    char numeroCelular[11];
    float totalPagar;
    Producto* carrito;
} Usuario;

#endif // ESTRUCTURAS_H

