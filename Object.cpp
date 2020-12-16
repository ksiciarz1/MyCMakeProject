#include "Object.h"

using namespace sf;

bool toDelete = false;

void Object::die()
{
	toDelete = true;
}
bool Object::move(Vector2i moveVector)
{
	sprite.setPosition(sprite.getPosition().x + moveVector.x, sprite.getPosition().y + moveVector.y);
	return true;
}
Vector2f Object::getPosition()
{
	return sprite.getPosition();
}
Object::Object(Texture texture, Vector2i position, Vector2i origin)
{
	sprite.setTexture(texture);
	sprite.setOrigin(origin.x, origin.y);
	sprite.setPosition(position.x, position.y);
}
Object::~Object()
{

}