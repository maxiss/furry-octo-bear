#include <iostream>

#include "ttr.h"

using namespace std;

void main()
{
   graph gr1;
   for (int i = 0; i < 22; i++)
      gr1.addVertex(0, 0);

   gr1.addEdge(0, 2);
   gr1.addEdge(0, 7);
   gr1.addEdge(0, 1);
   gr1.addEdge(0, 3);
   gr1.addEdge(1, 4);
   gr1.addEdge(1, 7);
   gr1.addEdge(2, 6);
   gr1.addEdge(2, 8);
   gr1.addEdge(3, 4);
   gr1.addEdge(3, 5);
   gr1.addEdge(4, 5);
   gr1.addEdge(4, 7);
   gr1.addEdge(4, 9);
   gr1.addEdge(5, 9);
   gr1.addEdge(5, 10);
   gr1.addEdge(6, 8);
   gr1.addEdge(6, 11);
   gr1.addEdge(7, 8);
   gr1.addEdge(7, 9);
   gr1.addEdge(7, 13);
   gr1.addEdge(7, 17);
   gr1.addEdge(8, 11);
   gr1.addEdge(8, 17);
   gr1.addEdge(9, 10);
   gr1.addEdge(9, 13);
   gr1.addEdge(9, 14);
   gr1.addEdge(9, 15);
   gr1.addEdge(9, 16);
   gr1.addEdge(10, 12);
   gr1.addEdge(10, 15);
   gr1.addEdge(11, 17);
   gr1.addEdge(11, 21);
   gr1.addEdge(12, 15);
   gr1.addEdge(12, 20);
   gr1.addEdge(13, 18);
   gr1.addEdge(14, 16);
   gr1.addEdge(14, 18);
   gr1.addEdge(15, 16);
   gr1.addEdge(15, 19);
   gr1.addEdge(15, 20);
   gr1.addEdge(16, 19);
   gr1.addEdge(17, 21);
   gr1.addEdge(18, 21);
   gr1.addEdge(19, 20);

   int sum = 0;
   for (int i = 0; i < 22; i++)
   {
      sum += gr1.vertices[i].degree;
      cout << i << " - " << gr1.vertices[i].degree << endl;
   }
   cout << sum << endl;





   system("pause");
}
