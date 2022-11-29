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
};

typedef struct strDGraph *DGraph;