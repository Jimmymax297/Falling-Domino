#pragma once
#include <GL/glew.h>
#include <string>
#include <vector>

class Roombox {
private:
	GLuint id;
	GLuint VAO;
	GLuint VBO;
	std::vector<GLfloat> vertices;
public:
	Roombox(std::vector<std::string> filenames);
	GLuint getID() const { return id; }
	void render() const;
};