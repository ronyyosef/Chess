#include "pawn.h"

namespace chess
{

    Pawn::Pawn(const int& color) :Unit(color)
    {
        if (color == WHITE)
        {
            if (!pawn_Texture.loadFromFile("chess_units.png", sf::IntRect(0, 80, 225, 225)))
                std::cout << "cannot load photo" << std::endl;
        }
        else
        {
            if (!pawn_Texture.loadFromFile("chess_units.png", sf::IntRect(990, 390, 225, 225)))
                std::cout << "cannot load photo" << std::endl;
        }
    }
    void Pawn::draw(sf::RenderWindow& window, const POS& pos)const
    {
        sf::RectangleShape pawn(sf::Vector2f((HEIGHT / ROW)-20, (WIDTH / COL)-20));
        pawn.setTexture(&pawn_Texture);
        pawn.setPosition((pos.col * (WIDTH / COL)) +10, (pos.row * (HEIGHT / ROW))+10);
        window.draw(pawn);
    }

    void Pawn::get_possible_moves(const Board& board,const POS& pos, std::vector<POS>& possible_moves) const
    {
        POS curr;
        if (color == BLACK)
        {
            //regular move
            if (board.is_empty(pos.row + 1, pos.col))
            {
                curr.row = pos.row + 1; curr.col = pos.col;
                possible_moves.push_back(curr);
            }
            //move for start position
            if (board.is_empty(pos.row + 2, pos.col) && board.is_empty(pos.row + 1, pos.col) && pos.row == 1)
            {
                curr.row = pos.row + 2; curr.col = pos.col;
                possible_moves.push_back(curr);
            }
            //attack
            if (!board.is_empty(pos.row + 1, pos.col + 1) && board.get_color(pos.row+1,pos.col+1) == WHITE) // right
            {
                curr.row = pos.row + 1; curr.col = pos.col + 1;
                possible_moves.push_back(curr);
            }
            if (!board.is_empty(pos.row + 1, pos.col - 1) && board.get_color(pos.row + 1, pos.col - 1) == WHITE)
            {
                curr.row = pos.row + 1; curr.col = pos.col - 1;
                possible_moves.push_back(curr);
            }

        }
        else
        {
            //regular move
            if (board.is_empty(pos.row - 1, pos.col))
            {
                curr.row = pos.row - 1; curr.col = pos.col;
                possible_moves.push_back(curr);
            }
            //move for start position
            if (board.is_empty(pos.row - 2, pos.col) && board.is_empty(pos.row - 1, pos.col) && pos.row == 6)
            {
                curr.row = pos.row - 2; curr.col = pos.col;
                possible_moves.push_back(curr);
            }
            //attack
            if (!board.is_empty(pos.row - 1, pos.col + 1) && board.get_color(pos.row - 1, pos.col + 1) == BLACK) // right
            {
                curr.row = pos.row - 1; curr.col = pos.col + 1;
                possible_moves.push_back(curr);
            }
            if (!board.is_empty(pos.row - 1, pos.col - 1) && board.get_color(pos.row - 1, pos.col - 1) == BLACK)
            {
                curr.row = pos.row - 1; curr.col = pos.col - 1;
                possible_moves.push_back(curr);
            }
        }


    }

}