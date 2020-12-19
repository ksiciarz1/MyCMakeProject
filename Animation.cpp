#include "Animation.h"

void Animation::startTimer()
{
	timer = clock();
	currentFrame = 0;
}
bool Animation::compareTime()
{
	if ((float)(clock() - timer) >= animationSpeed)
	{
		timer = clock();
		return true;
	}
	else return false;
}
Texture* Animation::getCurrentFrame()
{
	if (animationFrames.size() > currentFrame)
	{
		currentFrame++;
		return animationFrames.at(currentFrame - 1);
	}
	else
	{
		currentFrame = 0;
		return animationFrames.at(currentFrame);
	}
}
void Animation::addTexture(Texture* texture)
{
	animationFrames.push_back(texture);
}

/*void Animation::addTexture(String filePath)
{
	Texture texture;
	texture.loadFromFile(filePath);
	animationFrames.push_back(texture);
}*/

Animation::Animation()
{
}

Animation::~Animation()
{
}