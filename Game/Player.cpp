#include "Player.h"

void Player::move(Block ** blocks)
{
	bool moveUp = true;
	bool moveDown = true;
	bool moveLeft = true;
	bool moveRight = true;

	for (int i = 0; i < FIELDS.x; ++i)
		for (int j = 0; j < FIELDS.y; ++j)
		{
			if (blocks[i][j].getPosition().y + FIELD_SIZE == m_position.y && blocks[i][j].getPosition().x == m_position.x)
				moveUp = false;
			if (blocks[i][j].getPosition().y - FIELD_SIZE == m_position.y && blocks[i][j].getPosition().x == m_position.x)
				moveDown = false;
			if (blocks[i][j].getPosition().x + FIELD_SIZE == m_position.x && blocks[i][j].getPosition().y == m_position.y)
				moveLeft = false;
			if (blocks[i][j].getPosition().x - FIELD_SIZE == m_position.x && blocks[i][j].getPosition().y == m_position.y)
				moveRight = false;
		}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && m_position.y - FIELD_SIZE > 0 && moveUp)
	{
		m_position.y -= FIELD_SIZE;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && m_position.y + FIELD_SIZE < WIN_SIZE.y && moveDown)
	{
		m_position.y += FIELD_SIZE;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && m_position.x - FIELD_SIZE > 0 && moveLeft)
	{
		m_position.x -= FIELD_SIZE;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && m_position.x + FIELD_SIZE < WIN_SIZE.x && moveRight)
	{
		m_position.x += FIELD_SIZE;
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

Player::Player(sf::Vector2f position)
{
	m_position.x = position.x * FIELD_SIZE + FIELD_SIZE / 2;
	m_position.y = position.y * FIELD_SIZE + FIELD_SIZE / 2;

	m_player.setOrigin(FIELD_SIZE / 2, FIELD_SIZE / 2);
	m_player.setFillColor(sf::Color::Green);
	m_player.setSize(sf::Vector2f(FIELD_SIZE, FIELD_SIZE));
	m_player.setPosition(m_position);
}

Player::~Player()
{

}
