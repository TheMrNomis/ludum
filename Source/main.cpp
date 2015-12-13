#include <iostream>
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "TextureLoader.h"
#include <vld.h>

int main(int argc, char ** argv)
{
    Window w;
	char *testLeak = new char[1000000];
	testLeak = nullptr;
    return w.run();
}
