#include "Dino.h"

Dino::Dino() : m_velocity(0, 0) {
    if (!m_texture.loadFromFile("images/dinos.png")) {
        // Handle error
    }
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(100, 100);
}

void Dino::move() {
    // Update velocity based on which keys are pressed
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        m_velocity.y = -5;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        m_velocity.y = 5;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        m_velocity.x = -5;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        m_velocity.x = 5;
    }

    // Handle jumping
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && m_sprite.getPosition().y >= 100) {
        m_velocity.y = -10;
    }

    // Update position based on velocity
    m_sprite.move(m_velocity);

    // Clamp position to screen bounds
    sf::Vector2f position = m_sprite.getPosition();
    position.x = std::max(position.x, 0.0f);
    position.x = std::min(position.x, 800.0f);
    position.y = std::max(position.y, 0.0f);
    position.y = std::min(position.y, 600.0f);
    m_sprite.setPosition(position);

    // Reset velocity
    m_velocity = sf::Vector2f(0, 0);
}

bool Dino::isCollidingWith(const sf::Sprite& sprite) const {
    return m_sprite.getGlobalBounds().intersects(sprite.getGlobalBounds());
}

void Dino::draw(sf::RenderWindow& window) const {
    window.draw(m_sprite);

}
