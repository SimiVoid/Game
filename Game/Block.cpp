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

Block::Block(sf::Vector2f position, sf::Vector2f size)
{
	m_position.x = position.x * size.x + size.x / 2;
	m_position.y = position.y * size.y + size.y / 2;

	m_block.setOrigin(size.x / 2, size.y / 2);
	m_block.setFillColor(sf::Color::Yellow);
	m_block.setSize(size);
	m_block.setPosition(m_position);

	isActive = true;
}

Block::~Block()
{

}
