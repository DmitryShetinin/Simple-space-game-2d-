#include <vector>
#include "MyParticiple.h" 
#include <thread>


class Dot {
public: 
	Dot();
	~Dot();

	void draw();
	void move();
	glm::vec2 getPos(); 


	float m_dx{ 0 };
	float m_x{ 0 };
	float m_y{ 0 };

private: 
	float angle = 0.0f; 
	float m_dy{ 0.5f };

	std::vector<Particle*> m_particle;
	Texture* m_texture; 

};