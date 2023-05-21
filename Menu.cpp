#include "Menu.h"
#include <SFML/Audio.hpp>
#include <iostream>


using namespace std;


Menu::Menu(sf::RenderWindow& window, sf::Music& music, sf::Texture& Background) : m_window(window), m_music(music), m_optionSelected(false), m_visible(true), m_startingScreenVisible(true), difficultySelected(false), scenerySelected(false), characterSelected(false) {
   
    // Load font
    if (!m_font.loadFromFile("times.ttf")) {
        // Handle error
    }
    
    m_gameName.setFont(m_font);
    m_gameName.setString("Dino Game");
    m_gameName.setCharacterSize(100);
    m_gameName.setFillColor(sf::Color::White);
    m_gameName.setPosition(250, 100);
    m_pressAnyButton.setFont(m_font);
    m_pressAnyButton.setString("Press any button to continue");
    m_pressAnyButton.setCharacterSize(50);
    m_pressAnyButton.setFillColor(sf::Color::White);
    m_pressAnyButton.setPosition(500, 500);
    createColorColumns();
    // Load starting screen texture
    
   
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
    m_wButton.setString("W for going up");
    m_wButton.setCharacterSize(30);
    m_wButton.setFillColor(sf::Color::White);
    m_wButton.setPosition(150, 500);

    m_aButton.setFont(m_font);
    m_aButton.setString("A for going left");
    m_aButton.setCharacterSize(30);
    m_aButton.setFillColor(sf::Color::White);
    m_aButton.setPosition(150, 600);

    m_sButton.setFont(m_font);
    m_sButton.setString("S for going down");
    m_sButton.setCharacterSize(30);
    m_sButton.setFillColor(sf::Color::White);
    m_sButton.setPosition(150, 700);

    m_dButton.setFont(m_font);
    m_dButton.setString("D for going right");
    m_dButton.setCharacterSize(30);
    m_dButton.setFillColor(sf::Color::White);
    m_dButton.setPosition(150, 800);
    m_playOption.setFillColor(sf::Color::Red);

    if (!k_dButtonTexture.loadFromFile("images/key.png")) {
        // Handle error
    }
    k_dButtonSprite.setTexture(k_dButtonTexture);
    k_dButtonSprite.setPosition(100, 250);


    // Load moving images
    sf::Texture movingImageTexture1;
    if (!movingImageTexture1.loadFromFile("PNG/Dead (7).png")) {
        // Handle error
    }
    m_movingImagesTextures.push_back(movingImageTexture1);

    sf::Texture movingImageTexture2;
    if (!movingImageTexture2.loadFromFile("PNG/Idle (7).png")) {
        // Handle error
    }
    m_movingImagesTextures.push_back(movingImageTexture2);

    sf::Texture movingImageTexture3;
    if (!movingImageTexture3.loadFromFile("PNG/Jump (7).png")) {
        // Handle error
    }
    m_movingImagesTextures.push_back(movingImageTexture3);

    // Create moving image sprites
    float initialY = 0; // Adjust the initial Y position as needed
    for (const auto& texture : m_movingImagesTextures) {
        sf::Sprite sprite(texture);
        sprite.setPosition(0, initialY); // Set the initial position
        m_movingImagesSprites.push_back(sprite);
        initialY += texture.getSize().y - 100; // Add some space between the images
    }
   
   
}



int Menu::getSelectedDifficulty() const {
    return m_diffSelected;
}

// menu.cpp
void Menu::selectDifficulty() {
    difficultySelected = true;
    // Load the background image
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("images/background.png")) {
        // Handle error
    }
    sf::Sprite backgroundImage;
    backgroundImage.setTexture(backgroundTexture);
    backgroundImage.setScale(1.0f, 1.0f); // Adjust the scale as needed

    // Game name text
    sf::Text gameNameText;
    gameNameText.setFont(m_font);
    gameNameText.setCharacterSize(48);
    gameNameText.setFillColor(sf::Color::White);
    gameNameText.setString("Dino Game");
    sf::FloatRect gameNameBounds = gameNameText.getLocalBounds();
    gameNameText.setOrigin(gameNameBounds.left + gameNameBounds.width / 2.0f, gameNameBounds.top + gameNameBounds.height / 2.0f);
    gameNameText.setPosition(m_window.getSize().x / 2.0f, m_window.getSize().y / 4.0f);

    // Difficulty text
    sf::Text difficultyText[3];
    sf::Color normalColor(255, 255, 255);
    sf::Color hoverColor(255, 0, 0);
    int selectedIndex = 0;

    for (int i = 0; i < 3; ++i) {
        difficultyText[i].setFont(m_font);
        difficultyText[i].setCharacterSize(24);
        difficultyText[i].setFillColor(normalColor);
        difficultyText[i].setString(i == 0 ? "1. Easy" : (i == 1 ? "2. Medium" : "3. Hard"));
        sf::FloatRect textBounds = difficultyText[i].getLocalBounds();
        difficultyText[i].setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
        difficultyText[i].setPosition(m_window.getSize().x / 2.0f, m_window.getSize().y / 2.0f + i * 30);
    }

    // Main loop
    while (m_window.isOpen()) {
        sf::Event event;
        while (m_window.pollEvent(event)) {
            // Define mousePos
            sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

            // Close window: exit
            if (event.type == sf::Event::Closed) {
                m_window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                m_window.close();
            }

            // Keyboard navigation
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    selectedIndex = (selectedIndex - 1 + 3) % 3;
                }
                else if (event.key.code == sf::Keyboard::Down) {
                    selectedIndex = (selectedIndex + 1) % 3;
                }
                else if (event.key.code == sf::Keyboard::Enter || event.key.code == sf::Keyboard::Space) {
                    m_diffSelected = selectedIndex + 1;
                    return;
                }
            }

            // Update text color based on hover and selection
            for (int i = 0; i < 3; ++i) {
                sf::FloatRect textBounds = difficultyText[i].getGlobalBounds();
                if (textBounds.contains(mousePos.x, mousePos.y)) {
                    difficultyText[i].setFillColor(hoverColor);
                    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                        m_diffSelected = i + 1;
                        return;
                    }
                }
                else if (i == selectedIndex) {
                    difficultyText[i].setFillColor(hoverColor);
                }
                else {
                    difficultyText[i].setFillColor(normalColor);
                }
            }
        }

        // Clear the window
        m_window.clear();

        // Draw the background image
        m_window.draw(backgroundImage);

        // Draw the game name text
        m_window.draw(gameNameText);

        // Draw the difficulty text
        for (int i = 0; i < 3; ++i) {
            m_window.draw(difficultyText[i]);
        }

        // Update the window
        m_window.display();
    }
}


void Menu::processEvents1() {
    sf::Event event;

    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_window.close();
        }
        else if (event.type == sf::Event::KeyPressed) {
            m_startingScreenVisible = false;
            m_visible = true;

        }
    }
}


void Menu::processEvents() {
    sf::Event event;
    
    while (m_window.pollEvent(event)) {
        
        if (event.type == sf::Event::Closed) {
            m_window.close();
        }
        else if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);

                if (m_playOption.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                    m_optionSelected = true;
                    
                }
                else if (m_playOption2.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                    // Handle the second play option
                }
                else if (m_exitOption.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                    m_window.close();
                }
            }
        }
        else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Down) {
                // Move the selection down
                if (m_selectedOption < 2) {
                    m_selectedOption++;
                }
                else {
                    m_selectedOption = 0;
                }
            }
            else if (event.key.code == sf::Keyboard::Up) {
                // Move the selection up
                if (m_selectedOption > 0) {
                    m_selectedOption--;
                }
                else {
                    m_selectedOption = 2;
                }
            }
            else if (event.key.code == sf::Keyboard::Enter) {
                // Handle the selected option
                if (m_selectedOption == 0) {
                    m_optionSelected = true;
                }
                else if (m_selectedOption == 1) {
                    // Handle the second play option
                }
                else if (m_selectedOption == 2) {
                    m_window.close();
                }
            }
            else if (event.key.code == sf::Keyboard::M) {
                // Pause the music
                if (m_music.getStatus() == sf::Music::Playing) {
                    m_music.pause();
                }
            }
            else if (event.key.code == sf::Keyboard::N) {
                // Resume the music
                if (m_music.getStatus() == sf::Music::Paused) {
                    m_music.play();
                }
            }
        }
    }

    // Update the menu options based on the selected option
    if (m_selectedOption == 0) {
        m_playOption.setFillColor(sf::Color::Red);
        m_playOption2.setFillColor(sf::Color::White);
        m_exitOption.setFillColor(sf::Color::White);
    }
    else if (m_selectedOption == 1) {
        m_playOption.setFillColor(sf::Color::White);
        m_playOption2.setFillColor(sf::Color::Red);
        m_exitOption.setFillColor(sf::Color::White);
    }
    else if (m_selectedOption == 2) {
        m_playOption.setFillColor(sf::Color::White);
        m_playOption2.setFillColor(sf::Color::White);
        m_exitOption.setFillColor(sf::Color::Red);
    }
   
    
}
void Menu::displayStartingScreen() {
    

    for (auto& sprite : m_movingImagesSprites) {
        float newX = sprite.getPosition().x + 0.5; // Adjust the speed by changing the value added to x
        if (newX > m_window.getSize().x) {
            newX = -sprite.getGlobalBounds().width;
        }
        sprite.setPosition(newX, sprite.getPosition().y);
    }
    for (const auto& column : m_colorColumns) {
        m_window.draw(column);
    }
    // Draw moving image sprites
    for (const auto& sprite : m_movingImagesSprites) {
        m_window.draw(sprite);
    }
    
    
    m_window.draw(m_gameName);
    m_window.draw(m_pressAnyButton);
    
}
void Menu::createColorColumns() {
    float columnWidth = m_window.getSize().x / 4.0f;
    float columnHeight = m_window.getSize().y;

    sf::Color colors[] = {sf::Color::Red, sf::Color::Green, sf::Color::Blue, sf::Color::Yellow};

    for (int i = 0; i < 4; ++i) {
        sf::RectangleShape column(sf::Vector2f(columnWidth, columnHeight));
        column.setFillColor(colors[i]);
        column.setPosition(i * columnWidth, 0);
        m_colorColumns.push_back(column);
    }

}

void Menu::displayMenu() {
    
    

    if (m_startingScreenVisible) {
        for (const auto& column : m_colorColumns) {
            m_window.draw(column);
        }
        m_window.draw(m_gameName);
        m_window.draw(m_pressAnyButton);


    }
    else {
        clock.draw(m_window);
        clock.update();
        m_window.draw(m_title);
        m_window.draw(m_playOption);
        m_window.draw(m_playOption2);
        m_window.draw(m_exitOption);
        m_window.draw(m_wButton);
        m_window.draw(m_aButton);
        m_window.draw(m_sButton);
        m_window.draw(m_dButton);
        m_window.draw(k_dButtonSprite);
        
        
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
bool Menu::isStartingScreenVisible()  {
    return m_startingScreenVisible;
}


void Menu::ScenerySelection(sf::RenderWindow& m_window) {
    // Load the background image
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("images/background.png")) {
        // Handle error
    }
    sf::Sprite backgroundImage;
    backgroundImage.setTexture(backgroundTexture);
    backgroundImage.setScale(1.0f, 1.0f); // Adjust the scale as needed
   
    

    gamestate = 3;
    scenerySelected = true;
    // Load the textures for the different backgrounds
    sf::Texture bg1, bg2, bg3;
    bg1.loadFromFile("images/2.png");
    bg2.loadFromFile("images/22.png");
    bg3.loadFromFile("images/222.png");

    // Create sprites for the backgrounds
    sf::Sprite bgSprite1(bg1), bgSprite2(bg2), bgSprite3(bg3);

    // Desired width and height for the background sprites
    float desiredWidth = 200.0f;
    float desiredHeight = 150.0f;

    // Calculate the scale factors for each background sprite
    float scaleX1 = desiredWidth / bgSprite1.getLocalBounds().width;
    float scaleY1 = desiredHeight / bgSprite1.getLocalBounds().height;
    float scaleX2 = desiredWidth / bgSprite2.getLocalBounds().width;
    float scaleY2 = desiredHeight / bgSprite2.getLocalBounds().height;
    float scaleX3 = desiredWidth / bgSprite3.getLocalBounds().width;
    float scaleY3 = desiredHeight / bgSprite3.getLocalBounds().height;

    // Set the scale for the background sprites
    bgSprite1.setScale(scaleX1, scaleY1);
    bgSprite2.setScale(scaleX2, scaleY2);
    bgSprite3.setScale(scaleX3, scaleY3);

    // Position the background sprites
    bgSprite1.setPosition(100, 100);
    bgSprite2.setPosition(300, 100);
    bgSprite3.setPosition(500, 100);
    sf::Font font;
    if (!font.loadFromFile("times.ttf")) {
        // Handle font loading error
        std::cerr << "Error loading font" << std::endl;
    }

    // Create a text object for the "Choose scenery background" message
    sf::Text chooseSceneryText;
    chooseSceneryText.setFont(font);
    chooseSceneryText.setString("Choose scenery background");
    chooseSceneryText.setCharacterSize(100);
    chooseSceneryText.setFillColor(sf::Color::White);
    chooseSceneryText.setStyle(sf::Text::Bold);
    chooseSceneryText.setPosition(50, 50);

    // Draw the background sprites and text
    m_window.draw(backgroundImage);
    m_window.draw(bgSprite1);
    m_window.draw(bgSprite2);
    m_window.draw(bgSprite3);
    m_window.draw(chooseSceneryText);
    m_window.display();
    
    
    // Main loop for ScenerySelection
    while (m_window.isOpen()) {
        sf::Event event;
        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                m_window.close();
            }

            // Check for mouse hover
            if (bgSprite1.getGlobalBounds().contains(m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window)))) {
                m_background = bgSprite1;
                backgroundImage.setTexture(bg1);
            }
            else if (bgSprite2.getGlobalBounds().contains(m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window)))) {
                m_background = bgSprite2;
                backgroundImage.setTexture(bg2);
            }
            else if (bgSprite3.getGlobalBounds().contains(m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window)))) {
                m_background = bgSprite3;
                backgroundImage.setTexture(bg3);
            }
            else {
                m_background = backgroundImage;
                backgroundImage.setTexture(backgroundTexture);
            }

            if ((sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) ) {
                
               
                setBackground(m_background);
                return;
                
            }

            // Check for backspace to go to the previous enum
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
                // Go to the previous enum
                gamestate = (gamestate)-1;
                return;
            }
        }

        // Draw the background and background sprites
        m_window.clear();
        m_window.draw(backgroundImage);
        m_window.draw(bgSprite1);
        m_window.draw(bgSprite2);
        m_window.draw(bgSprite3);
        m_window.display();
    }
}


void Menu::CharacterSelection(sf::RenderWindow& m_window) {
    // Load the background image
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("images/background.png")) {
        // Handle error
    }
    sf::Sprite backgroundImage;
    backgroundImage.setTexture(backgroundTexture);
    backgroundImage.setScale(1.0f, 1.0f); // Adjust the scale as needed
    
    
    gamestate = 4;
    characterSelected = true;
    // Load the textures for the different characters
    sf::Texture ch1, ch2, ch3;
    ch1.loadFromFile("images/dino.PNG");
    ch2.loadFromFile("images/dino.PNG");
    ch3.loadFromFile("images/dino.PNG");

    // Create sprites for the characters
    sf::Sprite chSprite1(ch1), chSprite2(ch2), chSprite3(ch3);

    // Position the character sprites
    chSprite1.setPosition(100, 100);
    chSprite2.setPosition(300, 100);
    chSprite3.setPosition(500, 100);
  

    while (m_window.isOpen()) {
        sf::Event event;
        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                m_window.close();
            }

            // Check for mouse hover
            if (chSprite1.getGlobalBounds().contains(m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window)))) {
                charr = chSprite1;
            }
            else if (chSprite2.getGlobalBounds().contains(m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window)))) {
                charr = chSprite2;
            }
            else if (chSprite3.getGlobalBounds().contains(m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window)))) {
                charr = chSprite3;
            }

            // Check for mouse click or keyboard selection
            if ((sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) ) {
                // Save the selected character and return
                dino = charr;
                return;
            }

            // Check for backspace to go to the previous enum
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
                // Go to the previous enum
                gamestate = (gamestate) - 1;
                return;
            }
        }


        // Draw the character sprites
        m_window.clear();
        m_window.draw(backgroundImage);
        m_window.draw(chSprite1);
        m_window.draw(chSprite2);
        m_window.draw(chSprite3);
        m_window.display();
    }
}

sf::Sprite Menu:: getdino()
{
    return dino;
}

void Menu::HowToPlay(sf::RenderWindow& m_window) {
    // Load the background image
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("images/background.png")) {
        // Handle error
    }
    sf::Sprite backgroundImage;
    backgroundImage.setTexture(backgroundTexture);
    backgroundImage.setScale(1.0f, 1.0f); // Adjust the scale as needed
    
    gamestate = 5;
    howtoplay = true; 
    // Load the textures for the keyboard buttons
    sf::Texture wasd, space, m;
    wasd.loadFromFile("images/back.png");
    space.loadFromFile("images/back.png");
    m.loadFromFile("images/back.png");

    // Create sprites for the keyboard buttons
    sf::Sprite wasdSprite(wasd), spaceSprite(space), mSprite(m);

    // Position the keyboard button sprites
    wasdSprite.setPosition(100, 100);
    spaceSprite.setPosition(300, 100);
    mSprite.setPosition(500, 100);

    // Load a font for the text
    sf::Font font;
    font.loadFromFile("times.ttf");

    // Create text objects for the button descriptions
    sf::Text wasdText("Move character", font, 20);
    sf::Text spaceText("Jump", font, 20);
    sf::Text mText("mute audio", font, 20);

    // Position the text objects
    wasdText.setPosition(100, 200);
    spaceText.setPosition(300, 200);
    mText.setPosition(500, 200);

    // Main loop for HowToPlay
    while (m_window.isOpen()) {
        sf::Event event;
        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                m_window.close();
            }

            // Check for backspace to go to the previous enum
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
                // Go to the previous enum
                gamestate = (gamestate) - 1;
                return;
            }
            else if(event.type == sf::Event::KeyPressed) {
                // Return when any key is pressed
                return;
            }
        }

        // Draw the keyboard button sprites and text descriptions
        m_window.clear();
        m_window.draw(backgroundImage);
        m_window.draw(wasdSprite);
        m_window.draw(spaceSprite);
        m_window.draw(mSprite);
        m_window.draw(wasdText);
        m_window.draw(spaceText);
        m_window.draw(mText);
        m_window.display();
    }
}



