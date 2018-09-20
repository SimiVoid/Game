#include "Player.h"

void Player::move(Block ** blocks, Config * config, sf::Vector2f size, sf::Vector2i fieldsNumber)
{
	bool moveUp = true;
	bool moveDown = true;
	bool moveLeft = true;
	bool moveRight = true;

	for (int i = 0; i < fieldsNumber.x; ++i)
		for (int j = 0; j < fieldsNumber.y; ++j)
		{
			if (blocks[i][j].getPosition().y + size.y == m_position.y && blocks[i][j].getPosition().x == m_position.x)
				moveUp = false;
			if (blocks[i][j].getPosition().y - size.y == m_position.y && blocks[i][j].getPosition().x == m_position.x)
				moveDown = false;
			if (blocks[i][j].getPosition().x + size.x == m_position.x && blocks[i][j].getPosition().y == m_position.y)
				moveLeft = false;
			if (blocks[i][j].getPosition().x - size.x == m_position.x && blocks[i][j].getPosition().y == m_position.y)
				moveRight = false;
		}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && m_position.y - size.y > 0 && moveUp)
	{
		m_position.y -= size.y;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && m_position.y + size.y < config->getWindowSize().y && moveDown)
	{
		m_position.y += size.y;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && m_position.x - size.x > 0 && moveLeft)
	{
		m_position.x -= size.x;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && m_position.x + size.x < config->getWindowSize().x && moveRight)
	{
		m_position.x += size.x;
	}

	m_player.setPosition(m_position);
}

void Player::draw(sf::RenderWindow * window)
{
	window->draw(m_player);
}

bool Player::checkFinish(Finish * finish)
{
	if (m_player.getPosition().x == finish->getPosition().x
		&& m_player.getPosition().y == finish->getPosition().y)
		return true;

	return false;
}

sf::Vector2f Player::getPosition()
{
	return m_position;
}

Player::Player(sf::Vector2f position, sf::Vector2f size)
{
	m_position.x = position.x * size.x + size.x / 2;
	m_position.y = position.y * size.y + size.y / 2;

	m_player.setOrigin(size.x / 2, size .y/ 2);
	m_player.setFillColor(sf::Color::Green);
	m_player.setSize(size);
	m_player.setPosition(m_position);
}

Player::~Player()
{

}
