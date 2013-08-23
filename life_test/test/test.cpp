#include <iostream>
#include "life.h"

using namespace std;

void main()
{
   LgGame game;
   system("cls");
   game.generateRandom();
   game.draw();
   system("pause");

   for (int i = 0; i < 20; i++)
   {
      system("cls");
      game.generateNext();
      game.draw();
      system("pause");
   }

   system("pause");
}
