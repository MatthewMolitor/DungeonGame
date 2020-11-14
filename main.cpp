#include <SFML\Graphics.hpp>
#include <iostream>
#include "Animation.h"
#include "player.h"
#include "Platform.h"
#include "Enemy.h"
#include "Menu.h"
#include "GameOver.h"



static const float VIEW_HEIGHT = 512.0f;
static const float VIEW_WIDTH = 1024.0f;

void ResizedView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT* aspectRatio, VIEW_HEIGHT);
	//window.mapCoordsToPixel(view);
	//window.mapPixelToCoords(view);
	// get the current mouse position in the window
	//sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
	// convert it to world coordinates
	//sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
}


int main()
{  
	//open game window
	sf::Style::Fullscreen;
	sf::RenderWindow window(sf::VideoMode(VIEW_WIDTH, VIEW_HEIGHT), "SFML Tutorial", sf::Style::Close | sf::Style::Resize);
	sf::View view(sf::Vector2f(0.0f,0.0f),sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT));
	sf::FloatRect bounds(sf::Vector2f(0.0f, 0.0f), window.getDefaultView().getSize());

	view.setCenter((view.getSize().x / 2.0f), (view.getSize().y / 2.0f));
	
	//load background texture
	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("Backgrounds/cave_001.png");
	//scale factor sets background to size of view
	sf::Vector2f backgroundScaleFactor = sf::Vector2f(view.getSize().x/sf::Vector2f(backgroundTexture.getSize()).x, view.getSize().y/sf::Vector2f(backgroundTexture.getSize()).y);
	sf::Sprite background(backgroundTexture);
	background.scale(backgroundScaleFactor);

	//load player texture
	sf::Texture playerTexture;
	playerTexture.loadFromFile("Sprites/minotaur_b.png");
	Player player(&playerTexture, sf::Vector2u(3, 4), 0.25f, 300.0f,bounds);


	//load minotaur texture
	sf::Texture minotaurTexture;
	minotaurTexture.loadFromFile("Sprites/minotaur_r.png");
	Enemy minotaur(&minotaurTexture, sf::Vector2u(3, 4), 0.25f, 100.0f,bounds, &player);

	//main menu declaration
	Menu mainMenu;
	int mode = -1;

	//game over menu declaration
	GameOver gameOver;

	//quit button to display in game loop	sf::Texture button2;
	sf::Texture quitPanel;
	quitPanel.loadFromFile("Interface/panel_quit.png");
	Clickable quitButton(&quitPanel);
	quitButton.setPosition(800,400);


	float deltaTime = 0.0f;
	sf::Clock clock;
	
	while (window.isOpen())
	{
		if (mode == -2)		//game over
		{
			mode = gameOver.Display(window, view);
		}
		else
			mode = mainMenu.Display(window, view);
		//main game loop
		player.lives = 3;
		while (mode==1)
		{
	
			deltaTime = clock.restart().asSeconds();

			sf::Event event;
			while (window.pollEvent(event))
			{
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					break;

				case sf::Event::Resized:
					std::cout << "new window width: " << event.size.width << "new window height " << event.size.height << std::endl;

					ResizedView(window, view);
					break;
				case sf::Event::TextEntered:
					if (event.text.unicode < 128)
						printf("%c", event.text.unicode);
					break;
				}
			}


			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				mousePos = sf::Vector2i(window.mapPixelToCoords(mousePos));
				player.setPosition((float)mousePos.x, static_cast <float>(mousePos.y));
			}


			if (quitButton.isClicked(window))
				mode = 0;


			quitButton.isHovered(window);
			player.update(deltaTime);
			minotaur.update(deltaTime);

			//view.setCenter(player.getPosition());

			//check collision between player and enemy
			if (player.GetCollider().CheckCollision(minotaur.GetCollider(), -1))
			{
				player.hurt(deltaTime);
				if (player.lives == 0)
					mode = -2;
			}




			window.clear(sf::Color(150, 150, 150));
			window.setView(view);

			//draw background
			window.draw(background);

			//draw enemies
			minotaur.draw(window);

			//draw player
			player.draw(window);

			//draw buttons
			quitButton.draw(window);

			window.display();
		}
		if (mode == -1)
			exit(0);
	}
	return 0;
}




