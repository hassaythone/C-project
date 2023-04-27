#ifndef SUPER_ENEMY_H
#define SUPER_ENEMY_H

#include <SFML/Graphics.hpp>

class Super_Enemy {
public:
    Super_Enemy();
    void move();
    void reset();
    void increaseSpeed();
    void changeSize();
    void hit();
    bool isHit() const;
    bool isOffScreen() const;
    bool isCollidingWith(const sf::Sprite& sprite) ;
    void draw(sf::RenderWindow& window) const;
    sf::Sprite getSprite() const; // added member function
private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    sf::Vector2f m_velocity;
    bool m_hit;
    float m_speed;
    bool m_growing;
    

};

#endif // SUPER_ENEMY_H