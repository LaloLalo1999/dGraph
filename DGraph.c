#include "DGraph.h"
#include "List.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct strVertex{
    int id;
    Type data;
    List edges;
};

typedef struct strVertex *Vertex;

struct strEdge{
    Vertex origin;
    Vertex destination;
    Type label;
};

typedef struct strEdge *Edge;

struct strDGraph{
    List vertices; //Lista de vertices
};

DGraph dgraphCreate(size_t vertex_size, size_t edge_size){
    DGraph new=malloc(sizeof(struct strDGraph));
    new->vertices=listCreate(sizeof(struct strVertex));
    return new;
}

unsigned int sizeGraph(DGraph dg){
    if(dg!=NULL)
        return listSize(dg->vertices);
    return 0;
}

Vertex newVertex(Type data, size_t bytes){
    Vertex new=malloc(sizeof(struct strVertex));
    new->data=malloc(bytes);
    memcpy(new->data, data, bytes);
    new->edges=listCreate(sizeof(struct strEdge));
    return new;
}

void addVertex(DGraph dg, Type data){
    if(dg!=NULL){
        Vertex new=newVertex(data, sizeof(struct strVertex));
        new->id=sizeGraph(dg);
        listAdd(dg->vertices, new);
    }
}

Type getVertexData(DGraph dg,