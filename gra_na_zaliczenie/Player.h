#pragma once
#include <SFML/Graphics.hpp>
#include "const.h"
#include "Meteor.h"
#include <math.h>

class Player : public sf::Sprite
{
private:
    int points;
    int lives;
    sf::Vector2f size();
    void clamp_pos(sf::Vector2f& vec);
public:
    Player(sf::Texture* texture);
    virtual ~Player();

    void update(const sf::RenderWindow& window, const sf::Time& dt);
    bool collision(const Meteor& meteor);
    int get_points() const;
    int get_lives() const;
    bool lose_life();
    void add_point();
};

