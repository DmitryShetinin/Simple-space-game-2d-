#include <vector>
#include "MyParticiple.h" 
#include <thread>


class Dot {
public: 
	Dot();
	~Dot();

	void draw();
	void move();

private: 

	float m_dx{ 0.5f };
	float m_dy{ 0.5f };
	float m_x{ 0 };
	float m_y{ 0 };

	std::vector<Particle*> m_particle;
	Texture* m_texture; 

};