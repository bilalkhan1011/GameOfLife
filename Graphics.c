//File using the graphics library to draw the generation onto a 2-D world.
//Large amount of code in this file is adapted from the SDL tutorials https://lazyfoo.net/tutorials/SDL/ .

#include <SDL2/SDL.h>

#include "stdio.h"
#include "string.h"
#include "stdbool.h"



const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 900;
const int SQUARE_SIZE = 13;

SDL_Window* window = NULL;

SDL_Surface* screenSurface = NULL;

SDL_Renderer* renderer = NULL;


//creates the window for the game.
void init(){
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
    printf("SDL could not be initialised %s \n\n", SDL_GetError() );
  }

  else{
    window = SDL_CreateWindow( "Conway's Game Of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

    if( window == NULL ){
      printf("Window couldnt be created %s \n", SDL_GetError() );
    }

    else{
      renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);
      SDL_RenderClear(renderer);
    }
  }
  return;
}



//fills a square in the grid at the specified coordinates.
void fillSquare(int x, int y){

  SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
  SDL_Rect rect = {x*SQUARE_SIZE, y*SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE};
  SDL_RenderFillRect(renderer, &rect);

  return;
          }



//initialises the grid full of empty squares.
void drawGrid(int gridSize){

  for(int i = 0; i<gridSize; i++){
    for(int j = 0; j<gridSize; j++){

      SDL_Rect rect = {i*SQUARE_SIZE, j*SQUARE_SIZE , SQUARE_SIZE, SQUARE_SIZE};
      SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
      SDL_RenderDrawRect(renderer, &rect);

  }
}

return;
}



//updates the render to show it to the user for 500ms.
void showGrid(){

  SDL_RenderPresent(renderer);
  SDL_Delay(500);

  return;
  }


//frees the SDL resources once the program is complete.
void closeup(){

  //Destroys the window and renderer
  SDL_DestroyRenderer( renderer );
  SDL_DestroyWindow( window );
  window = NULL;
  renderer = NULL;

  SDL_Quit();
  return;

  }
