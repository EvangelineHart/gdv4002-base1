#include "Engine.h"

// Function prototypes
void myUpdateScene(GLFWwindow* window, double tDelta);

int main(void) {

	// Initialise the engine (create window, setup OpenGL backend)
	int initResult = engineInit("GDV4002 - Applied Maths for Games", 1024, 1024);

	// If the engine initialisation failed report error and exit
	if (initResult != 0) {

		printf("Cannot setup game window!!!\n");
		return initResult; // exit if setup failed
	}

	//
	// Setup game scene objects here
	
	addObject("player", glm::vec2(0, 0), glm::radians(0.0f), glm::vec2(0.5f, 0.5f), "Resources\\Textures\\1000012029.png");
	
	setUpdateFunction(myUpdateScene);
	
	addObject("asteriod_1", glm::vec2(1.3f, 1.3f), 0.0f, glm::vec2(0.6f, 0.6f), "Resources\\Textures\\1000012028.png");
	
	addObject("asteriod_2", glm::vec2(-1.3f, -1.0f), 0.0f, glm::vec2(0.9f, 0.9f), "Resources\\Textures\\1000012028.png");
	
	addObject("asteriod_3", glm::vec2(1.7f, -1.5f), 0.0f, glm::vec2(1.0f, 1.0f), "Resources\\Textures\\1000012027.png");
	
	addObject("asteriod_4", glm::vec2(-1.8f, 1.3f), 0.0f, glm::vec2(1.0f, 0.9f), "Resources\\Textures\\1000012027.png");
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	

	// Enter main loop - this handles update and render calls
	engineMainLoop();

	// When we quit (close window for example), clean up engine resources
	engineShutdown();

	// return success :)
	return 0;
}
void myUpdateScene(GLFWwindow* window, double tDelta) {
	// add update code here
	const float pi = 3.141593f;
	const float thetaVelocity = (pi / 180.0f) * -90.0f; // 90 degrees stored as radians
	GameObject2D* player1 = getObject("player");
	player1->orientation = player1->orientation + (thetaVelocity * tDelta);
}


