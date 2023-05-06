#ifndef MENU_H
#define MENU_H
#include "Character.h"
#include <chrono>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class Menu {
public:
    Menu(sf::RenderWindow& window, sf::Music& music);
    void processEvents();
    void displayMenu();
    bool isOptionSelected() const;
    void hide();
    bool isVisible() const;

private:
    sf::RenderWindow& m_window;
    sf::Music& m_music;
    sf::Font m_font;
    sf::Text m_title;
    sf::Text m_playOption;
    sf::Text m_playOption2;
    sf::Text m_exitOption;
    bool m_optionSelected;
    bool m_visible;
    std::vector<character> m_characters;
    sf::Text m_wButton;
    sf::Text m_aButton;
    sf::Text m_sButton;
    sf::Text m_dButton;
    
    
};

#endif // MENU_H