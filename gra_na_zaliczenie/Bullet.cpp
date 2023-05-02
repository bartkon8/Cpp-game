#include "Bullet.h"
#include<iostream>

Bullet::Bullet(sf::Texture* texture, Player* player) : sf::Sprite()
{
    setTexture(*texture);      
    setPosition(player->getPosition());
    setScale(0.5,0.5);
    y_vel = 800;
}
Bullet::~Bullet(){

}
bool Bullet::collision(const Meteor& meteor){
    return getGlobalBounds().intersects(meteor.getGlobalBounds());
}
void Bullet::step(const sf::Time& dt){
    move(0.0f, -y_vel * dt.asSeconds());
}
bool Bullet::shoot()
{

    return false;
}

bool Bullet::out_of_screen()
{
    auto rect = getGlobalBounds();
    return rect.top < 0;
}
