#include <stdio.h>
#include <string.h>
#include "estructuras.h"
#include "lectura_ar.h"
#include "funciones.h"

int main() {
    Usuario usuario;
    printf("Nombre del usuario: ");
    fgets(usuario.nombre, sizeof(usuario.nombre), stdin);
    usuario.nombre[strcspn(usuario.nombre, "\n")] = 0;

    printf("Numero de celular: ");
    fgets(usuario.numeroCelular, sizeof(usuario.numeroCelular), stdin);
    usuario.numeroCelular[strcspn(usuario.numeroCelular, "\n")] = 0;

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
                printf("Bye :)!\n");
                break;
            default:
                printf("Opcion no valida.\n");
        }
    } while (opcion != 4);

    return 0;
}
