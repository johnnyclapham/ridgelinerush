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
}

void Sprite::update(float time){
}

void Sprite::draw(sf::Vector2<float> position, sf::RenderWindow *window) {
    sf::Texture newTexture;
    
    if(!newTexture.loadFromFile(texture)){
       //error
       // new handling: if sprite fails to load, try alternate
       // addressing method (for Mac OS)
       std::cout << "failed to load: "<<texture<<" \n";
       texture = "../"+texture;
       std::cout << "now loading   : "<<texture<<" \n";
       newTexture.loadFromFile(texture);
    }
    
    sprite.setTexture(newTexture);
    sprite.setPosition(position);
    sprite.setScale(4,4);
    window->draw(sprite);
}

