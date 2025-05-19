#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"
#include "funciones.h"

void navegarYAgregar(Producto* lista, Usuario* usuario) {
    if (lista == NULL) {
        printf("Lista vacia.\n");
        return;
    }
    Producto* actual = lista;
    char opcion;
    do {
        printf("\nProducto: %s\nPrecio: $%.2f\n", actual->nombre, actual->precio);
        printf("[A] Anterior | [S] Siguiente | [G] Agregar al carrito | [X] Salir\n");
        scanf(" %c", &opcion);

        if (opcion == 'S' || opcion == 's') {
            if (actual->siguiente) actual = actual->siguiente;
            else printf("Ya estas en el ultimo producto.\n");
        } else if (opcion == 'A' || opcion == 'a') {
            Producto* temp = lista;
            Producto* anterior = NULL;
            while (temp != actual) {
                anterior = temp;
                temp = temp->siguiente;
            }
            if (anterior) actual = anterior;
            else printf("Ya estas en el primer producto.\n");
        } else if (opcion == 'G' || opcion == 'g') {
            Producto* copia = malloc(sizeof(Producto));
            if (!copia) {
                printf("Error de memoria.\n");
                continue;
            }
            strcpy(copia->nombre, actual->nombre);
            copia->precio = actual->precio;
            copia->siguiente = usuario->carrito;
            usuario->carrito = copia;
            usuario->totalPagar += copia->precio;
            printf(" Producto agregado al carrito!\n");
        }
    } while (opcion != 'X' && opcion != 'x');
}

void verCarrito(Usuario usuario) {
    Producto* actual = usuario.carrito;
    if (!actual) {
        printf(" Tu carrito esta vacio.\n");
        return;
    }
    printf("\n Carrito de compras:\n");
    while (actual) {
        printf("- %s: $%.2f\n", actual->nombre, actual->precio);
        actual = actual->siguiente;
    }
}

void verInformacion(Usuario usuario) {
    printf("\n Informacion del usuario:\n");
    printf("Nombre: %s\n", usuario.nombre);
    printf("Celular: %s\n", usuario.numeroCelular);
    printf("Total a pagar: $%.2f\n", usuario.totalPagar);
}

void guardarCarritoEnArchivo(Usuario usuario) {
    FILE* archivo = fopen("carrito.txt", "w");
    if (!archivo) {
        printf(" No se pudo guardar el carrito.\n");
        return;
    }
    Producto* actual = usuario.carrito;
    while (actual) {
        fprintf(archivo, "%s,%.2f\n", actual->nombre, actual->precio);
        actual = actual->siguiente;
    }
    fclose(archivo);
    printf(" Carrito guardado en 'carrito.txt'\n");
}

void liberarMemoria(Producto* lista) {
    Producto* temp;
    while (lista) {
        temp = lista;
        lista = lista->siguiente;
        free(temp);
    }
}
