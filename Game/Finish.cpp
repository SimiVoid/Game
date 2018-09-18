#include "Finish.h"

void Finish::draw(sf::RenderWindow * window)
{
	window->draw(m_finish);
}

sf::Vector2f Finish::getPosition()
{
	return m_position;
}

Finish::Finish(sf::Vector2f position)
{
	m_position.x = position.x * FIELD_SIZE + FIELD_SIZE / 2;
	m_position.y = position.y * FIELD_SIZE + FIELD_SIZE / 2;

	m_finish.setOrigin(FIELD_SIZE / 2, FIELD_SIZE / 2);
	m_finish.setFillColor(sf::Color::Cyan);
	m_finish.setSize(sf::Vector2f(FIELD_SIZE, FIELD_SIZE));
	m_finish.setPosition(m_position);
}

Finish::~Finish()
{
	
}
