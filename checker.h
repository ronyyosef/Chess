#pragma once
#include <iostream>
#include "unit.h"
#include <SFML/Graphics.hpp>
#include "mainHeader.h"

namespace chess
{
	class Checker
	{
	private:
		Unit* unit;
		const POS pos;
	public:
		//ctor
		Checker(const POS& pos) :pos(pos), unit(nullptr){}
		Checker(const int& row,const int& col) :pos(row,col), unit(nullptr) {}
		//copy_ctor
		Checker(const Checker& other) = delete;
		//dtor
		~Checker() { if (!is_empty()) delete unit; };
		//operator = 
		Checker& operator=(const Checker& other) = delete;

		bool is_empty()const { return unit == nullptr; }
		void draw(sf::RenderWindow& window)const { if (!is_empty()) unit->draw(window,pos); }
		void get_possible_moves(const Board& board, std::vector<POS>& possible_moves) const { if (!is_empty()) unit->get_possible_moves(board,pos, possible_moves); }
		void set_unit(Unit* unit) { this->unit = unit; }
		POS get_pos()const  { return pos; }
		int get_color()const { if (this->is_empty())return -1; else return unit->get_color(); }
		const Unit* get_unit()const { return unit; }
		void remove_unit() { unit = nullptr; }
		void delete_unit() { delete unit; unit = nullptr; }
	};
}


