#$(CC) = gcc

#final:
#	$(CC) main.c game.c components.c -o main `sdl-config --cflags --libs`

#OBJS specifies which files to compile as part of the project
OBJS = main.c game.c player.c enemies.c fruits.c menu.c

#CC specifies which compiler is used
CC = gcc

#COMPILER_FLAGS specifies the additional compilation options used
#-w suppresses all warnings
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries that being linked against
LINKER_FLAGS = -lSDL2 -lSDL2_image -pthread

#OBJ_NAME specifies tha name of our executable
OBJ_NAME = main

#Target for compilation
all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)