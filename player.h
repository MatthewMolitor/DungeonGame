#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"
#include "Collider.h"

class Player
{
public:
	Player(sf::Texture*texture, sf::Vector2u imageCount, float switchTime, float speed, sf::FloatRect bounds);
	~Player();

	void update(float deltaTime);
	void draw(sf::RenderWindow &window);
	sf::Vector2f getPosition() { return _body.getPosition();}
	Collider GetCollider() { return Collider(_body); }
	void setPosition(float x, float y) {_body.setPosition(x,y);}
	bool hurt(float deltaTime);

	unsigned int invinsible;
	int lives;

protected:
	sf::RectangleShape _body;
	Animation _animation;
	unsigned int _row;
	float _speed;
	bool _faceRight;
	bool _hurt;
	sf::FloatRect _bounds;

};

