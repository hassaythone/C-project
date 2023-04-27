#pragma once

#include <SFML/Graphics.hpp>

class Player
{
public:
    Player(sf::RenderWindow& window);

    void update(float deltaTime);
    void draw();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    sf::FloatRect getBounds();

private:
    sf::RenderWindow& m_window;
    sf::RectangleShape m_shape;
    float m_speed;
};