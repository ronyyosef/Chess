#include "knight.h"


namespace chess
{
    Knight::Knight(const int& color) :Unit(color)
    {
        if (color == WHITE)
        {
            if (!knight_Texture.loadFromFile("chess_units.png", sf::IntRect(385, 35, 235, 270)))
                std::cout << "cannot load photo" << std::endl;
        }
        else
        {
            if (!knight_Texture.loadFromFile("chess_units.png", sf::IntRect(580, 350, 235, 270)))
                std::cout << "cannot load photo" << std::endl;
        }
    }

    void Knight::draw(sf::RenderWindow& window,const POS& pos)const
    {
        sf::RectangleShape king(sf::Vector2f((HEIGHT / ROW) - 16, (WIDTH / COL) - 20));
        king.setTexture(&knight_Texture);
        king.setPosition((pos.col * (WIDTH / COL)) + 8, (pos.row * (HEIGHT / ROW)) + 10);
        window.draw(king);
    }

    void Knight::get_possible_moves(const Board& board, const POS& pos, std::vector<POS>& possible_moves) const
    {
        if (color == BLACK)
        {
            if (board.is_empty(pos.row+1, pos.col + 2))
            {
                possible_moves.push_back(POS(pos.row+1, pos.col + 2));
            }
            else
            {
                //attack
                if (board.get_color(pos.row+1, pos.col + 2) == WHITE)
                {
                    possible_moves.push_back(POS(pos.row + 1, pos.col + 2));
                }
            }
            if (board.is_empty(pos.row + 2, pos.col + 1))
            {
                possible_moves.push_back(POS(pos.row + 2, pos.col + 1));
            }
            else
            {
                //attack
                if (board.get_color(pos.row + 2, pos.col + 1) == WHITE)
                {
                    possible_moves.push_back(POS(pos.row + 2, pos.col + 1));
                }
            }
            if (board.is_empty(pos.row - 1, pos.col + 2))
            {
                possible_moves.push_back(POS(pos.row - 1, pos.col + 2));
            }
            else
            {
                //attack
                if (board.get_color(pos.row - 1, pos.col + 2) == WHITE)
                {
                    possible_moves.push_back(POS(pos.row - 1, pos.col + 2));
                }
            }
            if (board.is_empty(pos.row - 2, pos.col + 1))
            {
                possible_moves.push_back(POS(pos.row - 2, pos.col + 1));
            }
            else
            {
                //attack
                if (board.get_color(pos.row - 2, pos.col + 1) == WHITE)
                {
                    possible_moves.push_back(POS(pos.row - 2, pos.col + 1));
                }
            }
            if (board.is_empty(pos.row + 2, pos.col - 1))
            {
                possible_moves.push_back(POS(pos.row + 2, pos.col - 1));
            }
            else
            {
                //attack
                if (board.get_color(pos.row + 2, pos.col - 1) == WHITE)
                {
                    possible_moves.push_back(POS(pos.row + 2, pos.col - 1));
                }
            }
            if (board.is_empty(pos.row + 1, pos.col - 2))
            {
                possible_moves.push_back(POS(pos.row + 1, pos.col - 2));
            }
            else
            {
                //attack
                if (board.get_color(pos.row + 1, pos.col - 2) == WHITE)
                {
                    possible_moves.push_back(POS(pos.row + 1, pos.col - 2));
                }
            }
            if (board.is_empty(pos.row - 2, pos.col - 1))
            {
                possible_moves.push_back(POS(pos.row - 2, pos.col - 1));
            }
            else
            {
                //attack
                if (board.get_color(pos.row - 2, pos.col - 1) == WHITE)
                {
                    possible_moves.push_back(POS(pos.row - 2, pos.col - 1));
                }
            }
            if (board.is_empty(pos.row - 1, pos.col - 2))
            {
                possible_moves.push_back(POS(pos.row - 1, pos.col - 2));
            }
            else
            {
                //attack
                if (board.get_color(pos.row - 1, pos.col - 2) == WHITE)
                {
                    possible_moves.push_back(POS(pos.row - 1, pos.col - 2));
                }
            }

        }
        else
        {
            if (board.is_empty(pos.row + 1, pos.col + 2))
            {
                possible_moves.push_back(POS(pos.row + 1, pos.col + 2));
            }
            else
            {
                //attack
                if (board.get_color(pos.row + 1, pos.col + 2) == BLACK)
                {
                    possible_moves.push_back(POS(pos.row + 1, pos.col + 2));
                }
            }
            if (board.is_empty(pos.row + 2, pos.col + 1))
            {
                possible_moves.push_back(POS(pos.row + 2, pos.col + 1));
            }
            else
            {
                //attack
                if (board.get_color(pos.row + 2, pos.col + 1) == BLACK)
                {
                    possible_moves.push_back(POS(pos.row + 2, pos.col + 1));
                }
            }
            if (board.is_empty(pos.row - 1, pos.col + 2))
            {
                possible_moves.push_back(POS(pos.row - 1, pos.col + 2));
            }
            else
            {
                //attack
                if (board.get_color(pos.row - 1, pos.col + 2) == BLACK)
                {
                    possible_moves.push_back(POS(pos.row - 1, pos.col + 2));
                }
            }
            if (board.is_empty(pos.row - 2, pos.col + 1))
            {
                possible_moves.push_back(POS(pos.row - 2, pos.col + 1));
            }
            else
            {
                //attack
                if (board.get_color(pos.row - 2, pos.col + 1) == BLACK)
                {
                    possible_moves.push_back(POS(pos.row - 2, pos.col + 1));
                }
            }
            if (board.is_empty(pos.row + 2, pos.col - 1))
            {
                possible_moves.push_back(POS(pos.row + 2, pos.col - 1));
            }
            else
            {
                //attack
                if (board.get_color(pos.row + 2, pos.col - 1) == BLACK)
                {
                    possible_moves.push_back(POS(pos.row + 2, pos.col - 1));
                }
            }
            if (board.is_empty(pos.row + 1, pos.col - 2))
            {
                possible_moves.push_back(POS(pos.row + 1, pos.col - 2));
            }
            else
            {
                //attack
                if (board.get_color(pos.row + 1, pos.col - 2) == BLACK)
                {
                    possible_moves.push_back(POS(pos.row + 1, pos.col - 2));
                }
            }
            if (board.is_empty(pos.row - 2, pos.col - 1))
            {
                possible_moves.push_back(POS(pos.row - 2, pos.col - 1));
            }
            else
            {
                //attack
                if (board.get_color(pos.row - 2, pos.col - 1) == BLACK)
                {
                    possible_moves.push_back(POS(pos.row - 2, pos.col - 1));
                }
            }
            if (board.is_empty(pos.row - 1, pos.col - 2))
            {
                possible_moves.push_back(POS(pos.row - 1, pos.col - 2));
            }
            else
            {
                //attack
                if (board.get_color(pos.row - 1, pos.col - 2) == BLACK)
                {
                    possible_moves.push_back(POS(pos.row - 1, pos.col - 2));
                }
            }
        }
    }
 
}