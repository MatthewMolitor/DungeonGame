#include "Player.h"



Player::Player(sf::Texture*texture, sf::Vector2u imageCount, float switchTime, float speed, sf::FloatRect bounds)
	: _animation(texture, imageCount, switchTime)
{
	this->_speed = speed;
	invinsible = 0;
	lives = 3;

	_hurt = false;
	_row = 0;
	_faceRight = true;
	_bounds = bounds;
	
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
	float boost = 1;
	sf::Vector2f movement(0.0f, 0.0f);
	if (invinsible < 10)
	{
		invinsible = 0;
		_hurt = false;
	}
	else
	{
		_hurt = true;
		invinsible = invinsible - deltaTime;
	}

	sf::Color fill =  _hurt ? sf::Color::Red : sf::Color::White;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		boost = 2;

	//CHECK IF INSIDE WINDOW
	printf("%u....%u\n", _body.getPosition().x, _body.getPosition().y);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		_row = 3;
		movement.x -= _speed*boost*deltaTime;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		_row = 1;
		movement.x += _speed*boost*deltaTime;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		_row = 0;
		movement.y -= _speed*boost*deltaTime;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		_row = 2;
		movement.y += _speed*boost*deltaTime;
	}
	if (sf::Keyboard::isKeyPressed == false)
	{
		_row = 2;
	}
	if (_body.getPosition().y < _bounds.top)
		movement.y = 50.0f;
	if (_body.getPosition().y > _bounds.height)
		movement.y = -50.0f;
	if (_body.getPosition().x < _bounds.left)
		movement.x = 50.0f;
	if (_body.getPosition().x > _bounds.width)
		movement.x = -50.0f;
	
	_animation.update(_row, deltaTime, _faceRight);
	_body.setFillColor(fill);
	_body.setTextureRect(_animation.uvRect);
	_body.move(movement);
	
}
bool::Player::hurt(float deltaTime)
{
	if (invinsible == 0)
	{
		lives--;
		invinsible = 2000;
		return 1;
	}
	else return 0;
		
}

void Player::draw(sf::RenderWindow &window)
{
	window.draw(_body);
}