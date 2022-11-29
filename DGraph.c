#include "DGraph.h"
#include "List.h"
#include <stdlib.h>
#include <string.h>

struct strVertex{
    Type data;
    List edges;
};

typedef struct strVertex *Vertex;

struct strEdge{
    Type data;
    Vertex origin;
    Vertex destination;
};

typedef struct strEdge *Edge;

struct strDGraph{
    List vertices;
    List edges;
    size_t data_size;
};

typedef struct strDGraph *DGraph;

DGraph dgraphCreate(size_t bytes){
    DGraph new=malloc(sizeof(struct strDGraph));
    new->vertices=listCreate(bytes);
    new->edges=listCreate(bytes);
    new->data_size=bytes;
    return new;
}

unsigned int sizeGraph(DGraph graph){
    return listSize(graph->vertices);
}

bool adjacent(DGraph graph, Type x, Type y){
    Vertex vertex = listGet(graph->vertices, listSearch(graph->vertices, x));
    Edge edge = listGet(vertex->edges, listSearch(vertex->edges, y));
    if(edge != NULL)
        return true;
    return false;
}

Type neighbors(DGraph graph, Type x){
    Vertex vertex = listGet(graph->vertices, listSearch(graph->vertices, x));
    return vertex->edges;
}

void addVertex(DGraph graph, Type x){
    Vertex vertex = malloc(sizeof(graph->data_size));
    vertex->data = x;
    vertex->edges = listCreate(sizeof(graph->data_size));
    listAdd(graph->vertices, vertex);
}

Type removeVertex(DGraph graph, Type x){
    Vertex vertex = listGet(graph->vertices, listSearch(graph->vertices, x));
    listRemove(graph->vertices, listSearch(graph->vertices, x));
    return vertex->data;
}

void addEdge(DGraph graph, Type x, Type y){
    Vertex vertex = listGet(graph->vertices, listSearch(graph->vertices, x));
    Edge edge = malloc(sizeof(struct strEdge));
    edge->data = y;
    edge->origin = vertex;
    edge->destination = listGet(graph->vertices, listSearch(graph->vertices, y));
    listAdd(vertex->edges, edge);
    listAdd(graph->edges, edge);
}

Type removeEdge(DGraph graph, Type x, Type y);

Type GetVertexData(DGraph graph, Type x);

void SetVertexData(DGraph graph, Type x, Type y);

unsigned int getEdgeLabel(DGraph graph, Type x, Type y); 

void setEdgeLabel(DGraph graph, Type x, Type y, unsigned int i);

void destroyGraph(DGraph graph);

