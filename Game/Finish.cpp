#include "Finish.h"

void Finish::draw(sf::RenderWindow * window)
{
	window->draw(m_finish);
}

sf::Vector2f Finish::getPosition()
{
	return m_position;
}

Finish::Finish(sf::Vector2f position, sf::Vector2f size)
{
	m_position.x = position.x * size.x + size.x / 2;
	m_position.y = position.y * size.y + size.y / 2;

	m_finish.setOrigin(size.x / 2, size.y / 2);
	m_finish.setFillColor(sf::Color::Cyan);
	m_finish.setSize(size);
	m_finish.setPosition(m_position);
}

Finish::~Finish()
{
	
}
