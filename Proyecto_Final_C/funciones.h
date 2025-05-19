#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "estructuras.h"

void navegarYAgregar(Producto* lista, Usuario* usuario);
void verCarrito(Usuario usuario);
void verInformacion(Usuario usuario);
void guardarCarritoEnArchivo(Usuario usuario);
void liberarMemoria(Producto* lista);

#endif
