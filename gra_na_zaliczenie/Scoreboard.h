#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

class Scoreboard
{
private:
    sf::Font font;
    sf::Text points;
    sf::Text lives;
    sf::Text game_over;
    sf::RectangleShape background;
public:
    Scoreboard();
    ~Scoreboard();

    void update(Player* player);
    void draw(sf::RenderWindow& window);
    void draw_game_over_screen(sf::RenderWindow& window);
};

