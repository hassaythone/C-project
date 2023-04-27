#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>

class Bullet {
public:
    Bullet();
    void move();
    void reset();
    bool isCollidingWith(const sf::Sprite& sprite) const;
    void draw(sf::RenderWindow& window) const;
   
private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    sf::Vector2f m_velocity;
    bool m_active;
};

#endif // BULLET_H