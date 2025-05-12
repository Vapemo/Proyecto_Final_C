#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"
#include "lectura.h"

void mostrarProducto(Producto* producto) {
    if (producto) {
        printf("Producto: %s\n", producto->nombre);
        printf("Precio: $%.2f\n", producto->precio);
    } else {
        printf("No hay más productos.\n");
    }
}

void liberarLista(Producto* lista) {
    Producto* actual;
    while (lista) {
        actual = lista;
        lista = lista->siguiente;
        free(actual);
    }
}

int main() {
    Producto* productos = leerProductosDesdeArchivo("productos.txt");
    if (!productos) {
        printf("No se pudieron cargar los productos.\n");
        return 1;
    }

    Producto* actual = productos;
    char tecla;

    while (1) {
        system("clear"); // Usar "cls" en Windows
        mostrarProducto(actual);

        printf("\nPresiona A (anterior), S (siguiente), Q (salir): ");
        scanf(" %c", &tecla);

        if (tecla == 'A' || tecla == 'a') {
            // Retroceder en la lista no es posible en listas enlazadas simples
            printf("\nNo se puede retroceder en esta implementación.\n");
        } else if (tecla == 'S' || tecla == 's') {
            if (actual->siguiente) {
                actual = actual->siguiente;
            } else {
                printf("\nNo hay más productos.\n");
            }
        } else if (tecla == 'Q' || tecla == 'q') {
            break;
        }
    }

    liberarLista(productos);
    return 0;
}
