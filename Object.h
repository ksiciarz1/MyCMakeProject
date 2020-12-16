#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

using namespace sf;

class Object
{
private:

public:
	Sprite sprite;
	bool toDelete = false;
	std::vector<Animation> animations;

	void die();
	bool move(Vector2i moveVector);
	Vector2f getPosition();
	void addAnimation(Animation animation);
	void setAnimationSprite(int fromAnimation);

	Object(Texture texture, Vector2i position, Vector2i origin);
	~Object();
};