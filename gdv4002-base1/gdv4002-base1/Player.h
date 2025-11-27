#pragma once

#include "GameObject2D.h"

class Player : public GameObject2D {

private:
	float		mass;
	glm::vec2	velocity;
	const float thrust = 1.0f;

public:
	Player(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float mass);

	void update(double tDelta) override;

};

