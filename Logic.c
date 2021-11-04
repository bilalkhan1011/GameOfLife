//The file used to initialise the game and handle logical comparisons of live neighbours and building of
//generations

#include <stdlib.h>
#include <stdio.h>
#include "Logic.h"

int grid[WorldSize][WorldSize];
int numMoves = 15;
int worldSize;



//saves game to file.
int saveGame(){

  FILE *r;
  r = fopen("InitialState.txt", "w");

  if (r == NULL){
    printf("FILE OPEN ERROR");
    return 0;
  }

  else {
    printf("Writing to file\n");
    fprintf(r, "%i ", worldSize);
    for(int a=0; a<WorldSize; a++){
      for(int b=0; b<WorldSize; b++){

        fprintf(r,"%i ",grid[a][b]);
      }
      fprintf(r, "\n");
    }

    fclose(r);
  }
  return 1;
}



//loads game from a file.
int loadGame(){

  FILE *r;
  r = fopen("InitialState.txt", "r");

  if (r == NULL){
    printf("FILE OPEN ERROR");
    return 0;
  }

  else {
    fscanf(r, "%i ", &worldSize);
    printf("Reading from file\n");
    for(int a=0; a<WorldSize; a++){
      for(int b=0; b<WorldSize; b++){

        fscanf(r,"%i ",&grid[a][b]);
      }
      fscanf(r, "\0");
    }

    fclose(r);
  }
  return 1;
}



//returns number of live neighbours for each cell.
int numNeighbours(int x, int y){

  int n = 0;
  if (grid[x][y+1] == 1)
    n++;
  if (grid[x+1][y] == 1 )
    n++;
  if (grid[x+1][y+1] == 1)
    n++;
  if (grid[x-1][y-1] == 1)
    n++;
  if (grid[x][y-1] == 1)
    n++;
  if (grid[x-1][y] == 1)
    n++;
  if (grid[x+1][y-1] == 1)
    n++;
  if (grid[x-1][y+1] == 1)
    n++;
  return n;
}


//determines whether a cell should become alive, die or stay the same.
int stateChange(int neighbours, int x, int y){

  if (grid[x][y] == 0){
    if (neighbours == 3){
      return 1;
    }
  }

  else if (grid[x][y] == 1){
    if (neighbours < 2 || neighbours >3){
      return 0;
    }
  }

  else return -1;

  return 55;
}
