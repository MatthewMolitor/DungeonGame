#pragma once
#include "player.h"

class Enemy: public Player
{
public:
	Enemy(sf::Texture*texture, sf::Vector2u imageCount, float switchTime, float speed, sf::FloatRect bounds, Player *target = nullptr, float health = 100.0, float resource = 100.0);
	~Enemy();


	//overloaded movement
	void update(float deltaTime);
	void setTarget(Player* target) { _target = target;};

private:
	Player *_target;
	float _health;
	float _resource;
};

