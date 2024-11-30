OBJS = main.cpp

CC = g++

COMPILER_FLAGS = -w

LINKER_FLAGS =

OBJ_NAME = main

all : $(OBJ_NAME)

$(OBJ_NAME): $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

clean:
	rm -f $(OBJ_NAME)