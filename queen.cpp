#include "queen.h"


namespace chess
{
    Queen::Queen(const int& color) :Unit(color)
    {
        if (color == WHITE)
        {
            if (!queen_Texture.loadFromFile("chess_units.png", sf::IntRect(769, 40, 235, 270)))
                std::cout << "cannot load photo" << std::endl;
        }
        else
        {
            if (!queen_Texture.loadFromFile("chess_units.png", sf::IntRect(194, 345, 235, 270)))
                std::cout << "cannot load photo" << std::endl;
        }
    }


    void Queen::draw(sf::RenderWindow& window, const POS& pos)const
    {
        sf::RectangleShape queen(sf::Vector2f((HEIGHT / ROW)-20, (WIDTH / COL)-20));
        queen.setTexture(&queen_Texture);
        queen.setPosition((pos.col * (WIDTH / COL))+10, (pos.row * (HEIGHT / ROW))+10);
        window.draw(queen);
    }

    void Queen::get_possible_moves(const Board& board, const POS& pos, std::vector<POS>& possible_moves)const
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