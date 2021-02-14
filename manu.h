#pragma once

#include <SFML/Graphics.hpp>
#include "mainHeader.h"

namespace chess
{
	class MyManu
	{
	private:
		sf::RenderWindow* window;
	public:
		MyManu(sf::RenderWindow* window) : window(window) {}
		void run() {}
	};
}


