#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <SFML/Graphics.hpp>

class GameOver {
public:
    
    GameOver(sf::RenderWindow& window);
    void processEvents();
    void display();
    bool isRestartSelected() const;
    void hide();
    bool isVisible() ;
    sf::Sprite getSprite() const;
   void display(sf::RenderWindow& window);
private:
    sf::RenderWindow& m_window;
    sf::Font m_font;
    sf::Text m_gameOverText;
    sf::Text m_restartOption;
    bool m_restartSelected;
    bool m_visible;
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    sf::Text m_restartText;
};

#endif // GAMEOVER_H