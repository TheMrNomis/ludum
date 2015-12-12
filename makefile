CC = g++
LIBS = -lsfml-window -lsfml-system -lsfml-graphics
FLAGS = -std=c++14 -Wall -pedantic
INCLUDES = -I./
PROJECT_NAME = ludum.out

objects = main.o Window.o Building.o World.o Object.o Room.o FireDetector.o

all: $(objects)
	$(CC) -o $(PROJECT_NAME) $^ $(LIBS)

%.o: */%.cpp */%.h
	$(CC) -c $< $(FLAGS) $(INCLUDES)

main.o: main.cpp
	$(CC) -c main.cpp $(FLAGS) $(INCLUDES)

.PHONY: clean

clean:
	-rm -f *.o
