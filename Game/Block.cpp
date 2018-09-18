#include "Block.h"

void Block::draw(sf::RenderWindow * window)
{
	if(isActive)
		window->draw(m_block);
}

sf::Vector2f Block::getPosition()
{
	return m_position;
}

Block::Block()
{
	isActive = false;
}

Block::Block(sf::Vector2f position)
{
	m_position.x = position.x * FIELD_SIZE + FIELD_SIZE / 2;
	m_position.y = position.y * FIELD_SIZE + FIELD_SIZE / 2;

	m_block.setOrigin(FIELD_SIZE / 2, FIELD_SIZE / 2);
	m_block.setFillColor(sf::Color::Yellow);
	m_block.setSize(sf::Vector2f(FIELD_SIZE, FIELD_SIZE));
	m_block.setPosition(m_position);

	isActive = true;
}

Block::~Block()
{

}
