#include "MovementComponent.h"

MovementComponent::MovementComponent(sf::Sprite& sprite,
	float maxVelocity, float acceleration, float deceleration)
	: sprite(sprite), 
	maxVelocity(maxVelocity), acceleration(acceleration), deceleration(deceleration)
{
	
}

MovementComponent::~MovementComponent()
{

}

const sf::Vector2f& MovementComponent::getVelocity() const
{
	return this->velocity;
}

//Functions
void MovementComponent::move(const float dir_x, const float dir_y, const float& dt)
{
	//Acceleration
	this->velocity.x += this->acceleration * dir_x;
	this->velocity.y += this->acceleration * dir_y;

}


void MovementComponent::update(const float& dt)
{
	/*Decelerate the sprite and check controls the maximum velocity */
	if (this->velocity.x > 0.f) //Check pos x
	{
		//Max velocity Check 
		if (this->velocity.x > this->maxVelocity)
			this->velocity.x = this->maxVelocity;

		//deceleration 
		this->velocity.x -= deceleration;
		if (this->velocity.x < 0.f)
			this->velocity.x = 0.f;

	}
	else if (this->velocity.x < 0.f) //Check neg x
	{
		//Max velocity Check
		if (this->velocity.x < -this->maxVelocity)
			this->velocity.x = -this->maxVelocity;

		//deceleration
		this->velocity.x += deceleration;
		if (this->velocity.x > 0.f)
			this->velocity.x = 0.f;
	}

	if (this->velocity.y > 0.f) //Check pos y
	{
		//Max velocity Check 
		if (this->velocity.y > this->maxVelocity)
			this->velocity.y = this->maxVelocity;

		//deceleration 
		this->velocity.y -= deceleration;
		if (this->velocity.y < 0.f)
			this->velocity.y = 0.f;

	}
	else if (this->velocity.y < 0.f) //Check neg y
	{
		//Max velocity Check
		if (this->velocity.y < -this->maxVelocity)
			this->velocity.y = -this->maxVelocity;

		//deceleration
		this->velocity.y += deceleration;
		if (this->velocity.y > 0.f)
			this->velocity.y = 0.f;
	}

	//final move 
	this->sprite.move(this->velocity * dt);  //uesd velocity
}
