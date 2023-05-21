#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include <ctime>
#include <thread>
#pragma warning(disable : 4996)
class Clock {
public:
    Clock() {
        if (!font.loadFromFile("times.ttf")) {
            throw std::runtime_error("Failed to load font");
        }
        clockText.setFont(font);
        clockText.setCharacterSize(30);
        clockText.setFillColor(sf::Color::Red);
        clockText.setPosition(500,500);
        now = new std::time_t;
        clockThread = std::thread([&]() {
            while (true) {
                std::time(now);
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
            });
    }

    ~Clock() {
        delete now;
        if (clockThread.joinable()) {
            clockThread.join();
        }
    }

    void update() {
        std::string timeString = std::ctime(now);
        clockText.setString(timeString.substr(0, timeString.length() - 1));
    }

    void draw(sf::RenderWindow& window) {
        window.draw(clockText);
    }

private:
    sf::Font font;
    sf::Text clockText;
    std::time_t* now;
    std::thread clockThread;
};
