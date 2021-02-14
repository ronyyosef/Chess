#pragma once
#include "mainHeader.h"
#include <SFML/Graphics.hpp>

namespace chess
{
	class Board;
	class Unit
	{
	protected:
		int color;
		bool killed;
	public:
		//ctor
		Unit(const int& color) :color(color), killed(false){}
		//copy_ctor
		Unit(const Unit& other) = delete;
		//dtor
		virtual ~Unit() = default;
		//operator = 
		Unit& operator=(const Unit& other) = delete;


		virtual void draw(sf::RenderWindow& window, const POS& pos)const = 0;
		virtual void get_possible_moves(const Board& board, const POS& pos, std::vector<POS>& possible_moves)const = 0;
		int get_color()const { return color; }
	};
}
