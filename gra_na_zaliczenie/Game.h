#pragma once
#include "const.h"
#include <SFML/Graphics.hpp>
#include "Meteor.h"
#include "Player.h"
#include "Scoreboard.h"
#include "Bullet.h"
#include <vector>

class Game
{
private:
    sf::RenderWindow window;
    std::vector<Meteor> meteors;
    std::vector<Bullet> bullets;
    Player* player;
    Bullet* bullet;
    sf::Texture* meteor_tex;
    sf::Texture* bullet_tex;
    sf::Texture* player_tex;
    sf::Texture* background_tex;
    sf::Texture* mouse_tex;
    sf::Clock clock;
    sf::Time dt;
    sf::Sprite background;
    sf::Sprite mouse;
    Scoreboard scoreboard;
    float meteor_cd;
    float meteor_time;
    bool game_over;
    bool shot = true;

public:
    Game();
    virtual ~Game();
    void start();
    void update();
    void draw();
    void check_collision();
    void check_shooting();
    void add_meteor();
    void add_bullet();
    void game_over_screen();
    void update_mouse();
};

