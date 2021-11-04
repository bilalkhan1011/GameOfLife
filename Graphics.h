// Header file containing function prototypes for the Graphics.c module.
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "stdio.h"
#include "string.h"
#include "stdbool.h"


void  init(void);

void  drawGrid(int size);

void fillSquare(int x, int y);

void showGrid();

void closeup();
