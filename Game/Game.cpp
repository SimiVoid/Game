#include "Game.h"

void Game::loadData()
{
	srand(time(NULL));

	int value = rand() % m_config->getNubersOfLevels() + 1;

	std::string filePath = "Levels/level_" + std::to_string(value) + ".dat";

	m_gameFile = new File(filePath);
	m_fieldsNumber = m_gameFile->getSize();

	m_fieldSize = sf::Vector2f(m_config->getWindowSize().x / m_fieldsNumber.x, m_config->getWindowSize().y / m_fieldsNumber.y);

	m_blocks = new Block *[m_fieldsNumber.x];

	for (int i = 0; i < m_fieldsNumber.x; ++i)
		m_blocks[i] = new Block[m_fieldsNumber.y];

	for (int i = 0; i < m_fieldsNumber.x; ++i)
	{
		for (int j = 0; j < m_fieldsNumber.y; ++j)
			if (m_gameFile->getBoard()[i][j] == 1)
				m_blocks[i][j] = Block(sf::Vector2f(i, j), m_fieldSize);
			else if (m_gameFile->getBoard()[i][j] == 2)
				m_player = new Player(sf::Vector2f(i, j), m_fieldSize);
			else if (m_gameFile->getBoard()[i][j] == 3)
				m_finish = new Finish(sf::Vector2f(i, j), m_fieldSize);
	}
}

sf::RenderWindow * Game::getWindow()
{
	return m_window;
}

void Game::events()
{
	sf::Event event;

	while (m_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window->close();
		}
	}
}

void Game::update()
{
	m_player->move(m_blocks, m_config, m_fieldSize, m_fieldsNumber);

	if (m_player->checkFinish(m_finish))
		loadData();
}

void Game::render()
{
	m_window->clear();

	for (int i = 0; i < m_fieldsNumber.x; ++i)
		for (int j = 0; j < m_fieldsNumber.y; ++j)
			m_blocks[i][j].draw(m_window);

	m_finish->draw(m_window);
	m_player->draw(m_window);

	m_window->display();
}

Game::Game(Config * config)
{
	m_config = config;

	m_window = new sf::RenderWindow(sf::VideoMode(m_config->getWindowSize().x, m_config->getWindowSize().y, 32), "Game", sf::Style::Close);
	m_window->setFramerateLimit(MAX_FPS);

	loadData();
}

Game::~Game()
{
	delete m_window;
	delete m_player;
	delete[] m_blocks;
	delete m_gameFile;
	delete m_finish;
}
