CC = g++
LIBS = -lsfml-window -lsfml-system -lsfml-graphics
FLAGS = -std=c++14 -Wall -pedantic
INCLUDES = -I./Header
PROJECT_NAME = ludum.out
BUILD_DIR = Build/

objects := $(patsubst Source/%.cpp, $(BUILD_DIR)%.o, $(wildcard Source/*.cpp))


all: mkbuilddir $(objects)
	$(CC) -o $(BUILD_DIR)$(PROJECT_NAME) $(objects) $(LIBS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(FLAGS) $(INCLUDES)

$(BUILD_DIR)%.o: Source/%.cpp
	$(CC) -o $@ -c $< $(FLAGS) $(INCLUDES)

main.o: Source/main.cpp
	$(CC) -o $@ -c $< $(FLAGS) $(INCLUDES)

.PHONY: clean mkbuilddir

mkbuilddir:
	mkdir -p $(BUILD_DIR)

clean:
	-rm -f $(objects)
	-rm -f $(BUILD_DIR)$(PROJECT_NAME)
