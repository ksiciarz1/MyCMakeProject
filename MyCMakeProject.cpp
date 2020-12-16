// MyCMakeProject.cpp : Defines the entry point for the application.
//

#include "MyCMakeProject.h"

//using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(800, 600), "My Window", Style::Close);
	window.setFramerateLimit(60);
	window.setPosition(Vector2i(0, 0));
	window.setActive();


	Font font;
	font.loadFromFile("C:\\Users\\Kakasuke\\Desktop\\MyCMakeProject\\Fonts\\pixel_arial_11\\PIXEAB__.TTF");

	int i = 0;

	Texture sqr;
	sqr.loadFromFile("C:\\Users\\Kakasuke\\Desktop\\MyCMakeProject\\Texture\\sqr.png");

	/*Sprite myself(sqr);
	myself.setOrigin(50, 50);
	myself.setPosition(250, 250);
	myself.setColor(Color(255, 255, 255));*/

	Enemy myself(sqr, Vector2i(0, 0), Vector2i(50, 50));


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
				}
			}
			else if (event.type == Event::MouseButtonPressed)
			{
				if (event.key.code == Mouse::Left)
				{
					Vector2i mousePosition = Mouse::getPosition(window);
					if ((myself.getPosition().x - mousePosition.x <= 50) && (myself.getPosition().x - mousePosition.x >= -50) &&
						(myself.getPosition().y - mousePosition.y <= 50) && (myself.getPosition().y - mousePosition.y >= -50))
					{
						myself.sprite.setColor(Color(255, 0, 0));
						std::cout << "Dziala" << std::endl;
					}
					else
					{
						std::cout << std::to_string(myself.getPosition().x - mousePosition.y) + ", " + std::to_string(myself.getPosition().y - mousePosition.y) << std::endl;
					}
				}
			}
		} //end of Pollevent

		/*if (myself.getPosition().x >= 800)
		{
			myself.setPosition(0, myself.getPosition().y);
		}
		else if (myself.getPosition().x <= -50)
		{
			myself.setPosition(750, myself.getPosition().y);
		}
		if (myself.getPosition().y >= 600)
		{
			myself.setPosition(myself.getPosition().x, 0);
		}
		else if (myself.getPosition().y <= -50)
		{
			myself.setPosition(myself.getPosition().x, 550);
		}*/

		window.display();
		sleep(time);
	}
	//return EXIT_SUCCESS;
	return 0;
}
