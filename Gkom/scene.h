#pragma once
#ifdef _WIN32
#define GLEW_STATIC
#endif
#include <map>
#include <deque>
#include "render.h"
#include "modelComposite.h"
#include "modelComponent.h"
#include "light.h"
#include "texture.h"
#include "animation.h"
#include "parameters.h"

class Scene {
private:
	ModelComposite models;
	GLfloat timePosition;
	Light* light;
	std::deque<Animation> animations;
	Texture domino;
	Texture planeTexture;
	Texture blank;
	void initModels();
	void setPositionTexture(ModelComponent* model, glm::vec3 position, Texture texture);

public:
	Scene() : 
		domino("Texture/Ramka.jpg"),
		planeTexture("Texture/Plane.jpg"),
		blank("Texture/blank.jpg"),
		timePosition(0) {
		init();
	}
	~Scene();
	void incrementTime(GLfloat delta);
	Light& getLight() { return *light; }
	void init();
	void render(Render renderer);
};