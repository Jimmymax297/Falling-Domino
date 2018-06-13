#pragma once
#define SCENE_CYCLE 20
#define CYLINDER_SEGMENTS 16
#define ANIMATION_SPEED 2
#define LIGHT_COLOR (glm::vec3(245.0/255.0f, 222.0/255.0f, 179.0/255.0f))
#define LIGHT_INTENSITY 128.0f
#define GROUND_SIZE 1000.0f
#define GROUND_COLOR (glm::vec3(1.0f,1.0f,1.0f))
#define BELT_COLOR (glm::vec3(0.2f,0.2f,0.2f))
#define LAMP_POST_COLOR (glm::vec3(0.99f,0.99f,0.0f))
#define LAMP_COLOR (glm::vec3(1,252.0/255,60.0/255))
#define LAMP_POST_HEIGHT (PILLAR_Y + 0.5*PILLAR_HEIGHT + 2.5f)
#define DOMINO_COUNT 20
#define DOMINO_HEIGHT 20.0f
#define DOMINO_WIDTH 8.0f
#define DOMINO_DEPTH 2.0f
#define DOMINO1_COLOR glm::vec3(128.0/255.0f, 128.0/255.0f, 128.0/255.0f)
#define DOMINO_COMP_HEIGHT ((DOMINO_HEIGHT - 1.2f) / 2)
#define DOMINO_COMP_WIDTH (DOMINO_WIDTH - 0.6f)
#define DOMINO_COMP_DEPTH DOMINO_DEPTH + 0.1f
#define DOMINO_UP_COMP_Y (0.75 * DOMINO_HEIGHT - 0.125f)
#define DOMINO_DOWN_COMP_Y (0.25 * DOMINO_HEIGHT + 0.125f)
#define RED glm::vec3(1.0f, 0.0f, 0.0f)
#define BLUE glm::vec3(0.0f, 0.0f, 1.0f)
#define GREEN glm::vec3(0.0f, 1.0f, 0.0f)
#define WHITE glm::vec3(1.0f, 1.0f, 1.0f)
#define POINTER_RADIUS 1.5f
#define POINTER_HEIGHT 15.0f
#define POINTER_COLOR glm::vec3(255.0/256.0f, 228.0/255.0f, 196.0/255.0f)
#define POINTER_Y 17.0f