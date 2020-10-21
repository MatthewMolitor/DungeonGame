#include "Platform.h"



Platform::Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
	_body.setSize(size);
	_body.setTexture(texture);
	_body.setPosition(position);
	_body.setOrigin(size / 2.0f);
}


Platform::~Platform()
{
}


void Platform::Draw(sf::RenderWindow& window)
{
	window.draw(_body);
}