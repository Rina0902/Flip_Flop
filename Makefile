main: functions.o engine.o main.o
	gcc functions.o engine.o main.o -o main -g -LSDL -LSDL_image -lSDL_mixer -lSDL_ttf
main.o: main.c
	gcc -c main.c -g -LSDL -LSDL_image -lSDL_mixer -lSDL_ttf
functions.o: functions.c
	gcc -c functions.c -g -LSDL -LSDL_image -lSDL_mixer -lSDL_ttf
engine.o: engine.c
	gcc -c engine.c -g -LSDL -LSDL_image -lSDL_mixer -lSDL_ttf

