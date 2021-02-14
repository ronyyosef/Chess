#pragma once
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "mainHeader.h"
#include "checker.h"

#include "bishop.h"
#include "king.h"
#include "knight.h"
#include "pawn.h"
#include "queen.h"
#include "rook.h"
#include <string>

namespace chess
{
	class Board
	{
	private:
		std::vector<std::vector<Checker*>> Checker_2D_VC;
	public:
		//ctor
		Board();
		//copy_ctor
		Board(const Board& other);
		//dtor
		~Board();
		//operator = 
		Board& operator=(const Board& other) = delete;

		void draw(sf::RenderWindow& window) const;
		void get_possible_moves(const POS& pos, std::vector<POS>& possible_moves) const;
		bool is_empty(const POS& pos) const { return is_empty(pos.row, pos.col); }
		bool is_empty(const int& row, const int& col) const;
		int get_color(const POS& pos) const;
		int get_color(const int& row, const int& col) const;
		void move(const POS& from, const POS& to);
		void get_all_moves(const int& color, std::vector<POS>& all_moves) const;
		const Unit* get_unit(const POS& pos)const { return Checker_2D_VC[pos.row][pos.col]->get_unit(); }
		POS get_king_moves(const int& color, std::vector<POS>& all_moves) const;
		POS find_unit(const int& color, const std::type_info& unit) const;
		POS pawn_move(const int& color_turn) const;
		void pawn_promote(const POS& pos, const int& num, const int& color);
		void get_possible_unique_moves(const POS& pos, std::vector<POS>& possible_moves, const bool& Castling_available, const bool& Rook_left_available, const bool& Rook_right_available, const int& color) const;
	};
}


