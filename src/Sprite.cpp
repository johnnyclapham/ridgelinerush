//
// Created by John on 3/28/2021.
//

#include "Sprite.h"
#include <math.h>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

Sprite::Sprite() {
}

Sprite::Sprite(const std::string &spritesheet) {
    texture = spritesheet;
    spriteDirection = RIGHT;
    scaleX = 4;
    scaleY = 4;
    if(!newTexture.loadFromFile(texture)){
       //error
       // new handling: if sprite fails to load, try alternate
       // addressing method (for Mac OS)
       // commented out for console spam
       // std::cout << "failed to load: "<<texture<<" \n";
      texture = "../"+texture;
      std::cout << "Error with standard path. Now loading   : "<<texture<<" \n";
      newTexture.loadFromFile(texture);
    }
}

void Sprite::update(float time){
}

void Sprite::setDirection(Direction direction){
    spriteDirection = direction;
}

void Sprite::setWidth(float width){
    spriteWidth = width;
}

void Sprite::setScale(sf::Vector2<float> scale){
    scaleX = scale.x;
    scaleY = scale.y;
}

sf::FloatRect Sprite::getBounds(){
    return sprite.getGlobalBounds();
}

void Sprite::draw(sf::Vector2<float> position, sf::RenderWindow *window) {
    sprite.setTexture(newTexture);
    sprite.setScale(scaleX,scaleY);
    sprite.setPosition(position);
    if(spriteDirection == LEFT){
        sprite.scale(-1.f,1.f);
        sprite.setPosition(position.x + spriteWidth, position.y);
    }
    window->draw(sprite);
}

