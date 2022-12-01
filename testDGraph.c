#include "DGraph.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
    DGraph grafo_prueba = dgraphCreate();
    printf("Direccion del grafo: %p\n", grafo_prueba);
    unsigned int size = sizeGraph(grafo_prueba);
    printf("Tamaño del grafo: %d\n", size);
    addVertex(grafo_prueba, "Hola");
    size = sizeGraph(grafo_prueba);
    printf("Tamaño del grafo: %d\n", size);
}