CC = g++
LIBS = -lsfml-window -lsfml-system -lsfml-graphics
FLAGS = -std=c++14 -Wall -pedantic
INCLUDES = -I./Header
PROJECT_NAME = ludum.out
BUILD_DIR = ./build/

objects := $(patsubst %.cpp, %.o, $(wildcard Source/*.cpp))

all: $(objects)
	$(CC) -o $(BUILD_DIR)$(PROJECT_NAME) $^ $(LIBS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(FLAGS) $(INCLUDES)

%.o: Source/%.cpp
	$(CC) -o $@ -c $< $(FLAGS) $(INCLUDES)

main.o: Source/main.cpp
	$(CC) -o $@ -c $< $(FLAGS) $(INCLUDES)

.PHONY: clean

clean: $(objects)
	-rm -f $^
	-rm -f $(BUILD_DIR)$(PROJECT_NAME)
