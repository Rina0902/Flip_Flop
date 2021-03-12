#pragma once

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <stdbool.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>

//Screen attributes
int SCREEN_WIDTH ;
int SCREEN_HEIGHT;
int SCREEN_BPP ;

//background option
SDL_Surface *background_option;
SDL_Surface* screen;
SDL_Surface *mere;
SDL_Surface *fils;
SDL_Surface *personnage;
  

// boutons menu
SDL_Surface *bouton_jouer;
SDL_Surface *bouton_option;
SDL_Surface *bouton_quitter;
//boutons activé
SDL_Surface *bouton_jouerActive;
SDL_Surface *bouton_optionActive;
SDL_Surface *bouton_quitterActive;
//botons option
SDL_Surface *bouton_plein_ecran;
SDL_Surface *bouton_ecran_reduit;
SDL_Surface *bouton_volume;
SDL_Surface *bouton_plus_moin;
//SDL_Surface *bouton_moin;
SDL_Surface *bouton_fermeture_option;
SDL_Surface *bouton_fermeture_option_active;
SDL_Surface * bouton_ecran_reduit_active;
SDL_Surface * bouton_plein_ecran_active;
SDL_Surface * botton_active;

//variables
int mouse_detect_botton;
bool quit_option;
bool menu ;
bool option ;
int h;
int volume ;


//texte menu
SDL_Surface *texte_quitter;
SDL_Surface *texte_option;
SDL_Surface *texte_jouer;
SDL_Surface *texte_menu;
//texte option
SDL_Surface *texte_plein_ecran;
SDL_Surface *texte_ecran_reduit;
SDL_Surface *texte_volume;
SDL_Surface *texte_screen;
SDL_Surface *texte_settings;

   SDL_Surface* message;

//The color of the font
SDL_Color textColor;

//Font
TTF_Font *fontTest;
TTF_Font *fontTest1;

//Music
Mix_Music *musique;
Mix_Chunk *soundEffect;

//The event structure that will be used
SDL_Event event;

//background menu 
SDL_Surface *personnage;


typedef struct Window
{
    //Whether the window is windowed or not
    bool windowed;
    
    //Whether the window is fine
    bool windowOK;
    
} Window ;





