#pragma once

#include <SFML/Graphics.hpp>

#include "Block.h"
#include "defines.h"

class Player
{
private:
	sf::RectangleShape m_player;
	sf::Vector2f m_position;

public:
	void move(Block ** blocks);
	void draw(sf::RenderWindow * window);

	sf::Vector2f getPosition();

	Player(sf::Vector2f position);
	~Player();
};

