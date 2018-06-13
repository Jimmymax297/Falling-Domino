#include "scene.h"
#include <cmath>
#include <iterator>
#include <glm/gtc/quaternion.hpp>
#include <glm/glm.hpp>
#include <cstdlib>
#include <ctime>
#include "texture.h"
#include "SimpleModelFactory.h"

void Scene::setPositionTexture(ModelComponent* model, glm::vec3 position, Texture texture) {
	model->setPosition(position);
	model->setTexture(texture);
}

void Scene::init() {
	initModels();
}

void Scene::initModels() {

	//pointer
	{
		ModelComponent* pointer = new ModelComponent(SimpleModelFactory::createCylinder(POINTER_RADIUS, POINTER_HEIGHT, CYLINDER_SEGMENTS, POINTER_COLOR));
		pointer->setTexture(blank);
		pointer->setPosition(glm::vec3(0.0f, POINTER_Y, 15.0f));
		models.add(pointer);

		Animation* pointerAnimation = new Animation(pointer);
		pointerAnimation->addFrame(new Frame(0.0f, glm::vec3(0, POINTER_Y, 15.0f)));
		pointerAnimation->addFrame(new Frame(3.0f, glm::vec3(0, POINTER_Y, 15.0f)));
		pointerAnimation->addFrame(new Frame(4.0f, glm::vec3(0, POINTER_Y, 11.0f)));
		pointerAnimation->addFrame(new Frame(4.5f, glm::vec3(0, POINTER_Y, 7.5f)));
		pointerAnimation->addFrame(new Frame(5.0f, glm::vec3(0, POINTER_Y, 11.0f)));
		pointerAnimation->addFrame(new Frame(6.0f, glm::vec3(0, POINTER_Y, 15.0f)));
		animations.push_back(*pointerAnimation);

	}

	//dominos
	{
		GLfloat angle = -glm::half_pi<float>() * 12.2 / 14;
		GLfloat angleTouch = -glm::half_pi<float>() * 1 / 4;
		GLfloat deltaTime = 0.5f;

		srand(time(NULL));
		for (int i = 0; i < DOMINO_COUNT; ++i) {
			ModelComposite* dom = new ModelComposite();
			
			ModelComponent* domino1 = new ModelComponent(SimpleModelFactory::createBox(DOMINO_WIDTH, DOMINO_HEIGHT, DOMINO_DEPTH, DOMINO1_COLOR));
			domino1->setTexture(domino);
			domino1->setPosition(glm::vec3(0.0f, 10.0f, 0.0f));

			ModelComponent* domino1_up = new ModelComponent(SimpleModelFactory::createBox(DOMINO_COMP_WIDTH, DOMINO_COMP_HEIGHT, DOMINO_COMP_DEPTH, RED));
			domino1_up->setTexture(blank);
			domino1_up->setPosition(glm::vec3(0.0f, DOMINO_UP_COMP_Y, 0.1f));

			ModelComponent* domino1_down = new ModelComponent(SimpleModelFactory::createBox(DOMINO_COMP_WIDTH, DOMINO_COMP_HEIGHT, DOMINO_COMP_DEPTH, BLUE));
			domino1_down->setTexture(blank);
			domino1_down->setPosition(glm::vec3(0.0f, DOMINO_DOWN_COMP_Y, 0.1f));

			dom->add(domino1);
			dom->add(domino1_up);
			dom->add(domino1_down);

			{
				for (int i = 1; i <= 2; ++i) {
					int r = rand() % 4;
					switch (r)
					{
					case 0:
						(*dom)[i]->setColor(WHITE);
						break;
					case 1:
						(*dom)[i]->setColor(BLUE);
						break;
					case 2:
						(*dom)[i]->setColor(GREEN);
						break;
					case 3:
						(*dom)[i]->setColor(RED);
						break;
					default:
						break;
					}
				}
			}

			dom->setPosition(glm::vec3(0.0f, 0.0f, DOMINO_DEPTH / 2));

			ModelComposite* dom_1 = new ModelComposite();
			dom_1->add(dom);

			{
				Animation* domAnimation = new Animation(dom_1);
				domAnimation->addFrame(new Frame(0.0f, glm::vec3(1.0f, 0.0f, 0.0f), 0));
				domAnimation->addFrame(new Frame(4.2f + deltaTime * i, glm::vec3(1.0f, 0.0f, 0.0f), 0));
				domAnimation->addFrame(new Frame(4.7f + deltaTime * i, glm::vec3(1.0f, 0.0f, 0.0f), angleTouch));
				if (i != DOMINO_COUNT - 1)
				{
					domAnimation->addFrame(new Frame(5.45f + deltaTime * i, glm::vec3(1.0f, 0.0f, 0.0f), (angle - angleTouch) / 2 + angleTouch));
					domAnimation->addFrame(new Frame(5.95f + deltaTime * i, glm::vec3(1.0f, 0.0f, 0.0f), (angle - angleTouch) * 3 / 4 + angleTouch));
					domAnimation->addFrame(new Frame(6.5f + deltaTime * i, glm::vec3(1.0f, 0.0f, 0.0f), (angle - angleTouch) * 7 / 8 + angleTouch));
					domAnimation->addFrame(new Frame(7.3f + deltaTime * i, glm::vec3(1.0f, 0.0f, 0.0f), angle));
				}
				else
					domAnimation->addFrame(new Frame(6.5f + deltaTime * i, glm::vec3(1.0f, 0.0f, 0.0f), -glm::half_pi<float>()));
				animations.push_back(*domAnimation);
			}

			ModelComposite* dom_2 = new ModelComposite();
			dom_2->add(dom_1);
			dom_2->setPosition(glm::vec3(0.0f, 0.0f, -10.0f * i));
			models.add(dom_2);
		}
	}

	// plane
	{
		ModelComponent* plane = new ModelComponent(SimpleModelFactory::createPlane(GROUND_SIZE, GROUND_SIZE, GROUND_COLOR));
		plane->setQuatRotation(glm::vec3(1, 0, 0), -glm::half_pi<float>());
		plane->setPosition(glm::vec3(0.0f, 0.0f, -30.0f));
		plane->setTexture(planeTexture);
		models.add(plane);
	}

	// lamp
	{
		ModelComposite* lamp = new ModelComposite{};

		ModelComponent* lampPost = new ModelComponent(SimpleModelFactory::createCylinder(2.0f, 20.0f, CYLINDER_SEGMENTS, LAMP_POST_COLOR));
		lampPost->setTexture(blank);
		lamp->add(lampPost);

		lamp->setQuatRotation(glm::vec3(1.0f, 0.0f, 0.0f), -glm::half_pi<float>());
		lamp->setPosition(glm::vec3(-30.0f, 10.0f, -20.0f));
		models.add(lamp);

		light = new Light(lampPost->getTruePosition() + glm::vec3(0, 9.5f, 0), LIGHT_COLOR, LIGHT_INTENSITY); //+ glm::vec3(LAMP_THICKNESS*0.5f - 0.1f, -LAMP_RADIUS - 0.5f, 0), LIGHT_COLOR, LIGHT_INTENSITY);
	}
}

//Scene time
void Scene::incrementTime(GLfloat delta) {
	timePosition += delta;
	timePosition = (float)fmod(timePosition, SCENE_CYCLE);
	for (auto it = animations.begin(); it != animations.end(); ++it)
		it->setTime(timePosition);
}

//Scene render
void Scene::render(Render renderer) {
	for (auto it = animations.begin(); it != animations.end(); ++it)
		it->animate();
	renderer.renderLight(*light);
	renderer.renderModel(&models);
}

Scene::~Scene() {
	delete light;
}