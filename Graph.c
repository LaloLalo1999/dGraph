#include "Graph.h"
#include "List.h"
#include <stdlib.h>
#include <string.h>

struct strVertex{
    Type data;
    List edges;
}