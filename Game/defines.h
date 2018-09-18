#pragma once

#include <SFML/System.hpp>

#define WIN_SIZE sf::Vector2i(800, 600)
#define FIELD_SIZE 50
#define MAX_FPS 60
#define FIELDS sf::Vector2i(WIN_SIZE.x / FIELD_SIZE, WIN_SIZE.y / FIELD_SIZE)
#define RAND_VALUE 6
#define NUMBER_OF_LEVELS 1