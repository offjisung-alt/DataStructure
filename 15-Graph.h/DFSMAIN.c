#include <stdio.h>
#include "ALGraphDFS.h"

int main(void)
{
    ALGraph graph;
    GraphInit(&graph);

    AddEdge(&graph, A, B);
    AddEdge(&graph, A, D);
    AddEdge(&graph, B, C);
    AddEdge(&graph, D, C);
    AddEdge(&graph, D, E);
    AddEdge(&graph, E, F);
    AddEdge(&graph, E, G);

    ShowGraphEdgeInfo(&graph);

    DFShowGraphVertex(&graph, A);
    printf("\n");
    DFShowGraphVertex(&graph, B);
    printf("\n");
    DFShowGraphVertex(&graph, C);
    printf("\n");
    DFShowGraphVertex(&graph, D);
    printf("\n");

    GraphDestroy(&graph);
    return 0;
}