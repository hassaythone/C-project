#ifndef MENU_H
#define MENU_H
#include "Character.h"
#include <chrono>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Clock.h"




class Menu {
public:
    Menu(sf::RenderWindow& window, sf::Music& music,sf::Texture& Background);
    
    void processEvents();
    void processEvents1();
    void displayMenu();
    bool isOptionSelected() const;
    void hide();
    bool isVisible() const  ;
void displayStartingScreen()  ;
bool isStartingScreenVisible() ;
void  selectDifficulty()  ;
int getSelectedDifficulty() const;
void ScenerySelection(sf::RenderWindow& m_window);
void CharacterSelection(sf::RenderWindow& m_window);
void HowToPlay(sf::RenderWindow& window);


int gamestate;
bool difficultySelected;
bool scenerySelected;
bool characterSelected;
bool howtoplay;
bool isDifficultySelected() const {
    return difficultySelected;
}

bool isScenerySelected() const {
    return scenerySelected;
}

bool isCharacterSelected() const {
    return characterSelected;
}
bool ishowtoplay() const {
    return howtoplay;
}
sf::Sprite charr;
sf::Sprite dino;
sf::Sprite getdino();

void setBackground(sf::Sprite& Background) {
    background = Background;
}
sf::Sprite getBackground() const {
    return background;
}

void setchar(sf::Sprite& charr) {
    dino = charr;
}
sf::Sprite getchar() const {
    return dino;
}
private:
    sf::Sprite m_background;
    int m_diffSelected;
    sf::Sprite background;
    sf::RenderWindow& m_window;
    
    sf::Music& m_music;
    sf::Font m_font;
    sf::Text m_title;
    sf::Text m_playOption;
    sf::Text m_playOption2;
    sf::Text m_exitOption;
    int m_selectedOption;
    bool m_optionSelected;
    bool m_visible;
    bool m_startingScreenVisible;
    std::vector<character> m_characters;
    sf::Text m_wButton;
    sf::Text m_aButton;
    sf::Text m_sButton;
    sf::Text m_dButton;
    void createColorColumns();
    sf::Text m_gameName;
    sf::Text m_pressAnyButton;
    std::vector<sf::RectangleShape> m_colorColumns;
    Clock clock;
    sf::Texture k_dButtonTexture;
    sf::Sprite k_dButtonSprite;


    std::vector<sf::Texture> m_movingImagesTextures;
    std::vector<sf::Sprite> m_movingImagesSprites;
};

#endif // MENU_H