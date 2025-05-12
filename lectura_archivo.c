#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"
#include "lectura_ar.h"

Producto* leerProductosDesdeArchivo(const char* nombreArchivo) {
    FILE* archivo = fopen(nombreArchivo, "r");
    if (!archivo) {
        printf("Error al abrir el archivo %s.\n", nombreArchivo);
        return NULL;
    }

    Producto* inicio = NULL;
    Producto* actual = NULL;

    char linea[150];
    while (fgets(linea, sizeof(linea), archivo)) {
        Producto* nuevo = (Producto*)malloc(sizeof(Producto));
        if (!nuevo) {
            printf("Error al asignar memoria.\n");
            fclose(archivo);
            return NULL;
        }

        char* token = strtok(linea, ",");
        if (!token) continue;
        strncpy(nuevo->nombre, token, MAX_NOMBRE);

        token = strtok(NULL, ",");
        if (!token) {
            free(nuevo);
            continue;
        }
        nuevo->precio = atof(token);

        nuevo->siguiente = NULL;

        if (!inicio) {
            inicio = nuevo;
            actual = nuevo;
        } else {
            actual->siguiente = nuevo;
            actual = nuevo;
        }
    }

    fclose(archivo);
    return inicio;
}
