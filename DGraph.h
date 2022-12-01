#include <stddef.h>
#include "List.h"

#ifndef DGRAPH_H_
#define DGRAPH_H_

typedef void * Type;

typedef struct strDGraph *DGraph;

DGraph dgraphCreate(); // Crea un grafo vacio

unsigned int sizeGraph(DGraph); // Cantidad de vertices

void addVertex(DGraph, Type); // Agrega un vertice al grafo

Type getVertexData(DGraph, Type); // Devuelve el dato de un vertice

unsigned int adjacent(DGraph, Type, Type); // Verifica si dos vertices son adyacentes

Type neighbors(DGraph, Type); // Devuelve una lista con los vertices adyacentes a un vertice

Type removeVertex(DGraph, Type); // Elimina un vertice del grafo y devuelve su informacion

void addEdge(DGraph, Type, Type); // Agrega una arista al grafo

Type removeEdge(DGraph, Type, Type); // Elimina una arista del grafo y devuelve su informacion

void setVertexData(DGraph, Type, Type); // Modifica el dato de un vertice

Type getEdgeLabel(DGraph, Type, Type); // Retorna la etiqueta asociada con la arista que conecta a los vértices: x, y; 

void setEdgeLabel(DGraph, Type, Type, Type); // Modifica el label de una arista

void destroyGraph(DGraph); // Destruye el grafo

#endif /* DGRAPH_H_H */
