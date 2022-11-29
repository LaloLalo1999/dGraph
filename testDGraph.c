#include "DGraph.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
    DGraph G = dgraphCreate(sizeof(int));
    int x = 1;
    int y = 2;
    int *p = &x;
    int *q = &y;
    addVertex(G, p);
    printf("Size: %d \n", sizeGraph(G));
    addVertex(G, q);
    printf("Size: %d \n", sizeGraph(G));
    addEdge(G, p, q);
}