#include "Bullet.h"

Bullet::Bullet() : m_velocity(0.5, 0), m_active(false) {
    if (!m_texture.loadFromFile("images/bullet.jpg")) {
        // Handle error
    }
    m_sprite.setTexture(m_texture);
}

void Bullet::move() {
    if (m_active) {
        m_sprite.move(m_velocity);
    }
}

void Bullet::reset() {
    m_active = false;
    m_sprite.setPosition(-100, -100);
}

bool Bullet::isCollidingWith(const sf::Sprite& sprite) const {
    return m_active && m_sprite.getGlobalBounds().intersects(sprite.getGlobalBounds());
}

void Bullet::draw(sf::RenderWindow& window) const {
    if (m_active) {
        window.draw(m_sprite);
    }
}
