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

Enemy::Enemy(Texture texture, Vector2i position, Vector2i origin)
	:Object(texture, position, origin)
{

}