#include "Player.h"

Player::Player(sf::RenderWindow& window) : m_window(window), m_shape(sf::Vector2f(50, 50)), m_speed(200.0f)
{
    // Initialize variables and resources
    m_shape.setFillColor(sf::Color::Green);
    m_shape.setPosition(50, 50);
}

void Player::update(float deltaTime)
{
    // Update position based on input and time elapsed
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        moveUp();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        moveDown();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        moveLeft();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        moveRight();
    }
}

void Player::draw()
{
    // Draw player shape to window
    m_window.draw(m_shape);
}

void Player::moveUp()
{
    m_shape.move(0, -m_speed * sf::Time().asSeconds());
}

void Player::moveDown()
{
    m_shape.move(0, m_speed * sf::Time().asSeconds());
}

void Player::moveLeft()
{
    m_shape.move(-m_speed * sf::Time().asSeconds(), 0);
}

void Player::moveRight()
{
    m_shape.move(m_speed * sf::Time().asSeconds(), 0);
}

sf::FloatRect Player::getBounds()
{
    return m_shape.getGlobalBounds();
}