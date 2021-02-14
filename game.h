#pragma once
#include "board.h"
#include "mainHeader.h"
#include <string>

#include "checker.h"

#include "bishop.h"
#include "king.h"
#include "knight.h"
#include "pawn.h"
#include "queen.h"
#include "rook.h"

namespace chess
{
	class Game
	{
	private:
		sf::RenderWindow& window;
		Board board;
		int turn_counter;
		int color_turn;
		sf::Font font;
		bool show_possible_moves_bool;
		bool checked_bool;
		bool checked_mate_bool;

		POS pawn_move_pos;
	public:
		//ctor
		Game(sf::RenderWindow& window, bool& black_start);
		//copy_ctor
		Game(const Board& other) = delete;
		//dtor
		~Game() = default;
		//operator = 
		Game& operator=(const Game& other) = delete;
		void draw_possible_moves(std::vector<POS>& possible_moves);
		void run();
		void move_turn();
		void draw_tool_bar();
		bool is_checked();
		POS pawn_move();
		void pawn_choose();
		void get_pawn_choose(POS& pawn_move_pos, const int& y, const int& x);
		bool checked_mate();
	};
}


