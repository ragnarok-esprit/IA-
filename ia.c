#include "ia.h"




ennemyx Loadx(ennemyx E){


E.right1=IMG_Load("x1.png");
E.right2=IMG_Load("x2.png");
E.right3=IMG_Load("x3.png");
E.right4=IMG_Load("x4.png");

E.left1=IMG_Load("xa.png");
E.left1=IMG_Load("xb.png");
E.left1=IMG_Load("xc.png");
E.left1=IMG_Load("xd.png");

return(E);

}


void afficher_ennemyx(SDL_Surface *screen,SDL_Rect position , int direction ,int counter,ennemyx E){


if(direction==2){
switch(counter){
case 1 :
SDL_BlitSurface(E.right1,NULL,screen,&position);
break;
case 2 :
SDL_BlitSurface(E.right2,NULL,screen,&position);
break;
case 3:
SDL_BlitSurface(E.right3,NULL,screen,&position);
break;
case 4 :
SDL_BlitSurface(E.right4,NULL,screen,&position);
break;
}
SDL_Delay(30);
}
else if (direction==1){
switch(counter){
case 1 :
SDL_BlitSurface(E.left1,NULL,screen,&position);
break;
case 2 :
SDL_BlitSurface(E.left2,NULL,screen,&position);
break;
case 3:
SDL_BlitSurface(E.left3,NULL,screen,&position);
break;
case 4 :
SDL_BlitSurface(E.left4,NULL,screen,&position);
break;
}
SDL_Delay(30);
}
//SDL_Delay(30);
//SDL_Flip(screen);

}




firex Loadf(firex F){

F.fire1=IMG_Load("fire1.png");
F.fire2=IMG_Load("fire2.png");
return(F);
}



void afficher_fire(SDL_Surface *screen , int counter ,SDL_Rect position , firex F){

switch(counter){
	case 1 :
	position.x+=10;
SDL_BlitSurface(F.fire1,NULL,screen,&position);
	break;
	case 2 :
SDL_BlitSurface(F.fire2,NULL,screen,&position);
	break;
}

SDL_Delay(30);
}


int Distance(SDL_Rect hero , SDL_Rect ennemi ){
int diff;
int state;
diff=ennemi.x-hero.x;
if(diff<0){
	diff*=-1;
}
	if(diff>300){
		state=1 ; //waiting
	}
	else if(diff<300 && diff> 100){
		state=2; //following
	}
	else if (diff <100){
		state=3; //attacking
	}
	return state ;
}


int update_ennemi(SDL_Rect hero , SDL_Rect ennemi){

int state;
int diff;
SDL_Rect pos_final;
pos_final=ennemi;
diff=ennemi.x-hero.x;
state=Distance(hero,ennemi);
if(diff>0){
	if(state==1){
return(pos_final.x);
}
else if(state==2 ||state ==3){
	pos_final.x -=6;
}

}

else if(diff<0){
	if(state==1){
return(pos_final.x);
}
else if(state==2 ||state ==3){
	pos_final.x +=6;
}
}
return(pos_final.x);
}



void Free_All_en(ennemyx *E){

SDL_FreeSurface(E->right1);
SDL_FreeSurface(E->right2);
SDL_FreeSurface(E->right3);
SDL_FreeSurface(E->right4);
SDL_FreeSurface(E->left1);
SDL_FreeSurface(E->left2);
SDL_FreeSurface(E->left3);
SDL_FreeSurface(E->left4);


}



void Free_All_fr(firex *F){

SDL_FreeSurface(F->fire1);
SDL_FreeSurface(F->fire2);

}
