#include "Meteor.h"

Meteor::Meteor(sf::Texture* texture) : sf::Sprite()
{
    setTexture(*texture);
    setPosition(static_cast<float>(std::rand()%WIN_W), -100.0f);
    setOrigin(size()/2.f);
    y_vel = static_cast<float>(std::rand()%400)+MIN_YVEL;
    float s = static_cast<float>(rand()%2+1);
    setScale(s,s);
}

void Meteor::step(const sf::Time& dt)
{
    move(0.0f, y_vel * dt.asSeconds());
}

bool Meteor::out_of_screen()
{
    auto rect = getGlobalBounds();
    return rect.top > WIN_H;
}


Meteor::~Meteor()
{
}

sf::Vector2f Meteor::size()
{
    auto rect = getGlobalBounds();
    return sf::Vector2f(rect.width, rect.height);
}

float Meteor::random_float_in_range(const float& min, const float& max)
{
    std::srand(static_cast<unsigned int>(std::time(0)));
    return min + static_cast<float>(std::rand() % 101) / 100.0f * max;
}
