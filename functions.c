#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <stdbool.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include "header.h"
#include "functions.h"
#include "engine.h"



void functionRendering()
{
     
    //Render text menu
    message = TTF_RenderText_Solid(fontTest,"gimme cum",textColor);
    Check_rendering (message);

    texte_quitter = TTF_RenderText_Solid(fontTest,"quitter",textColor);
    texte_option = TTF_RenderText_Solid(fontTest,"options",textColor);
    texte_jouer = TTF_RenderText_Solid(fontTest,"jouer",textColor);
    texte_menu = TTF_RenderText_Solid(fontTest1,"menu",textColor);
    Check_rendering (texte_quitter);
    Check_rendering (texte_option);
    Check_rendering (texte_jouer);
    Check_rendering (texte_menu);
    //Render texte option
    texte_plein_ecran = TTF_RenderText_Solid(fontTest,"fullscreen",textColor);
    texte_ecran_reduit = TTF_RenderText_Solid(fontTest,"normal",textColor);
    texte_volume = TTF_RenderText_Solid(fontTest1,"volume",textColor);
    texte_screen = TTF_RenderText_Solid(fontTest1,"screen",textColor);
    texte_settings = TTF_RenderText_Solid(fontTest1,"option",textColor);
    Check_rendering (texte_plein_ecran);
    Check_rendering (texte_ecran_reduit);
    Check_rendering (texte_volume);
    Check_rendering (texte_screen);
    Check_rendering (texte_settings);
}

void functionloadImage()
{
    
    //Load the background image
    mere = load_image ("images/characters/mom.png");
    fils = load_image ("images/characters/fils.png");
    personnage=load_image("fichier/ahla7.gif");
    bouton_jouer =  IMG_Load("fichier/button6.gif");
    bouton_option= load_image("fichier/button6.gif");
    bouton_quitter= load_image("fichier/button6.gif");
    //Load bottons option
    background_option = load_image("fichier/fondflou.gif");
    bouton_plein_ecran = load_image("fichier/button3.gif");
    bouton_ecran_reduit  = load_image("fichier/button3.gif");
    bouton_volume = load_image("fichier/100.gif");
    bouton_fermeture_option = load_image("fichier/xx.png");
    bouton_fermeture_option_active = load_image("fichier/quit.png");
    bouton_plus_moin = load_image("fichier/Group4.png");
    //bouton active
    botton_active = load_image("fichier/Btn1click.png");

   
        
    //verify image
    verifyImage ( mere);
    verifyImage ( fils);
    verifyImage ( personnage);
    verifyImage ( bouton_jouer);
    verifyImage ( bouton_option);
    verifyImage ( bouton_quitter);
    verifyImage(background_option);
    verifyImage(bouton_plein_ecran );
    verifyImage(bouton_ecran_reduit);
    verifyImage ( bouton_volume);
    verifyImage(bouton_fermeture_option);
    verifyImage(bouton_fermeture_option_active);
    verifyImage(bouton_plus_moin) ;
    verifyImage(botton_active  );
    
 }

bool load_files()
{

    functionloadImage();
    
    //Open the font
    fontTest = TTF_OpenFont("fichier/game2.ttf",35);
    fontTest1 = TTF_OpenFont("fichier/game.ttf",35);

    

    //verify font
    verifyFont( fontTest);
    verifyFont( fontTest1);

    // load effect
    soundEffect = Mix_LoadWAV("fichier/son_bref.wav");
    //load musique 
    musique = Mix_LoadMUS("fichier/soncontinue.mp3");

    //verify effect
    verifyEffect (soundEffect);
    //verify music
    verifyMusic (musique);

    //If everything loaded fine
    return true;    
}

//verification:
// verify music 
bool verifyMusic(Mix_Music *music)
{
    //If there was a problem loading the music
    if( music == NULL )
    {
        printf("music is null\n");
        return false;    
    }
    return true;
}
//verify effect
bool verifyEffect ( Mix_Chunk *soundEffect)
{
       //If there was a problem loading the sound effects
    if ( soundEffect == NULL ) 
    {
        printf("effect is null\n");
        return false;    
    }
    return true;
}
// verify image
bool verifyImage ( SDL_Surface * image)
{
      //If there was a problem in loading the background
    if( image == NULL )
    {
        printf("image is null\n");
        return false;    
    }
    return true;
    
}
// verify font
bool verifyFont(  TTF_Font * font)
{
    //If there was an error in loading the font
    if( font == NULL )
    {
        printf("Font loading error");
        return false;
    }
    return true;
}

//apply surface Menu
void applyMenuJouerSurface()
{
       //images
    apply_surface((screen->w - personnage->w ) / 2, ( screen->h - personnage->h ) / 2, personnage, screen );
    apply_surface(550, 150, mere, personnage );
    apply_surface(170, 200, fils, personnage );
    //positions botons menu non activé
    apply_surface((screen->w - bouton_jouer->w ) / 2, ( screen->h - bouton_jouer->h ) / 2,  bouton_jouerActive, screen );
    apply_surface((screen->w - bouton_option->w ) / 2, ( (screen->h - bouton_option->h ) / 2)-100,  bouton_option, screen );
    apply_surface((screen->w - bouton_quitter->w ) / 2, ( (screen->h - bouton_quitter->h ) / 2)+100,  bouton_quitter, screen );
    //position texte menu 
    apply_surface(((screen->w - bouton_jouer->w ) / 2)+45, ( (screen->h - bouton_jouer->h ) / 2)-90, texte_jouer, screen );
    apply_surface(((screen->w - bouton_option->w ) / 2)+45, ( (screen->h - bouton_option->h ) / 2)+110, texte_quitter, screen );
    apply_surface(((screen->w - bouton_jouer->w ) / 2)+45, ((screen->h - bouton_jouer->h ) / 2)+10,  texte_option, screen );
    apply_surface(((screen->w - bouton_jouer->w ) / 2)+60 , ( (screen->h - bouton_jouer->h ) / 2)-200, texte_menu, screen );

}

void applyMenuOptionSurface()
{
    //images
    apply_surface((screen->w - personnage->w ) / 2, ( screen->h - personnage->h ) / 2, personnage, screen );
    apply_surface(550, 150, mere, personnage );
    apply_surface(170, 200, fils, personnage );
    //positions botons menu non activé
    apply_surface((screen->w - bouton_jouer->w ) / 2, ( screen->h - bouton_jouer->h ) / 2,  bouton_jouer, screen );
    apply_surface((screen->w - bouton_option->w ) / 2, ( (screen->h - bouton_option->h ) / 2)-100,  bouton_optionActive, screen );
    apply_surface((screen->w - bouton_quitter->w ) / 2, ( (screen->h - bouton_quitter->h ) / 2)+100,  bouton_quitter, screen );
    //position texte menu 
    apply_surface(((screen->w - bouton_jouer->w ) / 2)+45, ( (screen->h - bouton_jouer->h ) / 2)-90, texte_jouer, screen );
    apply_surface(((screen->w - bouton_option->w ) / 2)+45, ( (screen->h - bouton_option->h ) / 2)+110, texte_quitter, screen );
    apply_surface(((screen->w - bouton_jouer->w ) / 2)+45, ((screen->h - bouton_jouer->h ) / 2)+10,  texte_option, screen );
    apply_surface(((screen->w - bouton_jouer->w ) / 2)+60 , ( (screen->h - bouton_jouer->h ) / 2)-200, texte_menu, screen );

}

void applyMenuQuitterSurface()
{

    //images
    apply_surface((screen->w - personnage->w ) / 2, ( screen->h - personnage->h ) / 2, personnage, screen );
    apply_surface(550, 150, mere, personnage );
    apply_surface(170, 200, fils, personnage );
    //positions botons menu non activé
    apply_surface((screen->w - bouton_jouer->w ) / 2, ( screen->h - bouton_jouer->h ) / 2,  bouton_jouer, screen );
    apply_surface((screen->w - bouton_option->w ) / 2, ( (screen->h - bouton_option->h ) / 2)-100,  bouton_option, screen );
    apply_surface((screen->w - bouton_quitter->w ) / 2, ( (screen->h - bouton_quitter->h ) / 2)+100,  bouton_quitterActive, screen );
    //position texte menu 
    apply_surface(((screen->w - bouton_jouer->w ) / 2)+45, ( (screen->h - bouton_jouer->h ) / 2)-90, texte_jouer, screen );
    apply_surface(((screen->w - bouton_option->w ) / 2)+45, ( (screen->h - bouton_option->h ) / 2)+110, texte_quitter, screen );
    apply_surface(((screen->w - bouton_jouer->w ) / 2)+45, ((screen->h - bouton_jouer->h ) / 2)+10,  texte_option, screen );
    apply_surface(((screen->w - bouton_jouer->w ) / 2)+60 , ( (screen->h - bouton_jouer->h ) / 2)-200, texte_menu, screen );

}

void applyMenuDeafaultSurface()
{
   
    //images
    apply_surface((screen->w - personnage->w ) / 2, ( screen->h - personnage->h ) / 2, personnage, screen );
    apply_surface(550, 150, mere, personnage );
    apply_surface(170, 200, fils, personnage );
    //positions botons menu non activé
    apply_surface((screen->w - bouton_jouer->w ) / 2, ( screen->h - bouton_jouer->h ) / 2,  bouton_option, screen );
    apply_surface((screen->w - bouton_option->w ) / 2, ( (screen->h - bouton_option->h ) / 2)-100,  bouton_jouer, screen );
    apply_surface((screen->w - bouton_quitter->w ) / 2, ( (screen->h - bouton_quitter->h ) / 2)+100,  bouton_quitter, screen );
    //position texte menu 
    apply_surface(((screen->w - bouton_jouer->w ) / 2)+45, ( (screen->h - bouton_jouer->h ) / 2)-90, texte_jouer, screen );
    apply_surface(((screen->w - bouton_option->w ) / 2)+45, ( (screen->h - bouton_option->h ) / 2)+110, texte_quitter, screen );
    apply_surface(((screen->w - bouton_jouer->w ) / 2)+45, ((screen->h - bouton_jouer->h ) / 2)+10,  texte_option, screen );
    apply_surface(((screen->w - bouton_jouer->w ) / 2)+60 , ( (screen->h - bouton_jouer->h ) / 2)-200, texte_menu, screen );


}

//apply surface option
void applyMenuOptionDeafaultSurface()
{

    //images
    apply_surface((screen->w - personnage->w ) / 2, ( screen->h - personnage->h ) / 2, background_option, screen );
    //positions boutons option
    apply_surface((screen->w - bouton_plein_ecran->w ) / 2, (( screen->h - bouton_plein_ecran->h ) / 2) +120, bouton_plein_ecran, screen );
    apply_surface((screen->w - bouton_ecran_reduit->w ) / 2, (( screen->h - bouton_ecran_reduit->h ) / 2) +40 , bouton_ecran_reduit, screen );
    apply_surface(((screen->w - bouton_volume->w ) / 2) -60, (( screen->h - bouton_volume->h ) / 2) -100, bouton_volume, screen );
    apply_surface(((screen->w - bouton_plus_moin->w ) / 2) +120, (( screen->h - bouton_plus_moin->h ) / 2) -100, bouton_plus_moin, screen );
    apply_surface(((screen->w - bouton_fermeture_option->w ) / 2) +40 , ( (screen->h - bouton_fermeture_option->h ) / 2)-220, bouton_fermeture_option, screen );
   //positions texte option
    apply_surface(((screen->w - bouton_plein_ecran->w ) / 2) +20, (( screen->h - bouton_plein_ecran->h ) / 2) +130, texte_plein_ecran, screen );
    apply_surface((screen->w - texte_ecran_reduit->w ) / 2, (( screen->h - texte_ecran_reduit->h ) / 2) +40 , texte_ecran_reduit, screen );
    apply_surface(((screen->w - texte_volume->w ) / 2) +10, (( screen->h - texte_volume->h ) / 2) -150, texte_volume, screen );
    apply_surface (((screen->w - bouton_fermeture_option->w ) / 2 ) +50, ( (screen->h - bouton_fermeture_option->h ) / 2), texte_screen, screen );
    apply_surface(((screen->w - texte_settings->w ) / 2) +10 , ( (screen->h - texte_settings->h ) / 2)-220, texte_settings, screen );

}

void applyMenuOptionFermetureActiveSurface()
{
    //images
    apply_surface((screen->w - personnage->w ) / 2, ( screen->h - personnage->h ) / 2, personnage, screen );
    //positions boutons option
    apply_surface((screen->w - bouton_plein_ecran->w ) / 2, (( screen->h - bouton_plein_ecran->h ) / 2) +120, bouton_plein_ecran, screen );
    apply_surface((screen->w - bouton_ecran_reduit->w ) / 2, (( screen->h - bouton_ecran_reduit->h ) / 2) +40 , bouton_ecran_reduit, screen );
    apply_surface(((screen->w - bouton_volume->w ) / 2) -60, (( screen->h - bouton_volume->h ) / 2) -100, bouton_volume, screen);
    apply_surface(((screen->w - bouton_plus_moin->w ) / 2) +120, (( screen->h - bouton_plus_moin->h ) / 2) -100, bouton_plus_moin, screen  );
    apply_surface(((screen->w - bouton_fermeture_option_active->w ) / 2) +40 , ( (screen->h - bouton_fermeture_option_active->h ) / 2)-220, bouton_fermeture_option_active, screen  );
   //positions texte option
    apply_surface(((screen->w - bouton_plein_ecran->w ) / 2) +20, (( screen->h - bouton_plein_ecran->h ) / 2) +130, texte_plein_ecran, screen);
    apply_surface((screen->w - texte_ecran_reduit->w ) / 2, (( screen->h - texte_ecran_reduit->h ) / 2) +40 , texte_ecran_reduit, screen );
    apply_surface(((screen->w - texte_volume->w ) / 2) +10, (( screen->h - texte_volume->h ) / 2) -150, texte_volume, screen );
    apply_surface (((screen->w - bouton_fermeture_option->w ) / 2 ) +50, ( (screen->h - bouton_fermeture_option->h ) / 2), texte_screen, screen );
    apply_surface(((screen->w - texte_settings->w ) / 2) +10 , ( (screen->h - texte_settings->h ) / 2)-220, texte_settings, screen );
}

void applyMenuOptionReduitActiveSurface()
{
 
    //images
    apply_surface((screen->w - personnage->w ) / 2, ( screen->h - personnage->h ) / 2, background_option, screen );
    //positions boutons option
    printf("//positions boutons option\n");
    apply_surface((screen->w - bouton_plein_ecran->w ) / 2, (( screen->h - bouton_plein_ecran->h ) / 2) +120, bouton_plein_ecran, screen );
    apply_surface((screen->w - bouton_ecran_reduit_active->w ) / 2, (( screen->h - bouton_ecran_reduit_active->h ) / 2) +40 , bouton_ecran_reduit_active, screen );
    apply_surface(((screen->w - bouton_volume->w ) / 2) -60, (( screen->h - bouton_volume->h ) / 2) -100, bouton_volume, screen );
    apply_surface(((screen->w - bouton_plus_moin->w ) / 2) +120, (( screen->h - bouton_plus_moin->h ) / 2) -100, bouton_plus_moin, screen );
    apply_surface(((screen->w - bouton_fermeture_option->w ) / 2) +40 , ( (screen->h - bouton_fermeture_option->h ) / 2)-220, bouton_fermeture_option, screen );
   //positions texte option
       printf("//positions texte option\n");
    apply_surface(((screen->w - bouton_plein_ecran->w ) / 2) +20, (( screen->h - bouton_plein_ecran->h ) / 2) +130, texte_plein_ecran, screen );
    apply_surface((screen->w - texte_ecran_reduit->w ) / 2, (( screen->h - texte_ecran_reduit->h ) / 2) +40 , texte_ecran_reduit, screen );
    apply_surface(((screen->w - texte_volume->w ) / 2) +10, (( screen->h - texte_volume->h ) / 2) -150, texte_volume, screen );
    apply_surface (((screen->w - bouton_fermeture_option->w ) / 2 ) +50, ( (screen->h - bouton_fermeture_option->h ) / 2), texte_screen, screen );
    apply_surface(((screen->w - texte_settings->w ) / 2) +10 , ( (screen->h - texte_settings->h ) / 2)-220, texte_settings, screen );
}

void applyMenuOptionEcranActiveSurface()
{

    //images
    apply_surface((screen->w - personnage->w ) / 2, ( screen->h - personnage->h ) / 2, background_option, screen );
    //positions boutons option
    apply_surface((screen->w - bouton_plein_ecran_active->w ) / 2, (( screen->h - bouton_plein_ecran_active->h ) / 2) +120, bouton_plein_ecran_active, screen );
    apply_surface((screen->w - bouton_ecran_reduit->w ) / 2, (( screen->h - bouton_ecran_reduit->h ) / 2) +40 , bouton_ecran_reduit, screen );
    apply_surface(((screen->w - bouton_volume->w ) / 2) -60, (( screen->h - bouton_volume->h ) / 2) -100, bouton_volume, screen );
    apply_surface(((screen->w - bouton_plus_moin->w ) / 2) +120, (( screen->h - bouton_plus_moin->h ) / 2) -100, bouton_plus_moin, screen );
    apply_surface(((screen->w - bouton_fermeture_option->w ) / 2) +40 , ( (screen->h - bouton_fermeture_option->h ) / 2)-220, bouton_fermeture_option, screen );
   //positions texte option
    apply_surface(((screen->w - bouton_plein_ecran->w ) / 2) +20, (( screen->h - bouton_plein_ecran->h ) / 2) +130, texte_plein_ecran, screen );
    apply_surface((screen->w - texte_ecran_reduit->w ) / 2, (( screen->h - texte_ecran_reduit->h ) / 2) +40 , texte_ecran_reduit, screen );
    apply_surface(((screen->w - texte_volume->w ) / 2) +10, (( screen->h - texte_volume->h ) / 2) -150, texte_volume, screen );
    apply_surface (((screen->w - bouton_fermeture_option->w ) / 2 ) +50, ( (screen->h - bouton_fermeture_option->h ) / 2), texte_screen, screen );
    apply_surface(((screen->w - texte_settings->w ) / 2) +10 , ( (screen->h - texte_settings->h ) / 2)-220, texte_settings, screen );

}