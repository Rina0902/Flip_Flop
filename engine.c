//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "header.h"
#include "engine.h"
#include "functions.h"


SDL_Surface *load_image( char* filename ) 
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;
    
    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;
    
    //Load the image
    loadedImage = IMG_Load( filename);
    
    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );
        
        //Free the old image
        SDL_FreeSurface( loadedImage );

        //If the image was optimized just fine
        if( optimizedImage != NULL )
        {
            //Map the color key
            Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 0, 0 ,0);

            //Set all pixels of color R 0, G 0xFF, B 0xFF to be transparent
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );
        }
    }

        //Return the optimized image
    return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{

    //Temporary rectangle to hold the offsets
    SDL_Rect offset;
    
    //Get the offsets
    offset.x = x;
    offset.y = y;
    
    //Blit the surface
    SDL_BlitSurface( source, NULL, destination, &offset );
}

//checking the message
int Check_rendering(SDL_Surface *message)
{
    if (message = NULL)
    {
        return 1;
    }
}



bool init()

{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;    
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        return false;    
    }
    
    //Initialize SDL_mixer
    if ( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        return false;    
    }

    //If eveything loads fine
    return true;    
}

void clean_up()
{
    
    SDL_FreeSurface(personnage);
    SDL_FreeSurface(bouton_jouer);
    SDL_FreeSurface(bouton_option);
    SDL_FreeSurface(bouton_quitter);
    SDL_FreeSurface(mere);
    SDL_FreeSurface(fils);
    SDL_FreeSurface(texte_quitter);
    Mix_FreeMusic(musique);
    Mix_FreeChunk(soundEffect);
   
    //Close the font
    TTF_CloseFont( fontTest );
    TTF_CloseFont( fontTest1 );
    
    //Quit SDL_mixer
    Mix_CloseAudio();

    //Quit SDL_ttf
    TTF_Quit();
    
    //Quit SDL
    SDL_Quit();
}


//Full screen
void windowFunction (Window* theWindow)
{
    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE | SDL_RESIZABLE );
    
    //If there's an error
    if( screen == NULL )
    {
        theWindow->windowOK = false;
        return;
    }
    else
    {
        theWindow->windowOK = true;    
    }
    
    //Set the window caption
    SDL_WM_SetCaption( "Flip Flop", NULL );
    
    //Set window flag
    theWindow->windowed = true;
}

void toggle_fullscreen(Window* theWindow)
{
    //If the screen is windowed
    if( theWindow->windowed == true )
    {
        //Set the screen to fullscreen
        screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE | SDL_RESIZABLE | SDL_FULLSCREEN );
                         
        //If there's an error
        if( screen == NULL )
        {
            theWindow->windowOK = false;
            return;
        }
        
        //Set the window state flag
        theWindow->windowed = false;
    }
    //If the screen is fullscreen
    else if( theWindow->windowed == false )
    {
        //Window the screen
        screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE | SDL_RESIZABLE );
                     
        //If there's an error
        if( screen == NULL )
        {
            theWindow->windowOK = false;
            return;
        }
       
        //Set the window state flag
        theWindow->windowed = true;
    }
}

void handle_events(Window* theWindow)
{

    //If there's something wrong with the window
    if( theWindow->windowOK == false )
    {
        printf("theWindow->windowOK == false\n");
        return;    
    }
    
    //If the window resized
    if( event.type == SDL_VIDEORESIZE )
    {
   
        //Resize the screen
        screen = SDL_SetVideoMode( event.resize.w, event.resize.h, SCREEN_BPP, SDL_SWSURFACE | SDL_RESIZABLE );
        
        //If there's an error
        if( screen == NULL )
        {
            theWindow->windowOK = false;
            return;
        }
    }
      //If enter was pressed
    else if( ( event.type == SDL_KEYDOWN ) && ( event.key.keysym.sym == SDLK_RETURN ) )
    {
        //Turn fullscreen on/off
        toggle_fullscreen(theWindow);
        printf("made the function toggle_fullscreen\n ");
    }
    else if( event.type == SDL_VIDEOEXPOSE )
    {
        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            //If there's an error
            theWindow->windowOK = false;
            return;
        }
    }
}

bool error(Window* theWindow)
{
    return !theWindow->windowOK;
}

void moveMouse()
{
    bool buttonPlay = false;
    bool buttonOption = false;
    bool buttonQuit = false;
    bool buttonQuitOption = false;
    int BoutonXjouer = (screen->w - bouton_jouer->w ) / 2;
    int BoutonYjouer =  (screen->h - bouton_jouer->h ) / 2  ;
    int BoutonXoption = (screen->w - bouton_option->w ) / 2;
    int BoutonYoption = ((screen->h - bouton_option->h) / 2) -100;
    int BoutonXquitter = (screen->w - bouton_quitter->w ) / 2 ;
    int BoutonYquitter = ((screen->h - bouton_quitter->h ) / 2 ) +100 ;
    int BoutonXecranReduit = (screen->w - bouton_ecran_reduit->w ) / 2;
    int BoutonYecranReduit = (( screen->h - bouton_ecran_reduit->h ) / 2) +40;
    int BoutonXfermeture =((screen->w - bouton_fermeture_option->w ) / 2) +40 ;
    int BoutonYfermeture= ( (screen->h - bouton_fermeture_option->h ) / 2)-220;
    int BoutonXpleinEcran =(screen->w - bouton_plein_ecran->w ) / 2 ;
    int BoutonYpleinEcran= (( screen->h - bouton_plein_ecran->h ) / 2) +120;



    if (event.type == SDL_KEYDOWN)
    {

        if((event.key.keysym.sym == SDLK_DOWN )&&( option == false )&&( menu ) &&  (buttonQuit == false) 
                && (buttonOption == false) && (buttonPlay == false) && (buttonQuitOption == false) )
        {
            mouse_detect_botton = 1;
            buttonPlay = true;
            SDL_Delay(150);
        }
        else if((event.key.keysym.sym == SDLK_DOWN)&&(option == false) && ( menu ) && (buttonQuit == false) 
                && (buttonOption == false) && (buttonPlay == true) && (buttonQuitOption == false) )
        {
            mouse_detect_botton = 2;
            buttonPlay = false;
            buttonOption = true;
            SDL_Delay(150);
    
        }
        else if((event.key.keysym.sym == SDLK_DOWN)&&(option == false ) && (menu) && (buttonQuit == false) 
                && (buttonOption) && (buttonPlay == false) && (buttonQuitOption == false) )
        {
            mouse_detect_botton = 3;
            buttonOption = false;
            buttonQuit = true; 
            SDL_Delay(150);
        }
        else if((event.key.keysym.sym == SDLK_DOWN)&&(option == false)&&(menu) && (buttonQuit ) 
                && (buttonOption) && (buttonPlay == false) && (buttonQuitOption == false) )
        {
            mouse_detect_botton = 1;
             buttonQuit = false; 
            SDL_Delay(150);
        }
        else if ((event.key.keysym.sym == SDLK_RETURN)&& mouse_detect_botton == 2)
        {
            menu =false;
            option = true;
            mouse_detect_botton = 0;
        
        }
    }
 
    else if((menu == true)&&(event.type==SDL_MOUSEMOTION))
    {
        int x = 0;
        int y = 0;

        SDL_GetMouseState(&x,&y);
        //event mose motion 
 
        if ( 
            (event.motion.x > BoutonXjouer && 
            event.motion.x < BoutonXjouer + bouton_jouer->clip_rect.w && 
            event.motion.y > BoutonYjouer && 
            event.motion.y < BoutonYjouer + bouton_jouer->clip_rect.h) && (option == false))
        {
            //Mix_PlayChannel(-1,soundEffect,0);
            mouse_detect_botton = 2;
        }
    
        
       else if((event.motion.x > BoutonXoption && 
                event.motion.x < BoutonXoption+ bouton_option->clip_rect.w && 
                event.motion.y > BoutonYoption&& 
                event.motion.y < BoutonYoption+ bouton_option->clip_rect.h)
                &&(option == false)) 
    {

            //Mix_PlayChannel(-1,soundEffect,0);
           mouse_detect_botton = 1;
        }
        else if((event.motion.x > BoutonXquitter && 
                event.motion.x < BoutonXquitter+ bouton_quitter->clip_rect.w && 
                event.motion.y > BoutonYquitter && 
                event.motion.y < BoutonYquitter+ bouton_quitter->clip_rect.h)
                &&(option == false)) 
        
        //Mix_PlayChannel(-1,soundEffect,0);
            mouse_detect_botton=3;
        
        else
            mouse_detect_botton = 0;
    }
    else if ((event.type == SDL_MOUSEBUTTONDOWN) && (menu))
    {
        
        if( (event.button.button == SDL_BUTTON_LEFT)&&
            ((event.motion.x > BoutonXjouer )&& 
             event.motion.x < BoutonXjouer + bouton_option->clip_rect.w && 
             event.motion.y > BoutonYjouer && 
             event.motion.y < BoutonYjouer + bouton_option->clip_rect.h))
        {
            Mix_PlayChannel(-1,soundEffect,0);
            option = true;
            menu = false;
        }
    }
    else if ((option) && (event.type == SDL_MOUSEMOTION))
    {
        int x = 0;
        int y = 0;
        SDL_GetMouseState(&x,&y);

        if ((event.motion.x > BoutonXfermeture )&& 
            event.motion.x < BoutonXfermeture+ bouton_ecran_reduit->clip_rect.w && 
            event.motion.y > BoutonXfermeture && 
            event.motion.y < BoutonXfermeture + bouton_ecran_reduit->clip_rect.h)

            quit_option = 1;

        else if ((event.motion.x > BoutonXecranReduit )&& 
                event.motion.x < BoutonXecranReduit+ bouton_ecran_reduit->clip_rect.w && 
                event.motion.y > BoutonYecranReduit && 
                event.motion.y < BoutonYecranReduit + bouton_ecran_reduit->clip_rect.h)

            mouse_detect_botton = 4;
    }

    else if((event.motion.x > BoutonXpleinEcran )&& 
                event.motion.x < BoutonXpleinEcran+ bouton_ecran_reduit->clip_rect.w && 
                event.motion.y > BoutonYpleinEcran && 
                event.motion.y < BoutonYpleinEcran + bouton_ecran_reduit->clip_rect.h)
    
        mouse_detect_botton = 5;
    else
    {
        quit_option = 0; 
        mouse_detect_botton = 0;
    }
    
    /*else if ((option)&&(event.type == SDL_MOUSEBUTTONDOWN))
    {
        int x = 0;
        int y = 0;
        SDL_GetMouseState(&x,&y);
        if((event.motion.x> 550 ) && (event.motion.x < 600 )&&(event.motion.y > 120) && (event.motion.y<190)
        &&( event.button.button == SDL_BUTTON_LEFT))
        {
            menu = true;
            option= false;
            quit_option=0;
            Mix_PlayChannel(-1,soundEffect,0);
        }
        else
            menu=0;
    }
    else if ((option==0)&&(event.motion.x>375)&&(event.motion.x<570)&&(event.motion.y>400)&&(event.motion.y<450)&&(event.button.button==SDL_BUTTON_LEFT))
    {
        return;
    }*/
}