#pragma once
#include <SFML/Graphics.hpp>

class Collider
{
public:
	Collider(sf::RectangleShape& body);
	~Collider();

	void Move(float dx, float dy) { _body.move(dx, dy); }

	bool CheckCollision(Collider& other, float push);
	sf::Vector2f GetPosition() { return _body.getPosition(); }
	sf::Vector2f GetHalfSize() { return (_body.getSize() / 2.0f); }
private:
	sf::RectangleShape& _body;
};

