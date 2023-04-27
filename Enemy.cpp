#include "Enemy.h"

Enemy::Enemy() : m_hit(false), m_speed(0.5) {
    if (!m_texture.loadFromFile("images/monster.png")) {
        // Handle error
    }
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(800, 100);
    m_velocity.x = -m_speed;
}

void Enemy::move() {
    m_sprite.move(m_velocity);
}

void Enemy::reset() {
    m_hit = false;
    m_speed = 2;
    m_sprite.setPosition(800, 100);
    m_velocity.x = -m_speed;
}

void Enemy::increaseSpeed() {
    m_speed += 0.5;
    m_velocity.x = -m_speed;
}

void Enemy::hit() {
    m_hit = true;
}

bool Enemy::isHit() const {
    return m_hit;
}

bool Enemy::isOffScreen() const {
    return m_sprite.getPosition().x < -m_sprite.getGlobalBounds().width;
}

bool Enemy::isCollidingWith(const sf::Sprite& sprite)  {
    return m_sprite.getGlobalBounds().intersects(sprite.getGlobalBounds());
}

void Enemy::draw(sf::RenderWindow& window) const {
    window.draw(m_sprite);
}

sf::Sprite Enemy::getSprite() const { // added member function
    return m_sprite;
}