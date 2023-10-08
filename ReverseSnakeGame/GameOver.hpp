#pragma once
#ifndef GAME_OVER_HPP_
#define GAME_OVER_HPP_

#include "GameState.hpp"
#include <SFML/Graphics.hpp>
#include <string>

class GameOver2 : public GameState2
{
public:
	GameOver2() {};
};

class GameOver : public GameState
{
	sf::Font gameOverFont_;
	sf::Text gameOverText_;
	std::string scoreString_;
	sf::Text scoreText_;
	sf::Text restartText_;
public:
	GameOver() {};
	GameOver(sf::Vector2u windowSize, int gameScore);

	void processNextEvent(const sf::Event& gameEvent) override;
	void update(const sf::Time& deltaTime) override;
	void render(sf::RenderWindow& gameWindow) const override;

};

#endif //GAME_OVER_HPP_