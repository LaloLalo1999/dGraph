#include "DGraph.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
    DGraph G = dgraphCreate(sizeof(char), sizeof(int));
    char x = 'a';
    char y = 'b';
    int n = 1;
    addVertex(G, &x);
    printf("Size: %d \n", sizeGraph(G));
    addVertex(G, &y);
    printf("Size: %d \n", sizeGraph(G));
    addEdge(G, &x, &y);
    setEdgeLabel(G, &x, &y, &n);
    printf("Label: %d \n", getEdgeLabel(G, &x, &y));
}