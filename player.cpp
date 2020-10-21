#include "Player.h"



Player::Player(sf::Texture*texture, sf::Vector2u imageCount, float switchTime, float speed) 
	: _animation(texture, imageCount, switchTime)
{
	this->_speed = speed;
	_row = 0;
	_faceRight = true;

	_body.setSize(sf::Vector2f(100.00f, 150.00f));
	_body.setPosition(206.0f,206.0f);
	_body.setTexture(texture);
	_body.setOrigin(_body.getSize() / 2.0f);
}


Player::~Player()
{
}


void Player::update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		_row = 3;
		movement.x -= _speed*deltaTime;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		_row = 1;
		movement.x += _speed*deltaTime;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		_row = 0;
		movement.y -= _speed*deltaTime;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		_row = 2;
		movement.y += _speed*deltaTime;
	}
	if (sf::Keyboard::isKeyPressed == false)
	{
		_row = 2;
	}

	_animation.update(_row, deltaTime, _faceRight);
	_body.setTextureRect(_animation.uvRect);
	_body.move(movement);
}

void Player::draw(sf::RenderWindow &window)
{
	window.draw(_body);
}