#pragma once
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/mat4x4.hpp>
#include <GL/glew.h>
#include <glm/vec3.hpp>


class Frame
{
public:
	Frame(GLfloat startTime, glm::vec3 position);
	Frame(GLfloat startTime, glm::vec3 axis, GLfloat angle);

	void setPosition(glm::vec3 position);
	void setQuatRotation(glm::vec3 axis, GLfloat angle);
	void setStartTime(GLfloat startTime);
	const glm::vec3 getPosition() const;
	const GLfloat getStartTime() const;
	bool isPositionEnabled();
	bool isOrientationEnabled();
	const glm::quat getOrientation() const;

private:
	GLfloat startTime;
	glm::vec3 position;
	glm::quat orientation;
	glm::vec3 axis;
	GLfloat angle;
	bool position_enable;
	bool orientation_enable;
};