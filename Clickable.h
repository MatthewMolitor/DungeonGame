#pragma once
#include <SFML/Graphics.hpp>

class Clickable
{
public:
	Clickable(sf::Texture *texture, sf::Vector2f size = sf::Vector2f(200.00f, 100.00f));
	~Clickable();

	bool isHovered(sf::RenderWindow &window);
	bool isClicked(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
	void setPosition(float x, float y) { _button.setPosition(x,y); };
	void setSize(sf::Vector2f&size) { _button.setSize(size); };
	sf::RectangleShape getSprite() { return _button; };


private:
	sf::RectangleShape _button;
};

