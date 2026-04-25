#include <SFML/Graphics.hpp>
#include <iostream>

enum class State { Menu, Jogando };

int main() {
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    sf::VideoMode windowMode({1280, 720});
    
    sf::RenderWindow window(windowMode, "Cursed Relic", sf::Style::Default);
    window.setFramerateLimit(60);

    bool isFullscreen = false;
    State currentState = State::Menu;

    // Botão
    sf::RectangleShape startButton({300.f, 80.f});
    startButton.setFillColor(sf::Color(100, 100, 100));
    startButton.setOrigin({150.f, 40.f});
    startButton.setPosition({640.f, 450.f});

    // Jogador
    sf::CircleShape player(30.f);
    player.setFillColor(sf::Color::Cyan);
    player.setOrigin({30.f, 30.f});
    player.setPosition({640.f, 360.f});

    while (window.isOpen()) {
        while (const auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();

            if (event->is<sf::Event::KeyPressed>()) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F11)) {
                    isFullscreen = !isFullscreen;
                    
                    if (isFullscreen) {
                        window.create(desktopMode, "Cursed Relic", sf::State::Fullscreen);
                    } else {
                        window.create(windowMode, "Cursed Relic", sf::Style::Default);
                    }

                    // --- AJUSTE DA VIEW (RESOLVE O BUG VISUAL) ---
                    sf::View view(sf::FloatRect({0.f, 0.f}, {1280.f, 720.f}));
                    window.setView(view);
                    // ---------------------------------------------

                    window.setFramerateLimit(60);
                }
            }

            if (currentState == State::Menu && event->is<sf::Event::MouseButtonPressed>()) {
                sf::Vector2f worldPos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (startButton.getGlobalBounds().contains(worldPos)) {
                    currentState = State::Jogando;
                }
            }
        }

        window.clear(sf::Color(20, 20, 25));

        sf::Vector2f mouseWorldPos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

        if (currentState == State::Menu) {
            if (startButton.getGlobalBounds().contains(mouseWorldPos)) {
                startButton.setFillColor(sf::Color::Green);
            } else {
                startButton.setFillColor(sf::Color(100, 100, 100));
            }
            window.draw(startButton);
        } else if (currentState == State::Jogando) {
            window.draw(player);
        }

        window.display();
    }

    return 0;
}