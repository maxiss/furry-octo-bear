#include "ttr.h"

void graph::addVertex(int x, int y)
{
   vertex newVertex(x, y);
   vertices.push_back(newVertex);
   return;
}

void graph::addEdge(int v1, int v2)
{
   edge newEdge;
   newEdge.v1 = &vertices[v1];
   newEdge.v2 = &vertices[v2];
   vertices[v1].degree++;
   vertices[v2].degree++;
}
