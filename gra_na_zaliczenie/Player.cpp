#include "Player.h"

sf::Vector2f Player::size()
{
    auto rect = getGlobalBounds();
    return sf::Vector2f(rect.width, rect.height);
}

void Player::clamp_pos(sf::Vector2f& vec)
{
    vec.x = std::max(XMIN, std::min(vec.x, XMAX));
    vec.y = std::max(YMIN, std::min(vec.y, YMAX));
}

Player::Player(sf::Texture* texture): lives(PLAYER_LIVES), points(0)
{
    setTexture(*texture);
    setPosition(0.0f, PLAYER_Y);
    setOrigin(size()/2.0f);
}

Player::~Player()
{
}

void Player::update(const sf::RenderWindow& window, const sf::Time& dt)
{
    auto now_pos = getPosition();
    sf::Vector2f mouse_pos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
    float dx = -now_pos.x + mouse_pos.x;
    float dy = -now_pos.y + mouse_pos.y;

    float len = std::sqrt(dx * dx + dy * dy);

    sf::Vector2f move_dir(dx,dy);

    if (len != 0.0f)
    {
        move(move_dir / len * PLAYER_SPEED * dt.asSeconds());
    }

    sf::Vector2f new_pos = getPosition();
    clamp_pos(new_pos);
    setPosition(new_pos);
}

bool Player::collision(const Meteor& meteor)
{

    return getGlobalBounds().intersects(meteor.getGlobalBounds());
}

int Player::get_points() const
{
    return points;
}

int Player::get_lives() const
{
    return lives;
}

bool Player::lose_life()
{
    return (--lives) > 0;
}

void Player::add_point()
{
    points++;
}
