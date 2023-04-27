#include "Scoreboard.h"

Scoreboard::Scoreboard() : m_score(0) {
    if (!m_font.loadFromFile("times.ttf")) {
        // Handle error
    }
    m_scoreText.setFont(m_font);
    m_scoreText.setString("Score: 0");
    m_scoreText.setCharacterSize(30);
    m_scoreText.setFillColor(sf::Color::White);
    m_scoreText.setPosition(600, 50);
}

void Scoreboard::incrementScore() {
    m_score++;
    m_scoreText.setString("Score: " + std::to_string(m_score));
}

int Scoreboard::getScore() const {
    return m_score;
}

void Scoreboard::reset() {
    m_score = 0;
    m_scoreText.setString("Score: 0");
}

void Scoreboard::draw(sf::RenderWindow& window) const {
    window.draw(m_scoreText);
}