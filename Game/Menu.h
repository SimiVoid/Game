#pragma once

#include <SFML/Graphics.hpp>

#include "Game.h"
#include "Config.h"

class Menu
{
private:
	sf::RenderWindow * m_window;
	
	sf::Font vectorb;
	sf::Text m_playText;
	sf::Text m_exitText;

	Game * game;
	Config * config;

	bool onGame;

	void gameActions();
	void showMenu();
	void createMenuElements();
	void menuActions();

public:
	sf::RenderWindow * getWindow();

	void events();
	void update();
	void render();

	Menu();
	~Menu();
};

