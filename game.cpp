#include "game.h"


namespace chess
{
	Game::Game(sf::RenderWindow& window, bool& black_start): window(window), turn_counter(0), checked_bool(false)
	{
        checked_mate_bool = false;
        show_possible_moves_bool = false;
        if (black_start)
            color_turn = BLACK;
        else
            color_turn = WHITE;
        font.loadFromFile("arial.ttf");
	}

	void Game::run()
	{
        std::vector<POS> possible_moves;
        int clicked_row_1 = 0, clicked_col_1 = 0, clicked_row_2 = 0, clicked_col_2 = 0;
        sf::Event event;
        while (window.isOpen())
        {
            window.clear();
            board.draw(window);
            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        if (checked_mate_bool)
                            break;
                        if (event.mouseButton.x > 800)
                            break;
                        if (pawn_move_pos != POS(-1, -1))
                        {
                            get_pawn_choose(pawn_move_pos, event.mouseButton.y, event.mouseButton.x);
                            break;                         
                        }
                        if (show_possible_moves_bool)
                        {
                            clicked_row_2 = event.mouseButton.y / (HEIGHT / ROW);
                            clicked_col_2 = event.mouseButton.x / (WIDTH / COL);
                            std::vector<POS>::iterator itr = std::find(possible_moves.begin(), possible_moves.end(), POS(clicked_row_2, clicked_col_2));
                            if (itr != possible_moves.end())
                            {
                                board.move(POS(clicked_row_1, clicked_col_1), POS(clicked_row_2, clicked_col_2));
                                show_possible_moves_bool = false;
                                possible_moves.clear();
                                pawn_move_pos = pawn_move();
                                move_turn();
                                checked_bool = is_checked();
                                checked_mate_bool = checked_mate();
                            }
                            else
                            {
                                show_possible_moves_bool = false;
                                possible_moves.clear();
                            }

                        }
                        else
                        {
                            clicked_row_1 = event.mouseButton.y / (HEIGHT / ROW);
                            clicked_col_1 = event.mouseButton.x / (WIDTH / COL);
                            if (color_turn == BLACK)
                            {
                                if (!board.is_empty(clicked_row_1, clicked_col_1) && board.get_color(clicked_row_1, clicked_col_1) == BLACK)
                                {
                                    board.get_possible_moves(POS(clicked_row_1, clicked_col_1), possible_moves);
                                    show_possible_moves_bool = true;
                                }
                            }
                            else if (color_turn == WHITE)
                            {
                                if (!board.is_empty(clicked_row_1, clicked_col_1) && board.get_color(clicked_row_1, clicked_col_1) == WHITE)
                                {
                                    board.get_possible_moves(POS(clicked_row_1, clicked_col_1), possible_moves);
                                    show_possible_moves_bool = true;
                                }
                            }
                            else
                            {
                                std::cout << "no troops here" << std::endl;
                            }
                        }
                    }
                default:
                    break;
                }
            }
            if (show_possible_moves_bool)
            {   
                draw_possible_moves(possible_moves);
            }
            if (pawn_move_pos != POS(-1,-1) && !checked_mate_bool)
            {
                pawn_choose();
            }
            draw_tool_bar();
            window.display();
            window.setFramerateLimit(60);
        }
	}
    void Game::draw_possible_moves(std::vector<POS>& possible_moves)
    {
        sf::CircleShape circle(20, 30);
        circle.setFillColor(sf::Color(51, 153, 255, 255));
        circle.setOutlineThickness(4);
        circle.setOutlineColor(sf::Color::Black);
        for (int i = 0; i < possible_moves.size(); i++)
        {
            circle.setPosition(((possible_moves[i].col) * (WIDTH / COL)) + 25, ((possible_moves[i].row) * (HEIGHT / ROW)) + 25);
            window.draw(circle);
        }
    }
    void Game::move_turn()
    {
        if (color_turn == BLACK)
            color_turn = WHITE;
        else
            color_turn = BLACK;
        turn_counter++;
    }
    void Game::draw_tool_bar()
    {
        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(40);
        text.setStyle(sf::Text::Bold);
        text.setFillColor(sf::Color::White);
        text.setPosition(WIDTH, 0);
        if (color_turn == BLACK)
            text.setString("black turn");
        else
            text.setString("White turn");
        window.draw(text);

        text.setPosition(WIDTH, 50);
        text.setCharacterSize(25);
        text.setString(std::string("turn counter:" + std::to_string(turn_counter)));
        window.draw(text);

        if (checked_mate_bool)
        {
            text.setCharacterSize(24);
            text.setFillColor(sf::Color::Red);
            text.setPosition(WIDTH, 100);
            text.setString("CHECK MATE");
            window.draw(text);
        }
        else if (checked_bool)
        {
            text.setCharacterSize(32);
            text.setFillColor(sf::Color::Red);
            text.setPosition(WIDTH, 100);
            text.setString("CHECKED");
            window.draw(text);
        }

        if (checked_mate_bool)
        {
            text.setCharacterSize(50);
            text.setFillColor(sf::Color::Black);
            text.setPosition(100, 350);
            if(color_turn == BLACK)
                text.setString(std::string("The Winner is: WHITE"));
            else
                text.setString(std::string("The Winner is: BLACK"));
            window.draw(text);
        }

    }


    bool Game::is_checked()
    {
        std::vector<POS> opponent_moves;
        if (color_turn == BLACK)
            board.get_all_moves(WHITE, opponent_moves);
        else
            board.get_all_moves(BLACK, opponent_moves);

        for (int i = 0; i < opponent_moves.size(); i++)
        {
            const Unit* unit = board.get_unit(opponent_moves[i]);
            if (unit != nullptr)
            {
                if (typeid(*unit) == typeid(King))
                {
                    return true;
                }
            }
        }
        return false;
    }

    POS Game::pawn_move()
    {
        return board.pawn_move(color_turn);
    }


    void Game::pawn_choose()
    {
        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(40);
        text.setStyle(sf::Text::Bold);
        text.setFillColor(sf::Color::Black);
        text.setPosition(50, 300);
        text.setString(std::string("choose a unit to promote your pawn"));
        window.draw(text);
        sf::RectangleShape box(sf::Vector2f(160,100));
        box.setFillColor(sf::Color(135, 206, 235, 255));
        box.setOutlineColor(sf::Color::Black);
        box.setOutlineThickness(5);

        box.setPosition(20, 350);
        window.draw(box);
        box.setPosition(220, 350);
        window.draw(box);
        box.setPosition(420, 350);
        window.draw(box);
        box.setPosition(620, 350);
        window.draw(box);


        text.setPosition(40, 370);
        text.setString("Bishop");
        window.draw(text);

        text.setPosition(240, 370);
        text.setString("Knight");
        window.draw(text);

        text.setPosition(440, 370);
        text.setString("Queen");
        window.draw(text);

        text.setPosition(650, 370);
        text.setString("Rook");
        window.draw(text);
    }

    void Game::get_pawn_choose(POS & pawn_move_pos,const int& y, const int& x ) 
    {
        int curr_color;
        if (color_turn == WHITE)
            curr_color = BLACK;
        else curr_color = WHITE;
        if (y > 350 && y < 450 && x>20 && x < 180)
        {
            board.pawn_promote(pawn_move_pos, 1, curr_color);
        }
        if (y > 350 && y < 450 && x>220 && x < 380)
        {
            board.pawn_promote(pawn_move_pos, 2, curr_color);
        }
        if (y > 350 && y < 450 && x>420 && x < 580)
        {
            board.pawn_promote(pawn_move_pos, 3, curr_color);
        }
        if (y > 350 && y < 450 && x>620 && x < 780)
        {
            board.pawn_promote(pawn_move_pos, 4, curr_color);
        }
        pawn_move_pos = POS(-1, -1);
    }

    bool Game::checked_mate()
    {
        if (!checked_bool)
            return false;
        std::vector<POS> king_moves;
        std::vector<POS> opponent_moves;
        POS king_pos = board.get_king_moves(color_turn, king_moves);
        for (int i = 0; i < king_moves.size(); i++)
        {
            const Unit* unit = board.get_unit(king_moves[i]);
            if (unit != nullptr)
            {
                Board temp_board(board);
                temp_board.move(king_pos, king_moves[i]);
                if (color_turn == BLACK)
                    temp_board.get_all_moves(WHITE, opponent_moves);
                else temp_board.get_all_moves(BLACK, opponent_moves);
            }
            else
            {
                board.move(king_pos, king_moves[i]);
                if (color_turn == BLACK)
                    board.get_all_moves(WHITE, opponent_moves);
                else board.get_all_moves(BLACK, opponent_moves);
                board.move(king_moves[i], king_pos);
            }
            std::vector<POS>::iterator itr = std::find(opponent_moves.begin(), opponent_moves.end(), king_moves[i]);
            if (itr == opponent_moves.end())
                return false;
            opponent_moves.clear();
        }
        return true;
    }

}