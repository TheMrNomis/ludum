CC = g++
LIBS = -lsfml-window -lsfml-system
FLAGS = -std=c++14 -Wall -pedantic
INCLUDES = -I./
PROJECT_NAME = ludum.out

objects = main.o

all: $(objects)
	$(CC) -o $(PROJECT_NAME) $^ $(LIBS)

%.o: */%.cpp */%.h
	$(CC) -c $< $(FLAGS) $(INCLUDES)

.PHONY: clean

clean:
	-rm -f *.o
