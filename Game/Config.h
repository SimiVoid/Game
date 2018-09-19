#pragma once

#include <SFML/System.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Config
{
	std::vector<std::string> m_data;

	sf::Vector2i m_windowSize;
	int m_nuberOfLevels;

	void readFromFile();
	void loadConfig();

public:
	sf::Vector2i getWindowSize();
	int getNubersOfLevels();

	Config();
	~Config();
};

