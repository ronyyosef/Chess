#include "king.h"


namespace chess
{
    King::King(const int& color) :Unit(color)
    {
        if (color == WHITE)
        {
            if (!king_Texture.loadFromFile("chess_units.png", sf::IntRect(980, 2, 227, 300)))
                std::cout << "cannot load photo" << std::endl;
        }
        else
        {
            if (!king_Texture.loadFromFile("chess_units.png", sf::IntRect(0, 324, 227, 300)))
                std::cout << "cannot load photo" << std::endl;
        }
    }

    void King::draw(sf::RenderWindow& window, const POS& pos)const
    {
        sf::RectangleShape king(sf::Vector2f((HEIGHT / ROW) - 20, (WIDTH / COL)-10));
        king.setTexture(&king_Texture);
        king.setPosition((pos.col * (WIDTH / COL)) + 10, (pos.row * (HEIGHT / ROW))+5);
        window.draw(king);
    }


    void King::get_possible_moves(const Board& board, const POS& pos, std::vector<POS>& possible_moves)const
    {
        if (color == BLACK)
        {
            if (board.is_empty(pos.row , pos.col + 1 ))
            {
                possible_moves.push_back(POS(pos.row, pos.col + 1));
            }
            else
            {
                //attack
                if (board.get_color(pos.row, pos.col + 1) == WHITE)
                {
                    possible_moves.push_back(POS(pos.row, pos.col + 1));
                }
            }
            if (board.is_empty(pos.row, pos.col - 1))
            {
                possible_moves.push_back(POS(pos.row, pos.col - 1));
            }
            else
            {
                //attack
                if (board.get_color(pos.row, pos.col - 1) == WHITE)
                {
                    possible_moves.push_back(POS(pos.row, pos.col - 1));
                }
            }
            if (board.is_empty(pos.row+1, pos.col))
            {
                possible_moves.push_back(POS(pos.row+1, pos.col));
            }
            else
            {
                //attack
                if (board.get_color(pos.row+1, pos.col) == WHITE)
                {
                    possible_moves.push_back(POS(pos.row+1, pos.col));
                }
            }
            if (board.is_empty(pos.row - 1, pos.col))
            {
                possible_moves.push_back(POS(pos.row - 1, pos.col));
            }
            else
            {
                //attack
                if (board.get_color(pos.row - 1, pos.col) == WHITE)
                {
                    possible_moves.push_back(POS(pos.row - 1, pos.col));
                }
            }
            if (board.is_empty(pos.row + 1, pos.col +1))
            {
                possible_moves.push_back(POS(pos.row + 1, pos.col +1));
            }
            else
            {
                //attack
                if (board.get_color(pos.row + 1, pos.col +1) == WHITE)
                {
                    possible_moves.push_back(POS(pos.row + 1, pos.col + 1));
                }
            }
            if (board.is_empty(pos.row + 1, pos.col - 1))
            {
                possible_moves.push_back(POS(pos.row + 1, pos.col - 1));
            }
            else
            {
                //attack
                if (board.get_color(pos.row + 1, pos.col - 1) == WHITE)
                {
                    possible_moves.push_back(POS(pos.row + 1, pos.col - 1));
                }
            }
            if (board.is_empty(pos.row - 1, pos.col + 1))
            {
                possible_moves.push_back(POS(pos.row - 1, pos.col + 1));
            }
            else
            {
                //attack
                if (board.get_color(pos.row - 1, pos.col + 1) == WHITE)
                {
                    possible_moves.push_back(POS(pos.row - 1, pos.col + 1));
                }
            }
            if (board.is_empty(pos.row - 1, pos.col - 1))
            {
                possible_moves.push_back(POS(pos.row - 1, pos.col - 1));
            }
            else
            {
                //attack
                if (board.get_color(pos.row - 1, pos.col - 1) == WHITE)
                {
                    possible_moves.push_back(POS(pos.row - 1, pos.col - 1));
                }
            }

        }
        else
        {
            if (board.is_empty(pos.row, pos.col + 1))
            {
                possible_moves.push_back(POS(pos.row, pos.col + 1));
            }
            else
            {
                //attack
                if (board.get_color(pos.row, pos.col + 1) == BLACK)
                {
                    possible_moves.push_back(POS(pos.row, pos.col + 1));
                }
            }
            if (board.is_empty(pos.row, pos.col - 1))
            {
                possible_moves.push_back(POS(pos.row, pos.col - 1));
            }
            else
            {
                //attack
                if (board.get_color(pos.row, pos.col - 1) == BLACK)
                {
                    possible_moves.push_back(POS(pos.row, pos.col - 1));
                }
            }
            if (board.is_empty(pos.row + 1, pos.col))
            {
                possible_moves.push_back(POS(pos.row + 1, pos.col));
            }
            else
            {
                //attack
                if (board.get_color(pos.row + 1, pos.col) == BLACK)
                {
                    possible_moves.push_back(POS(pos.row + 1, pos.col));
                }
            }
            if (board.is_empty(pos.row - 1, pos.col))
            {
                possible_moves.push_back(POS(pos.row - 1, pos.col));
            }
            else
            {
                //attack
                if (board.get_color(pos.row - 1, pos.col) == BLACK)
                {
                    possible_moves.push_back(POS(pos.row - 1, pos.col));
                }
            }
            if (board.is_empty(pos.row + 1, pos.col + 1))
            {
                possible_moves.push_back(POS(pos.row + 1, pos.col + 1));
            }
            else
            {
                //attack
                if (board.get_color(pos.row + 1, pos.col + 1) == BLACK)
                {
                    possible_moves.push_back(POS(pos.row + 1, pos.col + 1));
                }
            }
            if (board.is_empty(pos.row + 1, pos.col - 1))
            {
                possible_moves.push_back(POS(pos.row + 1, pos.col - 1));
            }
            else
            {
                //attack
                if (board.get_color(pos.row + 1, pos.col - 1) == BLACK)
                {
                    possible_moves.push_back(POS(pos.row + 1, pos.col - 1));
                }
            }
            if (board.is_empty(pos.row - 1, pos.col + 1))
            {
                possible_moves.push_back(POS(pos.row - 1, pos.col + 1));
            }
            else
            {
                //attack
                if (board.get_color(pos.row - 1, pos.col + 1) == BLACK)
                {
                    possible_moves.push_back(POS(pos.row - 1, pos.col + 1));
                }
            }
            if (board.is_empty(pos.row - 1, pos.col - 1))
            {
                possible_moves.push_back(POS(pos.row - 1, pos.col - 1));
            }
            else
            {
                //attack
                if (board.get_color(pos.row - 1, pos.col - 1) == BLACK)
                {
                    possible_moves.push_back(POS(pos.row - 1, pos.col - 1));
                }
            }
        }
    }

}

