#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#include "unit.h" 
#include "mainHeader.h"
#include "board.h"
namespace chess
{
	class Pawn :public Unit
	{
	private:
		sf::Texture pawn_Texture;
	public:
		//ctor
		Pawn(const int& color);
		//copy_ctor
		Pawn(const Pawn& other) = delete;
		//dtor
		~Pawn() = default;
		//operator = 
		Pawn& operator=(const Pawn& other) = delete;

		void draw(sf::RenderWindow& window, const POS& pos)const;
		void get_possible_moves(const Board& board, const POS& pos, std::vector<POS>& possible_moves)const;
	};
}


