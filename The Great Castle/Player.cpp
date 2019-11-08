#include "Player.h"

//Initialize Functions
void Player::initVariables()
{

}

void Player::initComponents()
{

}


//Consturctors | Destructors
Player::Player(float x, float y, sf::Texture* texture)
{
	this->initVariables();
	this->initComponents();

	this->createSprite(texture);
	this->setPosition(x, y);
}

Player::~Player()
{

}
