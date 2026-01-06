#include "Engine.h"
#include "Keys.h"
#include <bitset>
#include "Player.h"
#include "EnemyType1.h"
#include "Emitter.h"



// Function prototypes
void myKeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods);
std::bitset<5> keys{ 0x0 };
glm::vec2 gravity = glm::vec2(0.0f, -0.03f);

// Global variables

void deleteBullets(GLFWwindow* window, double tDelta);

int main(void) {

	// Initialise the engine (create window, setup OpenGL backend)
	int initResult = engineInit("GDV4002 - Applied Maths for Games", 1024, 1024);

	// If the engine initialisation failed report error and exit
	if (initResult != 0) {

		printf("Cannot setup game window!!!\n");
		return initResult; // exit if setup failed
	}

	
	// Setup rendering properties (enable blending)
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDepthFunc(GL_ALWAYS);

	
	// Setup game scene objects here


	GLuint playerTexture = loadTexture("Resources\\Textures\\1000012029.png");

	Player* mainPlayer = new Player(glm::vec2(-1.5f, 0.0f), 0.0f, glm::vec2(0.5f, 0.5f), playerTexture, 1.0f);

	addObject("player", mainPlayer);

	
	// 1. Load enemy texture 
	GLuint enemyTexture1 = loadTexture("Resources\\Textures\\1000012027.png");
	GLuint enemyTexture2 = loadTexture("Resources\\Textures\\1000012028.png");

	// 2. Create enemy objects
	Enemy* enemy1 = new Enemy(glm::vec2(1.0f, 1.0f), 0.5f, glm::vec2(1.2f, 1.2f), enemyTexture1, 1.5f, glm::radians(45.0f));

	Enemy* enemy2 = new Enemy(glm::vec2(-2.0f, 0.5f), 0.2f, glm::vec2(0.5f, 0.5f), enemyTexture1, -0.5f, glm::radians(90.0f));

	Enemy* enemy3 = new Enemy(glm::vec2(2.0f, 0.0f), 0.4f, glm::vec2(0.9f, 0.9f), enemyTexture2, 0.5f, glm::radians(25.0f));
	
	Enemy* enemy4 = new Enemy(glm::vec2(-1.0f, -1.0f), 1.0f, glm::vec2(1.0f, 1.5f), enemyTexture2, -1.0f, glm::radians(-45.0f));
	
	
	// Add enemy objects to the engine
	addObject("enemy1", enemy1);
	addObject("enemy2", enemy2);
	addObject("enemy3", enemy3);
	addObject("enemy4", enemy4);

	setKeyboardHandler(myKeyboardHandler);

	setUpdateFunction(deleteBullets, false);

	// Enter main loop - this handles update and render calls
	engineMainLoop();

	// When we quit (close window for example), clean up engine resources
	engineShutdown();

	// return success :)
	return 0;
	
}
void deleteBullets(GLFWwindow* window, double tDelta) {

	GameObjectCollection bullet = getObjectCollection("bullets");

	for (int i = 0; i < bullet.objectCount; i++) {

		if (bullet.objectArray[i]->position.y < -(getViewplaneHeight() / 2.0f)) {

			deleteObject(bullet.objectArray[i]);
		}
		if (bullet.objectArray[i]->position.x < -(getViewplaneWidth() / 2.0f)) {

			deleteObject(bullet.objectArray[i]);
		}
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
		case GLFW_KEY_SPACE:
			keys[Key::SPACE] = true;
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
		case GLFW_KEY_SPACE:
			keys[Key::SPACE] = false;
			break;
		}

		
	}
}


