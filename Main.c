//Main module in which the functions from "Logic.c" and "Graphics.c" are implemented to create Conway's Game of Life.

#include <stdlib.h>
#include <stdio.h>
#include "Logic.h"
#include "Graphics.h"
#include <SDL2/SDL.h>
#include "string.h"
#include "stdbool.h"

int main(int argc, char* args[]){


  int moveCounter = 0;
  int numMoves = 15;
  loadGame();

  init();


  int next[worldSize][worldSize]; //a grid that represents the next generation.


  int  z = 0;
  while (z == 0){

    //compying all of the cells from the grid to the next generation array.
    for(int a=0; a<worldSize; a++){
      for(int b=0; b<worldSize; b++){
        next[a][b] = grid[a][b];
      }
    }


    if (moveCounter == numMoves){
      z=1;
    }

    //iterates over the grid ignoring the edge cells.
    for(int i=1; i<worldSize-1; i++){
      for(int j=1; j<worldSize-1; j++){

      int neighbours = (numNeighbours(i,j));
      int state = (stateChange(neighbours, i, j));

      if(state == 1){
        next[i][j] = 1;   //turns a cell to a 1 signifying it is alive
      }

      else if(state == 0){
        next[i][j] = 0;
      }

      else {
        next[i][j] = grid[i][j];
      }

    }
  }
  drawGrid(worldSize);


  //iterates over the grid filling the squares that are a 1.
  for(int x = 0; x<worldSize; x++){
    for(int y = 0; y<worldSize; y++){
      grid[x][y] = next[x][y];
      if (grid[x][y] == 1){
        fillSquare(x,y);
      }
    }
  }
  showGrid();
  moveCounter++;    //increment due to this generation now being over.
}

  saveGame();
  closeup();
  return 1;
}
