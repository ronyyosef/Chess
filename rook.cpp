#include "rook.h"


namespace chess
{
    Rook::Rook(const int& color) :Unit(color)
    {
        if (color == WHITE)
        {
            if (!rook_Texture.loadFromFile("chess_units.png", sf::IntRect(183, 50, 235, 250)))
                std::cout << "cannot load photo" << std::endl;
        }
        else
        {
            if (!rook_Texture.loadFromFile("chess_units.png", sf::IntRect(782, 370, 235, 250)))
                std::cout << "cannot load photo" << std::endl;
        }
    }


    void Rook::draw(sf::RenderWindow& window,const POS& pos)const
    {
        sf::RectangleShape bishop(sf::Vector2f((HEIGHT / ROW) - 20, (WIDTH / COL) - 20));
        bishop.setTexture(&rook_Texture);
        bishop.setPosition((pos.col * (WIDTH / COL)) + 10, (pos.row * (HEIGHT / ROW)) + 10);
        window.draw(bishop);
    }

    void Rook::get_possible_moves(const Board& board, const POS& pos, std::vector<POS>& possible_moves)const
    {
        if (color == BLACK)
        {
            for (int i = 1; i <= ROW; i++)
            {
                //regular move
                if (board.is_empty(pos.row + i, pos.col))
                {
                    possible_moves.push_back(POS(pos.row + i, pos.col));
                }
                else
                {
                    //attack
                    if (board.get_color(pos.row + i, pos.col) == WHITE)
                    {
                        possible_moves.push_back(POS(pos.row + i, pos.col));
                    }
                    break;
                }
            }
            for (int i = 1; i <= ROW; i++)
            {
                //regular move
                if (board.is_empty(pos.row - i, pos.col))
                {
                    possible_moves.push_back(POS(pos.row - i, pos.col));
                }
                else
                {
                    //attack
                    if (board.get_color(pos.row - i, pos.col) == WHITE)
                    {
                        possible_moves.push_back(POS(pos.row - i, pos.col));
                    }
                    break;
                }
            }
            for (int i = 1; i <= ROW; i++)
            {
                //regular move
                if (board.is_empty(pos.row, pos.col + i))
                {
                    possible_moves.push_back(POS(pos.row, pos.col + i));
                }
                else
                {
                    //attack
                    if (board.get_color(pos.row, pos.col + i) == WHITE)
                    {
                        possible_moves.push_back(POS(pos.row, pos.col + i));
                    }
                    break;
                }
            }
            for (int i = 1; i <= ROW; i++)
            {
                //regular move
                if (board.is_empty(pos.row, pos.col - i))
                {
                    possible_moves.push_back(POS(pos.row, pos.col - i));
                }
                else
                {
                    //attack
                    if (board.get_color(pos.row, pos.col - i) == WHITE)
                    {
                        possible_moves.push_back(POS(pos.row, pos.col - i));
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
                if (board.is_empty(pos.row + i, pos.col))
                {
                    possible_moves.push_back(POS(pos.row + i, pos.col));
                }
                else
                {
                    //attack
                    if (board.get_color(pos.row + i, pos.col) == BLACK)
                    {
                        possible_moves.push_back(POS(pos.row + i, pos.col));
                    }
                    break;
                }
            }
            for (int i = 1; i <= ROW; i++)
            {
                //regular move
                if (board.is_empty(pos.row - i, pos.col))
                {
                    possible_moves.push_back(POS(pos.row - i, pos.col));
                }
                else
                {
                    //attack
                    if (board.get_color(pos.row - i, pos.col) == BLACK)
                    {
                        possible_moves.push_back(POS(pos.row - i, pos.col));
                    }
                    break;
                }
            }
            for (int i = 1; i <= ROW; i++)
            {
                //regular move
                if (board.is_empty(pos.row, pos.col + i))
                {
                    possible_moves.push_back(POS(pos.row, pos.col + i));
                }
                else
                {
                    //attack
                    if (board.get_color(pos.row, pos.col + i) == BLACK)
                    {
                        possible_moves.push_back(POS(pos.row, pos.col + i));
                    }
                    break;
                }
            }
            for (int i = 1; i <= ROW; i++)
            {
                //regular move
                if (board.is_empty(pos.row, pos.col - i))
                {
                    possible_moves.push_back(POS(pos.row, pos.col - i));
                }
                else
                {
                    //attack
                    if (board.get_color(pos.row, pos.col - i) == BLACK)
                    {
                        possible_moves.push_back(POS(pos.row, pos.col - i));
                    }
                    break;
                }
            }
        }

    }

}