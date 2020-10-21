#include "Clickable.h"
#include <stdio.h>


Clickable::Clickable(sf::Texture *texture, sf::Vector2f size) 
	
{
	_button.setSize(size);
	_button.setPosition(0.0f, 0.0f);
	_button.setTexture(texture);
	//_button.setOrigin(_button.getSize() / 2.0f);
}


Clickable::~Clickable()
{
}


void Clickable::draw(sf::RenderWindow &window)
{
	window.draw(_button);
}

bool Clickable::isClicked(sf::RenderWindow &window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		sf::FloatRect bounds = _button.getLocalBounds();
		sf::Vector2f pos = _button.getPosition();
		sf::FloatRect foo(pos.x, pos.y, bounds.width, bounds.height);
		//printf("position of mouse = (%u,%u)\n", mousePos.x, mousePos.y);
		if (foo.contains(mousePos.x, mousePos.y))
			return true;
	}

	return false;
}

bool Clickable::isHovered(sf::RenderWindow &window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	sf::FloatRect bounds = _button.getLocalBounds();
	sf::Vector2f pos = _button.getPosition();
	sf::FloatRect foo(pos.x, pos.y, bounds.width, bounds.height);
	//printf("position of mouse = (%u,%u)\n", mousePos.x, mousePos.y);
	if (foo.contains(mousePos.x, mousePos.y))
	{
		_button.setFillColor(sf::Color::Blue);
		return false;
	}
	else
	{
		_button.setFillColor(sf::Color::White);
		return false;
	}
}
