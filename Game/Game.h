#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>

#include "Player.h"
#include "Block.h"
#include "File.h"
#include "defines.h"

class Game
{
private:
	sf::RenderWindow * m_window;

	Player * m_player;
	Block ** m_blocks;
	File * m_gameFile;

	void loadData();

public:
	sf::RenderWindow * getWindow();

	void events();
	void update();
	void render();

	Game();
	~Game();
};
