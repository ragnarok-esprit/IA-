#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"

typedef struct
{
SDL_Surface *right1;
SDL_Surface *right2;
SDL_Surface *right3;
SDL_Surface *right4;

SDL_Surface *left1;
SDL_Surface *left2;
SDL_Surface *left3;
SDL_Surface *left4;
}ennemyx;

typedef struct
{
SDL_Surface *fire1;
SDL_Surface *fire2;
}firex;

ennemyx Loadx(ennemyx E);

firex Loadf(firex F);

void afficher_ennemyx(SDL_Surface *screen,SDL_Rect position , int direction ,int counter ,ennemyx E);

void afficher_fire(SDL_Surface *screen , int counter ,SDL_Rect position,firex F);

int Distance(SDL_Rect hero , SDL_Rect ennemi);

int update_ennemi(SDL_Rect hero , SDL_Rect ennemi);

void Free_All_en(ennemyx *E);

void Free_All_fr(firex *F);
