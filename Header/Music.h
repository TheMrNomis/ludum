#pragma once

#include <SFML/Audio.hpp>
#include <string>


class Music
{
	private:
		std::string fileName;

	public:
		Music(std::string path);
		~Music();

	public:
		void play();
};