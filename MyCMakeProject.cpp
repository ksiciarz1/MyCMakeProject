// MyCMakeProject.cpp : Defines the entry point for the application.
//

#include "MyCMakeProject.h"

//using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(800, 600), "My Window", Style::Close);
	window.setFramerateLimit(60);
	//window.setPosition(Vector2i(0, 0));
	window.setActive();


	Font font;
	font.loadFromFile("C:\\Users\\Kakasuke\\Desktop\\MyCMakeProject\\Fonts\\pixel_arial_11\\PIXEAB__.TTF");

	int i = 0;

	Texture idle, move1, move2;
	Animation idleAnimation;
	Animation moveAnimation;

	idle.loadFromFile("..\\..\\..\\Texture\\idle.png");
	move1.loadFromFile("..\\..\\..\\Texture\\move1.png");
	move2.loadFromFile("..\\..\\..\\Texture\\move2.png");

	idleAnimation.addTexture(&idle);
	moveAnimation.addTexture(&move1);
	moveAnimation.addTexture(&move2);

	idleAnimation.startTimer();
	moveAnimation.startTimer();

	Character myself(&idle, Vector2i(150, 150), Vector2i(50, 50));

	myself.addAnimation(idleAnimation);
	myself.addAnimation(moveAnimation);
	myself.sprite.setTextureRect(IntRect(0, 0, 100, 100));

	clock_t idleTimer = 0;

	while (window.isOpen())
	{
		window.clear(Color(0, 25, 255));
		Text text("Dziala.", font, 12 * 6);
		text.setPosition(20, 20);

		int moveDistance = 50;

		window.draw(myself.sprite);
		window.draw(text);

		Mouse mouse;

		// Events
		Event event;
		Time time;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				std::cout << "Closed." << std::endl;
				window.close();
				return 0;
			}
			else if (event.type == Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case Keyboard::Escape:
					std::cout << "Closed." << std::endl;
					window.close();
					return 0;
					break;
				case Keyboard::S:
					myself.move(Vector2i(0, 50));
					break;
				case Keyboard::A:
					myself.move(Vector2i(-50, 0));
					break;
				case Keyboard::W:
					myself.move(Vector2i(0, -50));
					break;
				case Keyboard::D:
					myself.move(Vector2i(50, 0));
					break;
				case Keyboard::E:
					if (myself.animations.at(0).compareTime())
					{
						std::cout << "Animacja" << std::endl;
						std::cout << std::to_string(myself.animations.at(1).currentFrame) << std::endl;
						myself.setAnimationSprite(1);
						myself.sprite.setColor(Color(255, 255, 255));
						idleTimer = clock();
					}
					break;
				}
			}
			else if (event.type == Event::MouseButtonPressed)
			{
				if (event.key.code == Mouse::Left)
				{
					/*
					* foreach.enemyVecotr
					* {
					*  ||
					*  \/
					* }
					*/
					Vector2i mousePosition = Mouse::getPosition(window);
					if ((myself.getPosition().x - mousePosition.x <= 50) && (myself.getPosition().x - mousePosition.x >= -50) &&
						(myself.getPosition().y - mousePosition.y <= 50) && (myself.getPosition().y - mousePosition.y >= -50))
					{
						myself.sprite.setColor(Color(255, 25, 25));
						std::cout << "Hit" << std::endl;
					}
					else
					{
						//code ...
						//std::cout << std::to_string(myself.getPosition().x - mousePosition.y) + ", " + std::to_string(myself.getPosition().y - mousePosition.y) << std::endl;
					}
				}
			}
		} //end of Pollevent

		//map bounds
		if (myself.getPosition().x > 750)
		{
			myself.sprite.setPosition(750, myself.getPosition().y);
		}
		else if (myself.getPosition().x < 50)
		{
			myself.sprite.setPosition(50, myself.getPosition().y);
		}
		if (myself.getPosition().y > 550)
		{
			myself.sprite.setPosition(myself.getPosition().x, 550);
		}
		else if (myself.getPosition().y < 50)
		{
			myself.sprite.setPosition(myself.getPosition().x, 50);
		}

		//setting idle animation after 1500 milsec cooldown
		if ((float)(clock() - idleTimer) >= 1500)
		{
			myself.setAnimationSprite(0);
			myself.sprite.setColor(Color(255, 255, 255));
			idleTimer = clock();
		}


		std::cout << std::to_string(myself.getPosition().x) + ", " + std::to_string(myself.getPosition().y) << std::endl;


		window.display();
		sleep(time);
	}
	//return EXIT_SUCCESS;
	return 0;
}
