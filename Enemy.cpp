#include "Enemy.h"



Enemy::Enemy(sf::Texture*texture, sf::Vector2u imageCount, float switchTime, float speed, sf::FloatRect bounds, Player *target, float health, float resource) :
	Player(texture, imageCount, switchTime, speed, bounds), _target(target)
{
	_health = health;
	_resource = resource; 
	_body.setSize(sf::Vector2f(70.00f, 100.00f));
	_body.setPosition(sf::Vector2f(1000.0f, 500.0f));
}


Enemy::~Enemy()
{
}


void Enemy::update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	_row = 1;
	_speed = _speed + 5*deltaTime;
	if (_target)
	{
		//left
		if (_target->getPosition().x + 60 < _body.getPosition().x)
		{
			_row = 3;
			movement.x -= _speed*deltaTime;
		}
		
		//right
		if (_target->getPosition().x - 60 > _body.getPosition().x)
		{
			_row = 1;
			movement.x += _speed*deltaTime;
		}

		//up
		if (_target->getPosition().y + 20 < _body.getPosition().y)
		{
			_row = 0;
			movement.y -= _speed*deltaTime;
		}

		//down
		if (_target->getPosition().y - 20 > _body.getPosition().y)
		{
			_row = 2;
			movement.y += _speed*deltaTime;
		}
	}
	_animation.update(_row, deltaTime, _faceRight);
	_body.setTextureRect(_animation.uvRect);
	_body.move(movement);
}

