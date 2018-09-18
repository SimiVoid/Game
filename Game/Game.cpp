#include "Game.h"

void Game::loadData()
{
	srand(time(NULL));

	int value = rand() % NUMBER_OF_LEVELS + 1;

	std::string filePath = "Levels/level_" + std::to_string(value) + ".dat";

	m_gameFile = new File(filePath);

	m_blocks = new Block *[FIELDS.x];

	for (int i = 0; i < FIELDS.x; ++i)
		m_blocks[i] = new Block[FIELDS.y];

	for (int i = 0; i < m_gameFile->getSize().x; ++i)
		for (int j = 0; j < m_gameFile->getSize().y; ++j)
			if (m_gameFile->getBoard()[i][j] == 1)
				m_blocks[i][j] = Block(sf::Vector2f(i, j));
			else if (m_gameFile->getBoard()[i][j] == 2)
				m_player = new Player(sf::Vector2f(i, j));
			else if (m_gameFile->getBoard()[i][j] == 3)
				m_finish = new Finish(sf::Vector2f(i, j));
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
	m_player->move(m_blocks);

	if (m_player->checkFinish(m_finish))
		loadData();
}

void Game::render()
{
	m_window->clear();

	for (int i = 0; i < FIELDS.x; ++i)
		for (int j = 0; j < FIELDS.y; ++j)
			m_blocks[i][j].draw(m_window);

	m_finish->draw(m_window);
	m_player->draw(m_window);

	m_window->display();
}

Game::Game()
{
	m_window = new sf::RenderWindow(sf::VideoMode(WIN_SIZE.x, WIN_SIZE.y, 32), "Game", sf::Style::Close);
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
