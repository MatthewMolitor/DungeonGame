#include "Animation.h"



Animation::Animation(sf::Texture*texture, sf::Vector2u imagecount, float switchTime)
{
	this->_imageCount = imagecount;
	this->_switchTime = switchTime;
	_totalTime = 0.0f; 
	_currentImage.x = 0;

	uvRect.width = texture->getSize().x / float(imagecount.x);
	uvRect.height = texture->getSize().y / float(imagecount.y);
}


Animation::~Animation()
{
}


void Animation::update(int row, float deltaTime, bool dir)
{
	_currentImage.y = row;
	_totalTime += deltaTime;

	if (_totalTime >= _switchTime)
	{
		_totalTime -= _switchTime;
		_currentImage.x++;

		if (_currentImage.x >= _imageCount.x)
			_currentImage.x = 0;
	}

	uvRect.left = _currentImage.x*uvRect.width;
	uvRect.top = _currentImage.y*uvRect.height;


	if (dir)
	{
		uvRect.left = (_currentImage.x)* abs(uvRect.width);
		uvRect.width = abs(uvRect.width);
	}

	else
	{
		uvRect.left = (_currentImage.x + 1)* abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}
}
