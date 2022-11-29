#include "DGraph.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
    DGraph G = dgraphCreate();
    char x = 'a';
    char y = 'b';
    char *p = &x;
    char *q = &y;
    addVertex(G, p);
    printf("Size: %d \n", sizeGraph(G));
    addVertex(G, q);
    printf("Size: %d \n", sizeGraph(G));
    addEdge(G, p, q);
    setEdgeLabel()
}