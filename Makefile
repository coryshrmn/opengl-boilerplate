INC=-I /d/MinGW/include -I /d/glfw/include -I /d/glew/glew-1.10.0/include
LIB=-L /d/glew/glew-1.10.0/lib/Release/Win32/ -L /d/glfw/lib-mingw/
FLAGS=-std=c99 -O3

all: main

run: all
	./main

fresh: clean run

clean:
	rm *.o

main: main.o callbacks.o
	gcc $(FLAGS) main.o callbacks.o -o main $(LIB) -lglew32s -lglfw3 -lopengl32 -lglu32 -lgdi32 

main.o: main.c main.h
	gcc $(FLAGS) $(INC) -c -o main.o main.c

callbacks.o: callbacks.c callbacks.h
	gcc $(FLAGS) $(INC) -c -o callbacks.o callbacks.c
