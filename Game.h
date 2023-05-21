#ifndef GAME_H
#define GAME_H
#include "Dino.h"
#include "Enemy.h"
#include "Super_Enemy.h"
#include "Bullet.h"

#include "Clock.h"
#include <SFML/Graphics.hpp>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Game {
public:
    Game( sf::RenderWindow& m_window);
    void start(sf::Sprite background);
    void stop();
    bool isRunning() const;
    void processEvents();
    void update(Enemy& enemy, Super_Enemy& superEnemy, Bullet& bullet);
private:
    sf::Sprite backgroundImage;
    bool m_running;
    sf::RenderWindow m_doubleJumpCount;
    sf::RenderWindow m_window;
    sf::SoundBuffer m_jumpSoundBuffer;
    sf::SoundBuffer m_doubleJumpSoundBuffer;
    sf::SoundBuffer m_duckSoundBuffer;
    sf::SoundBuffer m_enemyHitSoundBuffer;
    sf::Sound m_jumpSound;
    sf::Sound m_doubleJumpSound;
    sf::Sound m_duckSound;
    sf::Sound m_enemyHitSound;
};


#endif // GAME_H