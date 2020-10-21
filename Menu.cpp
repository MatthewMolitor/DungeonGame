#include "Menu.h"


Menu::Menu()
{
	foo = 10;
}


Menu::~Menu()
{
}


int Menu::Display()
{
	//open main window
	sf::Style::Fullscreen;
	sf::RenderWindow window(sf::VideoMode(1512.0f, 1024.0f), "Main Menu", sf::Style::Close | sf::Style::Resize);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1512.0f, 1024.0f));

	view.setCenter((view.getSize().x / 2.0f), (view.getSize().y / 2.0f));

	//load background texture
	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("Backgrounds/main_menu.png");
	//scale factor sets background to size of view
	sf::Vector2f backgroundScaleFactor = sf::Vector2f(view.getSize().x / sf::Vector2f(backgroundTexture.getSize()).x, view.getSize().y / sf::Vector2f(backgroundTexture.getSize()).y);
	sf::Sprite background(backgroundTexture);
	background.scale(backgroundScaleFactor);

	sf::Texture button1;
	button1.loadFromFile("Interface/panel_play.png");
	sf::Texture button2;
	button2.loadFromFile("Interface/panel_quit.png");
	sf::Texture button3;
	button3.loadFromFile("Interface/panel_settings.png");

	Clickable playButton(&button1);
	Clickable quitButton(&button2);
	Clickable settingsButton(&button3);


	playButton.setPosition(100, 300);
	quitButton.setPosition(600, 300);
	settingsButton.setPosition(1100, 300);

	sf::Text text;
	sf::Font font;
	text.setFont(font);
	text.setString("PLAY");
	text.setCharacterSize(100);
	text.setFillColor(sf::Color::Red);
	//text.setPosition(100, 300);






	float deltaTime = 0.0f;
	sf::Clock clock;

	while (1)
	{
		deltaTime = clock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::Resized:
				std::cout << "new window width: " << event.size.width << "new window height " << event.size.height << std::endl;
				//ResizedView(window, view);
				break;
			case sf::Event::TextEntered:
				if (event.text.unicode < 128)
					printf("%c", event.text.unicode);
				break;
			}
		}


		playButton.isHovered(window);
		quitButton.isHovered(window);
		settingsButton.isHovered(window);


		if (quitButton.isClicked(window))
			return -1;
		if (playButton.isClicked(window))
			return 1;

		window.clear(sf::Color(150, 150, 150));
		window.setView(view);

		//draw background
		window.draw(background);

		//draw buttons

		quitButton.draw(window);
		playButton.draw(window);
		settingsButton.draw(window);


		//draw text
		window.draw(text);
		//draw player
		window.display();
	
	}
	window.close();
	return -1;
}