#include "File.h"

void File::createBoard()
{
	m_board = new int *[m_size.x];

	for (int i = 0; i < m_size.x; ++i)
		m_board[i] = new int[m_size.y];
}

void File::readBoard()
{
	for (int i = 0; i < m_size.y; ++i)
		for (int j = 0; j < m_size.x; ++j)
			*m_file >> m_board[j][i];
}

void File::readSize()
{
	*m_file >> m_size.x >> m_size.y;
}

void File::readFile(std::string filePath)
{
	m_file = new std::ifstream(filePath);

	if (m_file->good())
	{
		readSize();
		createBoard();
		readBoard();
	}

	m_file->close();
}

sf::Vector2i File::getSize()
{
	return m_size;
}

int ** File::getBoard()
{
	return m_board;
}

File::File(std::string filePath)
{
	readFile(filePath);
}

File::~File()
{
	delete m_file;
	delete[] m_board;
}
