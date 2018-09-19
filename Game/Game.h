#pragma once

#include <SFML/Graphics.hpp>

#include <string>
#include <stdlib.h>
#include <time.h>

#include "Player.h"
#include "Block.h"
#include "File.h"
#include "Finish.h"
#include "Config.h"

#define MAX_FPS 60

class Game
{
private:
	sf::RenderWindow * m_window;

	Player * m_player;
	Block ** m_blocks;
	File * m_gameFile;
	Finish * m_finish;
	Config * m_config;

	sf::Vector2i m_fieldsNumber;
	sf::Vector2f m_fieldSize;

	void loadData();

public:
	sf::RenderWindow * getWindow();

	void events();
	void update();
	void render();

	Game(Config * config);
	~Game();
};
