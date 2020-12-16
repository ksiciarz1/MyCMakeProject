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
		if (animationFrames.size() < currentFrame)
		{
			currentFrame++;
		}
		else {
			currentFrame = 0;
		}
		timer = clock();
		return true;
	}
	else
	{
		std::cout << std::to_string((float)(clock() - timer)) << std::endl;
		return false;
	}
}
Texture Animation::getCurrentFrame()
{
	return animationFrames.at(currentFrame);
}
void Animation::addTexture(Texture texture)
{
	animationFrames.push_back(texture);
}

Animation::Animation()
{
}

Animation::~Animation()
{
}