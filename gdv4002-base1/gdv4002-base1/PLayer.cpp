#include "Player.h"
#include "Keys.h"
#include "Engine.h"
#include "Emitter.h"
#include <bitset>
#include <iostream>

extern std::bitset<5> keys;

Player::Player(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float mass) : GameObject2D(initPosition, initOrientation, initSize, initTextureID) {

	this->mass = mass;
	velocity = glm::vec2(0.0f, 0.0f); 
}

void Player::update(double tDelta) {
	
	playerOrientationForBullet = orientation;
	
	float x = cosf(orientation);
	float y = sinf(orientation);

	Emitter* emitter = new Emitter(
		glm::vec2(position.x, position.y),
		glm::vec2(x, y), 0.2f);
	
	
	if (position.y < -2.5) {

		position.y = 2.5f;
	}
	if (position.x < -2.5) {

		position.x = 2.5f;
	}
	if (position.y > 2.5) {

		position.y = -2.5f;
	}
	if (position.x > 2.5) {

		position.x = -2.5f;
	}

	glm::vec2 F = glm::vec2(0.0f, 0.0f);
	// 1. accumulate forces
	if (keys.test(Key::W) == true) {
		
		float x = cosf(orientation);
		float y = sinf(orientation);
		glm::vec2 direction = glm::vec2(x, y);
		
		F += direction * thrust;
		
	}
	if (keys.test(Key::S) == true) {

		float x = cosf(orientation);
		float y = sinf(orientation);
		glm::vec2 direction = glm::vec2(x, y);

		F -= direction * thrust;
		
	}
	if (keys.test(Key::A) == true) {
		
		orientation += 0.002;
	}
	if (keys.test(Key::D) == true) {
		
		orientation -= 0.002f;
		
	}
	if (keys.test(Key::SPACE) == true) {

	addObject("bullet", emitter);

	}

	// 2. calculate acceleration.  If f=ma, a = f/m
	glm::vec2 a = F * (1.0f / mass);
	
	// 3. integate to get new velocity
	velocity = velocity + (a * (float)tDelta);
	
	// 4. integrate to get new position
	position = position + (velocity * (float)tDelta);

}
float Player::getPlayerOrientation()
{
	return playerOrientationForBullet;
}