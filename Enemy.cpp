#include "Enemy.h"
#include "Object.h"

bool Enemy::getHit(int damage)
{
	health -= damage;
	if (health <= 0)
	{
		return true;
		die();
	}
	return false;
}

Enemy::Enemy(Texture* texture, Vector2i position, Vector2i origin)
	:Object(texture, position, origin)
{

}

void Enemy::addAnimation(Animation animation)
{
	animations.push_back(animation);
}
void Enemy::setAnimationSprite(int fromAnimation)
{
	Texture* texture;
	texture = animations.at(fromAnimation).getCurrentFrame();
	sprite.setTexture(*texture);
}