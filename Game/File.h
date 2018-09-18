#pragma once

#include <SFML/System.hpp>

#include <iostream>
#include <fstream>
#include <string>

class File
{
private:
	sf::Vector2i m_size;
	std::ifstream * m_file;
	
	int ** m_board;

	void createBoard();
	void readBoard();
	void readSize();
	void readFile(std::string filePath);

public:
	sf::Vector2i getSize();
	int ** getBoard();

	File(std::string filePath);
	~File();
};

/*

First line size of game board (width, height)

In next lines board data:
0 -> Empty
1 -> Block
2 -> Player
3 -> Finish

*/