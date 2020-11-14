#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include "Clickable.h"



class GameOver
{
public:
	GameOver();
	~GameOver();
	int Display(sf::RenderWindow &window, sf::View &view);

private:
};
