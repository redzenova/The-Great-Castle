#include "Player.h"

//Initialize Functions
void Player::initVariables()
{

}

void Player::initComponents()
{

}


//Consturctors | Destructors
Player::Player(float x, float y, sf::Texture& texture_sheet)
{
	this->initVariables();

	this->setPosition(x, y);
	this->setSize(0.4f);

	this->createHitbocComponent(this->sprite, 42.f, 50.f, 50.f, 80.f);
	this->createMovementComponent(160.f, 10.f, 5.f);
	this->createAnimationComponent(texture_sheet);

	this->animationComponent->addAnimation("WALK", 10.f, 0, 0, 8, 0 , 310, 342);
	this->animationComponent->addAnimation("IDLE", 10.f, 0, 1, 9, 1, 310, 342);
}

Player::~Player()
{

}


//Functions
void Player::update(const float& dt)
{
	this->movementComponent->update(dt);

	if(this->movementComponent->getState(IDLE))
		this->animationComponent->play("IDLE", dt);
	else if (this->movementComponent->getState(MOVING_LEFT))
	{
		this->sprite.setOrigin(328.f, 0.f);
		this->sprite.setScale(-0.4f,0.4f);
		this->animationComponent->play("WALK", dt);
	}
	else if (this->movementComponent->getState(MOVING_RIGHT))
	{
		this->sprite.setOrigin(0.f, 0.f);
		this->sprite.setScale(0.4f, 0.4f);
		this->animationComponent->play("WALK", dt);
	}
		

	this->hitboxComponent->update();
}
