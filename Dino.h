#ifndef DINO_H
#define DINO_H

#include <SFML/Graphics.hpp>

class Dino {
public:
    Dino();
    void move();
    bool isCollidingWith(const sf::Sprite& sprite) const;
    void draw(sf::RenderWindow& window, sf::Sprite dinoo) ;
    sf::Sprite m_sprite;
private:
    
    
    sf::Vector2f m_velocity;
};

#endif // DINO_H