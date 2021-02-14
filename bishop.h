#pragma once
#include "unit.h"
#include "mainHeader.h"
#include "board.h"

namespace chess
{
	class Bishop : public Unit
	{
	private:
		sf::Texture bishop_Texture;
	public:
		//ctor
		Bishop(const int& color);
		//copy_ctor
		Bishop(const Bishop& other) = delete;
		//dtor
		virtual ~Bishop() = default;
		//operator = 
		Bishop& operator=(const Bishop& other) = delete;

		void draw(sf::RenderWindow& window, const POS& pos) const;
		void get_possible_moves(const Board& board,const POS& pos, std::vector<POS>& possible_moves) const;
	};
}
	

