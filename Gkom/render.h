#pragma once
#ifdef _WIN32
#define GLEW_STATIC
#endif
#include "model.h"
#include "shprogram.h"
#include "texture.h"
#include "Roombox.h"
#include "light.h"
#include "camera.h"

class Render {
private:
	GLuint mainShader;
	GLuint RoomboxShader;
	GLint modelHandle;
	GLuint viewHandle;
	GLuint projectionHandle;
	GLuint textureHandle;
	GLuint RoomboxViewHandle;
	GLuint RoomboxProjectionHandle;
	GLuint RoomboxTextureHandle;
	GLuint lightPositionHandle;
	GLuint lightDiffuseColorHandle;
	GLuint lightAmbientColorHandle;
	GLuint viewPositionHandle;
	Camera& camera;

public:
	Render(Camera& camera);
	void renderModel(const Model* model);
	void renderView();
	void renderRoombox(const Roombox& roombox);
	void renderLight(const Light& light);
};