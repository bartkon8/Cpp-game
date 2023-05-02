#include "Game.h"
#include <iostream>
#include <windows.h>

Game::Game():window(sf::VideoMode(WIN_W, WIN_H), "Game"), mouse_tex(new sf::Texture), meteor_tex(new sf::Texture), bullet_tex(new sf::Texture), player_tex(new sf::Texture), background_tex(new sf::Texture), meteor_cd(METEOR_MAX_CD), meteor_time(METEOR_MAX_CD), game_over(true)
{
    meteor_tex->loadFromFile("assets/meteor.png");
    bullet_tex->loadFromFile("assets/bullet.png");
    player_tex->loadFromFile("assets/player.png");
    background_tex->loadFromFile("assets/background.png");
    mouse_tex->loadFromFile("assets/mouse.png");


    player = new Player(player_tex);
    background.setTexture(*background_tex);
    mouse.setTexture(*mouse_tex);
    mouse.setOrigin(mouse.getGlobalBounds().width * 0.5f, mouse.getGlobalBounds().height * 0.5f);
    auto bg_rect = background.getGlobalBounds();
    sf::Vector2f size_now(bg_rect.width, bg_rect.height);

    background.setScale(WIN_W/size_now.x, WIN_H/size_now.y);
    window.setMouseCursorVisible(false);
}

Game::~Game()
{
    delete meteor_tex;
    delete player_tex;
    delete background_tex;
    delete player;
    delete mouse_tex;
}

void Game::start()
{
    game_over = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::Resized)
            {
                window.setSize({ WIN_W, WIN_H });
            }
        }

        if (game_over)
        {
            game_over_screen();
        }
        else
        {
            update();
            draw();

        }

        update_mouse();
    }
}

void Game::update()
{
    dt = clock.restart();
    meteor_time += dt.asSeconds();
    player->update(window, dt);

    for (auto it=meteors.begin(); it!=meteors.end();)
    {
     it->step(dt);

        if (it->out_of_screen())
        {
            it = meteors.erase(it);

        }
        else
        {
            it++;
        }


    }
    for(auto it=bullets.begin(); it!=bullets.end();){
        it->step(dt);
        if (it->out_of_screen())
        {
            it = bullets.erase(it);
        }
        else
        {
            it++;
        }

    }


    if (meteor_time >= meteor_cd)
    {
        add_meteor();
        meteor_time = 0.0f;
        meteor_cd = std::max(meteor_cd * 0.97f, METEOR_MIN_CD);
    }
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&& shot){
        add_bullet();
        shot = false;
    }
    if(!sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {

        shot = true;
    }


    scoreboard.update(player);
    check_collision();
    check_shooting();

}

void Game::check_collision()
{
    for (auto it = meteors.begin(); it != meteors.end(); )
    {
        if (player->collision(*it))
        {
            it = meteors.erase(it);


            if (!player->lose_life())
            {
                game_over = true;
            }
        }
        else
        {

            it++;

        }

    }
}
void Game::check_shooting()
{

        for (size_t m = 0; m < meteors.size(); m++)
        {

            for(size_t b = 0; b < bullets.size(); b++)
            {

               if(bullets[b].collision(meteors[m]))
               {
                   meteors.erase(meteors.begin()+m);
                   bullets.erase(bullets.begin()+b);
                   player->add_point();


               }
            }

        }
}
void Game::draw()
{
    window.clear(WIN_BG);
    window.draw(background);

    for (auto& d : meteors)
    {
        window.draw(d);

    }
    for(auto& b : bullets)
    {
        window.draw(b);
    }

    window.draw(*player);
    scoreboard.draw(window);
    window.draw(mouse);
    window.display();
}

void Game::add_meteor()
{
    meteors.emplace_back(meteor_tex);
    meteors.emplace_back(meteor_tex);
    meteors.emplace_back(meteor_tex);
    meteors.emplace_back(meteor_tex);
}
void Game::add_bullet()
{
    bullets.emplace_back(bullet_tex, player);
}

void Game::game_over_screen()
{
    window.clear(WIN_BG);
    scoreboard.draw_game_over_screen(window);
    window.draw(mouse);
    window.display();
}

void Game::update_mouse()
{
    mouse.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
}
