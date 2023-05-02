#include "Scoreboard.h"

Scoreboard::Scoreboard()
{
    background.setSize({WIN_W, SCOREBOARD_H});
    background.setFillColor(SCOREBOARD_COL);
    font.loadFromFile("assets/font.ttf");
    points.setFont(font);
    points.setCharacterSize(FONT_SIZE);
    lives.setFont(font);
    lives.setCharacterSize(FONT_SIZE);
    game_over.setFont(font);
    game_over.setCharacterSize(FONT_SIZE*2);
    game_over.setString("GAME OVER!");
    game_over.setOrigin(game_over.getGlobalBounds().width * 0.5f, game_over.getGlobalBounds().height * 0.5f);
    game_over.setPosition(WIN_W * 0.5f, WIN_H * 0.5f - 100.0f);
}


Scoreboard::~Scoreboard()
{
}

void Scoreboard::update(Player* player)
{
    points.setString("Score: " + std::to_string(player->get_points()));
    lives.setString("Lives: " + std::to_string(player->get_lives()));

    points.setPosition(10.0f, 5.0f);
    lives.setPosition(WIN_W - lives.getGlobalBounds().width - 10.0f, 5.0f);
}

void Scoreboard::draw(sf::RenderWindow& window)
{
    window.draw(background);
    window.draw(points);
    window.draw(lives);
}

void Scoreboard::draw_game_over_screen(sf::RenderWindow& window)
{
    points.setPosition(WIN_W * 0.5f - points.getGlobalBounds().width * 0.5f, WIN_H * 0.5f + 100.0f);
    background.setSize({ WIN_W, WIN_H });
    window.draw(background);
    window.draw(game_over);
    window.draw(points);
}
