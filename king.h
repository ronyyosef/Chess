#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#include "unit.h" 
#include "mainHeader.h"
#include "board.h"
namespace chess
{
	class King :public Unit
	{
	private:
		sf::Texture king_Texture;
	public:
		//ctor
		King(const int& color);
		//copy_ctor
		King(const King& other) = delete;
		//dtor
		~King() = default;
		//operator = 
		King& operator=(const King& other) = delete;

		void draw(sf::RenderWindow& window, const POS& pos)const;
		void get_possible_moves(const Board& board, const POS& pos, std::vector<POS>& possible_moves)const;
	};
}


