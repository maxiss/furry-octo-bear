#define LifeGameData unsigned char
#define lifeGameDataLength 8

class GameData
{
public:
   LifeGameData data;
   GameData() { data = 0; };
};

class LifeGame
{
public:
   LifeGame(int areaWidth, int areaHeight);
   ~LifeGame();
   int getCellState(int x, int y);
   void setCellState(int x, int y, int state);

private:
   int areaWidth, areaHeight;
   int areaCharWidth, areaCharHeight;
   GameData** gameData;

   int getCharNum(int x);
   int getCharPos(int x);
};
