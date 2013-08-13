#include "life.h"

#define   setBit(reg, bit)         (reg |= (1<<bit))
#define   clearBit(reg, bit)       (reg &= (~(1<<bit)))
#define   getBitState(reg, bit)    ((reg & (1<<bit)) != 0)

LifeGame::LifeGame(int areaWidth_, int areaHeight_)
{
   areaWidth  = areaWidth_;
   areaHeight = areaCharHeight = areaHeight_;
   areaCharWidth = getCharNum(areaWidth-1)+1;

   gameData = new GameData*[areaCharHeight];
   for (int i = 0; i < areaCharHeight; i++)
   {
      gameData[i] = new GameData[areaCharWidth];
   }
}

LifeGame::~LifeGame()
{
   for (int i = 0; i < areaCharHeight; i++)
   {
      delete[] gameData[i];
   }
   delete[] gameData;
}

int LifeGame::getCellState(int x, int y)
{
   return getBitState(gameData[y][getCharNum(x)].data, getCharPos(x));
}

void LifeGame::setCellState(int x, int y, int state)
{
   if (state)
      setBit(gameData[y][getCharNum(x)].data, getCharPos(x));
   else
      clearBit(gameData[y][getCharNum(x)].data, getCharPos(x));
}

int LifeGame::getCharNum(int x)
{
   int retval = x / lifeGameDataLength;
   return retval;
}

int LifeGame::getCharPos(int x)
{
   int retval = x % lifeGameDataLength;
   return retval;
}
