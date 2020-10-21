#pragma once
#include <SFML\Graphics.hpp>

class Animation
{
public:
	Animation(sf::Texture*texture, sf::Vector2u imagecount, float switchTime);
	~Animation();
	void update(int row, float deltaTime, bool dir);


	sf::IntRect uvRect; 


private:
	//number images in the sprite sheet
	sf::Vector2u _imageCount;
	sf::Vector2u _currentImage;


	float _totalTime;
	//time spent on each image before switch
	float _switchTime;
};

