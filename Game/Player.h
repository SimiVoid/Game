#pragma once

#include <SFML/Graphics.hpp>

#include "Block.h"
#include "Finish.h"
#include "Config.h"

class Player
{
private:
	sf::RectangleShape m_player;
	sf::Vector2f m_position;

public:
	void move(Block ** blocks, Config * config, sf::Vector2f size, sf::Vector2i fieldsNumber);
	void draw(sf::RenderWindow * window);
	bool checkFinish(Finish * finish);

	sf::Vector2f getPosition();

	Player(sf::Vector2f position, sf::Vector2f size);
	~Player();
};

