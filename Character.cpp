#include "Character.h"
#include "Object.h"

bool Character::getHit(int damage)
{
	health -= damage;
	if (health <= 0)
	{
		return true;
		die();
	}
	return false;
}

Character::Character(Texture* texture, Vector2i position, Vector2i origin)
	:Object(texture, position, origin)
{

}

void Character::addAnimation(Animation animation)
{
	animations.push_back(animation);
}
void Character::setAnimationSprite(int fromAnimation)
{
	Texture* texture;
	texture = animations.at(fromAnimation).getCurrentFrame();
	sprite.setTexture(*texture);
}