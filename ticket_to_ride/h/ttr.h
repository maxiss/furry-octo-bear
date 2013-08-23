#include <vector>

using namespace std;

class vertex
{
public:
   int x,
       y,
       degree;

   vertex(int x, int y);
};

class edge
{
public:
   vertex *v1,
          *v2;
};

class graph
{
public:
   vector<vertex> vertices;
   vector<edge> edges;

   void addVertex(int x, int y);
   void addEdge(int v1, int v2);
};
