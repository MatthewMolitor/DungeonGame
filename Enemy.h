#pragma once
#include "player.h"

class Enemy: public Player
{
public:
	Enemy(sf::Texture*texture, sf::Vector2u imageCount, float switchTime, float speed,Player *target, float health = 100.0, float resource = 100.0);
	~Enemy();


	//overloaded movement
	void update(float deltaTime);

private:
	Player *_target;
	float _health;
	float _resource;
};

