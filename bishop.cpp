#include "bishop.h"


namespace chess
{
    Bishop::Bishop(const int& color) :Unit(color)
    {
        if (color == WHITE)
        {
            if (!bishop_Texture.loadFromFile("chess_units.png", sf::IntRect(579, 40, 225, 270)))
                std::cout << "cannot load photo" << std::endl;
        }
        else
        {
            if (!bishop_Texture.loadFromFile("chess_units.png", sf::IntRect(393, 350, 225, 270)))
                std::cout << "cannot load photo" << std::endl;
        }
    }
    void Bishop::draw(sf::RenderWindow& window, const POS& pos) const
    {
        sf::RectangleShape bishop(sf::Vector2f((HEIGHT / ROW) - 20, (WIDTH / COL) - 20));
        bishop.setTexture(&bishop_Texture);
        bishop.setPosition((pos.col * (WIDTH / COL)) + 10, (pos.row * (HEIGHT / ROW)) + 10);
        window.draw(bishop);
    }

    void Bishop::get_possible_moves(const Board& board, const POS& pos, std::vector<POS>& possible_moves) const
    {
        if (color == BLACK)
        {
            for (int i = 1; i <= ROW; i++)
            {
                //regular move
                if (board.is_empty(pos.row + i, pos.col + i))
                {
                    possible_moves.push_back(POS(pos.row + i, pos.col + i));
                }
                else
                {
                    //attack
                    if (board.get_color(pos.row + i, pos.col + i) == WHITE)
                    {
                        possible_moves.push_back(POS(pos.row + i, pos.col + i));
                    }
                    break;
                }
            }
            for (int i = 1; i <= ROW; i++)
            {
                //regular move
                if (board.is_empty(pos.row + i, pos.col - i))
                {
                    possible_moves.push_back(POS(pos.row + i, pos.col - i));
                }
                else
                {
                    //attack
                    if (board.get_color(pos.row + i, pos.col - i) == WHITE)
                    {
                        possible_moves.push_back(POS(pos.row + i, pos.col - i));
                    }
                    break;
                }
            }
            for (int i = 1; i <= ROW; i++)
            {
                //regular move
                if (board.is_empty(pos.row - i, pos.col - i))
                {
                    possible_moves.push_back(POS(pos.row - i, pos.col - i));
                }
                else
                {
                    //attack
                    if (board.get_color(pos.row - i, pos.col - i) == WHITE)
                    {
                        possible_moves.push_back(POS(pos.row - i, pos.col - i));
                    }
                    break;
                }
            }
            for (int i = 1; i <= ROW; i++)
            {
                //regular move
                if (board.is_empty(pos.row - i, pos.col + i))
                {
                    possible_moves.push_back(POS(pos.row - i, pos.col + i));
                }
                else
                {
                    //attack
                    if (board.get_color(pos.row - i, pos.col + i) == WHITE)
                    {
                        possible_moves.push_back(POS(pos.row - i, pos.col + i));
                    }
                    break;
                }
            }
        }
        else
        {
            for (int i = 1; i <= ROW; i++)
            {
                //regular move
                if (board.is_empty(pos.row + i, pos.col + i))
                {
                    possible_moves.push_back(POS(pos.row + i, pos.col + i));
                }
                else
                {
                    //attack
                    if (board.get_color(pos.row + i, pos.col + i) == BLACK)
                    {
                        possible_moves.push_back(POS(pos.row + i, pos.col + i));
                    }
                    break;
                }
            }
            for (int i = 1; i <= ROW; i++)
            {
                //regular move
                if (board.is_empty(pos.row + i, pos.col - i))
                {
                    possible_moves.push_back(POS(pos.row + i, pos.col - i));
                }
                else
                {
                    //attack
                    if (board.get_color(pos.row + i, pos.col - i) == BLACK)
                    {
                        possible_moves.push_back(POS(pos.row + i, pos.col - i));
                    }
                    break;
                }
            }
            for (int i = 1; i <= ROW; i++)
            {
                //regular move
                if (board.is_empty(pos.row - i, pos.col - i))
                {
                    possible_moves.push_back(POS(pos.row - i, pos.col - i));
                }
                else
                {
                    //attack
                    if (board.get_color(pos.row - i, pos.col - i) == BLACK)
                    {
                        possible_moves.push_back(POS(pos.row - i, pos.col - i));
                    }
                    break;
                }
            }
            for (int i = 1; i <= ROW; i++)
            {
                //regular move
                if (board.is_empty(pos.row - i, pos.col + i))
                {
                    possible_moves.push_back(POS(pos.row - i, pos.col + i));
                }
                else
                {
                    //attack
                    if (board.get_color(pos.row - i, pos.col + i) == BLACK)
                    {
                        possible_moves.push_back(POS(pos.row - i, pos.col + i));
                    }
                    break;
                }
            }
        }

    }

}