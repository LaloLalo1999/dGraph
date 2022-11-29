#include <stddef.h>
#include "List.h"

#ifndef DGRAPH_H_H
#define DGRAPH_H_H

typedef enum {false, true} bool;

typedef void * Type;

typedef struct strDGraph *DGraph;

typedef struct strVertex *Vertex;

typedef struct strEdge *Edge;

DGraph dgraphCreate(size_t); // Crea un grafo vacio       

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


/*a) createDGraph()  Crea una nueva instancia de un contenedor DGraph. 
 
b) sizeGraph(DG)   Retorna el número de vértices que existen en el grafo. 
 
c) adjacent(DG, x, y)  Retornar true si en el contendor DG, existe una arista entre  
los vértices:  x y y. 
 
d) neighbors(DG, x)  Retorna los datos que se encuentran en los vértices y que  
son  vecinos  del  vértice  x.  Un  vértice  y  es  vecino  de  x,  si  
existe una arista de x a y. 
 
e) addVertex(DG, x)  Agrega un nuevo vértice x, si no existe en el grafo DG. 
 
f) removeVertex(DG, x) Remueve el vértice x, si existe en el grafo DG. 
 
g) addEdge(DG, x, y, z) Agrega al grafo DG una arista z del vértice x al vértice y, si  
no existe. 
 
 
h) removeEdge(DG, x, y) Remueve del grafo DG la arista del vértice x al vértice y, si  
existe. 
 
i) getVertexData(DG, x) Retorna el dato almacenado en el vértice x. 
 
j) setVertexData(DG, x, d) Almacena el dato d en el vértice x. 
 
k) getEdgeLabel(DG, x, y) Retorna la etiqueta asociada con la arista que conecta a los  
vértices: x, y; 
 
l) setEdgeLabel(DG, x, y, l) Asigna la etiqueta l a la arista asociada con la arista que une  
a los vértices: x, y. 
 
m)  destroyDGraph(DG) Destruye el contenedor DG, liberando toda la memoria  
dinámica */
