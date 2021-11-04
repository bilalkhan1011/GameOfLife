// Header file containing function prototypes for the Graphics.c module.h

#define WorldSize 100

extern int worldSize;
extern int grid[WorldSize][WorldSize];
extern int numMoves;

int numNeighbours(int x, int y);

int stateChange(int neighbours, int x, int y);

int saveGame();

int loadGame();

void printGrid();
