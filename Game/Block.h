#pragma once

#include <SFML/Graphics.hpp>

class Block
{
private:
	sf::Vector2f m_position;
	sf::RectangleShape m_block;

	bool isActive;

public:
	void draw(sf::RenderWindow * window);

	sf::Vector2f getPosition();

	Block();
	Block(sf::Vector2f position, sf::Vector2f size);
	~Block();
};

