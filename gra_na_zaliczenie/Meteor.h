#pragma once
#include <SFML/Graphics.hpp>
#include "const.h"



class Meteor : public sf::Sprite
{
private:
    float y_vel;

    float random_float_in_range(const float& min, const float& max);
    sf::Vector2f size();
public:
    Meteor(sf::Texture* texture);
    virtual ~Meteor();
    void step(const sf::Time& dt);

    bool out_of_screen();
};

