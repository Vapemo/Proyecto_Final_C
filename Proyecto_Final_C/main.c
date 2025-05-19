#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "estructuras.h"
#include "lectura_ar.h"
#include "funciones.h"



int esNumeroValido(char* numero) {
    if (strlen(numero) != 10) return 0;
    for (int i = 0; i < 10; i++) {
        if (!isdigit(numero[i])) return 0;
    }
    return 1;
}

int main() {
    Usuario usuario;
    printf("Nombre del usuario: ");
    fgets(usuario.nombre, sizeof(usuario.nombre), stdin);
    usuario.nombre[strcspn(usuario.nombre, "\n")] = 0;

    do {
        printf("Numero de celular (10 digitos): ");
        fgets(usuario.numeroCelular, sizeof(usuario.numeroCelular), stdin);
        usuario.numeroCelular[strcspn(usuario.numeroCelular, "\n")] = 0;
    } while (!esNumeroValido(usuario.numeroCelular));

    usuario.totalPagar = 0.0;
    usuario.carrito = NULL;

    Producto* productos = leerProductosDesdeArchivo("productos.txt");

    int opcion;
    do {
        printf("\n====== MENU PRINCIPAL ======\n");
        printf("1. Ver lista de productos\n");
        printf("2. Ver carrito\n");
        printf("3. Ver mi informacion\n");
        printf("4. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);
        getchar(); // Para consumir salto de linea

        switch (opcion) {
            case 1:
                navegarYAgregar(productos, &usuario);
                break;
            case 2:
                verCarrito(usuario);
                break;
            case 3:
                verInformacion(usuario);
                break;
            case 4:
                guardarCarritoEnArchivo(usuario);
                printf("Hasta luego!\n");
                break;
            default:
                printf("Opcion no valida.\n");
        }
    } while (opcion != 4);

    liberarMemoria(productos);
    liberarMemoria(usuario.carrito);

    return 0;
}

