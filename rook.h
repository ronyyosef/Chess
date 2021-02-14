#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#include "unit.h" 
#include "mainHeader.h"
#include "board.h"


namespace chess
{
	class Rook:public Unit
	{
	private:
		sf::Texture rook_Texture;
	public:
		//ctor
		Rook(const int& color);
		//copy_ctor
		Rook(const Rook& other) = delete;
		//dtor
		~Rook() = default;
		//operator = 
		Rook& operator=(const Rook& other) = delete;

		void draw(sf::RenderWindow& window, const POS& pos)const;
		void get_possible_moves(const Board& board, const POS& pos, std::vector<POS>& possible_moves)const;
	};
}
