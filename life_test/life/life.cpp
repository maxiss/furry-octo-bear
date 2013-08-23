#include <iostream>
#include <stdlib.h>

#include "life.h"

#define   setBit(reg, bit)         (reg |= (1<<bit))
#define   clearBit(reg, bit)       (reg &= (~(1<<bit)))
#define   getBitState(reg, bit)    ((reg & (1<<bit)) != 0)

LgField::LgField(int areaWidth_, int areaHeight_)
{
   areaWidth  = areaWidth_;
   areaHeight = areaCharHeight = areaHeight_;
   areaCharWidth = getCharNum(areaWidth-1)+1;

   gameData = new LgData*[areaCharHeight];
   for (int i = 0; i < areaCharHeight; i++)
   {
      gameData[i] = new LgData[areaCharWidth];
   }
}

LgField::~LgField()
{
   for (int i = 0; i < areaCharHeight; i++)
   {
      delete[] gameData[i];
   }
   delete[] gameData;
}

int LgField::getCellState(int x, int y)
{
   return getBitState(gameData[y][getCharNum(x)].data, getCharPos(x));
}

void LgField::setCellState(int x, int y, int state)
{
   if (state)
      setBit(gameData[y][getCharNum(x)].data, getCharPos(x));
   else
      clearBit(gameData[y][getCharNum(x)].data, getCharPos(x));
}

int LgField::getCharNum(int x)
{
   int retval = x / lgDataLength;
   return retval;
}

int LgField::getCharPos(int x)
{
   int retval = x % lgDataLength;
   return retval;
}

LgGame::LgGame()
{
   fieldWidth = 50;
   fieldHeight = 10;
   currentField = 0;
   nextField = 1;
   for (int i = 0; i < 2; i++)
      fields[i] = new LgField(fieldWidth, fieldHeight);
}

LgGame::~LgGame()
{
   for (int i = 0; i < 2; i++)
      delete fields[i];
}

void LgGame::generateNext()
{
   int neighborCount,
       currentState;
   for (int x = 0; x < fieldWidth; x++)
      for (int y = 0; y < fieldHeight; y++)
      {
         neighborCount = getNeighborCount(x, y);
         currentState   = getCellState(x, y);
         if ( (currentState == OFF) && (neighborCount == 3) )
            setCellNewState(x, y, ON);
         if ( (currentState == ON) && ( (neighborCount < 2) || (neighborCount > 3) ) )
            setCellNewState(x, y, OFF);
      }
   changeFields();
}

void LgGame::setCellNewState(int x, int y, int state)
{
   fields[nextField]->setCellState(x, y, state);
}

int LgGame::getCellState(int x, int y)
{
   return fields[currentField]->getCellState(x, y);
}

int LgGame::getNeighborCount(int x, int y)
{
   int neighborX,
       neighborY,
       neighborCount = 0;
   for (int i = 0; i < 9; i++)
   {
      if (i == 4)
         continue;
      neighborX = checkFieldHitX (x + i%3 - 1);
      neighborY = checkFieldHitY (y + i/3 - 1);
      neighborCount += getCellState (neighborX, neighborY);
   }
   return neighborCount;
}

int LgGame::checkFieldHitX(int x)
{
   if (x < 0)
      return fieldWidth-1;
   if (x >= fieldWidth)
      return 0;
   return x;
}

int LgGame::checkFieldHitY(int y)
{
   if (y < 0)
      return fieldHeight-1;
   if (y >= fieldHeight)
      return 0;
   return y;
}

void LgGame::changeFields()
{
   int tmp = currentField;
   currentField = nextField;
   nextField = tmp;
}

void LgGame::generateRandom()
{
   for (int x = 0; x < fieldWidth; x++)
      for (int y = 0; y < fieldHeight; y++)
         setCellNewState(x, y, !(rand()%4));
   changeFields();
}

void LgGame::draw()
{
   std::cout << std::endl;
   for (int y = 0; y < fieldHeight; y++)
   {
      for (int x = 0; x < fieldWidth; x++)
         std::cout << getCellState(x, y);
      std::cout << std::endl;
   }
}
