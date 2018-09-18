#pragma once

#include <SFML/Graphics.hpp>

#include "defines.h"

class Finish
{
private:
	sf::Vector2f m_position;
	sf::RectangleShape m_finish;

public:
	void draw(sf::RenderWindow * window);

	sf::Vector2f getPosition();

	Finish(sf::Vector2f position);
	~Finish();
};