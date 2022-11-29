#include <stddef.h>
#include "List.h"

#ifndef DGRAPH_H_H
#define DGRAPH_H_H

typedef enum {false, true} bool;

typedef void * Type;

typedef struct strDGraph *DGraph;

typedef struct strVertex *Vertex;

typedef struct strEdge *Edge;

DGraph dgraphCreate(); // Crea un grafo vacio

unsigned int sizeGraph(DGraph); // Cantidad de vertices

bool adjacent(DGraph, Type, Type); // Verifica si dos vertices son adyacentes

Type neighbors(DGraph, Type); // Devuelve una lista con los vertices adyacentes a un vertice

void addVertex(DGraph, Type); // Agrega un vertice al grafo

Type removeVertex(DGraph, Type); // Elimina un vertice del grafo y devuelve su informacion

void addEdge(DGraph, Type, Type); // Agrega una arista al grafo

Type removeEdge(DGraph, Type, Type); // Elimina una arista del grafo y devuelve su informacion

Type GetVertexData(DGraph, Type); // Devuelve el dato de un vertice

void SetVertexData(DGraph, Type, Type); // Modifica el dato de un vertice

Type getEdgeLabel(DGraph, Type, Type); // Retorna la etiqueta asociada con la arista que conecta a los vértices: x, y; 

void setEdgeLabel(DGraph, Type, Type, Type); // Modifica el label de una arista

void destroyGraph(DGraph); // Destruye el grafo

#endif /* DGRAPH_H_H */
