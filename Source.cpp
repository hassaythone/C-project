#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Game.h"
#include "Menu.h"
#include "Dino.h"
#include "Enemy.h"
#include "Super_Enemy.h"
#include "Bullet.h"
#include "Scoreboard.h"
#include "GameOver.h"
#include "Level.h"
using namespace std;
#include <iostream>
#include "Character.h"
#include <chrono>
#include <ctime>
#include "Clock.h"


int main()
{
  
    // Create game window
    sf::RenderWindow window(sf::VideoMode(1200, 1000), "Dino Game");
    window.setVisible(true);

    // Create game objects
    Game game;
    Clock clock;
    Menu menu(window);
    Dino dino;
    Enemy enemy;
    Super_Enemy superEnemy;
    Bullet bullet;
    Scoreboard scoreboard;
    GameOver gameOver(window);
    Level level;

    // Load game resources
    sf::Music music;
    if (!music.openFromFile("images/audio.ogg")) {
        // Handle error
    }
    music.setLoop(true);
    music.play();
    // Game loop
    
    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::M) {
                    if (music.getStatus() == sf::Music::Playing) {
                        music.pause();
                    }
                    else {
                        music.play();
                    }
                }
            }
        }
        clock.update();
        clock.draw(window);
        window.display();
       
        // Handle menu events
        
        menu.displayMenu();
       
        if (menu.isVisible()) {
            
            menu.processEvents();
            
            
            if (menu.isOptionSelected()) {
                menu.hide();
                window.clear();
                game.start();
                
            }
        }
        
        // Handle game events
        else if (game.isRunning()) {

            game.processEvents();
            dino.move();
            enemy.move();
            superEnemy.move();
            bullet.move();
            if (dino.isCollidingWith(enemy.getSprite()) || dino.isCollidingWith(superEnemy.getSprite())) {
                enemy.hit();
                superEnemy.hit();
                bullet.reset();
                scoreboard.incrementScore();
                game.update(enemy, superEnemy, bullet);
            }
            
            if (scoreboard.getScore() >= level.getScoreThreshold()) {
                level.increment();
                enemy.increaseSpeed();
                superEnemy.increaseSpeed();
                superEnemy.changeSize();
            }
            game.update( enemy,  superEnemy,  bullet);
            window.clear();
            dino.draw(window);
            enemy.draw(window);
            superEnemy.draw(window);
            bullet.draw(window);
            scoreboard.draw(window);
            
        }
        // Handle game over events
        else if (gameOver.isVisible()) {
            gameOver.processEvents();
            gameOver.display();
            if (gameOver.isRestartSelected()) {
                gameOver.hide();
                scoreboard.reset();
                level.reset();
                enemy.reset();
                superEnemy.reset();
                game.start();
            }
        }
        // Handle window events
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }

    return 0;
}