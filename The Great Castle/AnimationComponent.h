#ifndef ANIMATIONCOMPONENT_H
#define ANIMATIONCOMPONENT_H

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <map>

class AnimationComponent
{
private:
	class Animation
	{
	public:
		//Variable
		sf::Texture& textureSheets;
		float speed;
		int width;
		int heigth;

		sf::IntRect startRect;
		sf::IntRect endRect;

		Animation(sf::Texture& textureSheets, float speed, int start_x, int start_y, int end_x, int end_y, int width, int height)
			: textureSheets(textureSheets), speed(speed), width(width), height(height)
		{

			this->startRect = sf::IntRect(start_x, start_y, width, height);
			this->endRect = sf::IntRect(end_x, end_y, width, height);
		}

		//Functions
		void update(const float& dt)
		{

		}

		void pause();
		void reset();
	};

	std::map<std::string,Animation> animations;

public:
	AnimationComponent();
	virtual ~AnimationComponent();

	//Functions

};

#endif

