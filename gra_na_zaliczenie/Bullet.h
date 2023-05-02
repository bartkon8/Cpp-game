#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
#include "Player.h"

class Bullet : public sf::Sprite
{

private:
    float y_vel;

    int i = 0;
public:
    Bullet(sf::Texture* texture, Player* player);
    virtual ~Bullet();
    bool collision(const Meteor& meteor);
    void step(const sf::Time& dt);
    bool shoot();
    bool out_of_screen();
};

#endif // BULLET_H
