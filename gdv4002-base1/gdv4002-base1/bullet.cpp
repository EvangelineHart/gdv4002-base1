#include "bullet.h"
#include "player.h"
extern glm::vec2 gravity;

bullet::bullet(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float mass) : GameObject2D(initPosition, initOrientation, initSize, initTextureID) {

	this->mass = mass;
	velocity = glm::vec2(0.0f, 0.0f);
	
}


void bullet::update(double tDelta) {

	// 1. Physics bit for movement
	float x = cosf(orientation);
	float y = sinf(orientation);
	glm::vec2 direction = glm::vec2(x, y);

	// 1.1. Sum forces - only add gravity for now
	glm::vec2 F = direction * thrust;

	// 1.2. Calculate acceleration
	glm::vec2 accel = F * (1.0f / mass);

	// 1.3. Update velocity
	velocity = velocity + accel * (float)tDelta;

	// 1.4. Update position
	position = position + velocity * (float)tDelta;


}

