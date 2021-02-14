#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
namespace chess 
{
	class GameManu
	{
	private:
		sf::RenderWindow& window;
	public:
		GameManu(sf::RenderWindow& window) : window(window) {}
		void run(bool& black_start,bool& vs_computer)
		{
            vs_computer = false;// will my be add at the future
            sf::Font font;
            font.loadFromFile("arial.ttf");
            sf::Text text1;
            text1.setFont(font);
            text1.setCharacterSize(40);
            text1.setStyle(sf::Text::Bold);
            text1.setFillColor(sf::Color::White);
			text1.setString("Welcome To Chess Game");
			text1.setPosition(250, 50);

            sf::Text text2;
            text2.setFont(font);
            text2.setCharacterSize(34);
            text2.setStyle(sf::Text::Bold);
            text2.setFillColor(sf::Color::White);
            text2.setString("Choose which player will start the game");
            text2.setPosition(180, 250);

            sf::Text text3;
            text3.setFont(font);
            text3.setCharacterSize(50);
            text3.setStyle(sf::Text::Bold);
            text3.setFillColor(sf::Color::White);
            text3.setString("BLACK");
            text3.setPosition(200+40, 350+15);


            sf::Text text4;
            text4.setFont(font);
            text4.setCharacterSize(50);
            text4.setStyle(sf::Text::Bold);
            text4.setFillColor(sf::Color::White);
            text4.setString("WHITE");
            text4.setPosition(520 +40, 350+15);


            sf::RectangleShape squre1(sf::Vector2f(250,100));
            squre1.setPosition(200, 350);
            squre1.setFillColor(sf::Color::Black);
            squre1.setOutlineColor(sf::Color::White);
            squre1.setOutlineThickness(5);

            sf::RectangleShape squre2(sf::Vector2f(250, 100));
            squre2.setPosition(520, 350);
            squre2.setFillColor(sf::Color::Black);
            squre2.setOutlineColor(sf::Color::White);
            squre2.setOutlineThickness(5);

            while (window.isOpen())
            {
                window.clear();
                sf::Event event;
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
                            if (event.mouseButton.x > 200 && event.mouseButton.x < 450 && event.mouseButton.y >350 && event.mouseButton.y < 450)
                            {//BLACK
                                black_start = true;
                                return;
                            }
                            if (event.mouseButton.x > 520 && event.mouseButton.x < 770 && event.mouseButton.y >350 && event.mouseButton.y < 450)
                            {//WHITE
                                black_start = false;
                                return;
                            }
                        }
                    default:
                        break;
                    }
                }

                window.draw(squre1);
                window.draw(squre2);
                window.draw(text1);
                window.draw(text2);
                window.draw(text3);
                window.draw(text4);
                window.display();
                window.setFramerateLimit(60);
            }
		}
	};
}


