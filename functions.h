#pragma once

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <stdbool.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include "header.h"


void functionRendering();
void functionloadImage();
bool load_files();
//verification
bool verifyMusic(Mix_Music *music);
bool verifyEffect ( Mix_Chunk *soundEffect);
bool verifyImage ( SDL_Surface * image);
bool verifyFont(  TTF_Font * font);
//Menu
void applyMenuJouerSurface();
void applyMenuOptionSurface();
void applyMenuQuitterSurface();
void applyMenuDeafaultSurface();
void applyMenuOptionDeafaultSurface();
void applyMenuOptionFermetureActiveSurface();
void applyMenuOptionReduitActiveSurface();
void applyMenuOptionEcranActiveSurface();

