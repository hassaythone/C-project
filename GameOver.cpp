#include "GameOver.h"

GameOver::GameOver(sf::RenderWindow& window) : m_window(window), m_restartSelected(false), m_visible(false) {
    if (!m_font.loadFromFile("times.ttf")) {
        // Handle error
    }
    m_gameOverText.setFont(m_font);
    m_gameOverText.setString("Game Over");
    m_gameOverText.setCharacterSize(50);
    m_gameOverText.setFillColor(sf::Color::White);
    m_gameOverText.setPosition(300, 200);

    m_restartOption.setFont(m_font);
    m_restartOption.setString("Restart");
    m_restartOption.setCharacterSize(30);
    m_restartOption.setFillColor(sf::Color::White);
    m_restartOption.setPosition(350, 300);
}

void GameOver::processEvents() {
    sf::Event event;
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_window.close();
        }
        else if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2f mousePos = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
            if (m_restartOption.getGlobalBounds().contains(mousePos)) {
                m_restartSelected = true;
            }
        }
    }
}

void GameOver::display() {
    m_window.draw(m_gameOverText);
    m_window.draw(m_restartOption);
}

bool GameOver::isRestartSelected() const {
    return m_restartSelected;
}

void GameOver::hide() {
    m_visible = false;
}

bool GameOver::isVisible()  {
    return m_visible;
}
sf::Sprite GameOver::getSprite() const {
    return m_sprite;

}
  void GameOver::display(sf::RenderWindow & window) {
        window.draw(m_sprite);
        window.draw(m_restartText);
    }