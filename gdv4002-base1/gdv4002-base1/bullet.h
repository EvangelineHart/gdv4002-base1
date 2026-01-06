#pragma once


#include "GameObject2D.h"

class bullet : public GameObject2D {

private:

	// We'll model physics properties for (linear) movement - that is movement without rotation
	float		mass;
	glm::vec2	velocity;
	const float thrust = 1.0f;
	

public:

	bullet(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float mass);

	void update(double tDelta) override;

};


