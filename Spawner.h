#pragma once
#include "Enemy.h"
#include "Clickable.h"
#include "CharacterList.h"


class Spawner
{
public:
	Spawner(Enemy enemy, Clickable spawnBox);
	~Spawner();
	
	bool spawn(sf::RenderWindow &window, CharacterList list);

private:
	bool _dragging;
	Enemy _enemy;
	Clickable _spawnBox;

};

