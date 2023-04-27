#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <SFML/Graphics.hpp>

class Scoreboard {
public:
    Scoreboard();
    void incrementScore();
    int getScore() const;
    void reset();
    void draw(sf::RenderWindow& window) const;
private:
    sf::Font m_font;
    sf::Text m_scoreText;
    int m_score;
};

#endif // SCOREBOARD_H