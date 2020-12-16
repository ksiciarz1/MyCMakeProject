#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Object
{
private:

public:
	Sprite sprite;
	bool toDelete = false;

	void die();
	bool move(Vector2i moveVector);
	Vector2f getPosition();

	Object(Texture texture, Vector2i position, Vector2i origin);
	~Object();
};