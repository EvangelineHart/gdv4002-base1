#include "Asteriod.h"
#include "Engine.h"

Enemy::Enemy(glm::vec2 initPosition,float initOrientation,glm::vec2 initSize,GLuint initTextureID,float initialPhase,float initialPhaseVelocity): GameObject2D(initPosition, initOrientation, initSize, initTextureID) {

	phaseAngle = initialPhase;
	phaseVelocity = initialPhaseVelocity;
	orientation = initOrientation;
}
void Enemy::update(double tDelta) {
	
	// Set position based on phaseAngle
	position.y = phaseAngle;
	
	// Update phaseAngle based on velocity * time elapsed
	phaseAngle += phaseVelocity * tDelta;
	orientation += phaseVelocity * tDelta;

	if (position.y < -2.5) {
		
		phaseAngle = 2.4f;
		position.y = 2.4f;

	}
	
	if (position.y > 2.5) {
		
		phaseAngle = -2.4f;
		position.y = -2.4f;
	}
	
}
