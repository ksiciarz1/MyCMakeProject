#pragma once

#include <time.h>
#include <SFML\Graphics.hpp>
#include <iostream>


using namespace sf;

class Animation
{
public:
	void startTimer();
	bool compareTime();
	Texture* getCurrentFrame();
	void addTexture(Texture* texture);
	//void addTexture(String filePath);

	Animation();
	~Animation();

	int currentFrame = 0;
private:
	std::vector<Texture*> animationFrames;
	float animationSpeed = 300;
	clock_t timer;
};