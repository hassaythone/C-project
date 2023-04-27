#include "Game.h"
#include "Dino.h"
#include "Enemy.h"
#include "Super_Enemy.h"
#include "Bullet.h"
#include "Clock.h"

Game::Game() : m_running(false), m_window(sf::VideoMode(800, 600), "Dino Game") {
    // Load sound files
    m_jumpSoundBuffer.loadFromFile("images/audio.ogg");
    m_doubleJumpSoundBuffer.loadFromFile("images/audio.ogg");
    m_duckSoundBuffer.loadFromFile("images/audio.ogg");
    m_enemyHitSoundBuffer.loadFromFile("images/audio.ogg");

    // Set up sounds
    m_jumpSound.setBuffer(m_jumpSoundBuffer);
    m_doubleJumpSound.setBuffer(m_doubleJumpSoundBuffer);
    m_duckSound.setBuffer(m_duckSoundBuffer);
    m_enemyHitSound.setBuffer(m_enemyHitSoundBuffer);
}

void Game::start() {
    m_running = true;
}

void Game::stop() {
    m_running = false;
}

bool Game::isRunning() const {
    return m_running;
}

void Game::processEvents() {
    sf::Event event;
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_window.close();
        }
        else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Space) {
                // Jump
                // If 'W' is pressed twice, perform double jump
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                    m_doubleJumpSound.play();
                }
                else {
                    m_jumpSound.play();
                }
            }
            else if (event.key.code == sf::Keyboard::Space) {
                // Duck
                m_duckSound.play();
            }
        }
        
    }
}


void Game::update(  Enemy& enemy, Super_Enemy& superEnemy, Bullet& bullet) {
    
        
        enemy.move();
        superEnemy.move();
        bullet.move();
        
}