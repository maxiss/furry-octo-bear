#define lgData unsigned char
#define lgDataLength 8
#define OFF 0
#define ON 1

class LgData
{
public:
   lgData data;
   LgData() { data = 0; };
};

class LgField
{
public:
   LgField(int areaWidth, int areaHeight);
   ~LgField();
   int getCellState(int x, int y);
   void setCellState(int x, int y, int state);

private:
   int areaWidth, areaHeight;
   int areaCharWidth, areaCharHeight;
   LgData** gameData;

   int getCharNum(int x);
   int getCharPos(int x);
};

class LgGame
{
public:
   LgGame();
   ~LgGame();
   void generateRandom();
   void generateEmpty();
   void generateNext();
   int  getCellState(int x, int y);
   void setCellState();
   void draw();

private:
   int fieldWidth,
       fieldHeight,
       currentField,
       nextField;

   LgField *fields[2];
   int getNeighborCount(int x, int y);
   void setCellNewState(int x, int y, int state);
   int checkFieldHitX(int x);
   int checkFieldHitY(int y);
   void changeFields();
   
};
