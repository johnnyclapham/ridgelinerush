//
// Created by John on 3/28/2021.
//

#ifndef RIDGELINERUSH_SPRITE_H
#define RIDGELINERUSH_SPRITE_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Constants.h"

class Sprite
{
public:
    // constructors //
    Sprite();
    Sprite(const std::string &spritesheet);

    // mutators //
    void update(float time);
    void setDirection(Direction direction);
    void setWidth(float width);
    void setScale(sf::Vector2<float> scale);
    void draw(sf::Vector2<float> position, sf::RenderWindow* window);

    sf::FloatRect getBounds();

private:
    // members //
    sf::Sprite sprite;
    sf::Texture newTexture;
    float spriteWidth;
    Direction spriteDirection;
    std::string texture;
    float scaleX;
    float scaleY;
};

#endif // SPRITE_H
