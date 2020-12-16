#pragma once

#include <SFML\Graphics.hpp>
#include "Object.h"

using namespace sf;

class Enemy : public Object
{
private:
	int health = 100;

public:
	bool getHit(int damage);
	Enemy(Texture texture, Vector2i position, Vector2i origin);
};