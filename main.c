#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include "header.h"
#include "functions.h"
#include "engine.h"

int main(int argc,char *argv[])
{
    // Text color
    SDL_Color textColor  = { 0 , 0, 0 };

    //Screen attributes
    SCREEN_WIDTH = 900;
    SCREEN_HEIGHT = 600;
    SCREEN_BPP = 32;

   bouton_jouer = NULL;
   bouton_option = NULL;
   bouton_quitter= NULL;
    //boutons activé
   bouton_jouerActive= NULL;
   bouton_optionActive= NULL;
   bouton_quitterActive= NULL;
    //botons option
   bouton_plein_ecran= NULL;
   bouton_ecran_reduit= NULL;
   bouton_volume= NULL;
   bouton_plus_moin= NULL;
    //SDL_Surface *bouton_moin;
   bouton_fermeture_option= NULL;
   bouton_fermeture_option_active= NULL;
   bouton_ecran_reduit_active= NULL;
   bouton_plein_ecran_active= NULL;
   botton_active= NULL;

    volume = 1;
    mouse_detect_botton = 0;
    quit_option= false;
    menu = true;
    option =false;

 

    //Make sure the program waits for a quit
    bool quit = false;

    //Initialize
    if( init() == false )
    {
        return 1;    
    }
    //Create a window
    Window myWindow;
    windowFunction (&myWindow);
    
    //If the window failed
    if( error(&myWindow) == true )
    {
        printf("error1 is true\n");
        return 1;    
    }
    
    //Load the files
    if( load_files() == false )
    {
        return 1;    
    }
    //message = TTF_RenderText_Solid( fontTest1, "Up was pressed.", textColor );

Mix_PlayMusic ( musique,-1);

functionRendering();


while( quit == false )
{

     //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {

            //Handle window events
            handle_events(&myWindow);
            
            //If escape was pressed
            if( ( event.type == SDL_KEYDOWN ) && ( event.key.keysym.sym == SDLK_ESCAPE ) )
            {
                //Quit the program
                quit = true;
            }

            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }
           //If the window failed
        if( error(&myWindow) == true )
        {
            printf("error2 is true\n");
            return 1;    
        }
    
    if((event.type == SDL_KEYDOWN) && (option) || (event.type == SDL_KEYDOWN) && ( menu )) //ay felsa tetnzel bech yodkhol lil if hedhi
    {
        printf("event.type if\n");

        //Set the proper message surface
        switch( event.key.keysym.sym )
        {
            case SDLK_d:   volume = volume + 5;
                            SDL_Delay(250);
                            h = volume;
                            break;

            case SDLK_u:    volume = volume-5;
                            SDL_Delay(250);
                            h = volume; 
                            if(volume==-4)
                            {   
                                volume=1;
                            }
                             break;
        }
    
//*******************************************************REGLAGE VOLUME AHMED *****************

        switch (h)
        {
            case 1:     if(Mix_PausedMusic() == 1)//Si la musique est en pause
                        {
                            //Reprendre la musique
                            Mix_ResumeMusic(); 
                        }

                       bouton_volume = load_image ("fichier/100.gif");
                        verifyImage(bouton_volume);
                        break;

            case 6 :    if (Mix_PausedMusic() == 1) //Si la musique est en pause
                        {
                            Mix_ResumeMusic(); //Reprendre la musique
                        }
                       bouton_volume = load_image("fichier/75.gif");
                        break;

            case 11 :   if ( Mix_PausedMusic() == 1)//Si la musique est en pause
                        {
                            Mix_ResumeMusic(); //Reprendre la musique
                        }
                       bouton_volume= load_image ( "fichier/50.gif");
                        break;

            case 16 :   if(Mix_PausedMusic() == 1)//Si la musique est en pause
                        {
                            Mix_ResumeMusic(); //Reprendre la musique
                        }
                       bouton_volume= load_image ("fichier/25.gif");
                        break;

            case 21 :   Mix_PauseMusic();
                       bouton_volume = load_image("fichier/0.gif");
                        break;

            Mix_VolumeMusic(MIX_MAX_VOLUME / volume);
        }
    //if you press any keyboard button
    } 
    moveMouse();

    if( ( option == false ) && ( menu  ))
    {

        //printf("here\n");
        switch (mouse_detect_botton)
        {
        case 0 :   applyMenuDeafaultSurface();
                   
               
                    break;

        case 2 :    applyMenuJouerSurface();
                    
                    break;
                        

        case 1 :    applyMenuOptionSurface ();
                  
                    break;

        case 3 :    applyMenuQuitterSurface();
    
                    break;
        }
    }

  
    if (( option  ) && ( menu == false)) 
    {
        switch(mouse_detect_botton)
        {
            case 0 :    
                if(quit_option == false)
                {
                    applyMenuOptionDeafaultSurface();   
                }
                else if(quit_option == true)
                {
                    applyMenuOptionFermetureActiveSurface();
                }
                break;

            case 4 :
            
        
                applyMenuOptionReduitActiveSurface();
                break;
            case 5 :
                applyMenuOptionEcranActiveSurface();
                break;
        }
    }

    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {
        return 1;    
    }
}
    clean_up();
    return 0;
}

