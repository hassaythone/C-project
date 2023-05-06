#include "Menu.h"
#include <SFML/Audio.hpp>

Menu::Menu(sf::RenderWindow& window, sf::Music& music) : m_window(window), m_music(music), m_optionSelected(false), m_visible(true) {
    // Load font
    if (!m_font.loadFromFile("times.ttf")) {
        // Handle error
    }

    // Create title text
    m_title.setFont(m_font);
    m_title.setString("Dino Game");
    m_title.setCharacterSize(75);
    m_title.setFillColor(sf::Color::Magenta);
    m_title.setPosition(250, 100);

    // Create menu options
    m_playOption.setFont(m_font);
    m_playOption.setString("Play");
    m_playOption.setCharacterSize(30);
    m_playOption.setFillColor(sf::Color::White);
    m_playOption.setPosition(350, 250);

    m_playOption2.setFont(m_font);
    m_playOption2.setString("about");
    m_playOption2.setCharacterSize(30);
    m_playOption2.setFillColor(sf::Color::White);
    m_playOption2.setPosition(350, 300);

    m_exitOption.setFont(m_font);
    m_exitOption.setString("Exit");
    m_exitOption.setCharacterSize(30);
    m_exitOption.setFillColor(sf::Color::White);
    m_exitOption.setPosition(350, 350);

    m_wButton.setFont(m_font);
    m_wButton.setString("W");
    m_wButton.setCharacterSize(30);
    m_wButton.setFillColor(sf::Color::White);
    m_wButton.setPosition(100, 250);

    m_aButton.setFont(m_font);
    m_aButton.setString("A");
    m_aButton.setCharacterSize(30);
    m_aButton.setFillColor(sf::Color::White);
    m_aButton.setPosition(50, 300);

    m_sButton.setFont(m_font);
    m_sButton.setString("S");
    m_sButton.setCharacterSize(30);
    m_sButton.setFillColor(sf::Color::White);
    m_sButton.setPosition(100, 300);

    m_dButton.setFont(m_font);
    m_dButton.setString("D");
    m_dButton.setCharacterSize(30);
    m_dButton.setFillColor(sf::Color::White);
    m_dButton.setPosition(150, 300);
}

void Menu::processEvents() {
    
    // Handle events
    sf::Event event;
    while (m_window.pollEvent(event)) {
        
        if (event.type == sf::Event::Closed) {
            m_window.close();
        }
        else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up) {
                // Move up the menu
                if (m_playOption.getFillColor() == sf::Color::Red) {
                    m_playOption.setFillColor(sf::Color::White);
                    m_exitOption.setFillColor(sf::Color::Red);
                }
                else if (m_exitOption.getFillColor() == sf::Color::Red) {
                    m_exitOption.setFillColor(sf::Color::White);
                    m_playOption.setFillColor(sf::Color::Red);
                }
            }
            else if (event.key.code == sf::Keyboard::Down) {
                // Move down the menu
                if (m_playOption.getFillColor() == sf::Color::Red) {
                    m_playOption.setFillColor(sf::Color::White);
                    m_exitOption.setFillColor(sf::Color::Red);
                }
                else if (m_exitOption.getFillColor() == sf::Color::Red) {
                    m_exitOption.setFillColor(sf::Color::White);
                    m_playOption.setFillColor(sf::Color::Red);
                }
            }
            else if (event.key.code == sf::Keyboard::Return) {
                // Handle menu item selection
                if (m_playOption.getFillColor() == sf::Color::Red) {
                    m_optionSelected = true;
                    m_visible = false; // Hide the menu when the play option is selected
                }
                else if (m_exitOption.getFillColor() == sf::Color::Red) {
                    m_window.close();
                }
            }
            else if (event.key.code == sf::Keyboard::M) {
                m_music.pause();
            }
            else if (event.key.code == sf::Keyboard::N) {
                m_music.play();
            }
        }
        else if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2f mousePos = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
            if (m_playOption.getGlobalBounds().contains(mousePos)) {
                m_playOption.setFillColor(sf::Color::Red);
                m_exitOption.setFillColor(sf::Color::White);
                m_optionSelected = true;
            }
            else if (m_exitOption.getGlobalBounds().contains(mousePos)) {
                m_exitOption.setFillColor(sf::Color::Red);
                m_playOption.setFillColor(sf::Color::White);
                m_window.close();
            }
        }
    }
}

void Menu::displayMenu() {
    // Create characters
    
    sf::Texture characterTexture;
    characterTexture.loadFromFile("images/ball.PNG");
    m_characters.emplace_back(characterTexture, sf::Vector2f(100, 100), sf::Vector2f(50, 0));
    m_characters.emplace_back(characterTexture, sf::Vector2f(200, 200), sf::Vector2f(-30, 0));
    m_characters.emplace_back(characterTexture, sf::Vector2f(300, 300), sf::Vector2f(0, 20));
    m_characters.emplace_back(characterTexture, sf::Vector2f(300, 300), sf::Vector2f(0, 20));
    // Calculate deltaTime
    static sf::Clock clock;
    float deltaTime = clock.restart().asSeconds();
    for (const auto& character : m_characters) {
        m_window.draw(character);
    }
    
    
    m_window.clear(sf::Color(50,150,250));
    m_window.draw(m_title);
    m_window.draw(m_playOption);
    m_window.draw(m_playOption2);
    m_window.draw(m_exitOption);
    m_window.draw(m_wButton);
    m_window.draw(m_aButton);
    m_window.draw(m_sButton);
    m_window.draw(m_dButton);
    for (const auto& character : m_characters) {
        m_window.draw(character);
    }
    // Update characters
    for (auto& character : m_characters) {
        character.update(deltaTime);
    }
}

bool Menu::isOptionSelected() const {
    return m_optionSelected;
}

void Menu::hide() {
    m_visible = false;
}

bool Menu::isVisible() const {
    return m_visible;
}