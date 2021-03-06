#ifdef _WIN32
#define GLEW_STATIC
#endif


#include <iostream>
#include <vector>
#ifdef _WIN32
using namespace std;
#else //unnecessary
#include "vs_adapter.h"
#endif
#define GL_MAJOR 3
#define GL_MINOR 0


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <glm/gtx/transform.hpp>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL.h>

// Model
#include "SimpleModelFactory.h"
#include "modelComposite.h"
// Shader
#include "shprogram.h"
// Window
#include "window.h"
// Scene
#include "render.h"
#include "camera.h"
#include "scene.h"
// Texture
#include "texture.h"
#include "Roombox.h"

#define CLEAR_COLOR 100.0f/255, 120.0f/255, 235.0f/255


const GLuint WIDTH = 1600, HEIGHT = 900;

int main() {
	Window window(GL_MAJOR, GL_MINOR, "Domino", WIDTH, HEIGHT);
	Scene scene{};
	Light &light = scene.getLight();
	Camera camera(glm::vec3(0, 0, 0), 1.3f, 0.5f, 48.0f);
	Render render(camera);
	std::vector<std::string> RoomboxNames = { "Texture/wall_texture.jpg", "Texture/wall_texture.jpg", "Texture/wall_texture.jpg", "Texture/wall_texture.jpg", "Texture/wall_texture.jpg", "Texture/wall_texture.jpg" };
	Roombox Roombox(RoomboxNames);

	GLfloat delta = 0;
	GLfloat lastFrame = (GLfloat)glfwGetTime();

	glClearColor(CLEAR_COLOR, 1.0f);

	do {
		GLfloat currentFrame = (GLfloat)glfwGetTime(); //getting time
		delta = currentFrame - lastFrame; //for animation speed
		lastFrame = currentFrame;

		window.pollEvents();
		scene.incrementTime(delta * ANIMATION_SPEED);

		if (window.getKey(GLFW_KEY_RIGHT) == GLFW_PRESS)
			camera.incrementHAngle(-delta);
		if (window.getKey(GLFW_KEY_LEFT) == GLFW_PRESS)
			camera.incrementHAngle(delta);
		if (window.getKey(GLFW_KEY_UP) == GLFW_PRESS)
			camera.incrementVAngle(delta);
		if (window.getKey(GLFW_KEY_DOWN) == GLFW_PRESS)
			camera.incrementVAngle(-delta);
		if (window.getKey(GLFW_KEY_Z) == GLFW_PRESS)
			camera.incrementDistance(-delta);
		if (window.getKey(GLFW_KEY_X) == GLFW_PRESS)
			camera.incrementDistance(delta);
		if (window.getKey(GLFW_KEY_A) == GLFW_PRESS)
			light.incrementIntensity(-delta);
		if (window.getKey(GLFW_KEY_S) == GLFW_PRESS)
			light.incrementIntensity(delta);

		render.renderRoombox(Roombox);
		render.renderView();
		scene.render(render);


		window.swapBuffers();
		window.pollEvents();

	} //  If the ESC key was pressed or the window was closed
	while (window.getKey(GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		window.shouldClose() == 0);
}