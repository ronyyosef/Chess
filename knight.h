#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#include "unit.h" 
#include "mainHeader.h"
#include "board.h"
namespace chess
{
	class Knight :public Unit
	{
	private:
		sf::Texture knight_Texture;
	public:
		//ctor
		Knight(const int& color);
		//copy_ctor
		Knight(const Knight& other) = delete;
		//dtor
		~Knight() = default;
		//operator = 
		Knight& operator=(const Knight& other) = delete;

		void draw(sf::RenderWindow& window, const POS& pos)const;
		void get_possible_moves(const Board& board, const POS& pos, std::vector<POS>& possible_moves)const;
	};
}


