#pragma once

//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "header.h"

//Functions:
SDL_Surface *load_image( char* filename );
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );
int Check_rendering(SDL_Surface *message);
void clean_up();
bool init();
//Full screen

void windowFunction (Window* theWindow);
void windowFunction (Window* thewindow);
//Handle window events
void handle_events(Window* theWindow);

//Turn fullscreen on/off
void toggle_fullscreen(Window* theWindow);
//Check if anything's wrong with the window
bool error(Window* theWindow);
void moveMouse();