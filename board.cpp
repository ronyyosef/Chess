#include "board.h"


namespace chess
{
	Board::Board()
	{
		for (int i = 0; i < ROW; i++)
		{
			std::vector<Checker*> curr_row;
			for (int j = 0; j < COL; j++)
			{
				curr_row.insert(curr_row.begin() + j, new Checker(i, j));
			}
			Checker_2D_VC.insert(Checker_2D_VC.begin() + i, curr_row);
		}
		//set all unit of black side
		Checker_2D_VC[0][0]->set_unit(new Rook(BLACK));
		Checker_2D_VC[0][1]->set_unit(new Knight(BLACK));
		Checker_2D_VC[0][2]->set_unit(new Bishop(BLACK));
		Checker_2D_VC[0][3]->set_unit(new Queen(BLACK));
		Checker_2D_VC[0][4]->set_unit(new King(BLACK));
		Checker_2D_VC[0][5]->set_unit(new Bishop(BLACK));
		Checker_2D_VC[0][6]->set_unit(new Knight(BLACK));
		Checker_2D_VC[0][7]->set_unit(new Rook(BLACK));
		for (int i = 0; i < COL; i++)
		{
			Checker_2D_VC[1][i]->set_unit(new Pawn(BLACK));
		}

		//set all unit of white side
		Checker_2D_VC[7][0]->set_unit(new Rook(WHITE));
		Checker_2D_VC[7][1]->set_unit(new Knight(WHITE));
		Checker_2D_VC[7][2]->set_unit(new Bishop(WHITE));
		Checker_2D_VC[7][3]->set_unit(new Queen(WHITE));
		Checker_2D_VC[7][4]->set_unit(new King(WHITE));
		Checker_2D_VC[7][5]->set_unit(new Bishop(WHITE));
		Checker_2D_VC[7][6]->set_unit(new Knight(WHITE));
		Checker_2D_VC[7][7]->set_unit(new Rook(WHITE));
		for (int i = 0; i < COL; i++)
		{
			Checker_2D_VC[6][i]->set_unit(new Pawn(WHITE));
		}
    }

	Board::Board(const Board& other)
	{
		for (int i = 0; i < other.Checker_2D_VC.size(); i++)
		{
			std::vector<Checker*> curr_row;
			for (int j = 0; j < other.Checker_2D_VC[i].size(); j++)
			{
				curr_row.insert(curr_row.begin() + j, new Checker(i, j));
			}
			Checker_2D_VC.insert(Checker_2D_VC.begin() + i, curr_row);
		}
		for (int i = 0; i < other.Checker_2D_VC.size(); i++)
		{
			for (int j = 0; j < other.Checker_2D_VC[i].size(); j++)
			{
				if (!other.Checker_2D_VC[i][j]->is_empty())
				{
					const Unit* other_unit = other.Checker_2D_VC[i][j]->get_unit();
					if (typeid(*other_unit) == typeid(Pawn))
					{
						this->Checker_2D_VC[i][j]->set_unit(new Pawn(other_unit->get_color()));
					}
					if (typeid(*other_unit) == typeid(Queen))
					{
						this->Checker_2D_VC[i][j]->set_unit(new Queen(other_unit->get_color()));
					}
					if (typeid(*other_unit) == typeid(King))
					{
						this->Checker_2D_VC[i][j]->set_unit(new King(other_unit->get_color()));
					}
					if (typeid(*other_unit) == typeid(Knight))
					{
						this->Checker_2D_VC[i][j]->set_unit(new Knight(other_unit->get_color()));
					}
					if (typeid(*other_unit) == typeid(Rook))
					{
						this->Checker_2D_VC[i][j]->set_unit(new Rook(other_unit->get_color()));
					}
					if (typeid(*other_unit) == typeid(Bishop))
					{
						this->Checker_2D_VC[i][j]->set_unit(new Bishop(other_unit->get_color()));
					}
				}
			}
		}
	}


	Board::~Board()
	{
		for (int i = 0; i < Checker_2D_VC.size(); i++)
			for (int j = 0; j < Checker_2D_VC[i].size(); j++)
				delete Checker_2D_VC[i][j];
	}

	int Board::get_color(const POS& pos) const
	{ 
		if (is_empty(pos)) 
			return -1;
		else 
			return Checker_2D_VC[pos.row][pos.col]->get_color();
	}


	void Board::get_possible_moves(const POS& pos, std::vector<POS>& possible_moves) const
	{ 
		if (pos.col == -1 && pos.row == -1)
			return;
		if (!is_empty(pos))
			Checker_2D_VC[pos.row][pos.col]->get_possible_moves(*this, possible_moves); 
	}

			
	void Board::draw(sf::RenderWindow& window) const
	{
		bool is_black = false;
		sf::RectangleShape squre(sf::Vector2f(HEIGHT / ROW, WIDTH / COL));
		for (int i = 0; i < Checker_2D_VC.size(); i++)
		{
			for (int j = 0; j < Checker_2D_VC[i].size(); j++)
			{
				if (i%2 == 0)
					if (j % 2 == 0)
						squre.setFillColor(sf::Color(255, 206, 158, 255));//White
					else
						squre.setFillColor(sf::Color(209, 139, 71, 255));//Black
				else
					if (j % 2 == 1)
						squre.setFillColor(sf::Color(255, 206, 158, 255));//White
					else
						squre.setFillColor(sf::Color(209, 139, 71, 255));//Black

				squre.setPosition(j * (HEIGHT / ROW), i * (WIDTH / COL));
				window.draw(squre);
			}
		}
		for (int i = 0; i < Checker_2D_VC.size(); i++)
		{
			for (int j = 0; j < Checker_2D_VC[i].size(); j++)
			{
				if (!Checker_2D_VC[i][j]->is_empty())
				{
					Checker_2D_VC[i][j]->draw(window);
				}
			}
		}

	}
	void Board::move(const POS& from, const POS& to)
	{
		const Unit* unit = Checker_2D_VC[from.row][from.col]->get_unit();
		Checker_2D_VC[from.row][from.col]->remove_unit();
		if (!Checker_2D_VC[to.row][to.col]->is_empty())
		{ //attack
			Checker_2D_VC[to.row][to.col]->delete_unit();
			Checker_2D_VC[to.row][to.col]->set_unit((Unit*)(unit));
		}
		else
			Checker_2D_VC[to.row][to.col]->set_unit((Unit*)unit);
	}
	bool Board::is_empty(const int& row, const int& col) const
	{
		if (row > ROW-1 || row <0 || col > COL-1 || col <0)
		{
			return false;
		}
		else
		{
			return Checker_2D_VC[row][col]->is_empty();
		}
	}

	int Board::get_color(const int& row, const int& col) const 
	{ 
		if (is_empty(row, col) || row > ROW - 1 || row <0 || col > COL - 1 || col < 0) return -1/*error*/;
		else return Checker_2D_VC[row][col]->get_color();
	}

	void Board::get_all_moves(const int& color, std::vector<POS>& all_moves) const
	{
		for (int i = 0; i < Checker_2D_VC.size(); i++)
		{
			for (int j = 0; j < Checker_2D_VC[i].size(); j++)
			{
				if (Checker_2D_VC[i][j]->get_color() == color)
					get_possible_moves(POS(i, j), all_moves);
			}
		}
	}
	POS Board::find_unit(const int& color, const std::type_info& other) const
	{
		for (int i = 0; i < Checker_2D_VC.size(); i++)
		{
			for (int j = 0; j < Checker_2D_VC[i].size(); j++)
			{
				if (Checker_2D_VC[i][j]->get_color() == color)
				{
					const Unit* unit = get_unit(POS(i, j));
					if (typeid(*unit) == other)
					{
						return POS(i, j);
					}
				}
			}
		}
		return POS(-1, -1);
	}
	POS Board::get_king_moves(const int& color, std::vector<POS>& King_moves) const
	{
		POS pos = find_unit(color, typeid(King));
		get_possible_moves(pos, King_moves);
		return pos;
	}



	POS Board::pawn_move(const int& color_turn) const
	{
		if (color_turn == BLACK)
		{
			for (int i = 0; i < Checker_2D_VC[7].size(); i++)
			{
				const Unit* unit = get_unit(POS(7, i));
				if (unit != nullptr)
				{
					if (typeid(*unit) == typeid(Pawn))
						return POS(7,i);
				}
			}
		}
		else
		{
			for (int i = 0; i < Checker_2D_VC[0].size(); i++)
			{
				const Unit* unit = get_unit(POS(0, i));
				if (unit != nullptr)
				{
					if (typeid(*unit) == typeid(Pawn))
						return POS(0, i);
				}
			}
		}
		return POS(-1, -1);
	}

	void Board::pawn_promote(const POS& pos, const int& num,const int& color)
	{
		switch (num)
		{
		case 1:
		{
			Checker_2D_VC[pos.row][pos.col]->delete_unit();
			Checker_2D_VC[pos.row][pos.col]->set_unit(new Bishop(color));
			break;
		}
		case 2:
		{
			Checker_2D_VC[pos.row][pos.col]->delete_unit();
			Checker_2D_VC[pos.row][pos.col]->set_unit(new Knight(color));
			break;
		}
		case 3:
		{
			Checker_2D_VC[pos.row][pos.col]->delete_unit();
			Checker_2D_VC[pos.row][pos.col]->set_unit(new Queen(color));
			break;
		}
		case 4:
		{
			Checker_2D_VC[pos.row][pos.col]->delete_unit();
			Checker_2D_VC[pos.row][pos.col]->set_unit(new Rook(color));
			break;
		}
		default:
			break;
		}
	}
}