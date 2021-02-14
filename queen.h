#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#include "unit.h" 
#include "mainHeader.h"
#include "board.h"
namespace chess
{
	class Queen :public Unit
	{
	private:
		sf::Texture queen_Texture;
	public:
		//ctor
		Queen(const int& color);
		//copy_ctor
		Queen(const Queen& other) = delete;
		//dtor
		~Queen() = default;
		//operator = 
		Queen& operator=(const Queen& other) = delete;

		void draw(sf::RenderWindow& window, const POS& pos)const;
		void get_possible_moves(const Board& board, const POS& pos, std::vector<POS>& possible_moves)const;
	};

}

