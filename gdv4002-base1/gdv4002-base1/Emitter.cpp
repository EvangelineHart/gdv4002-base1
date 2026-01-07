#include "Emitter.h"
#include "Engine.h"
#include "bullet.h"
#include "Player.h"

using namespace std;


Emitter::Emitter(glm::vec2 initPosition, glm::vec2 initSize, float emitTimeInterval) : GameObject2D(initPosition, 0.0f, initSize, 0) {
	this->emitTimeInterval = emitTimeInterval;
	emitCounter = emitTimeInterval;

	particleNumber = 0;

	

}
// override render but do nothing - we'll not render anything for the emitter 
void Emitter::render() {
}
void Emitter::update(double tDelta) {

	//emitCounter += (float)tDelta;

	while (emitCounter >= emitTimeInterval) {

		// decrease emitCounter by emitTimeInterval - don't set to 0 as this would ignore the case where multiple particles are needed.
		emitCounter -= emitTimeInterval;
		
		
		// Create new particle
		float x = position.x;
		float y = position.y;
		float scale = 0.3f;
		float mass = 0.08;
		GLuint bulletTexture = loadTexture("Resources\\Textures\\Bullet.png");

		bullet* b1 = new bullet(glm::vec2(x, y), 0.0f, glm::vec2(scale, scale), bulletTexture, mass);

		string key = string("bullet");

		if (particleNumber > 0) { // first name in collection must not be numbered if using this approach

			// add value so unique anyway - not using engine mechanism
			key += to_string(particleNumber);
		}

		particleNumber++;

		addObject(key.c_str(), b1);
	}
}





