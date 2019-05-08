#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "ia.h"


int main ()
{
SDL_Surface *screen=NULL;

SDL_Surface *background=NULL;

SDL_Surface *sprite=NULL;



firex F;
ennemyx E;


SDL_Rect positionecran,positionsprte,pos_enemie,pos_fire;

SDL_Event event;

int done=1;

int save_pos;

int counter=0,counter2=0;

int direction =1;

int state =1;

screen = SDL_SetVideoMode(1350,400,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
if(SDL_Init(SDL_INIT_VIDEO)!=0){

printf("Unable to set 1350x400 video :%s\n",SDL_GetError());
return -1 ;
}

 background=SDL_LoadBMP("back.bmp");



positionecran.x=0;
positionecran.y=0;


//SDL_BlitSurface(background,NULL,screen,&positionecran);
positionsprte.x=30;
positionsprte.y=200;

pos_enemie.x=500;
pos_enemie.y=200;

pos_fire.x=400;
pos_fire.y=100;

E=Loadx(E);
F=Loadf(F);



sprite=SDL_LoadBMP("detective.bmp");


SDL_SetColorKey(sprite,SDL_SRCCOLORKEY,SDL_MapRGB(sprite->format,255,255,255));

SDL_EnableKeyRepeat(10,10);

    while (done)

    {

        SDL_PollEvent(&event);
        switch(event.type)
        {

            case SDL_QUIT:

                done = 0;
                break;

        case SDL_KEYDOWN:
switch (event.key.keysym.sym)
{
    case SDLK_ESCAPE:

        done = 0;
        break;

case SDLK_UP :
positionsprte.y-=10;
break;
case SDLK_DOWN :

positionsprte.y+=10;
break;

case SDLK_RIGHT :

positionsprte.x+=10;
break;

case SDLK_LEFT :

positionsprte.x-=10;
break;




default:
break;
}
break;
default:
break;
}


counter++ ;
counter2++ ;

if(counter>4) counter=0;



if(counter>2) counter2=0;

if(pos_enemie.x < positionsprte.x) direction=2;
if (pos_enemie.x > positionsprte.x) direction =1;


SDL_BlitSurface(background,NULL,screen,&positionecran);
SDL_BlitSurface(sprite,NULL,screen,&positionsprte);

pos_enemie.x= update_ennemi(positionsprte, pos_enemie);
afficher_ennemyx(screen,pos_enemie, direction ,counter,E);
state=Distance(positionsprte, pos_enemie);
if(state==3){
pos_fire.x=pos_enemie.x+10;
afficher_fire(screen , counter2 ,pos_fire,F);
}
SDL_Flip(screen);
    }

SDL_FreeSurface(background);
Free_All_fr(&F);
Free_All_en(&E);

SDL_FreeSurface(sprite);
SDL_FreeSurface(screen);

return 0 ;
}
