#pragma once
#include <SFML/Graphics.hpp>

class character : public sf::Sprite {
public:
    character(sf::Texture& texture, const sf::Vector2f& position, const sf::Vector2f& velocity)
        : m_velocity(velocity) {
        setTexture(texture);
        setPosition(position);
    }

    void update(float deltaTime) {
        // Update position based on velocity and deltaTime
        sf::Vector2f position = getPosition();
        position += m_velocity * deltaTime;
        setPosition(position);

        // Check if character has hit a wall and reverse direction if necessary
        if (position.x < 0 || position.x > 800) {
            m_velocity.x = -m_velocity.x;
        }
        if (position.y < 0 || position.y > 600) {
            m_velocity.y = -m_velocity.y;
        }
    }

    operator sf::Sprite() const {
        return static_cast<sf::Sprite>(*this);
    }

private:
    sf::Vector2f m_velocity;
};