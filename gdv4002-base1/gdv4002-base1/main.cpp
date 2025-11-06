#include "Engine.h"
#include "Keys.h"
#include <bitset>

// Function prototypes
void myUpdateScene(GLFWwindow* window, double tDelta);
void myKeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods);
std::bitset<5> keys{ 0x0 };

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
	
	addObject("asteriod_1", glm::vec2(1.3f, 1.3f), 0.0f, glm::vec2(0.6f, 0.6f), "Resources\\Textures\\1000012028.png");
	
	addObject("asteriod_2", glm::vec2(-1.3f, -1.0f), 0.0f, glm::vec2(0.9f, 0.9f), "Resources\\Textures\\1000012028.png");
	
	addObject("asteriod_3", glm::vec2(1.7f, -1.5f), 0.0f, glm::vec2(1.0f, 1.0f), "Resources\\Textures\\1000012027.png");
	
	addObject("asteriod_4", glm::vec2(-1.8f, 1.4f), 0.0f, glm::vec2(1.0f, 0.9f), "Resources\\Textures\\1000012027.png");

	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBlendFunc(GL_EQUAL, 0);
	
	setUpdateFunction(myUpdateScene);
	setKeyboardHandler(myKeyboardHandler);

	// Enter main loop - this handles update and render calls
	engineMainLoop();

	// When we quit (close window for example), clean up engine resources
	engineShutdown();

	// return success :)
	return 0;
}
void myUpdateScene(GLFWwindow* window, double tDelta) {
	// add update code here
	
	static float playerSpeed = 1.0f; // distance per second
	static float rotationSpeed = 1.0f;

	GameObject2D* player = getObject("player");

	if (keys.test(Key::W) == true) {

		player->position.y += playerSpeed * (float)tDelta;
	}
	if (keys.test(Key::S) == true) {

		player->position.y -= playerSpeed * (float)tDelta;
	}
	if (keys.test(Key::A) == true) {
		
		player->orientation += 0.03f;
		
	}
	if (keys.test(Key::D) == true) {

		player->orientation += -0.03f;
	}


}
void myKeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	// Check if the key was just pressed
	if (action == GLFW_PRESS) {

		// now check which key was pressed...
		switch (key)
		{
		case GLFW_KEY_ESCAPE:
			// If escape is pressed tell GLFW we want to close the 
			glfwSetWindowShouldClose(window, true);
			break;
		case GLFW_KEY_W:
			keys[Key::W] = true;
			break;
		case GLFW_KEY_S:
			keys[Key::S] = true;
			break;
		case GLFW_KEY_A:
			keys[Key::A] = true;
			break;
		case GLFW_KEY_D:
			keys[Key::D] = true;
			break;

		}
	}
	// If not pressed, check the key has just been released
	else if (action == GLFW_RELEASE) {
		switch (key)
		{
		case GLFW_KEY_W:
			keys[Key::W] = false;
			break;
		case GLFW_KEY_S:
			keys[Key::S] = false;
			break;
		case GLFW_KEY_A:
			keys[Key::A] = false;
			break;
		case GLFW_KEY_D:
			keys[Key::D] = false;
			break;

		}

		// handle key release events
	}
}


