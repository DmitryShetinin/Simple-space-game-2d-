#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include <GL/glew.h> 
#include <Windows.h>
#include <math/glm.hpp>



class Texture{

public:
	Texture(const char* path);
	Texture();
	~Texture();
	
	


	void draw(float alpha);
	void scale(float x);
	void Scale(float x);
	void setPos(float x, float y);


	glm::vec2 getPos();
	glm::vec2 Velocity; 
private:
	float PosX;
	float PosY;

	glm::vec2 vertex1[4]{
		glm::vec2(-1,-1),
		glm::vec2(1,-1),
		glm::vec2(1,1),
		glm::vec2(-1,1),
	};


	unsigned int texture;
	unsigned char* data;


};

