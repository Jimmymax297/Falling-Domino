#pragma once
#ifdef _WIN32
#define GLEW_STATIC
#endif
#include "mesh.h"
#include <glm/mat4x4.hpp>
#include <glm/gtx/quaternion.hpp>
#include "texture.h"


class Model
{
public:
	void setPosition(glm::vec3 position);
	void setOrientation(glm::quat orientation);
	void setQuatRotation(glm::vec3 axis, GLfloat angle);
	void setExternalMatrix(glm::mat4 matrix);
	const glm::vec3 getTruePosition() const;
	const glm::vec3 getPosition() const;
	const glm::quat getOrientation() const;
	const glm::mat4& getMatrix() const;
	const glm::mat4& getExternalMatrix() const;

	virtual void calculateMatrix() = 0;
	virtual void render(GLuint matrixHandle, GLuint textureHandle) const = 0;
	virtual Model* copy() = 0;
	virtual void setColor(glm::vec3 meshColor) = 0;

	glm::mat4 matrix;
	glm::mat4 externalMatrix;

protected:
	void setMatrix(glm::mat4 matrix);

private:
	
	glm::vec3 position;
	glm::quat orientation;
};