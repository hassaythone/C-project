#include "Super_Enemy.h"

Super_Enemy::Super_Enemy() : m_hit(false), m_speed(0.5), m_growing(true) {
    if (!m_texture.loadFromFile("images/dinos.png")) {
        // Handle error
    }
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(800, 350);
    m_velocity.x = -m_speed;
}

void Super_Enemy::move() {
    m_sprite.move(m_velocity);
}

void Super_Enemy::reset() {
    m_hit = false;
    m_speed = 1;
    m_growing = true;
    m_sprite.setScale(1, 1);
    m_sprite.setPosition(800, 350);
    m_velocity.x = -m_speed;
}

void Super_Enemy::increaseSpeed() {
    m_speed += 0.5;
    m_velocity.x = -m_speed;
}

void Super_Enemy::changeSize() {
    if (m_growing) {
        m_sprite.setScale(m_sprite.getScale().x + 0.1, m_sprite.getScale().y + 0.1);
        if (m_sprite.getScale().x >= 2) {
            m_growing = false;
        }
    }
    else {
        m_sprite.setScale(m_sprite.getScale().x - 0.1, m_sprite.getScale().y - 0.1);
        if (m_sprite.getScale().x <= 1) {
            m_growing = true;
        }
    }
}

void Super_Enemy::hit() {
    m_hit = true;
}

bool Super_Enemy::isHit() const {
    return m_hit;
}

bool Super_Enemy::isOffScreen() const {
    return m_sprite.getPosition().x < -m_sprite.getGlobalBounds().width;
}

bool Super_Enemy::isCollidingWith(const sf::Sprite& sprite)  {
    return m_sprite.getGlobalBounds().intersects(sprite.getGlobalBounds());
}

void Super_Enemy::draw(sf::RenderWindow& window) const {
    window.draw(m_sprite);
}
sf::Sprite Super_Enemy::getSprite() const { // added member function
    return m_sprite;
}