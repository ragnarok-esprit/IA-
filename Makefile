prog:main.o ia.o
	gcc main.o ia.o -o prog -g  -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
main.o:main.c
	gcc -c main.c -g
ia.o:ia.c
	gcc -c ia.c -g
