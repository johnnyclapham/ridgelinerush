//
// Created by John on 3/28/2021.
//

#ifndef RIDGELINERUSH_SPRITE_H
#define RIDGELINERUSH_SPRITE_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class Sprite
{
public:
    // constructors //
    Sprite();
    Sprite(const std::string &spritesheet);

    // mutators //
    void update(float time);
    void draw(sf::Vector2<float> position, sf::RenderWindow* window);

private:
    // members //
    sf::Sprite sprite;
    std::string texture;
};

#endif // SPRITE_H
