#include "DGraph.h"
#include "List.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct strVertex{
    Type data;
    List edges;
//    size_t data_size_vertex;
};

typedef struct strVertex *Vertex;

struct strEdge{
    Type data;
    Vertex origin;
    Vertex destination;
//    size_t data_size_edge;
};

typedef struct strEdge *Edge;

struct strDGraph{
    List vertices;
    List edges;
 //   size_t data_size_vertex;
 //   size_t data_size_edge;
};

typedef struct strDGraph *DGraph;

DGraph dgraphCreate(size_t bytes_vertex, size_t bytes_edge){
    DGraph new=malloc(sizeof(struct strDGraph));
    new->vertices=listCreate(sizeof(struct strVertex));
    new->edges=listCreate(sizeof(struct strEdge));
   // new->data_size_vertex=bytes_vertex;
  //  new->data_size_edge=bytes_edge;
    return new;
}

unsigned int sizeGraph(DGraph graph){
    return listSize(graph->vertices);
}

unsigned int adjacent(DGraph graph, Type x, Type y){
    Type vertex = listGet(graph->vertices, listSearch(graph->vertices, x));
    printf("Vertex: %c \n", *(char*)vertex);
//    Edge edge = listGet(vertex->edges, listSearch(vertex->edges, y));
//    if(edge != NULL)
//        return 1;
//    return 0;
}

Type neighbors(DGraph graph, Type x){
    Vertex vertex = listGet(graph->vertices, listSearch(graph->vertices, x));
    return vertex->edges;
}

void addVertex(DGraph graph, Type x){
    Vertex vertex = malloc(sizeof(struct strVertex));
    vertex->data = x;
    vertex->edges = listCreate(sizeof(struct strEdge));
    listAdd(graph->vertices, vertex);
}

Type removeVertex(DGraph graph, Type x){
    Vertex vertex = listGet(graph->vertices, listSearch(graph->vertices, x));
    listRemove(graph->vertices, listSearch(graph->vertices, x));
    return vertex->data;
}

void addEdge(DGraph graph, Type x, Type y) {
    Type vertex1 = listGet(graph->vertices, listSearch(graph->vertices, x));
    printf("First vertex: %c\n", *(char*)vertex1);
//    printf("listSearch(graph->vertices, x) = %d\n", listSearch(graph->vertices, x));
//    printf("listSearch(graph->vertices, y) = %d\n", listSearch(graph->vertices, y));
    if (listSearch(graph->vertices, x) != -1 && listSearch(graph->vertices, y) != -1) {
        printf("Both vertices exist\n");
        if (adjacent(graph, x, y) == 0) {
            printf("They are not adjacent\n");
            Vertex vertex = listGet(graph->vertices, listSearch(graph->vertices, x));
            Edge edge = malloc(sizeof(struct strEdge));
            edge->data = y;
            edge->origin = vertex;
            edge->destination = listGet(graph->vertices, listSearch(graph->vertices, y));
            listAdd(vertex->edges, edge);
            listAdd(graph->edges, edge);
            printf("Edge added successfully");
        } else
            printf("No se puede agregar la arista porque ya existe");
    }else
        printf("No se puede agregar la arista porque no existen los vertices");

}

Type removeEdge(DGraph graph, Type x, Type y){
    Vertex vertex = listGet(graph->vertices, listSearch(graph->vertices, x));
    Edge edge = listGet(vertex->edges, listSearch(vertex->edges, y));
    listRemove(vertex->edges, listSearch(vertex->edges, y));
    listRemove(graph->edges, listSearch(graph->edges, edge));
    return edge->data;
}

Type GetVertexData(DGraph graph, Type x){
    Vertex vertex = listGet(graph->vertices, listSearch(graph->vertices, x));
    return vertex->data;
}

void SetVertexData(DGraph graph, Type x, Type y){
    Vertex vertex = listGet(graph->vertices, listSearch(graph->vertices, x));
    vertex->data = y;
}

Type getEdgeLabel(DGraph graph, Type x, Type y){
    Vertex vertex = listGet(graph->vertices, listSearch(graph->vertices, x));
    Edge edge = listGet(vertex->edges, listSearch(vertex->edges, y));
    return edge->data;
}

void setEdgeLabel(DGraph graph, Type x, Type y, Type label){
    Vertex vertex = listGet(graph->vertices, listSearch(graph->vertices, x));
    Edge edge = listGet(vertex->edges, listSearch(vertex->edges, y));
    edge->data = label;
}

void destroyGraph(DGraph graph){
    listDestroy(graph->vertices);
    listDestroy(graph->edges);
    free(graph);
}

