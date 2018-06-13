#include "frame.h"


Frame::Frame(GLfloat startTime, glm::vec3 position) 
:	position_enable (true),
	orientation_enable(false)
{
	setStartTime(startTime);
	setPosition(position);
}

Frame::Frame(GLfloat startTime, glm::vec3 axis, GLfloat angle)
	: position_enable(false),
	orientation_enable(true)
{
	setStartTime(startTime);
	setQuatRotation(axis, angle);
}

void Frame::setPosition(glm::vec3 position) {
	this->position = position;
}

void Frame::setQuatRotation(glm::vec3 axis, GLfloat angle)
{
	this->angle = angle;
	this->axis = axis;
}

void Frame::setStartTime(GLfloat startTime) {
	this->startTime = startTime;
}

const glm::vec3 Frame::getPosition() const {
	return position;
}

const GLfloat Frame::getStartTime() const
{
	return startTime;
}

bool Frame::isPositionEnabled()
{
	return position_enable;
}

bool Frame::isOrientationEnabled()
{
	return orientation_enable;
}

const glm::quat Frame::getOrientation() const
{
	return glm::angleAxis(angle, axis);
}
