#include "Config.h"

void Config::readFromFile()
{
	std::ifstream * m_file = new std::ifstream("Game.cfg", std::ios::in);

	std::string buffer;

	if (m_file->good())
	{
		while (getline(*m_file, buffer))
		{
			m_data.push_back(buffer);
		}
	}

	m_file->close();

	delete m_file;
}

void Config::loadConfig()
{
	char numbers[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

	readFromFile();

	for (auto line : m_data)
	{
		std::string str = "";
		std::string buffer = "";

		int value = 0;

		for (auto c : line)
		{
			if (c == '=' || c == ' ')
				break;
			
			str += c;
		}

		for (auto c : line)
		{
			for(auto n : numbers)
				if (n == c)
				{
					buffer += c;
					break;
				}
		}

		value = atoi(buffer.c_str());
		
		if (str == "level_numbers")
			m_nuberOfLevels = value;
		else if (str == "window_width")
			m_windowSize.x = value;
		else if (str == "window_height")
			m_windowSize.y = value;
	}
}

sf::Vector2i Config::getWindowSize()
{
	return m_windowSize;
}

int Config::getNubersOfLevels()
{
	return m_nuberOfLevels;
}

Config::Config()
{
	loadConfig();
}

Config::~Config()
{
	
}
