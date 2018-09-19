#include "Menu.h"

void Menu::gameActions()
{
	game->events();
	game->update();
	game->render();
}

void Menu::showMenu()
{
	m_window->draw(m_playText);
	m_window->draw(m_exitText);
}

void Menu::createMenuElements()
{
	vectorb.loadFromFile("Fonts/Vectorb.ttf");

	m_playText.setFont(vectorb);
	m_playText.setString("PLAY");
	m_playText.setCharacterSize(70);
	m_playText.setFillColor(sf::Color::Yellow);
	m_playText.setOrigin(m_playText.getLocalBounds().width / 2, m_playText.getLocalBounds().height / 2);
	m_playText.setPosition(200, 200);

	m_exitText.setFont(vectorb);
	m_exitText.setString("EXIT");
	m_exitText.setCharacterSize(70);
	m_exitText.setFillColor(sf::Color::Yellow);
	m_exitText.setOrigin(m_exitText.getLocalBounds().width / 2, m_exitText.getLocalBounds().height / 2);
	m_exitText.setPosition(200, 350);
}

void Menu::menuActions()
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*m_window);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !onGame
		&& mousePosition.x > m_playText.getPosition().x - m_playText.getLocalBounds().width / 2
		&& mousePosition.y > m_playText.getPosition().y - m_playText.getLocalBounds().height / 2
		&& mousePosition.x < m_playText.getPosition().x + m_playText.getLocalBounds().width / 2
		&& mousePosition.y < m_playText.getPosition().y + m_playText.getLocalBounds().height / 2)
	{
		game = new Game(config);
		onGame = true;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !onGame
		&& mousePosition.x > m_exitText.getPosition().x - m_exitText.getLocalBounds().width / 2
		&& mousePosition.y > m_exitText.getPosition().y - m_exitText.getLocalBounds().height / 2
		&& mousePosition.x < m_exitText.getPosition().x + m_exitText.getLocalBounds().width / 2
		&& mousePosition.y < m_exitText.getPosition().y + m_exitText.getLocalBounds().height / 2)
	{
		m_window->close();
	}
}

sf::RenderWindow * Menu::getWindow()
{
	return m_window;
}

void Menu::events()
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

void Menu::update()
{
	menuActions();

	if (onGame) gameActions();

	if (game != nullptr)
		if (!game->getWindow()->isOpen())
		{
			delete game;
			game = nullptr;

			onGame = false;
		}
}

void Menu::render()
{
	m_window->clear();

	showMenu();

	m_window->display();
}

Menu::Menu()
{
	config = new Config();

	m_window = new sf::RenderWindow(sf::VideoMode(400, 600, 32), "Game", sf::Style::Close);
	m_window->setFramerateLimit(MAX_FPS);

	createMenuElements();

	onGame = false;
}

Menu::~Menu()
{
	delete m_window;
	delete config;
}
