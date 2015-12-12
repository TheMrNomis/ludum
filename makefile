CC = g++
LIBS = -lsfml-window -lsfml-system -lsfml-graphics
FLAGS = -std=c++14 -Wall -pedantic
INCLUDES = -I./Header
PROJECT_NAME = ludum.out
BUILD_DIR = ./build/

objects = main.o Window.o Building.o World.o Object.o Room.o FireDetector.o

all: $(objects)
	$(CC) -o $(BUILD_DIR)$(PROJECT_NAME) $^ $(LIBS)

%.o: %.cpp %.h
	$(CC) -c $< $(FLAGS) $(INCLUDES)

%.o: Source/%.cpp Header/%.h
	$(CC) -c $< $(FLAGS) $(INCLUDES)

main.o: Source/main.cpp
	$(CC) -c $< $(FLAGS) $(INCLUDES)

.PHONY: clean

clean:
	-rm -f *.o
