#include "Spawner.h"



Spawner::Spawner(Enemy enemy, Clickable spawnBox):
	_enemy(enemy), _spawnBox(spawnBox)
{
	_dragging = false;
}


Spawner::~Spawner()
{
}


bool Spawner::spawn(sf::RenderWindow &window, CharacterList list)
{
	if (list.numberCharacters >= list.maxCapacity)
	{
		printf("room is full\n");
		return false;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		_enemy.setPosition((float)mousePos.x, static_cast <float>(mousePos.y));
		_dragging = true;
	}
	return 0;
}